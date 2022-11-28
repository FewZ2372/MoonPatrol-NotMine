#include "Menu.h"


void Menu(int& screen, Texture2D& background, Texture2D& midground, Texture2D& foreground, bool& pause, bool& resetPause)
{
	Rectangle gameButton = { static_cast<int>(GetScreenWidth()) / static_cast <float>(2) - 150, static_cast<int>(GetScreenHeight()) / static_cast <float>(2) - 90, 250, 100 };
	Rectangle exitButton = { static_cast<int>(GetScreenWidth()) / static_cast <float>(2) - 150, static_cast<int>(GetScreenHeight()) / static_cast <float>(2) + 160, 250, 100 };
	Rectangle creditsButton = { static_cast<int>(GetScreenWidth()) / static_cast <float>(2) - 150, static_cast<int>(GetScreenHeight()) / static_cast <float>(2) + 35, 250, 100 };

	switch (screen)
	{
	case MENU:

		setBullet();
		setPlayer();
		setParallax();
		setEnemy();
		setObstacle();
		DrawMenu(gameButton, creditsButton, exitButton);
		TextMenu();
		ExitGame(exitButton, screen);
		runGame(gameButton, screen);
		Credits(creditsButton, screen);
		break;

	case GAME:

		if (!game.gameOver)
		{
			if (!game.pause)
			{
				Update(screen, game.gameOver, background, midground, foreground);
				DrawGame(screen, background, midground, foreground);
			}
		}

		break;

	case CREDITS:

		DrawCredits(screen);

		break;
	case PAUSE:

		Pause(pause, screen, resetPause);

		break;
	case EXIT:

		game.exitGame = true;

		break;


	default:

		CloseWindow();
		break;
	}
}

void Credits(Rectangle credits, int& screen)
{
	if (CheckCollisionPointRec(GetMousePosition(), credits))
	{
		DrawRectangleRec(credits, VIOLET);
		DrawText("CREDITOS", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 70, 30, WHITE);
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawRectangleRec(credits, DARKPURPLE);
			DrawText("CREDITOS", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 70, 30, WHITE);
			screen = CREDITS;
		}
	}
}

void TextMenu()
{
	DrawText("MOON PATROL", GetScreenWidth() / 2 - 290, 100, 100, WHITE);
	DrawText("SALIR", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 + 200, 30, WHITE);
	DrawText("CREDITOS", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 70, 30, WHITE);
	DrawText("JUGAR", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 - 50, 30, WHITE);
	DrawText("V 1.0", 1170, 850, 50, WHITE);

}

void DrawMenu(Rectangle game, Rectangle credits, Rectangle instruction)
{
	DrawRectangleRec(game, PURPLE);
	DrawRectangleRec(credits, PURPLE);
	DrawRectangleRec(instruction, PURPLE);
}

void DrawGame(int& screen, Texture2D& background, Texture2D& midground, Texture2D& foreground)
{
	DrawText(TextFormat("LIVES: " "%i", patrol[0].lives), 5, 2, 20, WHITE);//LIVES DRAWING
	DrawText(TextFormat("POINTS: " "%i", patrol[0].points), 5, 20, 20, WHITE);//POINTS DRAWING
	DrawRectangleRec(patrol[0].rec, BLUE);//CAR DRAWING
	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING
	DrawRectangleRec(enemy.rec, GREEN);//ENEMY DRAWING

	if (bullet.bulletActive == true)
	{
		DrawRectangle(static_cast<int>(bullet.rec.x),
			static_cast<int>(bullet.rec.y),
			static_cast<int>(bullet.rec.width),
			static_cast<int>(bullet.rec.height),
			WHITE);
	}

}

void DrawCredits(int& screen)
{
	Rectangle regresarMenu = { static_cast<int>(GetScreenWidth()) - 980.0f, static_cast<int>(GetScreenHeight()) - 135.0f,250, 100 };

	/*DrawText("CREDITOS:", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 350, 30, WHITE);
	DrawText("SONIDO METEORO Robinhood76 ", 0, GetScreenHeight() / 2 - 200, 20, WHITE);
	DrawText("PAGINA PRINCIPAL:", 0, GetScreenHeight() / 2 - 150, 20, WHITE);
	DrawText("https://freesound.org/people/Robinhood76/", 0, GetScreenHeight() / 2 - 100, 20, WHITE);
	DrawText("PAGINA DEL SONIDO DESCARGADO:", 0, GetScreenHeight() / 2 - 50, 20, WHITE);
	DrawText(" https://freesound.org/people/Robinhood76/sounds/503554/", 0, GetScreenHeight() / 2 - 20, 20, WHITE);
	DrawText("MUSICA: StephieQueen", 0, GetScreenHeight() / 2, 20, WHITE);
	DrawText("PAGINA PRINCIPAL:", 0, GetScreenHeight() / 2 + 20, 20, WHITE);
	DrawText("https://freesound.org/people/StephieQueen/", 0, GetScreenHeight() / 2 + 50, 20, WHITE);
	DrawText("PAGINA DE LA MUSICA: ", 0, GetScreenHeight() / 2 + 80, 20, WHITE);
	DrawText(" https://freesound.org/people/StephieQueen/sounds/650556/", 0, GetScreenHeight() / 2 + 100, 20, WHITE);
	DrawText("ASSETS:https://kenney.nl/assets/space-shooter-redux", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 150, 20, WHITE);*/
	DrawText("CODIGO: LEONARDO BRIZUELA y FELIPE BERAZAIN", GetScreenWidth() / 2 - MeasureText("CODIGO: LEONARDO BRIZUELA y FELIPE BERAZAIN", 20) / 2, GetScreenHeight() / 2 + 250, 20, WHITE);

	DrawRectangleRec(regresarMenu, PURPLE);
	DrawText("VOLVER AL MENU", GetScreenWidth() - 970, GetScreenHeight() - 100, 26, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), regresarMenu))
	{
		DrawRectangleRec(regresarMenu, VIOLET);
		DrawText("VOLVER AL MENU", GetScreenWidth() - 970, GetScreenHeight() - 100, 26, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			DrawRectangleRec(regresarMenu, DARKPURPLE);
			DrawText("VOLVER AL MENU", GetScreenWidth() - 970, GetScreenHeight() - 100, 26, WHITE);

			screen = MENU;

		}

	}
}

void Pause(bool& pause, int& screen, bool& resetPause)
{
	Rectangle volverMenu = { static_cast<int>(GetScreenWidth()) / static_cast <float>(2) + 100, static_cast<int>(GetScreenHeight()) / static_cast <float>(2) - 90,250, 100 };

	DrawRectangleRec(volverMenu, PURPLE);
	DrawText("VOLVER AL MENU", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 - 50, 26, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), volverMenu))
	{

		DrawRectangleRec(volverMenu, VIOLET);
		DrawText("VOLVER AL MENU", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 - 50, 26, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			DrawRectangleRec(volverMenu, DARKPURPLE);
			DrawText("VOLVER AL MENU", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 - 50, 26, WHITE);

			screen = MENU;
			resetPause = !resetPause;
		}

	}

}