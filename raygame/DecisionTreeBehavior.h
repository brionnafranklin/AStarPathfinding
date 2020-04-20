#pragma once
#include "Behavior.h"
#include "Decision.h"

class DecisionTreeBehavior : public Behavior
{
public:
	//constructor
	DecisionTreeBehavior(Decision* decision) : m_rootDecision(decision) {}
	//deconstructor
	virtual ~DecisionTreeBehavior() {}
	//makes decision
	virtual void update(Agent* agent, float deltaTime);

private:
	//declare root decision
	Decision* m_rootDecision;
};
