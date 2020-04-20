#pragma once
#include "Agent.h"
#include<vector>
#include<raylib.h>

class AStar
{
public:

	AStar();
	~AStar();

	std::vector<Agent*> AStarSearch(Agent* startNode, Agent* endNode);
	float heuristic(Agent* target, Agent* endNode);
private:

};