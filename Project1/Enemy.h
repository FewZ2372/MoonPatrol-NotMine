#pragma once
#include "raylib.h"
#include "raymath.h"

struct Enemy
{
	Rectangle rec;
};

extern Enemy enemy;

void setEnemy();
void enemyMovement();
void moveObstacle();
