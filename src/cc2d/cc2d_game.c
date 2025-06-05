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
	cc2d_loadImage("../img/indiana.png",renderer,&indiana_2);             //crèe la texture

	//position bullet
	initAmmo(bullet);




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

	SDL_DestroyTexture(indiana_2.texture);
	indiana_2.texture = NULL;

	for(int i = 0 ; i <= 10 ; i++)
	{
		SDL_DestroyTexture(bullet[i].texture);
		bullet[i].texture = NULL;
	}

	SDL_DestroyTexture(titre.texture);
	titre.texture = NULL;


	//fermeture des fonts

	TTF_CloseFont(titre.font);
	titre.font = NULL;
}
void initAmmo(CC2D_Image* projectile)
{
	for(int i = 0 ; i < 10 ; i++)
	{
		projectile[i]= (CC2D_Image){
				.texture = NULL,
				.rectSrc.x = 0,
				.rectSrc.w = 0,
				.rectSrc.h = 0, 

				.rectDst.x = 0,
				.rectDst.y = 0,
				.rectDst.w = 6,
				.rectDst.h = 5, 

				.realWidth = 0,
				.realHeight = 0,
				.a = blend,
				.angle = 0,
				.center = {0,0},
				.flipH = 0,
				.flipV = 0,
				.pastColision = {0,0,0,0},
				.shooted = 0,
				.affichable = 1,
			};

		   cc2d_loadImage("../img/bullet.png",renderer,&projectile[i]);   


		}

}













