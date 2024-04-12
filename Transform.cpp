#include "Transform.h"
#include "Engine.h"

Transform::Transform()
	: m_parentObjectId()
	, m_childObjectIds()
	, m_offset()
{
}

XY Transform::GetPosition() const
{
	XY result = m_offset;

	ObjectId objectId = m_parentObjectId;
	ECS& ecs = ECS::Get();
	while (ecs.HasComponent<Transform>(objectId))
	{
		const Transform& parentTransform = ecs.GetComponent<Transform>(objectId);

		result = result + parentTransform.m_offset;

		objectId = parentTransform.m_parentObjectId;
	}
	return result;
}

XY Transform::GetRelativePosition() const
{
	return m_offset;
}

void Transform::SetRelativePosition(XY offset)
{
	m_offset = offset;
}

void Transform::SetPosition(XY absolutePosition)
{
	XY parentPosition;
	ECS& ecs = ECS::Get();

	if (ecs.HasComponent<Transform>(m_parentObjectId))
	{ 
		const Transform& parentTransform = ecs.GetComponent<Transform>(m_parentObjectId);
		parentPosition = parentTransform.GetPosition();
	}

	m_offset = absolutePosition - parentPosition;
}