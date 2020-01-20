#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Constants.h"
#include <iostream>

using namespace::std;

//Globals
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture = NULL;
//Function Prototypes
bool InitSDL();
void CloseSDL();
bool Update();
void Render();
SDL_Texture* LoadTextureFromFile(string path);
void FreeTexture();

int main(int argc, char* args[])
{
	if (InitSDL())
	{
		//Flag to check if we wish to quit.
		bool quit = false;

		//Game Loop.
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}

	//Close Window and free resources 
	CloseSDL();

	return 0;
}

bool InitSDL() 
{
	//Setup SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		//All good, so attemp to create the window.
		gWindow = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);

		//Did the window get created?
		if (gWindow == NULL)
		{
			//Nope.
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
		//Image render stuff haha im jeff
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer != NULL)
		{
			//Initialise PNG Loading.
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_Image could not intialise. Error: " << IMG_GetError();
				return false;
			}//Load background texture
			gTexture = LoadTextureFromFile("images/test.bmp");
			if (gTexture == NULL)
			{
				return false;
			}
			
			
			
		}
		else
		{
			cout << "Renderer could not intialise. Error: " << SDL_GetError();
			return false;
		}
		return true;
	}
	
}

void FreeTexture()
{
	//Check 
	if (gTexture != NULL)
	{
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
	}
}

void CloseSDL() 
{
	//CLear up the the texture
	FreeTexture();

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	//Release the window.
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems.
	IMG_Quit();
	SDL_Quit();
}

void Render()
{
	//Clear the screen.
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Set where to render texture
	SDL_Rect renderLocation = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	//Render to screen 
	SDL_RenderCopyEx(gRenderer, gTexture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

	//Update the screen
	SDL_RenderPresent(gRenderer);

}

SDL_Texture* LoadTextureFromFile(string path)
{
	//Remove any memory used for preivosu textuer
	FreeTexture();
	SDL_Texture* pTexture = NULL;

	//Load the image
	SDL_Surface* pSurface = IMG_Load(path.c_str());
	if (pSurface != NULL)
	{
		pTexture = SDL_CreateTextureFromSurface(gRenderer, pSurface);
		if (pTexture == NULL)
		{
			cout << "unable to create texture from surface. Error " << SDL_GetError() << endl;
		}
		SDL_FreeSurface(pSurface);
	}
	else
	{
		cout << "Unable to create textuer from surface. Error: " << IMG_GetError() << endl;
	}
	return pTexture;
}

bool Update()
{
	//Event Handler.
	SDL_Event e;

	//Get the events. 
	SDL_PollEvent(&e);

	//Handle any events.
	switch (e.type)
	{
		//Click the 'X' to quit.
	case SDL_QUIT:
		return true;
	break;
	}
	return false;
}