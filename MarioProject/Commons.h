#pragma once

struct Vector2D
{
	float X;
	float Y;

	Vector2D(float x, float y)

	{
		X = x;
		Y = y;
	}
};

enum SCREENS
{
	SCREEN_INTRO = 0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};