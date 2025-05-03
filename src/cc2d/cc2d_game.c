#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void cc2d_gameInit(void)
{
	//chargement des Fonts
	TTF_Font* retroFont = cc2d_loadFont("../font/PixelMaster.ttf",sizeFont1);
	//chargement des Textes
	SDL_Texture* Titre  = cc2d_textureTexte("Hello World !",renderer,retroFont,retroFontWidth,retroFontHeight,255,255,255,255);
	//chargement des textures Graphiques
	SDL_Texture* texplanet = cc2d_loadImage(renderer,"../img/planet.png");
}
void cc2d_gameUpdate(void)
{

	//recupération du delta Time
	Uint32 now = SDL_GetTicks();
	elapsedTime  = now / 1000;		
	deltaTime = (now- frameStart) / 1000.0;
	frameStart = now ;

	//recuperation des valeurs precises
	Uint64 P_now = SDL_GetPerformanceCounter();
	precise_elapse = (double)P_now / SDL_GetPerformanceFrequency();
	precise_dt = (double)(P_now - precise_fst) / SDL_GetPerformanceFrequency();
	precise_fst = P_now ;
}

void cc2d_gameDraw(void)
{
}
/*
   void cc2d_gameClose(void)
   {

   SDL_DestroyTexture(texplanet);
   SDL_DestroyTexture(titre);
   }
 */
