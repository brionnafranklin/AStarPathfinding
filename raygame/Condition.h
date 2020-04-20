#pragma once
#include "Behavior.h"

class Condition : public Behavior
{
public:
	//constructor
	Condition() {}
	//deconstructor
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;
	virtual void update(Agent* agent, float deltaTime) {}
};
