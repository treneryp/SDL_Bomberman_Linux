#pragma once
//#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "test_sdl_inputhandler.h"
#include <string>
class SDL_Renderer;

class test_sprite_exp
{

public:

	test_sprite_exp(SDL_Renderer*& renderer,const char* filepathforsprite, SDL_Rect originRecTexture, SDL_Rect originRecSrc);
	test_sprite_exp(){};
	~test_sprite_exp();


	bool LoadSpriteFromSurface();
	bool CreateSpriteTextureFromSurface();
	void DrawSprite(SDL_Renderer*& renderer);
	void UpdateSprite(const char* keyvalue);
	void MoveSpriteXY(const int& x, const int& y);
	void Testingupdate(const char* keyvalue, bool ispressed);
	void UpdateSprite();
	bool Testing_SpriteSpawn();
    bool pressedf = false;
    bool pressedx = false;
	inline SDL_Rect* GetHitBox() { return &hitbox; }

	SDL_bool DetectCollision(SDL_Rect& touched_obstacle);
	bool OnCollision(test_sprite_exp touched_collectable);

	void outputbuttons();

	SDL_Rect tex_rec;
	SDL_Rect hitbox;
	SDL_Rect src_rec;

	int spritenum =999;

	test_sdl_inputhandler InputHandler;
private:

		SDL_Texture* spritetex = nullptr;
		SDL_bool HasCollided = (SDL_bool)false;

		int posx = 0;
		int posy = 0;





		//imgSurface = IMG_Load("C:/Users/trene/source/repos/SDL_Bomberman/Assets/Bomberman.png");

		//imgTexture = IMG_LoadTexture(renderer, "C:/Users/trene/source/repos/SDL_Bomberman/Assets/Bomberman.png");


};

