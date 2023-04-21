#pragma once
#include <string>
#include <map>

class test_sdl_inputhandler
{

	enum KEYEVENTS
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT,
		QUIT
	};

public: 
	test_sdl_inputhandler(); 
	~test_sdl_inputhandler();
	void Init(); 
	const std::string UpdateInput(const char* keyvalue, bool ispressed);
	std::map<const char*, bool> outputbuttonmap();

	inline std::map<const char*, bool> getButtonMap() { return buttonmap; }

private:

	std::map<const char*, bool> buttonmap = {};

};

