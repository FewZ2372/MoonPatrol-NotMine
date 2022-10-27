#include"raylib.h"
#include"iostream"

using namespace std;
const float SCREEN_WIDHT = 1000;
const float SCREEN_HEIGHT = 800;
struct OBSTACULO
{
	int x;
	int y;	
	

};

int main()
{
	InitWindow(static_cast<int>(SCREEN_HEIGHT), static_cast<int>(SCREEN_WIDHT), "Moon Patrol");

	int centerScreenX = GetScreenWidth() / 2;
	int centerScreenY = GetScreenHeight() / 2;
	int screenX = GetScreenWidth()-10 ;

	bool gameOver = false;

	OBSTACULO obstaculo;
	obstaculo.x = screenX;
	obstaculo.y = centerScreenY+5;
	Rectangle obstaculo_box = { static_cast<float>(obstaculo.x),static_cast<float>(obstaculo.y), 15.0f, 15.0f };

	Rectangle caja= { static_cast<float>(centerScreenX), 
					  static_cast<float>(centerScreenY),
					  20.0f, 
					  20.0f };

	while (!WindowShouldClose()&&!gameOver)
	{
		obstaculo.x -= 1;

		if (obstaculo.x < 0)
		{
			obstaculo.x = screenX;
			

		}
		BeginDrawing();
		DrawRectangle(obstaculo.x, obstaculo.y, 15, 15, WHITE);
		if (IsKeyDown(KEY_SPACE))
		{
			DrawRectangle(centerScreenX,centerScreenY-40, 20, 20, WHITE);
			

		}
		else
		{
			DrawRectangle(static_cast<int>(GetScreenWidth()) / (2), static_cast<int>(GetScreenHeight()) / (2), 20, 20, RED);
		}

		if (CheckCollisionRecs(Rectangle(caja),Rectangle(obstaculo_box)))
		{

			gameOver =true;

		}

		ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}