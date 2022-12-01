#pragma once

#include "Menu.h"

void Menu(int& screen, Texture2D& background, Texture2D& midground, Texture2D& foreground, bool& pause, bool& resetPause)
{
	Rectangle gameButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 90, 250, 100 };
	Rectangle exitButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 160, 250, 100 };
	Rectangle creditsButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 35, 250, 100 };
	Rectangle checkBox = { GetScreenWidth() / 5 * 2 ,  GetScreenHeight() / 8 * 2 + 35 , 41, 40 };
	Rectangle checkBoxOn = { GetScreenWidth() / 5 * 2 + 3 ,  GetScreenHeight() / 8 * 2 + 38 , 35, 35 };

	switch (screen)
	{
	case MENU:

		setPlayer1();
		setPlayer2();
		setBullet();
		setBulletP2();
		setParallax();
		setEnemy();
		setObstacle();
		DrawMenu(gameButton, creditsButton, exitButton);
		TextMenu();
		DrawQuitButton(exitButton, screen);
		DrawPlayButton(gameButton, screen);
		DrawCreditsButton(creditsButton, screen);
		Draw2PlayersCheckbox(checkBox, checkBoxOn, screen);

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

void DrawCreditsButton(Rectangle credits, int& screen)
{
	if (CheckCollisionPointRec(GetMousePosition(), credits))
	{
		DrawRectangleRec(credits, VIOLET);
		DrawText("CREDITS", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 70, 30, WHITE);
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawRectangleRec(credits, DARKPURPLE);
			DrawText("CREDITS", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 70, 30, WHITE);
			screen = CREDITS;
		}
	}
}

void Draw2PlayersCheckbox(Rectangle checkBox, Rectangle checkBoxOn, int& screen)
{
	DrawRectangleRec(checkBox, WHITE);
	DrawText("Right click on the check box to turn off", GetScreenWidth() / 5 * 2 + 60, GetScreenHeight() / 8 * 2 + 47, 15, WHITE);

	if (game.twoPlayersActive)
	{
		DrawRectangleRec(checkBoxOn, GREEN);
	}

	if (CheckCollisionPointRec(GetMousePosition(), checkBox))
	{
		DrawRectangleRec(checkBoxOn, GREEN);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !game.twoPlayersActive)
		{
			game.twoPlayersActive = true;
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && game.twoPlayersActive)
		{
			game.twoPlayersActive = false;
		}
	}
}


void DrawQuitButton(Rectangle exit, int& screen)
{
	if (CheckCollisionPointRec(GetMousePosition(), exit))
	{
		DrawRectangleRec(exit, VIOLET);
		DrawText("QUIT", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 + 200, 30, WHITE);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawRectangleRec(exit, DARKPURPLE);
			DrawText("QUIT", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 + 200, 30, WHITE);
			screen = EXIT;
		}
	}
}

void DrawPlayButton(Rectangle game, int& screen)
{
	if (CheckCollisionPointRec(GetMousePosition(), game))
	{
		DrawRectangleRec(game, VIOLET);
		DrawText("PLAY", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 - 50, 30, WHITE);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawRectangleRec(game, DARKPURPLE);
			DrawText("PLAY", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 - 50, 30, WHITE);
			screen = GAME;
		}
	}
}

void TextMenu()
{
	DrawText("2 PLAYERS: ", GetScreenWidth() / 4 * 1, GetScreenHeight() / 8 * 2 + 40, 30, WHITE);
	DrawText("MOON PATROL", GetScreenWidth() / 2 - 290, 100, 100, WHITE);
	DrawText("QUIT", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 + 200, 30, WHITE);
	DrawText("CREDITS", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 70, 30, WHITE);
	DrawText("PLAY", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2 - 50, 30, WHITE);
	DrawText("V 1.0", GetScreenWidth() - MeasureText("V 1.0", 50) - 10, GetScreenHeight() - 50, 50, WHITE);
	DrawText("INSTRUCTIONS: ", 5, GetScreenHeight() / 2 - 50, 20, WHITE);
	DrawText("Arrow Keys for P1 .  Shooting with ENTER", 5, GetScreenHeight() / 2 - 30, 15, WHITE);
	DrawText("A, W and D for P2 .  Shooting with E", 5, GetScreenHeight() / 2 - 10, 15, WHITE);

}

