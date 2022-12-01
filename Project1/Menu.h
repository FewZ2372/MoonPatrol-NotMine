#pragma once
#include "raylib.h"
#include "Game.h"


enum  SCREENS
{
	MENU,
	GAME,
	CREDITS,
	PAUSE,
	EXIT
};

void DrawGame(int& screen, Texture2D& background, Texture2D& midground, Texture2D& foreground);
void DrawCredits(int& screen);
void TextMenu();
void Menu(int& screen, Texture2D& background, Texture2D& midground, Texture2D& foreground, bool& pause, bool& resetPause);
void DrawMenu(Rectangle game, Rectangle credits, Rectangle instruction);
void DrawCreditsButton(Rectangle credits, int& screen);
void Pause(bool& pause, int& screen, bool& resetPause);
void DrawPlayButton(Rectangle game, int& screen);
void DrawQuitButton(Rectangle exit, int& screen);
void Draw2PlayersCheckbox(Rectangle checkBox, Rectangle checkBoxOn, int& screen);


