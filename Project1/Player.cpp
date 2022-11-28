#include "Player.h"

void setPlayer()
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

void setBullet()
{
	bullet.rec.x = patrol[0].rec.x;
	bullet.rec.y = patrol[0].rec.y;
	bullet.rec.width = 5;
	bullet.rec.height = 5;
	bullet.bulletActive = false;
}

void playerInput()
{
	if (IsKeyDown(KEY_SPACE) && !patrol[0].isJumping)
	{
		patrol[0].speed.y = -600;
		patrol[0].isJumping = true;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		patrol[0].speed.x = -200;

	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		patrol[0].speed.x = 200;

	}
	else if (!patrol[0].isJumping)
	{
		patrol[0].speed.x = 0;
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
}

void loseCondition(int& screen)
{
	if (patrol[0].lives <= 0 && patrol[0].canCollide == true)
	{
		screen = SCREENS::MENU;
	}
}

void bulletMovement()
{
	if (bullet.bulletActive == true)
	{
		bullet.rec.y -= 400 * GetFrameTime();
	}
	else if (bullet.bulletActive == false)
	{
		bullet.rec.x = patrol[0].rec.x;
		bullet.rec.y = patrol[0].rec.y;

	}

	if (bullet.rec.y <= 0)
	{

		bullet.bulletActive = false;
		bullet.rec.x = patrol[0].rec.x;
		bullet.rec.y = patrol[0].rec.y;
	}
}