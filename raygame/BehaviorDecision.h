#pragma once
#include "Decision.h"

class BehaviorDecision : public Decision
{
public:
	//constructor
	BehaviorDecision(Behavior* behavior) : m_behavior(behavior) {}
	//deconstructor
	~BehaviorDecision() {}

	virtual void makeDecision(Agent* agent, float deltaTime);

private:
	//behavior is null by default
	Behavior* m_behavior = nullptr;
};
