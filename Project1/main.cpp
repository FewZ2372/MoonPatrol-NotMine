#include "raylib.h"
#include "Menu.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Obstacle.h"
#include "Parallax.h"
#include "iostream"

using namespace std;

Enemy enemy;
Obstacle obstacle;
Player patrol[2];
Player bullet;
Parallax Background[2];
Parallax Midground[2];
Parallax Foreground[2];
Game game;
int framesCounter = 0;

float scrollingBack;
float scrollingSemiBack;
float scrollingMid;
float scrollingFore;

int main()
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 900;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Moon Patrol");

	Texture2D background = LoadTexture("./images/marsmountain.png");
	Texture2D midground = LoadTexture("./images/marsmid.png");
	Texture2D foreground = LoadTexture("./images/marsclose.png");

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










