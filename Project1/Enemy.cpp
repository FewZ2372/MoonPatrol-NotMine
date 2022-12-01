#pragma once

#include "Enemy.h"


void setEnemy()
{
	enemy.rec.x = -100;
	enemy.rec.y = GetScreenHeight() / 2 - 200;
	enemy.rec.width = 30.0f;
	enemy.rec.height = 30.0f;
}

void enemyMovement()
{
	enemy.rec.x += 100.0f * GetFrameTime();
	enemy.rec.y -= sin(enemy.rec.x / 8) * GetFrameTime() * 600.0f;

	if (enemy.rec.x > GetScreenWidth())
	{
		setEnemy();
	}
}

