#pragma once

#include "MreshEngine/Input.h"

namespace MreshEngine
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonmPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}

