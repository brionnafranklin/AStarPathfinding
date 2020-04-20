#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{
public:
	//constructor
	KeyboardBehavior() {}
	//deconstructor
	virtual ~KeyboardBehavior() {}
	//set up key bindings
	virtual void update(Agent* agent, float deltaTime);
};

