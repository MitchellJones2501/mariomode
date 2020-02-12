#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenLevel1::~GameScreenLevel1()
{
	Texture2D* gTexture = NULL;
	delete gTexture;
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}

void GameScreenLevel1::Render()
{
	mBackgroundTexture->Render(Vector2D(0,0), SDL_FLIP_NONE);	
}
bool GameScreenLevel1::SetUpLevel()
{
	//load the background texture
	if (!mBackgroundTexture->LoadFromFile("Images/Test.bmp"))
	{
		cout << "Failed to load background texture!";
		return false;
	}
		return true;
}
