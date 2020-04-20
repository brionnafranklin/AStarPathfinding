/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "KeyboardBehavior.h"
#include "ScreenEdgeBehavior.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "PursuitBehavior.h"
#include "WithinRangeCondition.h"
#include "DecisionTreeBehavior.h"
#include "BooleanDecision.h"
#include "BehaviorDecision.h"
#include "PatrolBehovior.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	
	//Create the player
	Agent* player = new Agent();
	player->setPosition(Vector2{ 800.0f, 450.0f });
	player->setSpeed(500.0f);
	player->setColor(SKYBLUE);
	//Create and add keyboard behavior
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);
	//Create and add screen edge behavior
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	player->addBehavior(screenEdgeBehavior);

	//Create the enemy
	Agent* enemy = new Agent();
	enemy->setPosition(Vector2{ 400.0f, 225.0f });
	enemy->setSpeed(250.0f);
	enemy->setColor(RED);

	//Leaves
	WanderBehavior* wanderBehavior = new WanderBehavior();
	BehaviorDecision* wanderDecision = new BehaviorDecision(wanderBehavior);
	SeekBehavior* seekBehavior = new SeekBehavior();
	seekBehavior->setTarget(player);
	BehaviorDecision* seekDecision = new BehaviorDecision(seekBehavior);
	PursuitBehavior* pursuitBehavior = new PursuitBehavior();
	pursuitBehavior->setTarget(player);
	BehaviorDecision* pursuitDecision = new BehaviorDecision(pursuitBehavior);
	//Branches
	WithinRangeCondition* canSeeCondition = new WithinRangeCondition(player, 150);
	BooleanDecision* canSeeDecision = new BooleanDecision(pursuitDecision, seekDecision, canSeeCondition);
	WithinRangeCondition* canHearCondition = new WithinRangeCondition(player, 300);
	BooleanDecision* canHearDecision = new BooleanDecision(canSeeDecision, wanderDecision, canHearCondition);
	//Enemy decision tree
	DecisionTreeBehavior* enemyDecisionTree = new DecisionTreeBehavior(canHearDecision);
	enemy->addBehavior(enemyDecisionTree);
	enemy->addBehavior(screenEdgeBehavior);
	
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();

		player->update(deltaTime);
		enemy->update(deltaTime);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		enemy->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}