#include "test_sdl_inputhandler.h"

#include <iostream>
#include <string.h>


using namespace std; 

test_sdl_inputhandler::test_sdl_inputhandler()
{
}

test_sdl_inputhandler::~test_sdl_inputhandler()
{
}

void test_sdl_inputhandler::Init()
{
}

const std::string  test_sdl_inputhandler::UpdateInput(const char* keyvalue,bool ispressed)
{
	

	//cout << keyvalue << endl; 
	//if (buttonmap[keyvalue] != NULL)
	//{
	//	buttonmap.insert(std::pair<const char*, bool>(keyvalue, ispressed));
	//}
	//else
	//{
	//	buttonmap[keyvalue] = std::pair<const char*, bool>(keyvalue, ispressed)

	//}

	buttonmap.insert_or_assign(keyvalue,ispressed);

	//if (std::string(keyvalue) == "Left")
	//{
	//	cout << " PRESSING LEFT" << endl; 
	//	return "Left";
	//}
	//else if (std::string(keyvalue) == "Right")
	//{
	//	cout << "PRESSING RIGHT" << endl;
	//	return "Right";
	//}
	//else if (std::string(keyvalue) == "Down")
	//{
	//	cout << "PRESSING DOWN" << endl;
	//	return "Down";
	//}
	//else if (std::string(keyvalue) == "Up")
	//{
	//	cout << "PRESSING UP" << endl;
	//	return "Up";
	//}
	//else
	//{
	//	return std::string(keyvalue);
	//}
	 	   

	return "test"; 
}

std::map<const char*, bool> test_sdl_inputhandler::outputbuttonmap()
{
	return buttonmap;
}

