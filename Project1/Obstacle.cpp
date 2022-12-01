#pragma once

#include "Obstacle.h"


void setObstacle()
{
	obstacle.rec.x = GetScreenWidth() + 10;
	obstacle.rec.y = GetScreenHeight() / 2 + 10;
	obstacle.rec.width = 15.0f;
	obstacle.rec.height = 15.0f;

}

void moveObstacle()
{
	obstacle.rec.x -= GetFrameTime() * 300;

	if (obstacle.rec.x < GetScreenWidth() * 0 - 700)
	{
		obstacle.rec.x = GetScreenWidth() + obstacle.rec.width;
	}
}

