#pragma once
#include "raylib.h"

#include "Menu.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Obstacle.h"
#include "Parallax.h"

#include <iostream>

Enemy enemy;
Obstacle obstacle;
Player bullet;
Player patrol[2];
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
	startGame();
}










