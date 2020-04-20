#pragma once
#include "Behavior.h"
#include "AStar.h"

class PursuitBehavior : public Behavior
{
public:
	//constructor
	PursuitBehavior() {}
	//deconstructor
	virtual ~PursuitBehavior() {}
	//chase after the target
	virtual void update(Agent* agent, float deltaTime);
	//sets target
	void setTarget(Agent* agent) { m_target = agent; }
private:
	//set target to null
	Agent* m_target = nullptr;
};

