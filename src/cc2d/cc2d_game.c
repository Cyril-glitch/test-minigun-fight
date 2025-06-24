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
	cc2d_loadImage("../img/indiana.png",renderer,&player1);             //crèe la texture
	cc2d_loadImage("../img/hpBar_out.png",renderer,&hpBar_out_p1);             //crèe la texture
	cc2d_loadImage("../img/hpBar_in.png",renderer,&hpBar_in_p1);             //crèe la texture


	//chargement des textures Graphiques P2
	cc2d_loadImage("../img/indiana.png",renderer,&player2);             //crèe la texture
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

	// dessine le fond
	cc2d_draw(renderer,land);

	//dessine le titre
	cc2d_drawTexte(renderer,titre);

	//dessine les performance graphique ou valeur de temps
	cc2d_printPerf("fps",renderer,&timer,deltaTime);

	//dessine l'ath
	cc2d_draw(renderer,hpBar_out_p1);
	cc2d_draw(renderer,hpBar_in_p1);

	cc2d_draw(renderer,hpBar_out_p2);
	cc2d_draw(renderer,hpBar_in_p2);

	//DESSINE LA HITBOX DU P2

	SDL_SetRenderDrawColor(renderer,0,255,0,255);           

	cc2d_drawHitBox(renderer,&player1);

	//DESSINE LA HITBOX DU P2

	cc2d_drawHitBox(renderer,&player2);

	//DESSINE LA HITBOX DES PROJECTILES

	hitBoxAmmo(&bulletP1[0]);
	hitBoxAmmo(&bulletP2[0]);

	//DESSINE LES OBJETS EN DUR

	mapPx(map,player1.hitBox.rect,renderer);


	mapPx(map,player2.hitBox.rect,renderer);


	mapPlayer(map,renderer);

	//EMPECHE LES OBJETS DE SE TRAVERSER ENTRE EUX

	//p1
	frontColision(map,&player1);
	backColision(map,&player1);
	downColision(map,&player1);
	upColision(map,&player1);


	//p2
	frontColision(map,&player2);
	backColision(map,&player2);
	downColision(map,&player2);
	upColision(map,&player2);


	//GERE LES DEPLACEMENTS DES JOEURS

	cc2d_playerMovement(&player1,&hpBar_in_p1);
	cc2d_player2_Movement(&player2,&hpBar_in_p2);


	//GERE LES ACTIONS LIE AUX TIRS

	cc2d_shoot(renderer,bulletP1,&player1,&player2,&hpBar_in_p2,"P1");
	cc2d_shoot(renderer,bulletP2,&player2,&player1,&hpBar_in_p1,"P2");

	//DESSINE LES JOUEURS	

	cc2d_drawAnime(renderer,&player1);
	cc2d_drawAnime(renderer,&player2);

//gestion des perfomances

//	cc2d_fpsLimiter(frameStart,10);

}

void cc2d_gameClose(void)
{
	//fermeture des textures

	SDL_DestroyTexture(player1.texture);
	player1.texture = NULL;

	SDL_DestroyTexture(player2.texture);
	player2.texture = NULL;

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

	SDL_DestroyTexture(hpBar_out_p1.texture);
	hpBar_out_p1.texture = NULL;

	SDL_DestroyTexture(hpBar_in_p1.texture);
	hpBar_in_p1.texture = NULL;



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
				.animation ={ 

					[0]={
					.first = 0,
					.last = 2,
					.frame = 0,
					.speed = 0,
					.loop = 0,
					},
				},

				.angle = 0,
				.center = {0,0},
				.flipH = 0,
				.flipV = 0,
				.pastColision = {0,0,0,0},

				.affichable = 0,
				.shootedRight = 0,
				.shootedLeft = 0,
				.damage = 10,
				.bulletSpeed = 3,
				.hit = 0,

				.hitBox.rect = {0,0,20,10}
		};
	
	cc2d_loadImage("../img/bullet_p1.png",renderer,&bulletP1[i]);



	}
	for(int i = 0 ; i < 10 ; i++)
	{
		bulletP2[i]= (CC2D_Image){
			.texture = NULL,
				.rectSrc.x = 0,
				.rectSrc.w = 0,
				.rectSrc.h = 0, 

				.rectDst.x = 1004,
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

				.affichable = 0,
				.shootedRight = 0,
				.shootedLeft = 0,
				.damage = 10,
				.bulletSpeed = 3,
				.hit = 0,

				.hitBox.rect = {0,0,20,10}
		};



		cc2d_loadImage("../img/bullet_p1.png",renderer,&bulletP2[i]);

	}


}

void hitBoxAmmo(CC2D_Image* projectile)
{
	for(int i = 0 ; i < 10 ; i++)
	{
		
		if(projectile[i].flipH)
		{	
			projectile[i].hitBox.rect.x = projectile[i].rectDst.x +2 ;
			projectile[i].hitBox.rect.y = projectile[i].rectDst.y +5;

		}
		else
		{
			projectile[i].hitBox.rect.x = projectile[i].rectDst.x +2 ;
			projectile[i].hitBox.rect.y = projectile[i].rectDst.y +5 ;
		}

		SDL_RenderDrawRects(renderer,&projectile[i].hitBox.rect,1);
	}
}

