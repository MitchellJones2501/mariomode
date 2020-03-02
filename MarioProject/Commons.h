#pragma once

struct Vector2D
{
	float X;
	float Y;

	Vector2D()

	{
		X = 0.0f;
		Y = 0.0f;
	}

	Vector2D(float initx, float inity)
	{
		X = initx;
		Y = inity;
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