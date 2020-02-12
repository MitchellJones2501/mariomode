#pragma once
#include "SDL.h"
#include "Commons.h"

class GameScreenManager
{
private:
	SDL_Renderer* mRenderer;
	GameScreenManager* mCurrentScreen;

public:
	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS newScreen);
};
