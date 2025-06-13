#include <stdio.h>
#include <stdlib.h>

#include "cc2d_game.h"
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_keyboard.h"

void cc2d_gameLoad(void)
{
	//chargement du fond

	cc2d_loadImage("../img/land.jpg",renderer,&land);             //crèe la texture


	//chargement des textes et fonts
	cc2d_loadFont("../font/PixelMaster.ttf",&titre);      //charge la font dans l'objet de texte
	cc2d_textureTexte(renderer,&titre);                                          //crée sa texture 

	//chargement des textures Graphiques P1
	cc2d_loadImage("../img/indiana.png",renderer,&indiana);             //crèe la texture
	cc2d_loadImage("../img/hpBar_out.png",renderer,&hpBar_out);             //crèe la texture
	cc2d_loadImage("../img/hpBar_in.png",renderer,&hpBar_in);             //crèe la texture


	//chargement des textures Graphiques P2
	cc2d_loadImage("../img/indiana.png",renderer,&indiana_2);             //crèe la texture
	cc2d_loadImage("../img/hpFlip_out.png",renderer,&hpBar_out_p2);             //crèe la texture
	cc2d_loadImage("../img/hpFlip_in.png",renderer,&hpBar_in_p2);             //crèe la texture

	//position bullet
	initAmmo();
	




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
	playerState(&indiana);
	playerState(&indiana_2);

	// dessine le fond
	cc2d_draw(renderer,land);

	//dessine le titre
	cc2d_drawTexte(renderer,titre);

	//dessine les performance graphique ou valeur de temps
	cc2d_printPerf("fps",renderer,&timer,deltaTime);

	//dessine l'ath
	cc2d_draw(renderer,hpBar_out);
	cc2d_draw(renderer,hpBar_in);

	cc2d_draw(renderer,hpBar_out_p2);
	cc2d_draw(renderer,hpBar_in_p2);

	//dessine les joueurs

//fonction de deplacement ou d'action

	//mouvement
	if(!indiana.state.dead)
	{
		
		cc2d_drawAnime(renderer,&indiana);
	
		cc2d_playerMovement(&indiana,&indiana_2);
	}
	else
	{	
		cc2d_drawAnimeLoop(renderer,&indiana);
	}
		
	
	if(!indiana_2.state.dead)
	{

		cc2d_drawAnime(renderer,&indiana_2);
		cc2d_player2_Movement(&indiana_2,&indiana);
	}
	else
	{	
		cc2d_drawAnimeLoop(renderer,&indiana_2);
	}

	//positionement des projectiles
	cc2d_shoot(renderer,bulletP1,&indiana,&indiana_2,&hpBar_in_p2,"P1");
	cc2d_shoot(renderer,bulletP2,&indiana_2,&indiana,&hpBar_in,"P2");

//gestion des perfomances

//	cc2d_fpsLimiter(frameStart,10);

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
		SDL_DestroyTexture(bulletP1[i].texture);
		bulletP1[i].texture = NULL;
	}
	for(int i = 0 ; i <= 10 ; i++)
	{
		SDL_DestroyTexture(bulletP2[i].texture);
		bulletP2[i].texture = NULL;
	}

	SDL_DestroyTexture(hpBar_out.texture);
	hpBar_out.texture = NULL;

	SDL_DestroyTexture(hpBar_in.texture);
	hpBar_in.texture = NULL;



	SDL_DestroyTexture(titre.texture);
	titre.texture = NULL;


	//fermeture des fonts

	TTF_CloseFont(titre.font);
	titre.font = NULL;
}
void initAmmo(void)
{
	for(int i = 0 ; i < 10 ; i++)
	{
		bulletP1[i]= (CC2D_Image){
			.texture = NULL,
				.rectSrc.x = 0,
				.rectSrc.w = 0,
				.rectSrc.h = 0, 

				.rectDst.x = 0,
				.rectDst.y = 0,
				.rectDst.w = 20,
				.rectDst.h = 20, 

				.realWidth = 0,
				.realHeight = 0,
				.a = blend,

				.angle = 0,
				.center = {0,0},
				.flipH = 0,
				.flipV = 0,
				.pastColision = {0,0,0,0},

				.shootedRight = 0,
				.shootedLeft = 0,
				.damage = 10,
				.bulletSpeed = 3,
				.hit = 0
		};

		cc2d_loadImage("../img/bullet.png",renderer,&bulletP1[i]);   


	}
	for(int i = 0 ; i < 10 ; i++)
	{
		bulletP2[i]= (CC2D_Image){
			.texture = NULL,
				.rectSrc.x = 0,
				.rectSrc.w = 0,
				.rectSrc.h = 0, 

				.rectDst.x = 0,
				.rectDst.y = 0,
				.rectDst.w = 20,
				.rectDst.h = 20, 

				.realWidth = 0,
				.realHeight = 0,
				.a = blend,

				.angle = 0,
				.center = {0,0},
				.flipH = 0,
				.flipV = 0,
				.pastColision = {0,0,0,0},

				.shootedRight = 0,
				.shootedLeft = 0,
				.damage = 10,
				.bulletSpeed = 3,
				.hit = 0
		};

		cc2d_loadImage("../img/bullet.png",renderer,&bulletP2[i]);   


	}


}
void playerState(CC2D_Image* player)
{
	if(player->hp == 0)
	{
		player->state.dead = 1;
	}
	if(player->state.dead)
	{
		player->animationState = DIE;
		player->animation[player->animationState].loop = 1;

	}
}























