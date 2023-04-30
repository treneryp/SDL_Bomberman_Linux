#include "test_gamecore_debug.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include "test_sprite_exp.h"
#include "test_animatedsprite.h"
#include "test_tilemap.h"
#include <string>

#include <sstream>

using namespace std;

#undef main



test_gamecore_debug::test_gamecore_debug()
{

}

void test_gamecore_debug::Init()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
		// End the program

	}

	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	SDL_SetWindowResizable(window, SDL_TRUE);

	SDL_SetWindowBordered(window, SDL_TRUE);



	char* debugpath = SDL_GetBasePath();

	std::string assetpath ="/bin/debug";

	std::stringstream ss;


	ss << debugpath;

    ss >> assetpath;

    assetpath.erase(assetpath.end()-10,assetpath.end());

    ss.clear();
    ss << assetpath;
    ss <<"SDL_Bomberman/Assets";
    ss >> assetpath;


    //std::cout << assetpath << std::endl;


	// Make sure creating the window succeeded
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		//return 1;
	}

	// Get the surface from the window

	winSurface = SDL_GetWindowSurface(window);

	if (!winSurface) {
		cout << "Error getting surface: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		//return 1;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC == 1);

	//imgSurface = IMG_Load("C:/Users/trene/source/repos/SDL_Bomberman/Assets/Bomberman.png");
    string bomberman = "/Bomberman.png";
    string fullpath = assetpath + bomberman;
    std::cout << fullpath <<  std::endl;
    imgSurface = IMG_Load(fullpath.c_str());
	imgTexture = IMG_LoadTexture(renderer, fullpath.c_str());

	tex_rec.x = 64;
	tex_rec.y = 32;
	tex_rec.w = 128;
	tex_rec.h = 128;

	src_rec.x = 0;
	src_rec.y = 64;
	src_rec.w = 32;
	src_rec.h = 32;

	test_animatedsprite sprite(renderer, fullpath.c_str(), tex_rec, src_rec);



	tex_rec.x = 0;
	tex_rec.y = 0;
	tex_rec.w = 128;
	tex_rec.h = 128;

	src_rec.x = 0;
	src_rec.y = 0;
	src_rec.w = 32;
	src_rec.h = 32;

    //string bomb = "/Bomb.png";
    string block = "/tiles/Blocks/stoneBlock.png";
    fullpath = assetpath + block;

	//test_animatedsprite sprite2(renderer, fullpath.c_str(), tex_rec, src_rec);

	//test_sprite_exp sprite3(renderer, fullpath.c_str(), tex_rec, src_rec);


	spritesToRender.push_back(sprite);

    uMap_AnimatedSpritestoRender.insert_or_assign("Player",sprite);

	//uMap_AnimatedSpritestoRender.insert_or_assign(9,sprite);

	//spritesToRender.push_back(sprite2);

//	std::vector<test_sprite_exp> tiles,tiles3;
//
    for(int i = 0; i <= 29; i++)
    {
        //tiles.push_back(test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        uMap_TilestoRender.insert_or_assign("Tile_stoneBlock"+ i,test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        tex_rec.x += 64;
    }
//
    tex_rec.x = 128;
    tex_rec.y=320;
    for(int i = 0; i <= 29; i++)
    {
        uMap_TilestoRender.insert_or_assign("Tile_stoneBlockr2"+ i,test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        tex_rec.x += 64;
    }


//	//tiles.push_back(sprite3);
//    tex_rec.x = 64;
//	tex_rec.y = 0;
//    test_sprite_exp sprite4(renderer, fullpath.c_str(), tex_rec, src_rec);
//	//tiles.push_back(sprite4);
//    tex_rec.x = 246;
//	tex_rec.y = 0;
//    test_sprite_exp sprite5(renderer, fullpath.c_str(), tex_rec, src_rec);
//
//	//tiles.push_back(sprite5);
//
//    tex_rec.x = 246;
//	tex_rec.y = 90;
//    test_sprite_exp sprite6(renderer, fullpath.c_str(), tex_rec, src_rec);
//
//	//tiles.push_back(sprite6);


//	TilemapA.tilemap.push_back(tiles);
//    TilemapA.tilemap.push_back(tiles3);

    std::vector<test_sprite_exp> tiles2;
    block = "/tiles/Blocks/darkStoneBlock.png";
    fullpath = assetpath + block;

    //tex_rec.x = 64;
	//tex_rec.y = 256;

	//test_sprite_exp ti[2] { test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec), test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec)};

    test_sprite_exp sprite8(renderer, fullpath.c_str(), tex_rec, src_rec);


    tex_rec.x = 0;
    tex_rec.y =64;

    for(int i = 0; i <= 10; i++)
    {
               uMap_TilestoRender.insert_or_assign("Tile_darkStoneBlock"+ i,test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        tex_rec.y += 64;
    }



	TilemapA.tilemap.push_back(tiles2);


    std::vector<test_sprite_exp> tiles4;
    block = "/tiles/Blocks/blueOrb.png";
    fullpath = assetpath + block;

    tex_rec.x =172;
    tex_rec.y =64;

    for(int i = 0; i <= 5; i++)
    {
        //tiles4.push_back(test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        Collectables.insert_or_assign(i,test_sprite_exp(renderer,fullpath.c_str(),tex_rec,src_rec));
        tex_rec.x += 98;
        //tex_rec.y += 64;
        Collectables[i].spritenum = i;

    }

    block = "/tiles/Blocks/coin.png";
    fullpath = assetpath + block;

    tex_rec.x =200;
    tex_rec.y =128;

    for(int i = 5; i <= 10; i++)
    {
        cout << fullpath.c_str() << endl;
        //tiles4.push_back(test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        Collectables.insert_or_assign(i,test_sprite_exp(renderer,fullpath.c_str(),tex_rec,src_rec));
        tex_rec.x += 98;
        //tex_rec.y += 64;
        Collectables[i].spritenum = i;

    }

    //TilemapB.tilemap.push_back(tiles4);
	//if (SDL_IsGameController(0))
	//{
	//	SDL_GameController* pad = SDL_GameControllerOpen(0);
	//	SDL_Joystick* joy = SDL_GameControllerGetJoystick(pad);
	//	int instanceID = SDL_JoystickInstanceID(joy);
	//}

	InputHandler.Init();
	//spritesToRender[0].InitializeAnimations();
	//uMap_AnimatedSpritestoRender[9].UpdateSpriteFrame();


	uMap_AnimatedSpritestoRender["Player"].InitializeAnimations();

	//uMap_TilestoRender.insert_or_assign("test",test_sprite_exp(renderer,fullpath.c_str(),tex_rec,src_rec));

    //cout << uMap_TilestoRender["test"].spritenum << endl;



}

void test_gamecore_debug::Update()
{
	SDL_UpdateWindowSurface(window);



	unsigned char alpha;



	// Wait
	//system("pause");
	SDL_Event e;
	bool quit = false;
	auto flip = SDL_FLIP_NONE;
	int x = 0;
	int y = 0;
	//std::string inputval = "NULL";
	const char* inputval = "";
	bool keyup = false;


	int alphaval = 50;


	const int FPS = 120;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	const Uint8* state = SDL_GetKeyboardState(NULL);

	//(*spritesToRender[0].GetHitBox());


	//SDL_bool collision = SDL_HasIntersection(&rect1, &rect2);




	while (!quit)
	{
		frameStart = SDL_GetTicks();


		while (SDL_PollEvent(&e) != 0)
		{

			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_UP), true);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_UP),true);
					break;
				case SDLK_DOWN:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_DOWN), true);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_DOWN),true);
					break;
				case SDLK_LEFT:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_LEFT), true);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_LEFT),true);
					break;
				case SDLK_RIGHT:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_RIGHT), true);
                    uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_RIGHT),true);
					break;
				case SDLK_SPACE:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_SPACE), true);
                    uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_SPACE),true);
					break;
				case SDLK_f:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_f), true);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_f),true);
					break;
				case SDLK_x:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_x), true);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_x),true);
					break;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_UP), false);
                    uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_UP),false);
					break;
				case SDLK_DOWN:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_DOWN), false);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_DOWN),false);

					break;
				case SDLK_LEFT:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_LEFT), false);
                    uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_LEFT),false);
					break;
				case SDLK_RIGHT:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_RIGHT), false);
                    uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_RIGHT),false);
					break;
				case SDLK_SPACE:
					spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_SPACE), false);
					break;
				case SDLK_f:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_f), false);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_f),false);
					break;
				case SDLK_x:
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(SDLK_x), false);
					uMap_AnimatedSpritestoRender["Player"].Testingupdate(SDL_GetKeyName(SDLK_x),false);
					break;
				}
				break;
			}
				//if (e.type == SDL_MOUSEWHEEL)
				//{
				//	if (e.wheel.y > 0)
				//	{
				//		++alphaval;
				//		SDL_GetTextureAlphaMod(imgTexture, &alpha);
				//		SDL_SetTextureAlphaMod(imgTexture, alpha + alphaval);
				//	}
				//	else if (e.wheel.y < 0)
				//	{
				//		--alphaval;
				//		SDL_GetTextureAlphaMod(imgTexture, &alpha);
				//		SDL_SetTextureAlphaMod(imgTexture, alpha - alphaval);
				//	}

				//}

				//switch (e.type)
				//{
				//	if (e.type == SDL_KEYDOWN)
				//	{
				//		spritesToRender[0].Testingupdate(SDL_GetKeyName(e.key.keysym.sym), true);
				//	}
				//	if (SDL_KEYUP)
				//	{
				//		spritesToRender[0].Testingupdate(SDL_GetKeyName(e.key.keysym.sym), false);
				//	}

				//}




				//switch (e.type)
				//{
				//case SDL_KEYUP:
					//inputval = SDL_GetKeyName(e.key.keysym.sym);
					//inputval = SDL_GetScancodeFromKey(e.key.keysym.sym);
					//inputval.append(" Released ");
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(e.key.keysym.sym), false);
					//break;
				//case SDL_KEYDOWN:
					//inputval = SDL_GetKeyCode(e.key.keysym.sym);
					//inputval = SDL_GetScancodeFromKey(e.key.keysym.sym);
					//inputval.append(" Pressed ");
					//cout << SDL_GetScancodeName(SDL_GetScancodeFromKey(e.key.keysym.sym)) << endl;

					//spritesToRender[0].UpdateSprite(SDL_GetKeyName(e.key.keysym.sym));
					//spritesToRender[0].Testingupdate(SDL_GetKeyName(e.key.keysym.sym), true);
		/*			break;
				default:
					inputval = "NULL";
					break;

				}*/

			}








		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);


			Draw();
		}
		inputval = "NULL";
		//spritesToRender[0].outputbuttons();
		//spritesToRender[0].MoveSpriteXY(0, 0);
		//spritesToRender[0].UpdateSpriteFrame();
		//spritesToRender[0].UpdateSprite();

        uMap_AnimatedSpritestoRender["Player"].UpdateSprite();
        uMap_AnimatedSpritestoRender["Player"].UpdateSpriteFrame();


		//spritesToRender[0].UpdateSpriteFrame();
		//spritesToRender[0].Testingupdate(inputval,keyup);

		//cout << "COLLISION" << collision << endl;

	}
}

