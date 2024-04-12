#pragma once

#include <vector>
#include "ECS.h"
#include "xy.h"
#include "Component.h"

class Transform : public Component
{
	ObjectId m_parentObjectId;
	std::vector<ObjectId> m_childObjectIds;

	XY m_offset;	// position relative to parent object
public:
	Transform();

	XY GetRelativePosition() const;
	void SetRelativePosition(XY offset);

	XY GetPosition() const;
	void SetPosition(XY absolutePosition);
};