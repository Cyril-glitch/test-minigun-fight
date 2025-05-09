#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void cc2d_gameLoad(void)
{
	
	//chargement des Fonts
	cc2d_loadFont("../font/PixelMaster.ttf",&titre);

	if((TTF_SizeText(titre.font,titre.charTexte, &titre.width, &titre.height)) != 0) //crée taille logique
	{
		printf("TTF_SizeText Error : %s\n",TTF_GetError());
	}
	
	//chargement des Textes
        cc2d_textureTexte(renderer,&titre);
	SDL_QueryTexture(titre.texture,NULL, NULL, &titre.width,&titre.height);
	

	//chargement des textures Graphiques
	idiana.texture = cc2d_loadImage(renderer,"../img/planet.png");
	SDL_QueryTexture(idiana.texture, NULL, NULL, &idiana.Width, &idiana.Height);


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

