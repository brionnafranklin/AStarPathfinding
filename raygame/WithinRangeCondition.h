#pragma once
#include "Condition.h"

class WithinRangeCondition : public Condition
{
public:
	//constructor
	WithinRangeCondition(Agent* target, float range)
		: m_target(target), m_range(range) {}
	//deconstructor
	virtual ~WithinRangeCondition() {}

	virtual bool test(Agent* agent) const;

private:
	//declare target and range variables
	Agent* m_target;
	float m_range;
};
