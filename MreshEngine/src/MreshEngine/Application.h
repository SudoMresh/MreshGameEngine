#pragma once
#include "mepch.h"

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "MreshEngine/Events/ApplicationEvent.h"

namespace MreshEngine
{
	class MRESH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);
	private:
		bool OnWindowClose(WindowCloaseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

