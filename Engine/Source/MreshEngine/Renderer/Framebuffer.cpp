#include <mepch.h>
#include "Framebuffer.h"

#include "MreshEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace MreshEngine
{
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& specifiacation)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    ME_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(specifiacation);
		}

		ME_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}

