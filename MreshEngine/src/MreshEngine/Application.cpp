#include "mepch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Input.h"

namespace MreshEngine
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ME_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(ME_BIND_EVENT_FN(Application::OnEvent));
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

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			auto[xPos, yPos] = Input::GetMousePosition();
			ME_CORE_TRACE("{0}, {1}", xPos, yPos);

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloaseEvent>(ME_BIND_EVENT_FN(Application::OnWindowClose));

		ME_CORE_TRACE("{0}", event);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(event);
			if (event.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLater(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloaseEvent& event)
	{
		m_Running = false;
		return true;
	}
}
