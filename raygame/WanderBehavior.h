#pragma once
#include "Behavior.h"

class WanderBehavior : public Behavior
{
public:
	//constructor
	WanderBehavior() {}
	//deconstructor
	virtual ~WanderBehavior() {}

	virtual void update(Agent* agent, float deltaTime);

private:
	//set radius, offset, and jitter
	float m_radius = 1000.0f;
	float m_offset = 0.0f;
	float m_jitter = 500.0f;
	//set previous target to be 0
	Vector2 m_prevTarget = { 0.0f, 0.0f };
};

