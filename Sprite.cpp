#include "Engine.h"
#include "Sprite.h"
#include "Transform.h"

#include <cassert>
#include <SDL3_image/SDL_image.h>

Sprite::Sprite()
	: m_texture(nullptr)
	, m_pixelFormat(0)
	, m_framePositions()
	, m_sheetSize(0,0)
	, m_frameSize(0,0)
	, m_frameRects()
{
}

Sprite::~Sprite()
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
	}
}


void Sprite::LoadPNG(
	const char* pngFilename,				// PNG file containing the sprite sheet
	XY frameSize,							// frame size
	const std::vector<XY>& framePositions	// frame positions
)
{
	m_texture = IMG_LoadTexture(Engine::Get().GetRenderer(), pngFilename);

	int access;
	SDL_QueryTexture(
		m_texture,
		&m_pixelFormat,
		&access,
		&m_sheetSize.x,
		&m_sheetSize.y);
}

void Sprite::m_frameSize(X)
	m_frameSize = frameSize;
	for (auto xy : framePositions)
	{
		m_frameRects.push_back(
			SDL_FRect{ 
				static_cast<float>(xy.x),
				static_cast<float>(xy.y),
				static_cast<float>(m_frameSize.x),
				static_cast<float>(m_frameSize.y)
			}
		);
	}
}

void Sprite::RenderFrame(int frameIndex, SDL_Renderer* renderTarget, XY drawPosition) const
{
	if (frameIndex < 0 || frameIndex >= m_frameRects.size())
	{
		// should probably log an error here but meh for now
		return;
	}

	assert(m_texture != nullptr);

	SDL_FRect drawRect{
		static_cast<float>(drawPosition.x),
		static_cast<float>(drawPosition.y),
		static_cast<float>(m_frameSize.x),
		static_cast<float>(m_frameSize.y)
	};

	SDL_RenderTexture(
		renderTarget, 
		m_texture, 
		&m_frameRects[frameIndex], 
		&drawRect);
}
