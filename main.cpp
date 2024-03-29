#include <SDL3\SDL.h>
#include <SDL3\SDL_Main.h>

#include "Singleton.h"

bool s_done = false;

bool done()
{
	return s_done;
}



class Engine : public Singleton<Engine>
{
	const int WIDTH = 640;
	const int HEIGHT = 480;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
public:
	void Init();
	void Shutdown();
};

void Engine::Init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Hello SDL", WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Engine::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void engine_shutdown()
{

}

int main(int argc, char* argv[])
{
	
	// init
	Engine::Get().Init();

	// do stuff
	while (!done())
	{

	}

	// shut down
	Engine::Get().Shutdown();
	
	return 0;
}