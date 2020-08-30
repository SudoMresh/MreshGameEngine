#pragma once

#include "MreshEngine/Core/Core.h"

namespace MreshEngine
{
	struct FramebudderSpecification
	{
		uint32_t Width, Height;

		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void Resize(uint32_t width, uint32_t height) = 0;

		virtual uint32_t GetColorAttachmentRendererID() const = 0;

		virtual const FramebudderSpecification& GetSpecification() const = 0;

		static Ref<Framebuffer> Create(const FramebudderSpecification& specifiacation);

	private:

	};
}

