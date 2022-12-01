#pragma once
#include "raylib.h"


struct Obstacle
{
	Rectangle rec;
};

extern Obstacle obstacle;
void setObstacle();
