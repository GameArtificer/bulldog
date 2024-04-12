#include "SpriteRenderer.h"
#include "Sprite.h"
#include "Engine.h"
#include "Transform.h"

#include <SDL3/sdl.h>
#include <cassert>

void SpriteRenderer::Render(SDL_Renderer* renderTarget) const
{
	assert(renderTarget != nullptr);

	ECS& ecs = ECS::Get();
	const Sprite& sprite = ecs.GetComponent<Sprite>(m_spriteObjectId);
	const Transform& transform = ecs.GetComponent<Transform>(GetObjectId());
	

	sprite.RenderFrame(m_currentFrame, renderTarget, transform.GetPosition());	
}

void SpriteRenderer::Render(SDL_Renderer* renderTarget, XY position) const
{
	assert(renderTarget != nullptr);

	ECS& ecs = ECS::Get();
	const Sprite& sprite = ecs.GetComponent<Sprite>(m_spriteObjectId);
	const Transform& transform = ecs.GetComponent<Transform>(GetObjectId());

	sprite.RenderFrame(m_currentFrame, renderTarget, position + transform.GetRelativePosition());
}

void SpriteRenderer::SetCurrentFrame(int frame)
{
	m_currentFrame = frame;
}

int SpriteRenderer::GetCurrentFrame() const
{
	return m_currentFrame;
}