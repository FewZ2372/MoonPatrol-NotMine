#pragma once

#include "Parallax.h"

void setParallax()
{
	Background[0].rec.x = 0;
	Background[0].rec.y = 0;
	Background[0].rec.width = 1280;
	Background[0].rec.height = 720;

	Background[1].rec.x = Background[0].rec.width;
	Background[1].rec.y = 0;
	Background[1].rec.width = 1280;
	Background[1].rec.height = 720;

	Midground[0].rec.x = 0;
	Midground[0].rec.y = 0;
	Midground[0].rec.width = 1280;
	Midground[0].rec.height = 720;

	Midground[1].rec.x = Midground[0].rec.width;
	Midground[1].rec.y = 0;
	Midground[1].rec.width = 1280;
	Midground[1].rec.height = 720;

	Foreground[0].rec.x = 0;
	Foreground[0].rec.y = 0;
	Foreground[0].rec.width = 1280;
	Foreground[0].rec.height = 900;

	Foreground[1].rec.x = Foreground[0].rec.width;
	Foreground[1].rec.y = 0;
	Foreground[1].rec.width = 1280;
	Foreground[1].rec.height = 900;


	scrollingBack = 50;
	scrollingMid = 100;
	scrollingFore = 200;
}

void moveParallax()
{
	Background[0].rec.x -= scrollingBack * GetFrameTime();
	Background[1].rec.x -= scrollingBack * GetFrameTime();

	Midground[0].rec.x -= scrollingMid * GetFrameTime();
	Midground[1].rec.x -= scrollingMid * GetFrameTime();

	Foreground[0].rec.x -= scrollingFore * GetFrameTime();
	Foreground[1].rec.x -= scrollingFore * GetFrameTime();

	if (Background[0].rec.x + Background[0].rec.width < 0)
	{
		Background[0].rec.x = GetScreenWidth();
	}
	if (Background[1].rec.x + Background[1].rec.width < 0)
	{
		Background[1].rec.x = GetScreenWidth();
	}

	if (Midground[0].rec.x + Midground[0].rec.width < 0)
	{
		Midground[0].rec.x = GetScreenWidth();
	}
	if (Midground[1].rec.x + Midground[1].rec.width < 0)
	{
		Midground[1].rec.x = GetScreenWidth();
	}

	if (Foreground[0].rec.x + Foreground[0].rec.width < 0)
	{
		Foreground[0].rec.x = GetScreenWidth();
	}
	if (Foreground[1].rec.x + Foreground[1].rec.width < 0)
	{
		Foreground[1].rec.x = GetScreenWidth();
	}
}

void drawParallax(Texture2D& background, Texture2D& midground, Texture2D& foreground)
{

	DrawTexture(background, Background[0].rec.x, Background[0].rec.y, WHITE);
	DrawTexture(background, Background[1].rec.x, Background[1].rec.y, WHITE);

	DrawTexture(midground, Midground[0].rec.x, Midground[0].rec.y, WHITE);
	DrawTexture(midground, Midground[1].rec.x, Midground[1].rec.y, WHITE);

	DrawTexture(foreground, Foreground[0].rec.x, Foreground[0].rec.y, WHITE);
	DrawTexture(foreground, Foreground[1].rec.x, Foreground[1].rec.y, WHITE);

}

