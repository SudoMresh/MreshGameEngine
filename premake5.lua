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
IncludeDir["GLFW"] = "Engine/ThirdParty/GLFW/include"
IncludeDir["Glad"] = "Engine/ThirdParty/Glad/include"
IncludeDir["ImGui"] = "Engine/ThirdParty/imgui"
IncludeDir["glm"] = "Engine/ThirdParty/glm"
IncludeDir["stb_image"] = "Engine/ThirdParty/stb_image"

group "Dependencies"
	include "Engine/ThirdParty/GLFW"
	include "Engine/ThirdParty/Glad"
	include "Engine/ThirdParty/imgui"

group ""

project "MreshEngine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mepch.h"
	pchsource "Engine/Source/mepch.cpp"

	files
	{
		"Engine/Source/**.h",
		"Engine/Source/**.cpp",
		"Engine/ThirdParty/stb_image/**.h",
		"Engine/ThirdParty/stb_image/**.cpp",
		"Engine/ThirdParty/glm/glm/**.hpp",
		"Engine/ThirdParty/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"Engine/Source",
		"Engine/ThirdParty/spdlog/include",
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

	targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"Engine/ThirdParty/spdlog/include",
		"Engine/Source",
		"Engine/ThirdParty",
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
