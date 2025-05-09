#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#include "cc2d_graphics.h"
#include "cc2d_font.h"

void cc2d_gameLoad(void)
{
	
	//chargement des textes et fonts
	cc2d_loadFont("../font/PixelMaster.ttf",&titre);      //charge la font dans l'objet de texte

	if((TTF_SizeText(titre.font,titre.charTexte, &titre.width, &titre.height)) != 0)  //crée sa taille logique
	{
		printf("TTF_SizeText Error : %s\n",TTF_GetError());
	}	
        cc2d_textureTexte(renderer,&titre);                                          //crée sa texture 
	SDL_QueryTexture(titre.texture,NULL, NULL, &titre.width,&titre.height);     //recupere ses dimensions originals
	

	//chargement des textures Graphiques
	indiana.texture = cc2d_loadImage(renderer,"../img/indiana.png");             //crèe la texture
	SDL_QueryTexture(indiana.texture, NULL, NULL, &indiana.Width, &indiana.Height); //recupere les dimensions orig


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

   SDL_DestroyTexture(indiana.texture);
   SDL_DestroyTexture(titre.texture);
}

