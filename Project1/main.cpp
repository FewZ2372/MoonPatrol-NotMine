#include"raylib.h"
#include"iostream"

using namespace std;
const int SCREEN_WIDHT = 1280;
const int SCREEN_HEIGHT = 900;

int centerScreenX;
int centerScreenY;
int screenX;

bool gameOver;

float scrollingBack = 0.0f;
float scrollingSemiBack = 0.0f;
float scrollingMid = 0.0f;
float scrollingFore = 0.0f;

Rectangle obstaculo_box;
Rectangle caja;
void Input();
void Update();
void Draw();

//Texture2D background = LoadTexture(" marsmountain.png");
//Texture2D semibackground = LoadTexture(" marsfar.png");
//Texture2D midground = LoadTexture(" marsmid.png");
//Texture2D foreground = LoadTexture(" marsclose.png");

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

	SetTargetFPS(60);

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
	obstaculo_box.x -= 8;

	if (obstaculo_box.x < 0)
	{
		obstaculo_box.x = static_cast<float>(screenX);
	}

	

	if (CheckCollisionRecs(Rectangle(caja), Rectangle(obstaculo_box)))
	{

		gameOver = true;
	

	}
}
void Draw()
{
	/*scrollingBack -= 0.1f;
	scrollingSemiBack -= 0.25f;
	scrollingMid -= 0.5f;
	scrollingFore -= 1.0f;



	if (scrollingBack <= -background.width * 2) scrollingBack = 0;
	if (scrollingMid <= -semibackground.width * 2) scrollingMid = 0;
	if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
	if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;*/

	BeginDrawing();


	/*DrawTextureEx(background, (Vector2) { scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(background, (Vector2) { bakground.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(semibackground, (Vector2) { scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(semibackground, (Vector2){ semibackground.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

	
	DrawTextureEx(midground, (Vector2) { scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(midground, (Vector2) { midground.width * 2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

	
	DrawTextureEx(foreground, (Vector2) { scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(foreground, (Vector2) { foreground.width * 2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);*/

	DrawRectangle(static_cast<int>(obstaculo_box.x), static_cast<int>(obstaculo_box.y), static_cast<int> (obstaculo_box.width), static_cast<int> (obstaculo_box.height), WHITE);
	
		DrawRectangle(static_cast<int>(caja.x), static_cast<int>(caja.y), static_cast<int>(caja.width), static_cast<int>(caja.height), RED);
	

	ClearBackground(BLACK);
	EndDrawing();
}