#pragma once

#ifdef ME_PLATFORM_WINDOWS

extern MreshEngine::Application* MreshEngine::CreateApplication();

int main(int argc, char** argv)
{
	MreshEngine::Log::Init();
	ME_CORE_WARN("Initialized Log!");
	ME_INFO("Hello! Var={0}", 5);

	auto app = MreshEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // ME_PLATFORM_WINDOWS


