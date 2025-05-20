#include <stdio.h>
#include <stdlib.h>

#include "cc2d_game.h"
#include "cc2d_graphics.h"
#include "cc2d_font.h"

void cc2d_gameLoad(void)
{
	
	//chargement des textes et fonts
	cc2d_loadFont("../font/PixelMaster.ttf",&titre);      //charge la font dans l'objet de texte
	cc2d_textureTexte(renderer,&titre);                                          //crée sa texture 
	
	//chargement des textures Graphiques
	cc2d_loadImage("../img/indiana.png",renderer,&indiana);             //crèe la texture

	//chargement des amimation 
//	frame = anime_indiana[WALK].first;

	
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
	//fermeture des textures

   SDL_DestroyTexture(indiana.texture);
   indiana.texture = NULL;
   SDL_DestroyTexture(titre.texture);
   titre.texture = NULL;

   //fermeture des fonts

   TTF_CloseFont(titre.font);
   titre.font = NULL;
}

