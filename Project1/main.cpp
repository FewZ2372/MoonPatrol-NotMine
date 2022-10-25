#include"raylib.h"
#include"iostream"

using namespace std;
const float SCREEN_WIDHT = 1000;
const float SCREEN_HEIGHT = 800;
int main()
{
	InitWindow((int)(SCREEN_HEIGHT),(int)(SCREEN_WIDHT) , "Moon Patrol");

	Rectangle caja={ (float)((GetScreenHeight())) /(float) 2,(float)((GetScreenWidth())) /(float) 2, 20, 20 };
	while (!WindowShouldClose)
	{
		DrawRectangle((int)((GetScreenWidth())) / (float)2, (int)((GetScreenHeight())) / (float)2, 20, 20, RED);

	}
}