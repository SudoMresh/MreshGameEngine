#include <MreshEngine.h>
#include <MreshEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace MreshEngine
{
	class MreshEngineEditor : public Application
	{
	public:
		MreshEngineEditor()
			: Application("MreshEngine Editor")
		{
			PushLayer(new EditorLayer());
		}

		~MreshEngineEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new MreshEngineEditor();
	}
}
