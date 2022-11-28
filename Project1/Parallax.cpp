#include "Parallax.h"

void setParallax()
{
	for (int i = 0; i < 2; i++)
	{
		Background[i].rec.x = 0;
		Background[i].rec.y = 0;
		Background[i].rec.width = 1280;

		Midground[i].rec.x = 0;
		Midground[i].rec.y = 0;
		Midground[i].rec.width = 1280;

		Foreground[i].rec.x = 0;
		Foreground[i].rec.y = 0;
		Foreground[i].rec.width = 1280;

		Background[i].rec.height = 900;
		Background[i].rec.height = 900;

		Midground[i].rec.height = 720;
		Midground[i].rec.height = 720;

		Foreground[i].rec.height = 720;
		Foreground[i].rec.height = 720;
	}

	scrollingBack = 50;
	scrollingMid = 100;
	scrollingFore = 150;
}

void moveParallax()
{

	Background[0].rec.x -= scrollingBack * GetFrameTime();
	Background[1].rec.x -= scrollingBack * GetFrameTime();

	Midground[0].rec.x -= scrollingMid * GetFrameTime();
	Midground[1].rec.x -= scrollingMid * GetFrameTime();

	Foreground[0].rec.x -= scrollingMid * GetFrameTime();
	Foreground[1].rec.x -= scrollingFore * GetFrameTime();

	//if (Background[0].rec.x <= 0 - Background[0].rec.width)
	//{
	//	Background[0].rec.x = Background[1].rec.width;

	//}
	//if (Background[1].rec.x <= 0 - Background[1].rec.width)
	//{
	//	Background[1].rec.x = Background[0].rec.width;

	//}

	//if (Foreground[0].rec.x <= 0 - Foreground[0].rec.width)
	//{
	//	Foreground[0].rec.x = Foreground[1].rec.width;

	//}
	//if (Foreground[0].rec.x <= 0 - Foreground[1].rec.width)
	//{
	//	Foreground[1].rec.x = Foreground[0].rec.width;

	//}

	//if (Midground[0].rec.x <= 0 - Midground[0].rec.width)
	//{
	//	Midground[0].rec.x = Midground[1].rec.width;

	//}
	//if (Midground[0].rec.x <= 0 - Midground[1].rec.width)
	//{
	//	Midground[1].rec.x = Midground[0].rec.width;

	//}
}

void drawParallax(Texture2D& background, Texture2D& midground, Texture2D& foreground)
{

	DrawTexture(background, Background[0].rec.x, Background[0].rec.y, WHITE);
	DrawTexture(background, Background[0].rec.x + Background[1].rec.width, Background[1].rec.y, WHITE);

	DrawTexture(midground, Midground[0].rec.x, Foreground[0].rec.y, WHITE);
	DrawTexture(midground, Midground[0].rec.x + Midground[1].rec.width, Foreground[1].rec.y, WHITE);
	//DrawTexture(foreground, Foreground[0].rec.x, Foreground[0].rec.y, WHITE);
	//DrawTexture(foreground, Foreground[1].rec.width, Foreground[1].rec.y, WHITE);

}