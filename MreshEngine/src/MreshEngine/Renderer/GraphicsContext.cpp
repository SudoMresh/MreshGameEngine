#include "mepch.h"
#include "MreshEngine/Renderer/GraphicsContext.h"

#include "MreshEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace MreshEngine
{
	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    ME_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		ME_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}