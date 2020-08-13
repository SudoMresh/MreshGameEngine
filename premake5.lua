workspace "MreshEngine"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MreshEngine/thirdparty/GLFW/include"
IncludeDir["Glad"] = "MreshEngine/thirdparty/Glad/include"
IncludeDir["ImGui"] = "MreshEngine/thirdparty/imgui"
IncludeDir["glm"] = "MreshEngine/thirdparty/glm"
IncludeDir["stb_image"] = "MreshEngine/thirdparty/stb_image"

group "Dependencies"
	include "MreshEngine/thirdparty/GLFW"
	include "MreshEngine/thirdparty/Glad"
	include "MreshEngine/thirdparty/imgui"

group ""

project "MreshEngine"
	location "MreshEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mepch.h"
	pchsource "MreshEngine/src/mepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/thirdparty/stb_image/**.h",
		"%{prj.name}/thirdparty/stb_image/**.cpp",
		"%{prj.name}/thirdparty/glm/glm/**.hpp",
		"%{prj.name}/thirdparty/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/thirdparty/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ME_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ME_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ME_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"MreshEngine/thirdparty/spdlog/include",
		"MreshEngine/src",
		"MreshEngine/thirdparty",
		"%{IncludeDir.glm}"
	}

	links
	{
		"MreshEngine"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "ME_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ME_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ME_DIST"
		runtime "Release"
		optimize "on"