void DrawMenu(Rectangle game, Rectangle credits, Rectangle instruction)
{
	DrawRectangleRec(game, PURPLE);
	DrawRectangleRec(credits, PURPLE);
	DrawRectangleRec(instruction, PURPLE);
}

void DrawGame(int& screen, Texture2D& background, Texture2D& midground, Texture2D& foreground)
{
	DrawText(TextFormat("P1 LIVES: " "%i", patrol[0].lives), 5, 2, 20, WHITE);//LIVES DRAWING
	DrawText(TextFormat("POINTS: " "%i", patrol[0].points), 5, 20, 20, WHITE);//POINTS DRAWING

	DrawRectangleRec(enemy.rec, GREEN);//ENEMY DRAWING
	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING
	DrawRectangleRec(patrol[0].rec, BLUE);//CAR 1 DRAWING

	if (game.twoPlayersActive)
	{
		DrawText(TextFormat("P2 LIVES: " "%i", patrol[1].lives), 5, 42, 20, WHITE);//LIVES DRAWING
		DrawText(TextFormat("POINTS: " "%i", patrol[1].points), 5, 62, 20, WHITE);//POINTS DRAWING
		DrawRectangleRec(patrol[1].rec, PINK);//CAR 2 DRAWING
	}

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

	DrawText("CREDITS:", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 350, 30, WHITE);

	DrawText("Texturas:", GetScreenWidth() / 2 - 300, GetScreenHeight() / 5 * 1, 20, WHITE);
	DrawText("https://opengameart.org/content/mars-background-pixel-art", GetScreenWidth() / 2 - 300, GetScreenHeight() / 4 * 1, 20, WHITE);
	DrawText("https://opengameart.org/content/rocky-desert-landscape-layered-looping", GetScreenWidth() / 2 - 300, GetScreenHeight() / 5 * 1.5, 20, WHITE);
	DrawText("CODING: LEONARDO BRIZUELA y FELIPE BERAZAIN", GetScreenWidth() / 2 - MeasureText("CODIGO: LEONARDO BRIZUELA y FELIPE BERAZAIN", 20) / 2 - 35, GetScreenHeight() / 2, 20, WHITE);

	DrawRectangleRec(regresarMenu, PURPLE);
	DrawText("BACK TO MENU", GetScreenWidth() - 960, GetScreenHeight() - 100, 26, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), regresarMenu))
	{
		DrawRectangleRec(regresarMenu, VIOLET);
		DrawText("BACK TO MENU", GetScreenWidth() - 960, GetScreenHeight() - 100, 26, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			DrawRectangleRec(regresarMenu, DARKPURPLE);
			DrawText("BACK TO MENU", GetScreenWidth() - 960, GetScreenHeight() - 100, 26, WHITE);

			screen = MENU;
		}
	}
}

void Pause(bool& pause, int& screen, bool& resetPause)
{
	Rectangle volverMenu = { GetScreenWidth() / 2 - 250 / 2, GetScreenHeight() / 4 * 1, 250, 100 };

	DrawRectangleRec(volverMenu, PURPLE);
	DrawText("BACK TO MENU", GetScreenWidth() / 2 - 100, GetScreenHeight() / 4 * 1 + 35, 26, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), volverMenu))
	{
		DrawRectangleRec(volverMenu, VIOLET);
		DrawText("BACK TO MENU", GetScreenWidth() / 2 - 100, GetScreenHeight() / 4 * 1 + 35, 26, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			DrawRectangleRec(volverMenu, DARKPURPLE);
			DrawText("BACK TO MENU", GetScreenWidth() / 2 - 100, GetScreenHeight() / 4 * 1 + 35, 26, WHITE);
			setPlayer1();
			setPlayer2();
			setBullet();
			setBulletP2();
			setParallax();
			setEnemy();
			setObstacle();
			screen = MENU;
		}
	}
}
