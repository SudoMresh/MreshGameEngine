#include <MreshEngine.h>
#include <MreshEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace MreshEngine
{
	class MreshEngineEditor : public Application
	{
	public:
		MreshEngineEditor(ApplicationCommandLineArgs args)
			: Application("MreshEngine Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~MreshEngineEditor()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new MreshEngineEditor(args);
	}
}
