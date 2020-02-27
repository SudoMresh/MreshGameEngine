#pragma once

#include "Core.h"

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

