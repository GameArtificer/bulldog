#pragma once

#include "ECS.h"
#include "Component.h"
#include "xy.h"

class SpriteRenderer : public Component
{
	ObjectId m_spriteObjectId;
	int m_currentFrame;
public:
	int GetCurrentFrame() const;
	void SetCurrentFrame(int frame);
	void Render(struct SDL_Renderer* renderer) const;
	void Render(struct SDL_Renderer* renderer, XY position) const;
};