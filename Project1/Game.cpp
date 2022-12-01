#pragma once

#include "Game.h"


float currentTimer = 0;
float targetTime = 5.0f;

void startGame()
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 900;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Moon Patrol");

	Texture2D background = LoadTexture("../images/marsmountain.png"); /*../*/
	Texture2D midground = LoadTexture("../images/marsmid.png"); /*../*/
	Texture2D foreground = LoadTexture("../images/marsclose.png");/* ../*/

	int screen = MENU;

	setGame();

	while (!WindowShouldClose() && !game.exitGame)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		Menu(screen, background, midground, foreground, game.pause, game.resetPause);
		EndDrawing();
	}
}

void setGame()
{
	game.pause = false;
	game.resetPause = false;
	game.exitGame = false;
	game.gameOver = false;
	game.stillPlaying = false;
	game.twoPlayersActive = false;
}

void Update(int& screen, bool& gameOver, Texture2D& background, Texture2D& midground, Texture2D& foreground)
{
	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
	{
		screen = PAUSE;
	}

	checkCollisionBullet();
	hasCollided();
	enemyMovement();
	moveObstacle();
	playerInput();
	playerMovement();
	drawParallax(background, midground, foreground);
	moveParallax();
	bulletMovement();
	loseCondition(screen);
}

void hasCollided()
{
	currentTimer += GetFrameTime();

	if (CheckCollisionRecs(patrol[0].rec, obstacle.rec) && patrol[0].canCollide == true)
	{
		patrol[0].canCollide = false;
		patrol[0].lives--;
	}

	if (currentTimer >= targetTime)
	{
		currentTimer = 0;
		patrol[0].canCollide = true;
	}

	if (game.twoPlayersActive)
	{
		currentTimer += GetFrameTime();

		if (CheckCollisionRecs(patrol[1].rec, obstacle.rec) && patrol[1].canCollide == true)
		{
			patrol[1].canCollide = false;
			patrol[1].lives--;
		}

		if (currentTimer >= targetTime)
		{
			currentTimer = 0;
			patrol[1].canCollide = true;

		}

	}
}

void checkCollisionBullet()
{
	if (CheckCollisionRecs(bullet.rec, enemy.rec))
	{
		setEnemy();
		bullet.bulletActive = false;
		patrol[0].points++;
	}

	if (game.twoPlayersActive)
	{
		if (CheckCollisionRecs(bullet.rec, enemy.rec))
		{
			setEnemy();
			bullet.bulletActive = false;
			patrol[1].points++;
		}
	}
}

