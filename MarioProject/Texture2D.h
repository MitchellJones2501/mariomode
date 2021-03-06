#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

#include "SDL.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include "Commons.h"

using namespace::std;

class Texture2D
{
public:
	Texture2D(SDL_Renderer* renderer);
	~Texture2D();

	bool LoadFromFile(string path);
	void Free();
	void Render(Vector2D newPosition, SDL_RendererFlip flip, double angle = 0.0f);

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
private:
	SDL_Renderer* mRenderer = NULL;
	SDL_Texture* mTexture = NULL;

	int mWidth;
	int mHeight;
};
#endif _TEXTIRE2D_H