#pragma once

#include "Object.h"
#include "Component.h"
#include "Time.h"
#include "Singleton.h"

// entity component system
class ECS : public Singleton<ECS>
{
	entt::registry m_registry;

	// internal stuff for making things work
	struct ObjectMetadata : public Component
	{
		TimePoint creationTime;
	};

public:

	ObjectId CreateObject()
	{
		ObjectId objectId = m_registry.create();

		ObjectMetadata& header = AddComponent<ObjectMetadata>(objectId);
		header.creationTime = GetCurrentTime();

		return objectId;
	}
	void DestroyObject(ObjectId objectId)
	{
		m_registry.destroy(objectId);
	}

	bool Exists(ObjectId objectId) const
	{
		return m_registry.valid(objectId) 
			&& m_registry.any_of<ObjectMetadata>(objectId);
	}

	template<typename ComponentType>
	ComponentType& AddComponent(ObjectId objectId)
	{
		ComponentType& component = m_registry.emplace<ComponentType>(objectId);
		component.SetObjectId(objectId);
		component.OnComponentAdded();
	}

	template<typename ComponentType>
	ComponentType& GetOrAddComponent(ObjectId objectId)
	{
		if (m_registry.any_of<ComponentType>(objectId))
		{
			return GetComponent<ComponentType>(objectId);
		}
		else
		{
			return AddComponent<ComponentType>(objectId);
		}
	}

	template<typename ComponentType>
	ComponentType& GetComponent(ObjectId objectId)
	{
		return m_registry.get<ComponentType>(objectId);
	}

	template<typename ComponentType>
	bool HasComponent(ObjectId objectId) const
	{
		return m_registry.any_of<ComponentType>(objectId);
	}

	template<typename ComponentType>
	void ForAllComponentsOfType(void(*DoSomething)(ComponentType& component))
	{
		for (ObjectId object : m_registry.view<ComponentType>())
		{
			DoSomething(GetComponent<ComponentType>(object));
		}
	}
};