#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "cc2d_font.h"
#include "cc2d_graphics.h"



int cc2d_loadFont(const char* path ,CC2D_Texte* texte)
{
	texte->font = TTF_OpenFont(path,texte->fontSize);

	if(texte->font == NULL)
	{
		printf("TTF can't creat font From %s error : %s\n",path,TTF_GetError());
		return -1;

	}

        if((TTF_SizeText(texte->font,texte->charTexte, &texte->width, &texte->height)) != 0)  
	{
			printf("TTF_SizeText Error : %s\n",TTF_GetError());
	}	

	return 0;
}

int cc2d_textureTexte(SDL_Renderer* renderer,CC2D_Texte* texte)
{
	SDL_Surface* surface = TTF_RenderUTF8_Solid(texte->font,texte->charTexte,texte->color);
	
	if(surface == NULL)
	{
		printf(" can't load font surface error: %s\n",SDL_GetError());
		return -1;
	}
	else
	{
		texte->texture = SDL_CreateTextureFromSurface(renderer,surface);
		SDL_QueryTexture(texte->texture,NULL, NULL, &timer.width,&timer.height);    

		if(texte->texture == NULL)
		{
			printf(" can't create texture from surface error: %s\n",SDL_GetError());
			return -1;
		}
	
	}

	SDL_FreeSurface(surface);

	return 0;
}
int cc2d_DrawTexte(SDL_Renderer* renderer,CC2D_Texte texte)
{


	SDL_Rect rectDst;
	rectDst.x = texte.x;
	rectDst.y = texte.y;
	rectDst.w = texte.width;
	rectDst.h = texte.height;
	
	if((SDL_SetTextureAlphaMod(texte.texture,texte.color.a)) != 0)
	{
		printf("SDl c'ant set alphamod error : %s\n",SDL_GetError());
		return -1;
	}
	if((SDL_RenderCopy(renderer,texte.texture,NULL,&rectDst)) != 0)
	{
		printf("SDl c'ant copy render error : %s\n",SDL_GetError());
		return -1;
	}

	return 0;

}

int cc2d_DrawCenteredTexte(SDL_Renderer* renderer,CC2D_Texte texte,SDL_Window* windoWidth,SDL_Window* windowHeight)
{


	SDL_Rect rectDst;
	rectDst.x = (windowW - texte.x) / 2 ;
	rectDst.y =  (windowH - texte.y) / 2 ;
	
	rectDst.w = texte.width;
	rectDst.h = texte.height;

	if((SDL_SetTextureAlphaMod(texte.texture,texte.color.a)) != 0)
	{
		printf("SDl c'ant set alphamod error : %s\n",SDL_GetError());
		return -1;
	}
	if((SDL_RenderCopy(renderer,texte.texture,NULL,&rectDst)) != 0)
	{
		printf("SDl c'ant copy render error : %s\n",SDL_GetError());
		return -1;
	}

	return 0;

}














