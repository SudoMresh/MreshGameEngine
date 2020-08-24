#include "mepch.h"
#include "MreshEngine/Core/Input.h"

#ifdef ME_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace MreshEngine
{
	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
	#ifdef ME_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
	#else
		ME_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
} 