void mapPx(PIXEL map[768][1024],SDL_Rect h,SDL_Renderer* renderer)
{
	 

	//le pixel compris dans la hitbox devienne plein
	for(int y = 0 ; y < 768 ; y ++)
	{
		for(int x = 0 ; x < 1024 ; x++)
		{
			if((x >= h.x  && x <= h.x + h.w)&&                 //si x supp au point x du de la hitbox moins sa marge mais inferieur au x de la hitbox + sa marge
			  (y >= h.y   && y <= h.y + h.h))
			{

				map[y][x].plein = 1;
			}	
			if(map[y][x].plein)
			{
//				cc2d_drawRect(renderer,"fill",x,y,1,1);
			}

		}
	}


}
void freshMap(PIXEL map[768][1024])
{
	//le pixel compris dans la hitbox devienne plein
	for(int y = 0 ; y < 768 ; y ++)
	{
		for(int x = 0 ; x < 1024 ; x++)
		{
			map[y][x].plein = 0;
			map[y][x].p1 = 0;
			map[y][x].p2 = 0;
		}
	}


}

void mapPlayer(PIXEL map[768][1024],SDL_Renderer* renderer)
{
	 

	//le pixel compris dans la hitbox devienne plein
	for(int y = 0 ; y < 768 ; y ++)
	{
		for(int x = 0 ; x < 1024 ; x++)
		{
			//PLAYER1
			if((x >= player1.hitBox.rect.x  && x <=  player1.hitBox.rect.x + player1.hitBox.rect.w)&&                 
			  (y >= player1.hitBox.rect.y   && y <= player1.hitBox.rect.y + player1.hitBox.rect.h))
			{

				map[y][x].p1 = 1;

	//			cc2d_drawRect(renderer,"fill",x,y,1,1);
			}
			//PLAYER2
			if((x >= player2.hitBox.rect.x  && x <=  player2.hitBox.rect.x + player2.hitBox.rect.w)&&                 
			  (y >= player2.hitBox.rect.y   && y <= player2.hitBox.rect.y + player2.hitBox.rect.h))
			{

				map[y][x].p2 = 1;
	//			cc2d_drawRect(renderer,"fill",x,y,1,1);
			}

		}
	}


}

int bulletDamage(PIXEL map[768][1024],CC2D_Image* projectile)
{

	//on regarde une case a droite de notre hitBox
	int x = projectile->hitBox.rect.x + projectile->hitBox.rect.w +1;
	

	//puis on parcours toute ces cases de haut en bas
	for(int y = projectile->hitBox.rect.y ; y <= (projectile->hitBox.rect.y + projectile->hitBox.rect.h) ; y ++)
	{

	
		//si cette case appartient a un joueur notre fontion prend 1
		if(map[y][x].p1 || map[y][x].p2) 
		{
			return 1;
		
		}

	} 


	//on regarde une case a gauche de notre hitBox
	int x2 = projectile->hitBox.rect.x - 1;
	

	//puis on parcours toute ces cases de haut en bas
	for(int y2 = projectile->hitBox.rect.y ; y2 <= (projectile->hitBox.rect.y + projectile->hitBox.rect.h) ; y2 ++)
	{

	
		//si cette case appartient a un joueur notre fontion prend 1
		if(map[y2][x2].p1 || map[y2][x2].p2) 
		{
			return 1;
		
		}

	} 

	return 0;
	
}


int frontColision(PIXEL map[768][1024],CC2D_Image* h)
{

	//on regarde une case a droite de notre hitbox
	int x = h->hitBox.rect.x + h->hitBox.rect.w +1;
	

	//puis on parcours toute ces cases de haut en bas
	for(int y = h->hitBox.rect.y ; y <= (h->hitBox.rect.y + h->hitBox.rect.h) ; y ++)
	{

	
		if(map[y][x].plein) 
		{
			h->hitBox.frontCol = 1;
			return 0;
		
		}
		else
		{

			h->hitBox.frontCol = 0;
		}

	} 

		return 0;
}
//gauche

int backColision(PIXEL map[768][1024],CC2D_Image* h)
{
	int x = h->hitBox.rect.x - 1;

	for(int y = h->hitBox.rect.y ; y <= (h->hitBox.rect.y + h->hitBox.rect.h) ; y ++)
	{


		if(map[y][x].plein) 
		{
			h->hitBox.backCol = 1;
			return 0;

		}
		else
		{

			h->hitBox.backCol = 0;
		}

	} 

		return 0;
}
//BAS

int downColision(PIXEL map[768][1024],CC2D_Image* h)
{
        int y = h->hitBox.rect.y + h->hitBox.rect.h +1;

	for(int  x = h->hitBox.rect.x ; x <= (h->hitBox.rect.x + h->hitBox.rect.w) ; x ++)
	{


		if(map[y][x].plein) 
		{
			h->hitBox.downCol = 1;
			return 0;

		}
		else
		{

			h->hitBox.downCol = 0;
		}

	}

		return 0;
}	

//HAUT

int upColision(PIXEL map[768][1024],CC2D_Image* h)
{
	int y = h->hitBox.rect.y - 1;
	for(int x= h->hitBox.rect.x ; x <= (h->hitBox.rect.x + h->hitBox.rect.w) ; x ++)
	{


		if(map[y][x].plein) 
		{
			h->hitBox.upCol = 1;
			return 0;

		}
		else
		{

			h->hitBox.upCol = 0;
		}

	}
	

		return 0;
}
