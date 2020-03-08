#include "mepch.h"
#include "MreshEngine/Renderer/RenderCommand.h"

namespace MreshEngine
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}