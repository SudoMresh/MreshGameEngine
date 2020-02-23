#pragma once

#ifdef ME_PLATFORM_WINDOWS

extern MreshEngine::Application* MreshEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = MreshEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // ME_PLATFORM_WINDOWS


