#pragma once
#include "raylib.h"
#include "Menu.h"
#include "Player.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "Parallax.h"


struct Game
{
	bool pause;
	bool resetPause;
	bool exitGame;
	bool gameOver;
	bool stillPlaying;
	bool twoPlayersActive;
};

extern Game game;
extern int framesCounter;

void setGame();
void Update(int& screen, bool& gameOver, Texture2D& background, Texture2D& midground, Texture2D& foreground);
void hasCollided();
void checkCollisionBullet();
void startGame();


