#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void cc2d_gameLoad(void)
{
	//chargement des Fonts
	retroFont = cc2d_loadFont("../font/PixelMaster.ttf",sizeFont1);
	if((TTF_SizeText(retroFont, "Hello World !", &retroFontWidth, &retroFontHeight)) != 0)
	{
		printf("TTF_SizeText Error : %s\n",TTF_GetError());
	}
	//chargement des Textes
	texTitre= cc2d_textureTexte("Hello World !",renderer,retroFont,retroFontWidth,retroFontHeight,255,255,255,255);
	SDL_QueryTexture(texTitre, NULL, NULL, &titreWidth, &titreHeight);
	centered_titreX = (windowWidth - titreWidth) / 2;
	centered_titreY = (windowHeight - titreHeight) / 2;

	//chargement des textures Graphiques
	texPlanet = cc2d_loadImage(renderer,"../img/planet.png");
	SDL_QueryTexture(texPlanet, NULL, NULL, &planetWidth, &planetHeight);
	centered_planetX = (windowWidth - planetWidth) / 2;
	centered_planetY = (windowHeight - planetHeight) / 2;

}
void cc2d_gameUpdate(void)
{

	//recupération du delta Time
	now = SDL_GetTicks();
	elapsedTime  = now / 1000;		
	deltaTime = (now- frameStart) / 1000.0;
	frameStart = now ;

	//recuperation des valeurs precises
	P_now = SDL_GetPerformanceCounter();
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
