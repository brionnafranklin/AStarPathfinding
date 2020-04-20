#include "DecisionTreeBehavior.h"

//makes decision
void DecisionTreeBehavior::update(Agent* agent, float deltaTime)
{
	m_rootDecision->makeDecision(agent, deltaTime);
}
