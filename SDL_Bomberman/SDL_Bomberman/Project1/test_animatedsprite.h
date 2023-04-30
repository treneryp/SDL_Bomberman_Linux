#pragma once
#include "test_sprite_exp.h"
#include <vector>
class test_animatedsprite :public test_sprite_exp
{

public:
    test_animatedsprite(){};
	test_animatedsprite(SDL_Renderer*& renderer, const char* filepathforsprite, SDL_Rect originRecTexture, SDL_Rect originRecSrc)
		:test_sprite_exp(renderer, filepathforsprite, originRecTexture, originRecSrc)
	{
		animatedRecSrc = originRecSrc;
		animatedRecTexture = originRecTexture;
	};
	void UpdateSpriteFrame();
	void InitializeAnimations();
	void UpdateBombAni();
	void UpdateExplodeAni();


private:
	SDL_Rect animatedRecTexture, animatedRecSrc;

	//TODO: Need to make these Vectors instead of arrays?
	std::vector< std::pair<int, int> > animation_idle = { { 0,64 }};
	std::vector< std::pair<int, int> > animation_WalkingDown = { { 32,64 },{ 0,64 } ,{ 64,64 },{ 0,64 } };
	std::vector< std::pair<int, int> > animation_WalkingRight = { {32,32 } ,{ 0,32 },{ 64,32 } ,{ 0,32 } };
	std::vector< std::pair<int, int> > animation_WalkingUp = { { 32,0 },{0,0}, { 64,0 },{0,0} };
	std::vector< std::pair<int, int> > animation_WalkingLeft = { { 32,96 },{ 0,96 } ,{ 64,96 },{ 0,96 } };

	std::vector< std::pair<int, int> > animation_BombExplosion  { { 0,0 },{ 17,0} ,{ 34,0 } ,{ 51,0 } };

	std::vector< std::pair<int, int> > animation_Explosion {  { 0,0 },{ 17,0} ,{ 34,0 } ,{ 51,0 } };

	//std::vector< std::pair<int, int> > vecOfAnimationFrames = { { 32,0 },{0,0}, { 64,0 },{0,0} };

	std::map<const char*, std::vector< std::pair<int, int> >> AnimationMap;
};

