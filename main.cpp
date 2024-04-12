#include "Engine.h"
#include <SDL3\SDL_Main.h>


bool OnGameUpdate()
{
	return false;
}

int main(int argc, char* argv[])
{	
	// init
	if (int errorCode = Engine::Get().Initialize(); errorCode != 0)
	{ 
		return errorCode;
	}

	Engine::Get().MainEventLoop(OnGameUpdate);

	// shut down
	Engine::Get().Shutdown();
	
	return 0;
}