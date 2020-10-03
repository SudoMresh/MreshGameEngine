#pragma once

#include "MreshEngine.h"

namespace MreshEngine
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

		template<class T>
		void DrawUIComponent(Entity entity, const char* name, std::function<void ()> uiFunction, bool bNeedToCreateTreeNode = true)
		{
			if (entity.HasComponent<T>())
			{
				if (bNeedToCreateTreeNode)
				{
					if (ImGui::TreeNodeEx((void*)typeid(T).hash_code(), ImGuiTreeNodeFlags_DefaultOpen, name))
					{
						uiFunction();
					}
				}
				else
				{
					uiFunction();
				}
			}
		}

	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}

