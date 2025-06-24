#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "cc2d_keyboard.h"
#include "cc2d_graphics.h"
#include "cc2d_game.h"


int cc2d_downKey(SDL_Scancode key)
{

	//la fonction getkeyboardstate créer un tableau de booléens on pourras passer par le pointeur state pour y acceder
	//Ce tableau met a jours l'etat des touches du clavier : 1 si la touche est pressée 0 si elle ne l'est pas

	const Uint8* state = SDL_GetKeyboardState(NULL);

	if(state[key])
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


void cc2d_playerMovement(CC2D_Image* p1,CC2D_Image* hpBar)
{
	

	

	
	//si le player est a 0 hp
	if(p1->state.hp < 1)
	{
		//on joue l'anime DIE
		p1->animationState = DIE;	
		//il perd une vie 
		p1->state.heart --;


		//quand on arrive apres avoir joué l'animation le player retouve ses hp et donc sa position de base
		if((int)p1->animation[DIE].frame >= p1->animation[DIE].last +1)
		{
			p1->state.hp = 200;
			hpBar->rectDst.w = 200;
			
			p1->rectDst.x = 0;
			p1->rectDst.y = 50;
			p1->animation[DIE].frame = p1->animation[DIE].first;
		}

	}
	else
	{

		p1->animationState = IDLE;
	}


	if((cc2d_downKey(SDL_SCANCODE_D)||
	cc2d_downKey(SDL_SCANCODE_A)||
	cc2d_downKey(SDL_SCANCODE_S)||
	cc2d_downKey(SDL_SCANCODE_W))&& 
	!cc2d_downKey(SDL_SCANCODE_SPACE))
	{



		p1->animationState = WALK ; 
		p1->animation[p1->animationState].loop = 1;

		//DROITE

		if(cc2d_downKey(SDL_SCANCODE_D) &&  p1->hitBox.frontCol == 0)        
		{
			 
			p1->rectDst.x += p1->speed;
			p1->flipH = 0;


		}

		//GAUCHE
		if(cc2d_downKey(SDL_SCANCODE_A) && p1->hitBox.backCol == 0)
		{
				p1->rectDst.x -= p1->speed;
				p1->flipH = 1;
		}

		//BAS
		if(cc2d_downKey(SDL_SCANCODE_S) && p1->hitBox.downCol == 0)
		{

				p1->rectDst.y += p1->speed;
		}

		//HAUT
		if(cc2d_downKey(SDL_SCANCODE_W) && p1->hitBox.upCol == 0)
		{

				p1->rectDst.y-= p1->speed;
		}

		//JUMP
	}
	else if(cc2d_downKey(SDL_SCANCODE_SPACE))
	{
		p1->animationState = FIRE;
		p1->animation[p1->animationState].loop = 1;
	}
	else
	{

		p1->animation[p1->animationState].loop = 0;
	}
}






void cc2d_player2_Movement(CC2D_Image* p2,CC2D_Image* hpBar)
{ 

//	printf("DOWNCOL = %d\n",p2->hitBox.downCol);
//	printf("UPCOL = %d\n",p2->hitBox.upCol);
//	printf("frontCOL = %d\n",p2->hitBox.frontCol);
//	printf("backCOL = %d\n",p2->hitBox.backCol);
	
	
	
	//si le player est a 0 hp
	if(p2->state.hp < 1)
	{
		//on joue l'anime DIE
		p2->animationState = DIE;	
		//il perd une vie 
		p2->state.heart --;


		//quand on arrive apres avoir joué l'animation le player retouve ses hp et donc sa position de base
		if((int)p2->animation[DIE].frame >= p2->animation[DIE].last +1)
		{
			p2->state.hp = 200;
			p2->state.hp = 200;
			hpBar->rectDst.w = 200;
			hpBar->rectDst.x = 734;
			
			p2->rectDst.x = 924;
			p2->rectDst.y = 50;

			p2->animation[DIE].frame = p2->animation[DIE].first;
		}

	}
	else
	{

		p2->animationState = IDLE;
	}


	


	if((cc2d_downKey(SDL_SCANCODE_KP_6)||
	cc2d_downKey(SDL_SCANCODE_KP_4)||
	cc2d_downKey(SDL_SCANCODE_KP_5)||
	cc2d_downKey(SDL_SCANCODE_KP_8))&& 
	!cc2d_downKey(SDL_SCANCODE_KP_0))
	{



		p2->animationState = WALK ; 
		p2->animation[p2->animationState].loop = 1;

		//DROITE

		if(cc2d_downKey(SDL_SCANCODE_KP_6) && p2->hitBox.frontCol == 0 )        
		{
				p2->rectDst.x+= p2->speed;
				p2->flipH = 0;


		}

		//GAUCHE
		if(cc2d_downKey(SDL_SCANCODE_KP_4) && p2->hitBox.backCol == 0)
		{
				p2->rectDst.x-= p2->speed;
				p2->flipH = 1;
		}

		//BAS
		if(cc2d_downKey(SDL_SCANCODE_KP_5) && p2->hitBox.downCol == 0)
		{

				p2->rectDst.y+= p2->speed;
		}

		//HAUT
		if(cc2d_downKey(SDL_SCANCODE_KP_8) && p2->hitBox.upCol == 0)
		{

				p2->rectDst.y-= p2->speed;
		}

		//JUMP
	}
	else if(cc2d_downKey(SDL_SCANCODE_KP_0))
	{
		p2->animationState = FIRE;
		p2->animation[p2->animationState].loop = 1;
	}
	else
	{

		p2->animation[p2->animationState].loop = 0;
	}
}


void cc2d_shoot(SDL_Renderer* renderer,CC2D_Image* projectile,CC2D_Image* playerImage,CC2D_Image* enemie,CC2D_Image* enemieHpBar,const char* player)
{



	static int currentShoot = 0;

	int i = 0;
	int j = 0;
	int k = 0;

	//On met tout les projectile a leur position initiale si il n'ont pas ete tiré	
	for( i = 0 ; i < 10 ; i++)              
	{
		if(!projectile[i].shootedRight && !projectile[i].shootedLeft )
		{

			if(playerImage->flipH)
			{
				projectile[i].flipH = 1;

				projectile[i].rectDst.x = playerImage->hitBox.rect.x - 50 ;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;

				projectile[i].a = alpha;


			}
			else
			{
				projectile[i].flipH = 0;

				projectile[i].rectDst.x = playerImage->hitBox.rect.x + playerImage->hitBox.rect.w +10;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;

				projectile[i].a = alpha;

			}
/*
			if(playerImage->flipH)
			{
				projectile[i].flipH = 1;

				projectile[i].rectDst.x = playerImage->hitBox.rect.x + playerImage->hitBox.rect.w;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;
				projectile[i].a = alpha;


			}
			else
			{
				projectile[i].flipH = 0;

				projectile[i].rectDst.x = playerImage->hitBox.rect.x;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;
				projectile[i].a = alpha;

			}

*/			

		}
	}
	//tir en rafale si on rest appuyer sur espaces 

	for( k = 0 ; k < 10 ; k ++)
	{ 
		//shooted prend 1 a chaque coup de feu
		if((int)playerImage->animation[FIRE].frame >= playerImage->animation[FIRE].last +1 && !playerImage->flipH && currentShoot == k)
		{
			if(!projectile[k].shootedLeft)
			{
				projectile[k].shootedRight = 1;
				projectile[k].flipH = 0;
				
			}
		}
		else if((int)playerImage->animation[FIRE].frame >= playerImage->animation[FIRE].last +1 && playerImage->flipH && currentShoot == k)
		{
			if(!projectile[k].shootedRight)
			{
				projectile[k].shootedLeft = 1;
				projectile[k].flipH = 1;
			}
		}


		//si shooted se verifie alors le projectile avance
		if(projectile[k].shootedRight)
		{	
			projectile[k].affichable = 1;
			projectile[k].rectDst.x += projectile[k].bulletSpeed;		
			projectile[k].a = blend;
			
		}
		else if(projectile[k].shootedLeft)
		{	
			projectile[k].affichable = 1;
			projectile[k].rectDst.x -= projectile[k].bulletSpeed;		
			projectile[k].a = blend;


		}
		//si le projectile n'est plus affichable il revient a sa position initiale
		if(projectile[k].rectDst.x > gameWidth || projectile[k].rectDst.x < 0)
		{

			projectile[k].affichable = 0;
		}






		//si le projectile touche le player adverse 
		if(strcmp(player,"P1") == 0)
		{
			if(bulletDamage(map,&projectile[k]) && !projectile[k].hit && projectile[k].affichable) 
			{


				enemie->state.hp -= projectile[k].damage;

				//la bar de vie se racourcis au pourcentage de degats infligés

				enemieHpBar->rectDst.w -= 10;
				enemieHpBar->rectDst.x += 10;

				projectile[k].affichable = 0;
				projectile[k].hit = 1;
			}

		}
		
		else if(strcmp(player,"P2") == 0)
		{
			if(bulletDamage(map,&projectile[k]) && !projectile[k].hit && projectile[k].affichable) 
			{


				enemie->state.hp -= projectile[k].damage;

				//la bar de vie se racourcis au pourcentage de degats infligés

				enemieHpBar->rectDst.w -= 10;
				projectile[k].hit = 1;
				projectile[k].affichable = 0;
			}

		}

		else
		{
			printf("unkowned mode");
		}






		if(!projectile[k].affichable)
		{
			projectile[k].shootedRight = 0;
			projectile[k].shootedLeft = 0;
			projectile[k].hit = 0;

		}

					
		
		
	}
	if((int)playerImage->animation[FIRE].frame >= playerImage->animation[FIRE].last +1 )
	{	

		if(currentShoot == 9 )
		{
			currentShoot = 0;
		}
		if(currentShoot < 9)
		{
			currentShoot ++;		
		}
	}





	//affiche tout les projectiles

	for(j = 0 ; j < 10 ; j++)
	{
		SDL_SetTextureAlphaMod(projectile[j].texture,projectile[j].a);
	SDL_RenderCopyEx(renderer,projectile[j].texture,NULL,&projectile[j].rectDst,0,NULL,projectile[j].flipH);



//	printf("projectile [%d] : shootedright = %d shootedleft :%d hit :%d \n",j,projectile[j].shootedRight,projectile[j].shootedLeft,projectile[j].hit);

	}

//				printf("HP P1= %d\n",playerImage->state.hp);
//				printf("HP P2= %d\n",enemie->state.hp);
}





