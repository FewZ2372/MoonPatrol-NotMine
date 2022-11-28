#pragma once
#include "raylib.h"
#include "Menu.h"
#include "Enemy.h"


struct Parallax
{
	Rectangle rec;
};

extern Parallax Background[2];
extern Parallax Midground[2];
extern Parallax Foreground[2];

extern float scrollingBack; //marsmountain
extern float scrollingMid;//marsmid
extern float scrollingFore;//marsclose

void setParallax();
void moveParallax();
void drawParallax(Texture2D& background, Texture2D& midground, Texture2D& foreground);
