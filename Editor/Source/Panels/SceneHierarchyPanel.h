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
		void DrawUIComponent(Entity entity, const char* name, std::function<void ()> uiFunction,
			int flags = ImGuiTreeNodeFlags_DefaultOpen, bool bDrawComponentSetting = false, bool bNeedToCreateTreeNode = true)
		{
			if (entity.HasComponent<T>())
			{
				if (bNeedToCreateTreeNode)
				{
					bool removeComponent = false;
					bool open = ImGui::TreeNodeEx((void*)typeid(T).hash_code(), flags, name);

					if (bDrawComponentSetting)
					{
						ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 4, 4 });
						ImGui::SameLine(ImGui::GetWindowWidth() - 25.0f);

						if (ImGui::Button("+", ImVec2{ 20, 20 }))
						{
							ImGui::OpenPopup("ComponnetSettings");
						}

						ImGui::PopStyleVar();

						if (ImGui::BeginPopup("ComponnetSettings"))
						{
							if (ImGui::MenuItem("Remove Component"))
								removeComponent = true;

							ImGui::EndPopup();
						}
					}

					if (open)
					{
						uiFunction();
					}

					if (removeComponent)
						entity.RemoveComponent<T>();
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

