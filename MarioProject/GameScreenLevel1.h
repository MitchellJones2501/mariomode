#pragma once

#include "SDL.h"
#include "Commons.h"
#include "GameScreen.h"
#include "Texture2D.h"

class Texture2D;

class GameScreenLevel1 : GameScreen
{
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render();
	void Update(float deltaTime, SDL_Event e);
	bool SetUpLevel();
private:
	Texture2D* mBackgroundTexture;

};
