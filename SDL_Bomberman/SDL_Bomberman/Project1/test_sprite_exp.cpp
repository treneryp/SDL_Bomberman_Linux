#include "test_sprite_exp.h"
#include <map>
#include <iostream>

namespace GLOBAL
{
	int SPEED = 2;
    int velx = 0;
	int vely = 0;
}

test_sprite_exp::test_sprite_exp(SDL_Renderer*& renderer, const char* filepath,SDL_Rect originRecTexture, SDL_Rect originRecSrc)
{

    spritetex = IMG_LoadTexture(renderer, filepath);



	tex_rec.x = originRecTexture.x;
	tex_rec.y = originRecTexture.y;
	tex_rec.w = 64;
	tex_rec.h = 64;

	src_rec.x = originRecSrc.x;
	src_rec.y = originRecSrc.y;
	src_rec.w = 32;
	src_rec.h = 32;

	hitbox = tex_rec;
}

bool test_sprite_exp::LoadSpriteFromSurface()
{
    return false;
}

bool test_sprite_exp::CreateSpriteTextureFromSurface()
{
    return false;
}

void test_sprite_exp::DrawSprite(SDL_Renderer*& renderer)
{

    SDL_RenderCopyEx(renderer, spritetex, &src_rec, &tex_rec, NULL, NULL, SDL_FLIP_NONE);



}

void test_sprite_exp::UpdateSprite()
{
	//std::string input = InputHandler.UpdateInput(keyvalue,);
	//DrawSprite();
	//if (input == "Left Pressed")
	//{
	//	MoveSpriteXY(-10, 0);
	//}
	//else if (input == "Right Pressed")
	//{
	//	MoveSpriteXY(10, 0);
	//}
	//else if (input == "Down Pressed")
	//{
	//	MoveSpriteXY(0, 10);
	//}
	//else if (input == "Up Pressed")
	//{
	//	MoveSpriteXY(0, -10);
	//}
	//else
	//{
	//	MoveSpriteXY(0, 0);
	//}
	//MoveSpriteXY(tex_rec.x, tex_rec.y);


    MoveSpriteXY(GLOBAL::velx,GLOBAL::vely);



}

void test_sprite_exp::MoveSpriteXY(const int& x, const int& y)
{

	tex_rec.x += x;
	tex_rec.y += y;
	//std::cout << posx << " " << posy << std::endl;

	hitbox = tex_rec;
}

void test_sprite_exp::Testingupdate(const char* keyvalue, bool ispressed)
{
	InputHandler.UpdateInput(keyvalue,ispressed);
	//std::map<const char*, bool > testing;

	//testing = InputHandler.outputbuttonmap();

    GLOBAL::velx = 0;
    GLOBAL::vely = 0;

	for (auto x : InputHandler.getButtonMap())
	{
		//std::cout << x.first << " " << x.second << std::endl;
		if(std::string(x.first) == "Down" && x.second == 1)
		{
            GLOBAL::vely = GLOBAL::SPEED;
            //MoveSpriteXY(0,vely);
		}
        if(std::string(x.first) == "Up" && x.second == 1)
		{
            GLOBAL::vely  = -GLOBAL::SPEED;
           // MoveSpriteXY(0,vely);
		}

        if(std::string(x.first) == "Left" && x.second == 1)
		{
            GLOBAL::velx  = -GLOBAL::SPEED;
           // MoveSpriteXY(velx,0);
		}
        if(std::string(x.first) == "Right" && x.second == 1)
		{
            GLOBAL::velx  = GLOBAL::SPEED;
           // MoveSpriteXY(velx,0);
		}

        if(std::string(x.first) == "Space" && x.second == 1)
		{
            GLOBAL::SPEED = 4;
           // MoveSpriteXY(velx,0);
		}
		else if(std::string(x.first) == "Space" && x.second == 0)
		{
            GLOBAL::SPEED = 2;
		}

        if(std::string(x.first) == "F" && x.second ==1)
		{
            std::cout << "PRESSED F " << std::endl;
            pressedf = true;



		}
        else if(std::string(x.first) == "F" && x.second == 0)
		{
            std::cout << "PRESSED F " << std::endl;

           pressedf = false;

		}
		//UpdateSprite();

    }







}

SDL_bool test_sprite_exp::DetectCollision(SDL_Rect& touched_obstacle)
{

	SDL_bool Collsion = SDL_HasIntersection(GetHitBox(), &touched_obstacle);


		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int btmA, btmB;

		leftA = tex_rec.x;
		rightA = tex_rec.x + tex_rec.w;
		topA = tex_rec.y;
		btmA = tex_rec.y + tex_rec.h;


        leftB = touched_obstacle.x;
		rightB = touched_obstacle.x + touched_obstacle.w;
		topB = touched_obstacle.y;
		btmB = touched_obstacle.y + touched_obstacle.h;

	if (Collsion)
	{
		HasCollided = (SDL_bool)true;


        if(leftA <= leftB)
        {
            std::cout << "touching the left sided. " << std::endl;
            MoveSpriteXY(-tex_rec.w/10,0);


        }

        if(rightA >= rightB)
        {
            std::cout << "touching the right sided. " << std::endl;
            MoveSpriteXY(tex_rec.w/10,0);

        }


        if(btmA >= btmB)
        {
            std::cout << "touching the btm sided. " << std::endl;
            MoveSpriteXY(0,tex_rec.h/10);


        }

        if(topA <= topB)
        {
            std::cout << "touching the top sided. " << std::endl;
            MoveSpriteXY(0,-tex_rec.h/10);


        }
	}
	else
	{
		HasCollided = (SDL_bool)false;
	}
	return Collsion;

}

bool test_sprite_exp::OnCollision(test_sprite_exp touched_collectable)
{
    //if collision is blueorb delete sprite from vector
    SDL_bool Collsion = SDL_HasIntersection(GetHitBox(), touched_collectable.GetHitBox());
    if (Collsion)
	{
        return true;

	}
	else
	{
        return false;
	}



}

void test_sprite_exp::outputbuttons()
{




	//for (auto x : InputHandler.getButtonMap())
	//	std::cout << x.first << " " << x.second << std::endl;

}



test_sprite_exp::~test_sprite_exp()
{
    //SDL_DestroyTexture(spritetex);
    //delete this;

}
bool test_sprite_exp::Testing_SpriteSpawn()
{
    return pressedf;
}
