#include "Character.h"
#include <iostream>
#include "Texture2D.h"
#include "Commons.h"


Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition)
{
	mRenderer = renderer;
	mTexture = new Texture2D(renderer);


}

Character::~Character()
{
	mRenderer = NULL;
}

void Character::Render()
{
	mTexture->Render(Vector2D(0, 0), SDL_FLIP_NONE);
}

void Character::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		case SDLK_LEFT:
			mPosition.X -= 1;
			break;

		case SDLK_RIGHT:
			mPosition.X =+ 1;
			break;
	}
}

void Character::SetPosition(Vector2D newPosition)
{
	mPosition = newPosition;
}

Vector2D Character::GetPosition()
{
	return mPosition;
}