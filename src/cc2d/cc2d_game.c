#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void cc2d_gameLoad(void)
{
	/*
	//chargement des Fonts
	retroFont = cc2d_loadFont("../font/PixelMaster.ttf",sizeFont1);     //recupere la font et ça taille en points
	if((TTF_SizeText(retroFont, "Mini-Gun-Fight", &retroFontWidth, &retroFontHeight)) != 0) //crée taille logique
	{
		printf("TTF_SizeText Error : %s\n",TTF_GetError());
	}
	//chargement des Textes
	titre.texture = cc2d_textureTexte("Mini-Gun-Fight",renderer,retroFont,retroFontWidth,retroFontHeight,255,255,255,255);
	SDL_QueryTexture(titre.texture,NULL, NULL, titre.width,titre.Height);
	centered_titreX = (windowWidth - titre.Width) / 2;
	centered_titreY = (windowHeight - titre.Height) / 2;

	//chargement des textures Graphiques
	idiana.texture = cc2d_loadImage(renderer,"../img/planet.png");
	SDL_QueryTexture(idiana.texture, NULL, NULL, idiana.Width, idiana.Height);
	centered_planetX = (windowWidth - idiana.Width) / 2;
	centered_planetY = (windowHeight - idiana.Height) / 2;
*/
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
void cc2d_gameClose(void)
{

//   SDL_DestroyTexture(idiana.texture);
  // SDL_DestroyTexture(titre.texture);
}

