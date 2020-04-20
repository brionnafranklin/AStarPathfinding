#include "Agent.h"
#include "Behavior.h"

//update agent's position
void Agent::update(float deltaTime)
{
	//Set total force to zero
	//For each Behavior in the Behavior list
	for (auto i = m_behaviorList.begin(); i != m_behaviorList.end(); i++) {
		//Call the Behavior's update function
		(*i)->update(this, deltaTime);
	}
	//Add velocity times delta time to position
	m_position += m_velocity * deltaTime;
}

//Draw the agent
void Agent::draw()
{
	DrawRectangle((int)m_position.x, (int)m_position.y, 20, 20, m_color);
}

//draw the agent but smaller
void Agent::drawSmall()
{
	DrawRectangle((int)m_position.x, (int)m_position.y, 5, 5, m_color);
}

//Adds a Behavior
void Agent::addBehavior(Behavior* behavior)
{
	//Add the Behavior to the Behavior list
	m_behaviorList.insert(m_behaviorList.end(), behavior);
}

//changes velocity by adding a new force
void Agent::addForce(Vector2 force)
{
	m_velocity += force;
}
