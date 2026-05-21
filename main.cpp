#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

#include <iostream>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_Window* win = SDL_CreateWindow("SI-XR", 640, 480, 0);
	if (win == nullptr)
	{
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);
	if (ren == nullptr)
	{
		std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	SDL_Event e;
	bool quit = false;

	// Define a rectangle
	SDL_FRect greenSquare{ 270, 190, 100, 100 };

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_EVENT_QUIT)
			{
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // set render draw color to black
		SDL_RenderClear(ren); // clear the renderer

		SDL_SetRenderDrawColor(ren, 0, 255, 0, 255); // set render draw color to green
		SDL_RenderFillRect(ren, &greenSquare); // render the rectangle

		SDL_RenderPresent(ren); // render the screen
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}