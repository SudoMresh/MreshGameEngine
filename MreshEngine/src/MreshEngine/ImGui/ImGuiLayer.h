#pragma once

#include "MreshEngine/Layer.h"

#include "MreshEngine/Events/Event.h"
#include "MreshEngine/Events/KeyEvent.h"
#include "MreshEngine/Events/MouseEvent.h"
#include "MreshEngine/Events/ApplicationEvent.h"

namespace MreshEngine
{
	class MRESH_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnWindowResizedEvent(WindowResizeEvent& event);

	private:
		float m_Time;
	};
}

