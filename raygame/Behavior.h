#pragma once
#include "Agent.h";

class Behavior
{
public:
	//constructor
	Behavior() {}
	//deconstructor
	virtual ~Behavior() {}

	virtual void update(Agent* agent, float deltaTime) = 0;
};
