#pragma once
#include "Behavior.h"

class ScreenEdgeBehavior : public Behavior
{
public:
	//constructor
	ScreenEdgeBehavior() {}
	//deconstructor
	virtual ~ScreenEdgeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
};

