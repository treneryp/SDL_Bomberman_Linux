#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "test_sdl_window.h"
#include "test_sprite_exp.h"

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

const int test_sdl_window::testwin()
{
	// You must include the command line parameters for your main function to be recognized by SDL


	// Pointers to our window and surface
	SDL_Surface* winSurface = NULL;
	SDL_Surface* imgSurface = NULL;
	SDL_Window* window = NULL;
	SDL_Texture* imgTexture = NULL;

	SDL_Renderer* renderer = NULL;

	//C:\Users\trene\source\repos\SDL_Bomberman\Assets\SNES - Super Bomberman - Bomberman.png



	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		return 1;
	}

	// Create our window
	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	SDL_SetWindowResizable(window, SDL_TRUE);

	SDL_SetWindowBordered(window, SDL_TRUE);

	// Make sure creating the window succeeded
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		return 1;
	}

	// Get the surface from the window

	winSurface = SDL_GetWindowSurface(window);




	// Make sure getting the surface succeeded
	if (!winSurface) {
		cout << "Error getting surface: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		return 1;
	}

	//renderer and texture.
	renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);

	//imgSurface = IMG_Load("C:/Users/trene/source/repos/SDL_Bomberman/Assets/Bomberman.png");




	imgTexture = IMG_LoadTexture(renderer,"C:/Users/trene/source/repos/SDL_Bomberman/Assets/Bomberman.png");


	// Fill the window with a crimson rectangle
	//SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 157, 34, 53));



	// Update the window display
	SDL_UpdateWindowSurface(window);

	SDL_Rect tex_rec;
	tex_rec.x = 0;
	tex_rec.y = 0;
	tex_rec.w = 128;
	tex_rec.h = 128;

	SDL_Rect src_rec;
	src_rec.x = 0;
	src_rec.y = 64;
	src_rec.w = 32;
	src_rec.h = 32;

	unsigned char alpha;


	SDL_SetTextureBlendMode(imgTexture, SDL_BLENDMODE_BLEND);



	SDL_SetRenderDrawColor(renderer, 157, 34, 53, 255);

	// Wait
	//system("pause");
	SDL_Event e;
	bool quit = false;
	auto flip = SDL_FLIP_NONE;

	int alphaval = 50;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEWHEEL)
			{
				if (e.wheel.y > 0)
				{
					++alphaval;
					SDL_GetTextureAlphaMod(imgTexture, &alpha);
					SDL_SetTextureAlphaMod(imgTexture, alpha + alphaval);
				}
				else if (e.wheel.y < 0)
				{
					--alphaval;
					SDL_GetTextureAlphaMod(imgTexture, &alpha);
					SDL_SetTextureAlphaMod(imgTexture, alpha - alphaval);
				}

			}

			if(e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT: tex_rec.x--;
					src_rec.x = 0;
					src_rec.y = 96;

					//flip = SDL_FLIP_NONE;
					break;

				case SDLK_RIGHT: tex_rec.x++;
				src_rec.x = 0;
				src_rec.y = 32;

				//flip = SDL_FLIP_HORIZONTAL;
				break;
				case SDLK_UP:    tex_rec.y--;

					src_rec.x = 0;
					src_rec.y = 0;
				break;
				case SDLK_DOWN:  tex_rec.y++;
					src_rec.x = 0;
					src_rec.y = 64;
					break;

				}
				break;

			}
			//int x = 10;
			//double sine = sin(x);
			//for (double i = 0; i < 3.14; i += 0.1)
			//{
			//	sine = sin(i);
			//}



		}



		SDL_RenderClear(renderer);
		SDL_RenderCopyEx(renderer, imgTexture, &src_rec, &tex_rec, NULL, NULL, flip);



		SDL_RenderPresent(renderer);
	}

	// Destroy the window. This will also destroy the surface
	SDL_DestroyWindow(window);

	// Quit SDL
	SDL_Quit();

	// End the program
	return 0;
}
