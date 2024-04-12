#pragma once
#include <SDL3/SDL.h>

#include "Singleton.h"
#include "UserInterface.h"

#include "ECS.h"
#include "Time.h"

#include "SpriteRenderer.h"

#include <queue>

// a very simple game engine for quickly making simple, fun games using c++ and FOSS tools
// this is the top-level singleton class that we get and call into from main()
class Engine : public Singleton<Engine>
{	
public:
	using EventQueue = std::queue<SDL_Event>;
private:

	bool m_quit;

	// window/rendering
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_drawBuffer;

	// input handling
	EventQueue m_keyboardEvents;
	EventQueue m_mouseEvents;
	void HandleInput();
			
	// draw functions
	void ClearDrawBuffer();
	void RenderObjectsInScene();
	void CopyDrawBufferToScreen();

	// main event loop
	void HandleSystemEvents();
	bool Update();
	void Draw();


public:
	using OnUpdateCallback = bool (*)();
	int Initialize();

	void MainEventLoop(OnUpdateCallback onUpdate);
	void MainEventLoop();
	void Shutdown();

	SDL_Renderer* GetRenderer();
};