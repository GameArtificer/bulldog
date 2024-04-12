#pragma once

#include "Object.h"

// base class for all components to be added to objects
// contains overridable stub functions that can be used as callbacks
class Component
{
	// component-level metadata
	ObjectId m_objectId;
public:
	Component();

	// component-level callbacks
	virtual void OnComponentAdded() {}
	virtual void Update() {}

	// component-level facilities
	ObjectId GetObjectId() const;
	void SetObjectId(ObjectId objectId);// for internal use only. do not call this.
};