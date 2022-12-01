#pragma once

#include "Player.h"


void setPlayer1()
{
	patrol[0].rec.x = GetScreenWidth() / 4 * 1;
	patrol[0].rec.y = GetScreenHeight() / 2 + 5;
	patrol[0].rec.width = 50;
	patrol[0].rec.height = 25;
	patrol[0].speed.x = 200;
	patrol[0].speed.y = 200;
	patrol[0].isJumping = false;
	patrol[0].canCollide = true;
	patrol[0].lives = 4;
}

void setPlayer2()
{
	patrol[1].rec.x = GetScreenWidth() / 4 * 2;
	patrol[1].rec.y = GetScreenHeight() / 2 + 5;
	patrol[1].rec.width = 50;
	patrol[1].rec.height = 25;
	patrol[1].speed.x = 200;
	patrol[1].speed.y = 200;
	patrol[1].isJumping = false;
	patrol[1].canCollide = true;
	patrol[1].lives = 4;
}

void setBullet()
{
	bullet.rec.x = patrol[0].rec.x;
	bullet.rec.y = patrol[0].rec.y;
	bullet.rec.width = 5;
	bullet.rec.height = 5;
	bullet.bulletActive = false;
}
void setBulletP2()
{
	if (game.twoPlayersActive)
	{
		bullet.rec.x = patrol[1].rec.x;
		bullet.rec.y = patrol[1].rec.y;
		bullet.rec.width = 5;
		bullet.rec.height = 5;
		bullet.bulletActive = false;
	}
}

void playerInput()
{
	if (IsKeyDown(KEY_W) && !patrol[0].isJumping)
	{
		patrol[0].speed.y = -600;
		patrol[0].isJumping = true;
	}
	if (IsKeyDown(KEY_A))
	{
		patrol[0].speed.x = -200;

	}
	else if (IsKeyDown(KEY_D))
	{
		patrol[0].speed.x = 200;

	}
	else if (!patrol[0].isJumping)
	{
		patrol[0].speed.x = 0;
	}

	if (game.twoPlayersActive)
	{
		if (IsKeyDown(KEY_UP) && !patrol[1].isJumping)
		{
			patrol[1].speed.y = -600;
			patrol[1].isJumping = true;
		}
		if (IsKeyDown(KEY_LEFT))
		{
			patrol[1].speed.x = -200;

		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			patrol[1].speed.x = 200;

		}
		else if (!patrol[1].isJumping)
		{
			patrol[1].speed.x = 0;
		}
	}
}

void playerMovement()
{
	patrol[0].rec.x += patrol[0].speed.x * GetFrameTime();
	patrol[0].rec.y += patrol[0].speed.y * GetFrameTime();

	if (patrol[0].isJumping)
	{
		patrol[0].speed.y += 1500 * GetFrameTime();
	}

	if (patrol[0].rec.y > GetScreenHeight() / 2 + 5)
	{
		patrol[0].speed.y = 0;
		patrol[0].isJumping = false;
	}

	if (patrol[0].rec.x < 0)
	{
		patrol[0].rec.x = 0;
	}
	if (patrol[0].rec.x > GetScreenWidth() - patrol[0].rec.width)
	{
		patrol[0].rec.x = GetScreenWidth() - patrol[0].rec.width;
	}

	if (game.twoPlayersActive)
	{
		patrol[1].rec.x += patrol[1].speed.x * GetFrameTime();
		patrol[1].rec.y += patrol[1].speed.y * GetFrameTime();

		if (patrol[1].isJumping)
		{
			patrol[1].speed.y += 1500 * GetFrameTime();
		}
		if (patrol[1].rec.y > GetScreenHeight() / 2 + 5)
		{
			patrol[1].speed.y = 0;
			patrol[1].isJumping = false;
		}

		if (patrol[1].rec.x < 0)
		{
			patrol[1].rec.x = 0;
		}
		if (patrol[1].rec.x > GetScreenWidth() - patrol[1].rec.width)
		{
			patrol[1].rec.x = GetScreenWidth() - patrol[1].rec.width;
		}
	}

}

void loseCondition(int& screen)
{
	if (patrol[0].lives <= 0 && patrol[0].canCollide == true)
	{
		screen = SCREENS::MENU;
	}

	if (bullet.bulletActive)
	{
		if (patrol[1].lives <= 0 && patrol[1].canCollide == true)
		{
			screen = SCREENS::MENU;
		}
	}
}

void bulletMovement()
{
	if (game.twoPlayersActive)
	{
		if (IsKeyPressed(KEY_E))
		{
			bullet.bulletActive = true;
		}
		if (bullet.bulletActive == true)
		{
			bullet.rec.y -= 400 * GetFrameTime();
		}
		else if (bullet.bulletActive == false)
		{
			bullet.rec.x = patrol[1].rec.x + patrol[1].rec.width / 2;
			bullet.rec.y = patrol[1].rec.y;
		}

		if (bullet.rec.y <= 0)
		{
			bullet.bulletActive = false;
			bullet.rec.x = patrol[1].rec.x;
			bullet.rec.y = patrol[1].rec.y;
		}
	}
	if (IsKeyPressed(KEY_ENTER))
	{
		bullet.bulletActive = true;
	}

	if (bullet.bulletActive == true)
	{
		bullet.rec.y -= 400 * GetFrameTime();
	}
	else if (bullet.bulletActive == false)
	{
		bullet.rec.x = patrol[0].rec.x + patrol[0].rec.width / 2;
		bullet.rec.y = patrol[0].rec.y;

	}

	if (bullet.rec.y <= 0)
	{

		bullet.bulletActive = false;
		bullet.rec.x = patrol[0].rec.x;
		bullet.rec.y = patrol[0].rec.y;
	}



}