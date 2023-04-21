#include <iostream>
#include "test_gamecore_debug.h"
//#include "test_gamecore.h"

//#include "test_sdl_coreclass.h"
using namespace std; 


//#include "test_sdl_window.h"

int main()
{

	//test_sdl_window::testwin();

	//test_sdl_coreclass* x = new test_sdl_coreclass(); 



	//x->Init();
	//x->Draw();
	//x->Update(); 


	test_gamecore_debug* game = new test_gamecore_debug();


	game->Init();
	game->Update();
	//game->Draw(); 





	

	return 0; 
}