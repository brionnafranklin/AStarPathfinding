#pragma once
#include "raylib.h"
#include <vector>

class Behavior;
struct Edge;
class Agent
{
public:
	//constructor
	Agent() {}
	//deconstructor
	virtual ~Agent() {}

	//Update the agent and its behaviors
	virtual void update(float deltaTime);

	//Draw the agent
	virtual void draw();

	//draw the agent but smaller
	void drawSmall();

	//Add a behavior to the agent
	void addBehavior(Behavior* behavior);

	//Add a force to the agent's velocity
	void addForce(Vector2 force);

	//Movement functions
	void setPosition(Vector2 position) { m_position = position; }
	Vector2 getPosition() { return m_position; }
	void setVelocity(Vector2 velocity) { m_velocity = velocity; }
	Vector2 getVelocity() { return m_velocity; }

	//Speed functions
	void setSpeed(float speed) { m_speed = speed; }
	float getSpeed() { return m_speed; }
	
	//Color functions
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }

	float gScore = 0.0f;
	//## Add hScore ##//
	float hScore = 0.0f;
	//## Add fScore ##//
	float fScore = 0.0f;
	Agent* previous = nullptr;

	std::vector<Edge> connections;

protected:
	//a list of behaviors
	std::vector<Behavior*> m_behaviorList;

	//default position and velocity
	Vector2 m_position = { 0.0f, 0.0f };
	Vector2 m_velocity = { 0.0f, 0.0f };

	//set default speed and color
	float m_speed = 500.0f;
	Color m_color = MAROON;
};

struct Edge
{
	//declare target and cost
	Agent* target;
	float cost;
};
