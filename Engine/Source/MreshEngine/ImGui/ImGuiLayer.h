#pragma once

#include "MreshEngine/Core/Layer.h"

#include "MreshEngine/Events/ApplicationEvent.h"
#include "MreshEngine/Events/KeyEvent.h"
#include "MreshEngine/Events/MouseEvent.h"

namespace MreshEngine
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}