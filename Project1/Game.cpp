#include "Game.h"

float currentTimer = 0;
float targetTime = 5.0f;

void setGame()
{
	game.pause = false;
	game.resetPause = false;
	game.exitGame = false;
	game.gameOver = false;
	game.stillPlaying = false;

}

void ExitGame(Rectangle exit, int& screen)
{
	if (CheckCollisionPointRec(GetMousePosition(), exit))
	{
		DrawRectangleRec(exit, VIOLET);
		DrawText("SALIR", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 + 200, 30, WHITE);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawRectangleRec(exit, DARKPURPLE);
			DrawText("SALIR", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 + 200, 30, WHITE);
			screen = EXIT;
		}
	}
}

void runGame(Rectangle game, int& screen)
{
	if (CheckCollisionPointRec(GetMousePosition(), game))
	{
		DrawRectangleRec(game, VIOLET);
		DrawText("JUGAR", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 - 50, 30, WHITE);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			screen = GAME;
			DrawRectangleRec(game, DARKPURPLE);
			DrawText("JUGAR", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 - 50, 30, WHITE);
		}

	}
}

void Update(int& screen, bool& gameOver, Texture2D& background, Texture2D& midground, Texture2D& foreground)
{
	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
	{
		screen = PAUSE;
		//cout << pause << endl;
		//0 false
		//1 true
	}
	if (IsKeyPressed(KEY_ENTER))
	{
		bullet.bulletActive = true;
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

}

void checkCollisionBullet()
{
	if (CheckCollisionRecs(bullet.rec, enemy.rec))
	{
		setEnemy();
		bullet.bulletActive = false;
		patrol[0].points++;
	}

}

