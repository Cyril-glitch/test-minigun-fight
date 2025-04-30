#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "cc2d_graphics.h"
#include "cc2d_font.h"

SDL_Texture* cc2d_textureTexte(char* texte ,SDL_Renderer* renderer,TTF_Font* font,int x,int y,int r,int g,int b,int a)
{

	SDL_Color color = {r,g,b,a};
	SDL_Texture* texture = NULL;


	SDL_Surface* surface = TTF_RenderUTF8_Solid(font,texte,color);
	
	if(surface == NULL)
	{
		printf(" can't load surface error: %s\n",SDL_GetError());
		return NULL;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer,surface);

		if(texture == NULL)
		{
			printf(" can't create texture from surface error: %s\n",SDL_GetError());
			return NULL;
		}
	
	}
	SDL_FreeSurface(surface);

	return texture;
}

TTF_Font* cc2d_loadFont(const char* path ,int ftsize)
{
	TTF_Font* font = TTF_OpenFont(path,ftsize);

	if(font == NULL)
	{
		printf("TTF can't creat font From %s error : %s\n",path,TTF_GetError());
		return NULL;

	}

	return font;
}
