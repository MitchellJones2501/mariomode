#pragma once
#include <SDL.h>
#include "Commons.h"
#include "GameScreenManager.h"
#include "GameScreenLevel1.h"
#include "GameScreen.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
    mRenderer = renderer;
    mCurrentScreen = NULL;
    ChangeScreen(startScreen);
}

GameScreenManager::~GameScreenManager()
{
    mRenderer = NULL;
    delete mCurrentScreen;
    mCurrentScreen = NULL;
}

void GameScreenManager::Render()
{
    mCurrentScreen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
    mCurrentScreen->Update(deltaTime, e);
}

void GameScreenManager::ChangeScreen(SCREENS newScreen)
{
    //Clear up the old screen
    if (mCurrentScreen != NULL)
    {
        delete mCurrentScreen;
    }

    GameScreenLevel1* tempScreen;

    switch (newScreen)
    {
    case SCREEN_INTRO:
        break;
    case SCREEN_MENU:
        break;
    case SCREEN_LEVEL1:
        tempScreen = new GameScreenLevel1(mRenderer);
        mCurrentScreen = (GameScreen*)tempScreen;
        tempScreen = NULL;
        break;
    case SCREEN_LEVEL2:
        break;
    case SCREEN_GAMEOVER:
        break;
    case SCREEN_HIGHSCORES:
        break;
    default:
        break;
    }
}