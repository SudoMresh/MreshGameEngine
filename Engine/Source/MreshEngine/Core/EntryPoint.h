#pragma once
#include "MreshEngine/Core/Base.h"
#include "MreshEngine/Core/Application.h"

#ifdef ME_PLATFORM_WINDOWS

extern MreshEngine::Application* MreshEngine::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	MreshEngine::Log::Init();

	ME_PROFILE_BEGIN_SESSION("Startup", "MreshEngineProfile-Startup.json");
	auto app = MreshEngine::CreateApplication({ argc, argv });
	ME_PROFILE_END_SESSION();

	ME_PROFILE_BEGIN_SESSION("Runtime", "MreshEngineProfile-Runtime.json");
	app->Run();
	ME_PROFILE_END_SESSION();

	ME_PROFILE_BEGIN_SESSION("Shutdown", "MreshEngineProfile-Shutdown.json");
	delete app;
	ME_PROFILE_END_SESSION();
}

#endif
