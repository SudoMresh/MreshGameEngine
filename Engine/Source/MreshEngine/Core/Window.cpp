#include "mepch.h"
#include "MreshEngine/Core/Window.h"

#ifdef ME_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace MreshEngine
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef ME_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		ME_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}