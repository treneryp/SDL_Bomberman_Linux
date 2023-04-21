#include "test_animatedsprite.h"
#include <array>
#include "iostream"

namespace GLOBAL {
	Uint32 time = 0;
	Uint32 frame_last_changed = 10;
	int frame = 0;
}

void test_animatedsprite::UpdateSpriteFrame()
{
	bool playanimation = true;

	const char* curr_animationset = "";

	//TODO: Fixed Animation speedup issue, still need to polish idle stance;

	for (auto x : InputHandler.getButtonMap())
	{
		if (std::string(x.first) == "Down" && x.second != 0)
		{
			curr_animationset = "Down";
			GLOBAL::time++;
			//while button is down, loop through a vector of x,y values that represent the animation frame coords.

		}
		//else if (std::string(x.first) == "Down" && x.second != 1)
		//{
		//	curr_animationset = "Idle";
		//	src_rec.x = AnimationMap["Idle"][GLOBAL::frame].first;
		//	src_rec.y = AnimationMap["Idle"][GLOBAL::frame].second;
		//}
		if (std::string(x.first) == "Right" && x.second != 0)
		{
			curr_animationset = "Right";
			GLOBAL::time++;

			//while button is down, loop through a vector of x,y values that represent the animation frame coords.

		}

		if (std::string(x.first) == "Left" && x.second != 0)
		{
			curr_animationset = "Left";
			GLOBAL::time++;

			//while button is down, loop through a vector of x,y values that represent the animation frame coords.

		}
		if (std::string(x.first) == "Up" && x.second != 0)
		{
			curr_animationset = "Up";
			GLOBAL::time++;


			//while button is down, loop through a vector of x,y values that represent the animation frame coords.

		}




		for (int i = 0; i < AnimationMap[curr_animationset].size(); i++)

			if (GLOBAL::time > GLOBAL::frame_last_changed)
			{

				//std::cout << animation_WalkingDown[GLOBAL::frame].first << animation_WalkingDown[GLOBAL::frame].second << std::endl;
				//std::cout << (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)) << std::endl;
				GLOBAL::time = 0;
				if (GLOBAL::frame >= AnimationMap[curr_animationset].size() - 1)
				{
					GLOBAL::frame = 0;
				}
				else
				{
					GLOBAL::frame += 1;

				}

				src_rec.x = AnimationMap[curr_animationset][GLOBAL::frame].first;
				src_rec.y = AnimationMap[curr_animationset][GLOBAL::frame].second;
				std::cout << GLOBAL::time << std::endl;

			}


	}

	//InitializeAnimations();


	//for (auto x : InputHandler.getButtonMap())
	//{
	//	if (std::string(x.first) == "Down" && x.second != 0)
	//	{

	//		//while button is down, loop through a vector of x,y values that represent the animation frame coords.

	//		for (int i = 0; i < (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)); i++)

	//			if (GLOBAL::time > GLOBAL::frame_last_changed)
	//			{

	//				//std::cout << animation_WalkingDown[GLOBAL::frame].first << animation_WalkingDown[GLOBAL::frame].second << std::endl;
	//				//std::cout << (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)) << std::endl;
	//				GLOBAL::time = 0;
	//				if (GLOBAL::frame >= (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)-1))
	//				{
	//					GLOBAL::frame = 0;
	//				}
	//				else
	//				{
	//					GLOBAL::frame += 1;

	//				}
	//
	//				src_rec.x = animation_WalkingDown[GLOBAL::frame].first;
	//				src_rec.y = animation_WalkingDown[GLOBAL::frame].second;
	//

	//			}

	//			GLOBAL::time++;


	//	}

	//	if (std::string(x.first) == "Right" && x.second != 0)
	//	{

	//		//while button is down, loop through a vector of x,y values that represent the animation frame coords.

	//		for (int i = 0; i < (std::end(animation_WalkingRight) - std::begin(animation_WalkingRight)); i++)

	//			if (GLOBAL::time > GLOBAL::frame_last_changed)
	//			{

	//				//std::cout << animation_WalkingDown[GLOBAL::frame].first << animation_WalkingDown[GLOBAL::frame].second << std::endl;
	//				//std::cout << (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)) << std::endl;
	//				GLOBAL::time = 0;
	//				if (GLOBAL::frame >= (std::end(animation_WalkingRight) - std::begin(animation_WalkingRight) - 1))
	//				{
	//					GLOBAL::frame = 0;
	//				}
	//				else
	//				{
	//					GLOBAL::frame += 1;

	//				}

	//				src_rec.x = animation_WalkingRight[GLOBAL::frame].first;
	//				src_rec.y = animation_WalkingRapt-get install libsdl2-image-devight[GLOBAL::frame].second;


	//			}

	//		GLOBAL::time++;


	//	}

	//	if (std::string(x.first) == "Left" && x.second != 0)
	//	{

	//		//while button is down, loop through a vector of x,y values that represent the animation frame coords.

	//		for (int i = 0; i < (std::end(animation_WalkingLeft) - std::begin(animation_WalkingLeft)); i++)

	//			if (GLOBAL::time > GLOBAL::frame_last_changed)
	//			{

	//				//std::cout << animation_WalkingDown[GLOBAL::frame].first << animation_WalkingDown[GLOBAL::frame].second << std::endl;
	//				//std::cout << (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)) << std::endl;
	//				GLOBAL::time = 0;
	//				if (GLOBAL::frame >= (std::end(animation_WalkingLeft) - std::begin(animation_WalkingLeft) - 1))
	//				{
	//					GLOBAL::frame = 0;
	//				}
	//				else
	//				{
	//					GLOBAL::frame += 1;

	//				}

	//				src_rec.x = animation_WalkingLeft[GLOBAL::frame].first;
	//				src_rec.y = animation_WalkingLeft[GLOBAL::frame].second;


	//			}

	//		GLOBAL::time++;


	//	}

	//	if (std::string(x.first) == "Up" && x.second != 0)
	//	{

	//		//while button is down, loop through a vector of x,y values that represent the animation frame coords.

	//		for (int i = 0; i < (std::end(animation_WalkingUp) - std::begin(animation_WalkingUp)); i++)

	//			if (GLOBAL::time > GLOBAL::frame_last_changed)
	//			{

	//				//std::cout << animation_WalkingDown[GLOBAL::frame].first << animation_WalkingDown[GLOBAL::frame].second << std::endl;
	//				//std::cout << (std::end(animation_WalkingDown) - std::begin(animation_WalkingDown)) << std::endl;
	//				GLOBAL::time = 0;
	//				if (GLOBAL::frame >= (std::end(animation_WalkingUp) - std::begin(animation_WalkingUp) - 1))
	//				{
	//					GLOBAL::frame = 0;
	//				}
	//				else
	//				{
	//					GLOBAL::frame += 1;

	//				}

	//				src_rec.x = animation_WalkingUp[GLOBAL::frame].first;
	//				src_rec.y = animation_WalkingUp[GLOBAL::frame].second;


	//			}

	//		GLOBAL::time++;


	//	}
	//}


}

void test_animatedsprite::InitializeAnimations()
{
	AnimationMap.insert_or_assign("Down", animation_WalkingDown);
	AnimationMap.insert_or_assign("Right", animation_WalkingRight);
	AnimationMap.insert_or_assign("Left", animation_WalkingLeft);
	AnimationMap.insert_or_assign("Up", animation_WalkingUp);
	AnimationMap.insert_or_assign("Idle", animation_idle);


}
