#pragma once
#include "mepch.h"

#include "Window.h"
#include "Core.h"
#include "Events/Event.h"
#include "MreshEngine/Events/ApplicationEvent.h"
#include "MreshEngine/LayerStack.h"

namespace MreshEngine
{
	class MRESH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloaseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}

