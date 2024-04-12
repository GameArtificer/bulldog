#include "Component.h"

ObjectId Component::GetObjectId() const
{
	return m_objectId;
}

void Component::SetObjectId(ObjectId objectId)
{
	m_objectId = objectId;
}

Component::Component() 
	: m_objectId(static_cast<entt::entity>(-1)) 
{
}