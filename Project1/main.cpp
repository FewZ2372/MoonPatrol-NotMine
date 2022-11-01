#include"raylib.h"
#include"iostream"

using namespace std;
const int SCREEN_WIDHT = 1000;
const int SCREEN_HEIGHT = 800;

int centerScreenX;
int centerScreenY;
int screenX;

bool gameOver;


Rectangle obstaculo_box;
Rectangle caja;
void Input();
void Update();
void Draw();

int main()
{
	InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, "Moon Patrol");
	centerScreenX = GetScreenWidth() / 2;
	centerScreenY = GetScreenHeight() / 2;
	 screenX = GetScreenWidth() - 10;

	gameOver = false;
	

	
	
	obstaculo_box = { static_cast<float>(screenX),static_cast<float>(centerScreenY+5), 15.0f, 15.0f };

	caja= { static_cast<float>(centerScreenX),
					  static_cast<float>(centerScreenY),
					  20.0f,
					  20.0f };

	while (!WindowShouldClose()&&!gameOver)
	{

		Input();
		Update();
		Draw();

		
		
	}

	CloseWindow();
	return 0;
}
 
void Input()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		caja.y -= 50;
	}
	else if(IsKeyReleased(KEY_SPACE))
	{
		caja.y += 50;
	}
}
void Update()
{
	obstaculo_box.x -= 1;

	if (obstaculo_box.x < 0)
	{
		obstaculo_box.x = static_cast<float>(screenX);
	}

	if (CheckCollisionRecs(Rectangle(caja), Rectangle(obstaculo_box)))
	{

		gameOver = true;
		cout << "colision" << endl;

	}
}
void Draw() 
{
	BeginDrawing();
	DrawRectangle(static_cast<int>(obstaculo_box.x), static_cast<int>(obstaculo_box.y), static_cast<int> (obstaculo_box.width), static_cast<int> (obstaculo_box.height), WHITE);
	
	
		DrawRectangle(static_cast<int>(caja.x), static_cast<int>(caja.y), static_cast<int>(caja.width), static_cast<int>(caja.height), RED);
	

	

	ClearBackground(BLACK);
	EndDrawing();
}