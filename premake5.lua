include "./ThirdParty/premake/customization/solution_items.lua"
include "Dependencies.lua"

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