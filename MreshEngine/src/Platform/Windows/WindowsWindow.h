#pragma once

#include "MreshEngine/Window.h"

#include <GLFW/glfw3.h>

namespace MreshEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		// Inherited via Window
		virtual unsigned int GetWidth() const override { return m_Data.Width; }
		virtual unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attribute
		virtual void SetEventCallBack(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enable) override;
		virtual bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const override { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}

