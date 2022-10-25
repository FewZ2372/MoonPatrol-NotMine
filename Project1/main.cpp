#include"raylib.h"
#include"iostream"

using namespace std;
const float SCREEN_WIDHT = 1000;
const float SCREEN_HEIGHT = 800;

int main()
{
	InitWindow(static_cast<int>(SCREEN_HEIGHT), static_cast<int>(SCREEN_WIDHT), "Moon Patrol");

	int centerScreenX = GetScreenWidth() / 2;
	int centerScreenY = GetScreenHeight() / 2;

	Rectangle caja= { static_cast<float>(centerScreenX), 
					  static_cast<float>(centerScreenY),
					  20.0f, 
					  20.0f };

	while (!WindowShouldClose())
	{

		BeginDrawing();

		if (IsKeyDown(KEY_SPACE))
		{
			DrawRectangle(static_cast<int>(GetScreenWidth()) / (2), static_cast<int>(GetScreenHeight()) / (2)-40, 20, 20, WHITE);

		}
		else
		{
			DrawRectangle(static_cast<int>(GetScreenWidth()) / (2), static_cast<int>(GetScreenHeight()) / (2), 20, 20, RED);
		}

		ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}