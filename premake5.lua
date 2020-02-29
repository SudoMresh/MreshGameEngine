workspace "MreshEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MreshEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "MreshEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "MreshEngine/vendor/imgui"

include "MreshEngine/vendor/GLFW"
include "MreshEngine/vendor/Glad"
include "MreshEngine/vendor/imgui"

project "MreshEngine"
	location "MreshEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "mepch.h"
	pchsource "MreshEngine/src/mepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"Glad",
		"GLFW",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect  "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ME_PLATFORM_WINDOWS",
			"ME_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "ME_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		buildoptions "/MD"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"MreshEngine/vendor/spdlog/include",
		"MreshEngine/src"
	}

	links 
	{
		"MreshEngine"
	}

	filter "system:windows"
		cppdialect  "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ME_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "ME_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		buildoptions "/MD"
		optimize "On"
