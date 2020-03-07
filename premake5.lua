workspace "MreshEngine"
	architecture "x64"

	startproject "Sandbox"
	
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
IncludeDir["glm"] = "MreshEngine/vendor/glm"

include "MreshEngine/vendor/GLFW"
include "MreshEngine/vendor/Glad"
include "MreshEngine/vendor/imgui"

project "MreshEngine"
	location "MreshEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "mepch.h"
	pchsource "MreshEngine/src/mepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
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
		systemversion "latest"

		defines
		{
			"ME_PLATFORM_WINDOWS",
			"ME_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "ME_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		runtime "Release"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"MreshEngine/src",
		"MreshEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links 
	{
		"MreshEngine"
	}

	filter "system:windows"
		cppdialect  "C++17"
		systemversion "latest"

		defines
		{
			"ME_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "ME_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		runtime "Release"
		optimize "On"
