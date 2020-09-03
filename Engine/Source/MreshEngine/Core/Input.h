#pragma once

#include "MreshEngine/Core/Core.h"
#include "MreshEngine/Core/KeyCodes.h"
#include "MreshEngine/Core/MouseCodes.h"

namespace MreshEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}