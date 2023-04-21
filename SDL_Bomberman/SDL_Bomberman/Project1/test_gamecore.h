#pragma once
class test_gamecore
{

public: 

	virtual ~test_gamecore(){}
	virtual void Init() = 0; 
	virtual void Update() = 0; 
	virtual void Draw() = 0; 


};

