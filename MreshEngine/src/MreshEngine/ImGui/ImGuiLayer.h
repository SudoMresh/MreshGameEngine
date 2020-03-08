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

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}