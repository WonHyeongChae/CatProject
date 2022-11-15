workspace "Catz"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}


startproject "Sandbox"

group "Dependencies"

project "Ragdoll"
	location "Ragdoll"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ragpch.h"
	pchsource "Ragdoll/src/ragpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	links 
	{ 
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines
		{
			"RAG_PLATFORM_WINDOWS",
			"RAG_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RAG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RAG_RELEASE"
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
		"Ragdoll/src",
		"Ragdoll/vendor/spdlog/include"
	}

	links
	{
		"Ragdoll"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines
		{
			"RAG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RAG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RAG_RELEASE"
		runtime "Release"
		optimize "On"