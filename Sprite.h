#pragma once
#include <SDL3/SDL.h>

#include <vector>

#include "xy.h"
#include "Component.h"

// a sprite is an animated 2D bitmap
// this class represents a sprite resource that has been loaded into the game
// in this class, we need to: 
// - store all the frames for a single sprite object
// - provide a way for loading frame data from external source
// - provide access to frames for rendering
class Sprite : public Component
{
	SDL_Texture* m_texture;

	Uint32 m_pixelFormat;

	std::vector<XY> m_framePositions;

	XY m_sheetSize;
	XY m_frameSize;
	std::vector<SDL_FRect> m_frameRects;

public:
	Sprite();
	~Sprite();

	void LoadPNG(
		const char* pngFilename,				// PNG file containing the sprite sheet
	);

	void SetFrameSize(XY frameSize);
	void SetFrame(
		const std::vector<XY>& framePositions	// frame positions)

	void RenderFrame(int frameIndex, SDL_Renderer* renderTarget, XY xy) const;
};