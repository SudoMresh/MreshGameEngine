#pragma once

#include "Scene.h"

#include "entt.hpp"

namespace MreshEngine
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;
		~Entity() {}

		template<class T, class... Args>
		T& AddComponent(Args&&... args)
		{
			ME_CORE_ASSERT(!HasComponent<T>(), "Entity has alread component!");

			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
		}

		template<class T>
		T& GetComponent()
		{
			ME_CORE_ASSERT(HasComponent<T>(), "Entity doesn't have component!");
			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<class T>
		void RemoveComponent()
		{
			ME_CORE_ASSERT(!HasComponent<T>(), "Entity doesn't have component!");
			m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		template<class T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.has<T>(m_EntityHandle);
		}

		operator bool() const { return m_EntityHandle != entt::null; }
		operator uint32_t() const { return (uint32_t)m_EntityHandle; }

		bool operator==(const Entity& other) const 
		{
			return m_EntityHandle == other.m_EntityHandle && m_Scene == other.m_Scene;
		}

		bool operator!=(const Entity& other) const
		{
			return !(*this == other);
		}

	private:
		entt::entity m_EntityHandle{ entt::null };
		Scene* m_Scene = nullptr;
	};
}

