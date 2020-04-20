#include "BehaviorDecision.h"
#include "Behavior.h"

void BehaviorDecision::makeDecision(Agent* agent, float deltaTime)
{
	//make sure behavior is not null
	if (m_behavior == nullptr)
		return;
	//call behavior's update
	m_behavior->update(agent, deltaTime);
}
