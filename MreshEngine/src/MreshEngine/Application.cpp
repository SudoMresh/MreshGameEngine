#include "mepch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace MreshEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloaseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		ME_CORE_TRACE("{0}", event);
	}

	bool Application::OnWindowClose(WindowCloaseEvent& event)
	{
		m_Running = false;
		return true;
	}
}
