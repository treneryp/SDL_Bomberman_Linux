#pragma once
#include "test_gamecore.h"
#include "SDL2/SDL.h"
//#include "SDL_image.h"
#include "test_sprite_exp.h"
#include "test_animatedsprite.h"
#include <vector>
#include "test_sdl_inputhandler.h"
#include "test_tilemap.h"

#undef main
class test_gamecore_debug : test_gamecore
{
public:
	test_gamecore_debug();

	virtual ~test_gamecore_debug() {}
	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;


private:
	SDL_Surface* winSurface = NULL;
	SDL_Surface* imgSurface = NULL;
	SDL_Window* window = NULL;
	SDL_Texture* imgTexture = NULL;

	SDL_Renderer* renderer = NULL;

	SDL_Rect tex_rec;

	SDL_Rect src_rec;

	std::vector<test_animatedsprite> spritesToRender;

	test_tilemap TilemapA;

	test_sdl_inputhandler InputHandler;






};