void test_gamecore_debug::Draw()
{



	//SDL_Rect src_rec(tex_rec);


	//test_sprite_exp sprite2(renderer, "C:/Users/trene/source/repos/SDL_Bomberman/Assets/Bomb.png",tex_rec,src_rec);
	//sprite.LoadSpriteFromSurface(imgSurface);
	//sprite.CreateSpriteTextureFromSurface();
	//Esprite.DrawSprite();

	auto flip = SDL_FLIP_NONE;



	SDL_SetRenderDrawColor(renderer, 157, 34, 53, 255);


	SDL_RenderClear(renderer);
	//SDL_RenderCopyEx(renderer, imgTexture, &src_rec, &tex_rec, NULL, NULL, flip);
	//sprite.DrawSprite(renderer);
	//sprite2.DrawSprite(renderer);

	//spritesToRender[1].DrawSprite(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

//	SDL_Rect rect2 = { 400,100,500,500 };
//	SDL_Rect rect1 = { 200,100,400,400 };
//
//    SDL_Rect tBrd = { 0,0,500,64 };
//	SDL_Rect rBrd = { 0,648,500,64 };
//    SDL_Rect lBrd = { 0,0,64,500};
//	SDL_Rect bBrd = { 648,0,64,500 };
//
//	std::vector<SDL_Rect> testborders;
//
//	testborders.push_back(tBrd);
//    testborders.push_back(bBrd);
//    testborders.push_back(lBrd);
//    testborders.push_back(rBrd);

//	SDL_RenderFillRect(renderer, &tBrd);
//
//	SDL_RenderFillRect(renderer, &bBrd);
//
//
//	SDL_RenderFillRect(renderer, &rBrd);
//
//
//	SDL_RenderFillRect(renderer, &lBrd);


//    for( std::vector<test_sprite_exp> t : TilemapA.tilemap)
//    {
//        //std::cout << "tiles" << std::endl;
//        for(test_sprite_exp ts : t)
//        {
//         ts.DrawSprite(renderer);
//         uMap_AnimatedSpritestoRender["Player"].DetectCollision(*(ts.GetHitBox()));
//         //SDL_RenderDrawRect(renderer, ts.GetHitBox());
//        }
//    }
    auto tr_it = uMap_TilestoRender.begin();
    while(tr_it != uMap_TilestoRender.cend())
    {
        //am_it = uMap_AnimatedSpritestoRender[am_it-first];
        //uMap_AnimatedSpritestoRender[am_it->first].DrawSprite(renderer);

        uMap_TilestoRender[tr_it->first].DrawSprite(renderer);
        uMap_AnimatedSpritestoRender["Player"].DetectCollision(*(uMap_TilestoRender[tr_it->first].GetHitBox()));
        tr_it++;
    }


//    for (auto& ts: uMap_TilestoRender)
//    {
//        //uMap_TilestoRender[ts.first].DrawSprite(renderer);
//        //uMap_AnimatedSpritestoRender["Player"].DetectCollision(*(uMap_TilestoRender[ts.first].GetHitBox()));
//
//
//    }

//    for (auto& ts: uMap_AnimatedSpritestoRender)
//    {
//        uMap_AnimatedSpritestoRender[ts.first].DrawSprite(renderer);
//        //uMap_AnimatedSpritestoRender["Player"].DetectCollision(*(uMap_TilestoRender[ts.first].GetHitBox()));
//
//    }

    auto am_it = uMap_AnimatedSpritestoRender.begin();
    while(am_it != uMap_AnimatedSpritestoRender.cend())
    {
        //am_it = uMap_AnimatedSpritestoRender[am_it-first];
        uMap_AnimatedSpritestoRender[am_it->first].DrawSprite(renderer);
        am_it++;
    }





    auto xm_it = uMap_TilestoRender.begin();
    while(xm_it != uMap_TilestoRender.cend())
    //for (auto& ts: uMap_TilestoRender)
    {

     if(uMap_AnimatedSpritestoRender["ExplosionN"].DetectCollision(*uMap_TilestoRender[xm_it->first].GetHitBox()))
         {

            //cout << ts.first << endl;
           xm_it = uMap_TilestoRender.erase(xm_it);
            //cout << objtoremove[0].first << endl;

         }

     if(uMap_AnimatedSpritestoRender["ExplosionS"].DetectCollision(*uMap_TilestoRender[xm_it->first].GetHitBox()))
         {

            //cout << ts.first << endl;
           xm_it = uMap_TilestoRender.erase(xm_it);
            //cout << objtoremove[0].first << endl;

         }
     if(uMap_AnimatedSpritestoRender["ExplosionW"].DetectCollision(*uMap_TilestoRender[xm_it->first].GetHitBox()))
         {

            //cout << ts.first << endl;
           xm_it = uMap_TilestoRender.erase(xm_it);
            //cout << objtoremove[0].first << endl;

         }

     if(uMap_AnimatedSpritestoRender["ExplosionE"].DetectCollision(*uMap_TilestoRender[xm_it->first].GetHitBox()))
         {

            //cout << ts.first << endl;
           xm_it = uMap_TilestoRender.erase(xm_it);
            //cout << objtoremove[0].first << endl;

         }
     else
         {
            ++xm_it;
         }
    }


//
//    for( auto&  ts : Collectables)
//    {
//     //  std:: cout << ts.first << endl;
//      ts.second.DrawSprite(renderer);
//     //ts.spritenum = i;
//     //++i;
//     if(uMap_AnimatedSpritestoRender["Player"].DetectCollision(*ts.second.GetHitBox()))
//     {
//
//        //objtoremove.push_back(ts);
//        if(Collectables.count(ts.first) == 1)
//        {
//            Collectables.erase(ts.first);
//            cout << ts.first << endl;
//        }
//
//        //cout << objtoremove[0].first << endl;
//
//     }


        auto pm_it = Collectables.begin();
        while(pm_it != Collectables.cend())
        {

            Collectables[pm_it->first].DrawSprite(renderer);

            if(uMap_AnimatedSpritestoRender["Player"].DetectCollision(*Collectables[pm_it->first].GetHitBox()))
            {
                pm_it = Collectables.erase(pm_it);
                //cout << pm_it->first << endl;

            }
            else
            {
                ++pm_it;
            }


        }


     //cout <<  ts.second.spritenum << endl;

//     for(auto o : objtoremove)
//     {
//        if( !objtoremove.empty())
//        {
//            //Removal works but sometimes causes crashes, most likely trying to remove something too fast.
//            Collectables.erase(o.first);
//            objtoremove.pop_back();
//            std::cout << objtoremove.size()<< endl;
//
//        }





    if(uMap_AnimatedSpritestoRender["Player"].pressedf)
    {
        //cout << "F received " << endl;


        std::string fullpath = "/home/patrick/Desktop/C++/SDL_Bomberman/SDL_Bomberman/Assets/tiles/Blocks/Bomb4.png";
        //TilemapA.tilemap[0].push_back(test_sprite_exp(renderer, fullpath.c_str(), tex_rec, src_rec));
        SDL_Rect testrec = {0,0,32,32};
        SDL_Rect testrec2 = {0,0,16,16};

        testrec = uMap_AnimatedSpritestoRender["Player"].tex_rec;
        //tex_rec.x += 32;

        //cout << tex_rec.x << endl;

        //spritesToRender.push_back(test_animatedsprite(renderer, fullpath.c_str(), testrec,testrec2 ));
        //spritesToRender[1].InitializeAnimations();

        uMap_AnimatedSpritestoRender.insert_or_assign("Bomb",test_animatedsprite(renderer, fullpath.c_str(), testrec, src_rec));
        uMap_AnimatedSpritestoRender["Bomb"].InitializeAnimations();


        //cout << fullpath.c_str() << endl;

        uMap_AnimatedSpritestoRender["Player"].pressedf = false;
    }


	//SDL_RenderDrawRect(renderer, spritesToRender[0].GetHitBox());
	SDL_RenderDrawRect(renderer, uMap_AnimatedSpritestoRender["Player"].GetHitBox());
	//SDL_RenderDrawRect(renderer, spritesToRender[1].GetHitBox());

	//SDL_bool collision = SDL_HasIntersection(spritesToRender[0].GetHitBox(), spritesToRender[1].GetHitBox());

	//spritesToRender[0].UpdateSpriteFrame();

	//spritesToRender[0].DetectCollision(rect1);

	//spritesToRender[0].DetectCollision(rect2);

    //spritesToRender[0].DetectCollision(*(spritesToRender[1].GetHitBox()));



	//spritesToRender[0].DrawSprite(renderer);

//    uMap_AnimatedSpritestoRender["Player"].DrawSprite(renderer);
//    uMap_AnimatedSpritestoRender["Bomb"].DrawSprite(renderer);
    uMap_AnimatedSpritestoRender["Bomb"].UpdateBombAni();



//	cout << spritesToRender.size() << endl;
//	if(spritesToRender.size() >= 2 && &spritesToRender[1]!= NULL)
//	{
//
//        spritesToRender[1].DrawSprite(renderer);
//        spritesToRender[1].UpdateBombAni();

    if(uMap_AnimatedSpritestoRender["Player"].pressedx)
    {

        std::string fullpath = "/home/patrick/Desktop/C++/SDL_Bomberman/SDL_Bomberman/Assets/tiles/Blocks/Flame.png";

        SDL_Rect arecforfire = {uMap_AnimatedSpritestoRender["Bomb"].tex_rec.x + 64,uMap_AnimatedSpritestoRender["Bomb"].tex_rec.y ,36,36};
        uMap_AnimatedSpritestoRender.insert_or_assign("ExplosionN",test_animatedsprite(renderer, fullpath.c_str(), arecforfire, uMap_AnimatedSpritestoRender["Bomb"].src_rec));

        //TilemapA.tilemap[0].push_back(test_sprite_exp(renderer, fullpath.c_str(), arecforfire,  spritesToRender[1].src_rec));
        arecforfire = {uMap_AnimatedSpritestoRender["Bomb"].tex_rec.x,uMap_AnimatedSpritestoRender["Bomb"].tex_rec.y+64 ,36,36};
        uMap_AnimatedSpritestoRender.insert_or_assign("ExplosionS",test_animatedsprite(renderer, fullpath.c_str(), arecforfire,  uMap_AnimatedSpritestoRender["Bomb"].src_rec));

        //TilemapA.tilemap[0].push_back(test_sprite_exp(renderer, fullpath.c_str(), arecforfire,  spritesToRender[1].src_rec));
        arecforfire = {uMap_AnimatedSpritestoRender["Bomb"].tex_rec.x - 64,uMap_AnimatedSpritestoRender["Bomb"].tex_rec.y ,36,36};
        uMap_AnimatedSpritestoRender.insert_or_assign("ExplosionE",test_animatedsprite(renderer, fullpath.c_str(), arecforfire,  uMap_AnimatedSpritestoRender["Bomb"].src_rec));

        //TilemapA.tilemap[0].push_back(test_sprite_exp(renderer, fullpath.c_str(), arecforfire,  spritesToRender[1].src_rec));
        arecforfire = {uMap_AnimatedSpritestoRender["Bomb"].tex_rec.x,uMap_AnimatedSpritestoRender["Bomb"].tex_rec.y-64 ,36,36};
        uMap_AnimatedSpritestoRender.insert_or_assign("ExplosionW",test_animatedsprite(renderer, fullpath.c_str(), arecforfire,  uMap_AnimatedSpritestoRender["Bomb"].src_rec));

        //TilemapA.tilemap[0].push_back(test_sprite_exp(renderer, fullpath.c_str(), arecforfire,  spritesToRender[1].src_rec));
        //spritesToRender[1].tex_rec = {0,0,0,0};
        //
        //spritesToRender.push_back(test_animatedsprite(renderer, fullpath.c_str(), testrec,testrec2 ));
        //spritesToRender[3].InitializeAnimations();
        //spritesToRender[3].DrawSprite(renderer);
    }




	//spritesToRender[1].DrawSprite(renderer);





	//std::cout << collision << std::endl;
	//SDL_SetTextureBlendMode(imgTexture, SDL_BLENDMODE_BLEND);

	SDL_RenderPresent(renderer);

	//SDL_RenderPresent(renderer);

	//TODO: Finish Collision, try and spawn bomb sprite, remove/destroy sprites
}
