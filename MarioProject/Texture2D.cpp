#include "Texture2D.h"

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	mRenderer = renderer;
}
Texture2D::~Texture2D()
{

}

bool Texture2D::LoadFromFile(string path)
{
	
	//Remove any memory used for previous texture
	Free();
	mTexture = NULL;

	//Load the image
	SDL_Surface* pSurface = IMG_Load(path.c_str());
	

	if (pSurface != NULL)
	{
		mWidth = pSurface->w;
		mHeight = pSurface->h;
		mTexture = SDL_CreateTextureFromSurface(mRenderer, pSurface);
		if (mTexture == NULL)
		{
			cout << "unable to create texture from surface. Error " << SDL_GetError() << endl;
			
		}
		//Colour key the image = The colour to be transparent.
		SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0xFF, 0xFF));
		SDL_FreeSurface(pSurface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError() << endl;
	}
	
	return mTexture != NULL;
}

void Texture2D::Free()
{
	//Free();
	//mRenderer = NULL;

	//Check 
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}

void Texture2D::Render(Vector2D newPosition, SDL_RendererFlip flip, double angle)
{
	
		//Clear the screen.
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mRenderer);

		//Set where to render texture
		SDL_Rect renderLocation = { 0, 0, mWidth, mHeight };

		//Render to screen 
		SDL_RenderCopyEx(mRenderer, mTexture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

		//Update the screen
		SDL_RenderPresent(mRenderer);
}