project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Source/**.h",
		"Source/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Engine/ThirdParty/spdlog/include",
		"%{wks.location}/Engine/Source",
		"%{wks.location}/Engine/ThirdParty",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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
