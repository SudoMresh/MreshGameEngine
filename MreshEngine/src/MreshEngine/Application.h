#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace MreshEngine
{
	class MRESH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

