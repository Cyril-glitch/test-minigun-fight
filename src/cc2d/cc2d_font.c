#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "cc2d_graphics.h"
#include "cc2d_font.h"



int cc2d_loadFont(const char* path ,CC2D_Text texte)
{
	texte.font = TTF_OpenFont(path,texte.fontSize);

	if(texte.font == NULL)
	{
		printf("TTF can't creat font From %s error : %s\n",path,TTF_GetError());
		return -1;

	}

	return 0;
}

int cc2d_textureTexte(char* texte ,SDL_Renderer* renderer,CC2D_Texte texte)
{
	SDL_Surface* surface = TTF_RenderUTF8_Solid(font,texte,texte.color);
	
	if(surface == NULL)
	{
		printf(" can't load font surface error: %s\n",SDL_GetError());
		return -1;
	}
	else
	{
		texte.texture = SDL_CreateTextureFromSurface(renderer,surface);

		if(texture == NULL)
		{
			printf(" can't create texture from surface error: %s\n",SDL_GetError());
			return -1;
		}
	
	}
	SDL_FreeSurface(surface);

	return 0;
}
void cc2d_DrawTexte(SDL_Renderer* renderer,CC2D_Texte texte)
{


	SDL_Rect rectDst;
	rectDst.x = texte.x
	rectDst.y = texte.y
	rectDst.w = texte.width;
	rectDst.h = texte.height;
	SDL_SetTextureAlphaMod(texte.texture,texte.a);
	SDL_RenderCopy(renderer,texte.texture,NULL,&rectDst);
}

void cc2d_DrawCenteredTexte(SDL_Renderer* renderer,CC2D_Texte texte,SDL_Window* windoWidth,SDL_Window* windowHeight)
{

	texte.centerX = (windowWidth - texte.width) / 2;
	texte.centerY = (windowHeight - texte.height) / 2;

	SDL_Rect rectDst;
	rectDst.x = texte.centerX;
	rectDst.y = texte.centerY;	
	rectDst.w = texte.width;
	rectDst.h = texte.height;
	SDL_SetTextureAlphaMod(texte.texture,texte.a);
	SDL_RenderCopy(renderer,texte.texture,NULL,&rectDst);
}















