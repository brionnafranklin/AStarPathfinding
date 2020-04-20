#include "AStar.h"
std::vector<Agent*> AStar::AStarSearch(Agent* startNode, Agent* endNode)
{
	//Validate the input
	if (startNode == nullptr || endNode == nullptr) {
		return std::vector<Agent*>();
	}

	if (startNode == endNode) {
		std::vector<Agent*> singleNodePath;
		singleNodePath.push_back(startNode);
		return singleNodePath;
	}

	//Initialize the starting node
	startNode->gScore = 0;
	startNode->previous = nullptr;

	//Create our temporary lists for storing nodes
	std::vector<Agent*> openList;
	std::vector<Agent*> closedList;

	//Add the starting node to openList
	openList.push_back(startNode);

	while (!openList.empty())
	{
		//Set the current node to the first node in the openList
		Agent* currentNode = openList.front();
		//Remove currentNode from openList
		openList.erase(openList.begin());
		//Add currentNode to closedList
		closedList.push_back(currentNode);

		//If the destination node was added to the closed list,
		//the shortest path has been found
		if (currentNode == endNode) {
			break;
		}
		//For each Edge e in currentNode's connections
		for (Edge e : currentNode->connections) {
			//If the target node is in the closedList, ignore it
			if (std::find(closedList.begin(), closedList.end(), e.target) != closedList.end()) {
				continue;
			}
			e.target->gScore = currentNode->gScore + e.cost;
			e.target->hScore = heuristic(e.target, endNode);
			e.target->fScore = currentNode->gScore + currentNode->hScore;
			//If the target node is not in the openList, update it
			if (std::find(openList.begin(), openList.end(), e.target) == openList.end()) {
				//Calculate the target node's G Score

				//Set the target node's previous to currentNode
				e.target->previous = currentNode;
				//Find the earliest point we should insert the node
				//to the list to keep it sorted
				auto insertionPos = openList.end();
				for (auto i = openList.begin(); i != openList.end(); i++) {
					if (e.target->fScore < (*i)->fScore) {
						insertionPos = i;
						break;
					}
				}
				//Insert the node at the appropriate position
				openList.insert(insertionPos, e.target);
			}
			//Otherwise the target node IS in the open list
			else {
				//Compare the new F Score to the old one before updating
				if (currentNode->fScore < e.target->fScore)
				{
					//Calculate the target node's G Score
					e.target->gScore = currentNode->gScore;
					e.target->fScore = currentNode->fScore;
					//Set the target node's previous to currentNode
					e.target->previous = currentNode;
				}
			}
		}
	}
	//Create path in reverse from endNode to startNode
	std::vector<Agent*> path;
	Agent* currentNode = endNode;

	while (currentNode != nullptr)
	{
		//Add the current node to the beginning of the path
		path.insert(path.begin(), currentNode);
		//Go to the previous node
		currentNode = currentNode->previous;
	}
	return path;
}

float AStar::heuristic(Agent* target, Agent* endNode)
{
	return 0;
}
AStar::AStar()
{
}
AStar::~AStar()
{
}