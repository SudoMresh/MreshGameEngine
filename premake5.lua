include "./ThirdParty/premake/customization/solution_items.lua"

workspace "MreshEngine"
	architecture "x86_64"
	startproject "MreshEngine-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	solution_items
	{
		".editorconfig"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Engine/ThirdParty/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Engine/ThirdParty/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Engine/ThirdParty/imgui"
IncludeDir["glm"] = "%{wks.location}/Engine/ThirdParty/glm"
IncludeDir["stb_image"] = "%{wks.location}/Engine/ThirdParty/stb_image"
IncludeDir["entt"] = "%{wks.location}/Engine/ThirdParty/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Engine/ThirdParty/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Engine/ThirdParty/ImGuizmo"

group "Dependencies"
	include "ThirdParty/premake"
	include "Engine/ThirdParty/GLFW"
	include "Engine/ThirdParty/Glad"
	include "Engine/ThirdParty/imgui"
	include "Engine/ThirdParty/yaml-cpp"

group ""

include "Engine"
include "Editor"
include "Sandbox"