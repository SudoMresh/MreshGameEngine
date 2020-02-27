#include "mepch.h"
#include "Application.h"

#include "MreshEngine/Events/ApplicationEvent.h"
#include "MreshEngine/Log.h"

namespace MreshEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ME_TRACE(e);

		while (true);
	}
}
