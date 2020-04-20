#pragma once
#include "Behavior.h"
#include "AStar.h"
class PatrolBehovior : public Behavior
{
public:

	PatrolBehovior() {};
	virtual ~PatrolBehovior() {};

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};

