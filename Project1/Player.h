#pragma once
#include "raylib.h"
#include "Menu.h"


struct Player
{
	Rectangle rec;

	Vector2 speed;

	bool isJumping;
	bool bulletActive;
	bool canCollide;

	int points;
	int lives;
};
extern Player patrol[2];
extern Player bullet;

void setPlayer1();
void setPlayer2();
void setBullet();
void setBulletP2();
void playerInput();
void playerMovement();
void hasCollided();
void loseCondition(int& screen);
void bulletMovement();

