#pragma once
#include "Behavior.h"

class SeekBehavior : public Behavior
{
public:
	//constructor
	SeekBehavior() {}
	//deconstructor
	virtual ~SeekBehavior() {}
	//look for player
	virtual void update(Agent* agent, float deltaTime);
	//set target
	void setTarget(Agent* agent) { m_target = agent; }

private:
	//set target to null
	Agent* m_target = nullptr;
};

