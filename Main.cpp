#include "Main.h"

int startup();

int main(int argc, char* argv[])
{
	startup();

	bool running = true;
	SDL_Event event;

	while (running) 
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT) {running = false; }	
		}

	}

	SDL_Quit();
	return 0;
}

int startup()
{
	//Initalizes SDL3
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		cerr << "SDL3 Initialization Error: " << SDL_GetError() << endl;
		return 1;
	}

	//Gets primary displays resolution
	const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(1);
	if (!mode)
	{
		cerr << "Failed to get display mode: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	//creates a window
	SDL_Window* window = SDL_CreateWindow("Main screen", mode->w, mode->h, SDL_WINDOW_OPENGL);
	if (!window)
	{
		cerr << "SDL3 Window Creation Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	//adds a renderer for drawing
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	if (!renderer)
	{
		cerr << "SDL3 Renderer Creation Error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	//insures a black background
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	return 0;
}
