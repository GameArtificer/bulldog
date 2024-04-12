#include <random>
#include <SDL3_image/SDL_image.h>
#include "Engine.h"
#include "InputManager.h"
#include "SpriteRenderer.h"

const char* k_windowTitle = "engine testbed";
constexpr int k_windowWidth = 1024;
constexpr int k_windowHeight = 768;
constexpr int k_windowFlags = 0;

int Engine::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}

	m_window = SDL_CreateWindow(k_windowTitle, k_windowWidth, k_windowHeight, k_windowFlags);

	m_renderer = SDL_CreateRenderer(m_window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	m_quit = false;

	IMG_Init(IMG_INIT_PNG);

	return 0;
}

bool IsSDLInputEvent(Uint32 eventType)
{
	// input event types are all grouped together in the event type enum
	if (eventType >= 0x300 &&					// lowest input event type enum value
		eventType < 0x800)									// highest input event type enum value
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Engine::HandleSystemEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			m_quit = true;
			return;
		}

		if (IsSDLInputEvent(event.type))
		{
			InputManager::Get().AddEvent(event);
		}

	}
}

void Engine::HandleInput()
{
	InputManager::Get().HandleEvents();
}

void Engine::Draw()
{
	ClearDrawBuffer();

	ECS::Get().ForAllComponentsOfType<SpriteRenderer>(
		[](SpriteRenderer& spriteRenderer)
		{
			spriteRenderer.Render(Engine::Get().GetRenderer());
		}		
	);

	CopyDrawBufferToScreen();
}


void Engine::MainEventLoop()
{
	MainEventLoop(nullptr);
}

void Engine::MainEventLoop(OnUpdateCallback onUpdate)
{	
	if (!onUpdate)
	{
		return;
	}

	HandleSystemEvents();
	while (!m_quit)
	{
		HandleInput();

		TickInterval dt = Tick();		

		m_quit = onUpdate();

		Draw();

		HandleSystemEvents();
	}
}

void Engine::Shutdown()
{
	IMG_Quit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

SDL_Renderer* Engine::GetRenderer()
{
	return m_renderer;
}

void Engine::ClearDrawBuffer()
{
	SDL_SetRenderTarget(m_renderer, m_drawBuffer);

	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(m_renderer);
}


void Engine::CopyDrawBufferToScreen()
{
	// set render target to screen
	SDL_SetRenderTarget(m_renderer, NULL);

	// render the draw buffer texture to the screen
	SDL_RenderTexture(m_renderer, m_drawBuffer, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
