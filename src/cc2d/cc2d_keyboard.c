#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "cc2d_keyboard.h"
#include "cc2d_graphics.h"


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


void cc2d_playerMovement(CC2D_Image* playerImage,CC2D_Image* player2_Image)
{


	playerImage->animationState = IDLE;


	if((cc2d_downKey(SDL_SCANCODE_D)||
	   cc2d_downKey(SDL_SCANCODE_A)||
	   cc2d_downKey(SDL_SCANCODE_S)||
	   cc2d_downKey(SDL_SCANCODE_W))&& 
	   !cc2d_downKey(SDL_SCANCODE_SPACE ))
	{

		playerImage->animationState = WALK;
		playerImage->animation[playerImage->animationState].loop = 1;




		//DROITE
		if(cc2d_downKey(SDL_SCANCODE_D)  )        
		{
			if((playerImage->rectDst.x < (gameWidth - playerImage->rectDst.w ) && 
			!colision(playerImage,player2_Image)) || 
			playerImage->pastColision.left || 
			playerImage->pastColision.up  || 
			playerImage->pastColision.down ) 
			{
				playerImage->pastColision.left = 0;
				playerImage->pastColision.up = 0;
				playerImage->pastColision.down = 0;

				playerImage->rectDst.x++;
				playerImage->flipH = 0;

			}
			else if(colision(playerImage,player2_Image))
			{
				playerImage->pastColision.right = 1;
			}

		}

		//GAUCHE
		if(cc2d_downKey(SDL_SCANCODE_A))
		{
			if((playerImage->rectDst.x > 0 && !colision(playerImage,player2_Image))|| 
			playerImage->pastColision.right || 
			playerImage->pastColision.up  || 
			playerImage->pastColision.down )
			{
				playerImage->pastColision.right = 0;
				playerImage->pastColision.up = 0;
				playerImage->pastColision.down = 0;
				playerImage->rectDst.x--;
				playerImage->flipH = 1;
			}		
			else if(colision(playerImage,player2_Image))
			{
				playerImage->pastColision.left = 1;
			}	
		}

		//BAS
		if(cc2d_downKey(SDL_SCANCODE_S))
		{
			if((playerImage->rectDst.y < gameHeight - playerImage->rectDst.h && 
			!colision(playerImage,player2_Image)) || 
			playerImage->pastColision.right || 
		        playerImage->pastColision.left  || 
			playerImage->pastColision.up )

			{
				playerImage->pastColision.right = 0;
				playerImage->pastColision.left = 0;
				playerImage->pastColision.up = 0;
				playerImage->rectDst.y++;
			}
			else if(colision(playerImage,player2_Image))
			{
				playerImage->pastColision.down = 1;
			}	
		}

		//HAUT
		if(cc2d_downKey(SDL_SCANCODE_W))
		{
			if((playerImage->rectDst.y > 0 && !colision(playerImage,player2_Image))|| 
			playerImage->pastColision.right || 
			playerImage->pastColision.left  || 
			playerImage->pastColision.down )

			{
				playerImage->pastColision.right = 0;
				playerImage->pastColision.left = 0;
				playerImage->pastColision.down = 0;
				playerImage->rectDst.y--;
			}
			else if(colision(playerImage,player2_Image))
			{
				playerImage->pastColision.up = 1;
			}	
		}


	}
	else if(cc2d_downKey(SDL_SCANCODE_SPACE))
	{
		playerImage->animationState = FIRE;
		playerImage->animation[playerImage->animationState].loop = 1;
	}




	else
	{
		playerImage->animation[playerImage->animationState].loop = 0;

	}

}

void cc2d_player2_Movement(CC2D_Image* player2_Image,CC2D_Image* playerImage)
{ 

	player2_Image->animationState = IDLE ; 


	if((cc2d_downKey(SDL_SCANCODE_KP_6)||
	cc2d_downKey(SDL_SCANCODE_KP_4)||
	cc2d_downKey(SDL_SCANCODE_KP_5)||
	cc2d_downKey(SDL_SCANCODE_KP_8))&& 
	!cc2d_downKey(SDL_SCANCODE_DOWN))
	{



		player2_Image->animationState = WALK ; 
		player2_Image->animation[player2_Image->animationState].loop = 1;

		//DROITE

		if(cc2d_downKey(SDL_SCANCODE_KP_6)  )        
		{
			if((player2_Image->rectDst.x < (gameWidth - player2_Image->rectDst.w )&& 
			!colision(playerImage,player2_Image)) || 
			player2_Image->pastColision.left || 
			player2_Image->pastColision.up  || 
			player2_Image->pastColision.down ) 
			{
				player2_Image->pastColision.left = 0;
				player2_Image->pastColision.up = 0;
				player2_Image->pastColision.down = 0;
				player2_Image->rectDst.x++;
				player2_Image->flipH = 0;

			}
			else if(colision(playerImage,player2_Image))
			{
				player2_Image->pastColision.right = 1;
			}

		}

		//GAUCHE
		if(cc2d_downKey(SDL_SCANCODE_KP_4))
		{
			if((player2_Image->rectDst.x > 0 && !colision(player2_Image,playerImage))|| 
			player2_Image->pastColision.right || 
			player2_Image->pastColision.up  || 
			player2_Image->pastColision.down )
			{
				player2_Image->pastColision.right = 0;
				player2_Image->pastColision.up = 0;
				player2_Image->pastColision.down = 0;
				player2_Image->rectDst.x--;
				player2_Image->flipH = 1;
			}		
			else if(colision(playerImage,player2_Image))
			{
				player2_Image->pastColision.left = 1;
			}	
		}

		//BAS
		if(cc2d_downKey(SDL_SCANCODE_KP_5))
		{
			if((player2_Image->rectDst.y < gameHeight - playerImage->rectDst.h && 
			!colision(player2_Image,playerImage)) || 
			player2_Image->pastColision.right || 
			player2_Image->pastColision.left  || 
			player2_Image->pastColision.up )

			{
				player2_Image->pastColision.right = 0;
				player2_Image->pastColision.left = 0;
				player2_Image->pastColision.up = 0;
				player2_Image->rectDst.y++;
			}
			else if(colision(playerImage,player2_Image))
			{
				player2_Image->pastColision.down = 1;
			}	
		}

		//HAUT
		if(cc2d_downKey(SDL_SCANCODE_KP_8))
		{
			if((player2_Image->rectDst.y > 0 && !colision(player2_Image,playerImage))|| 
			player2_Image->pastColision.right || 
			player2_Image->pastColision.left  || 
			player2_Image->pastColision.down )

			{
				player2_Image->pastColision.right = 0;
				player2_Image->pastColision.left = 0;
				player2_Image->pastColision.down = 0;
				player2_Image->rectDst.y--;
			}
			else if(colision(player2_Image,playerImage))
			{
				player2_Image->pastColision.up = 1;
			}	
		}

		//JUMP
	}
	else if(cc2d_downKey(SDL_SCANCODE_DOWN))
	{
		player2_Image->animationState = FIRE;
		player2_Image->animation[player2_Image->animationState].loop = 1;
	}
	else
	{

		player2_Image->animation[player2_Image->animationState].loop = 0;
	}
}


void cc2d_shoot(SDL_Renderer* renderer,CC2D_Image* projectile,CC2D_Image* playerImage,CC2D_Image* enemie,CC2D_Image* enemieHpBar,const char* player)
{



	static int tour = 0;

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

				projectile[i].rectDst.x = playerImage->rectDst.x ;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;
				projectile[i].a = alpha;
			}
			else
			{
				projectile[i].flipH = 0;

				projectile[i].rectDst.x = playerImage->rectDst.x + 88;
				projectile[i].rectDst.y = playerImage->rectDst.y + 34;
				projectile[i].a = alpha;
			}

			

		}
	}
	//tir en rafale si on rest appuyer sur espaces 

	for( k = 0 ; k < 9 ; k ++)
	{ 
		//shooted prend 1 a chaque coup de feu
		if((int)playerImage->animation[FIRE].frame == playerImage->animation[FIRE].last && !playerImage->flipH && tour == k)
		{
			if(!projectile[k].shootedLeft)
			{
				projectile[k].shootedRight = 1;
				projectile[k].flipH = 0;
			}
		}
		else if((int)playerImage->animation[FIRE].frame == playerImage->animation[FIRE].last && playerImage->flipH && tour == k)
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
			projectile[k].rectDst.x += projectile[k].bulletSpeed;		
			projectile[k].a = blend;
		}
		if(projectile[k].shootedLeft)
		{	
			projectile[k].rectDst.x -= projectile[k].bulletSpeed;		
			projectile[k].a = blend;
		}
		//si le projectile n'est plus affichable il revient a sa position initiale
		if(projectile[k].rectDst.x > gameWidth || projectile[k].rectDst.x < 0)
		{
			projectile[k].shootedRight = 0;
			projectile[k].shootedLeft = 0;
			projectile[k].hit = 0;
		}
		//si le projectile touche le player adverse 
		if(strcmp(player,"P1") == 0)
		{
			if(colision(&projectile[k],enemie) && !projectile[k].hit) 
			{

				enemie->hp -= projectile[k].damage;
				//la bar de vie se racourcis au pourcentage de degats infligés
				enemieHpBar->rectDst.w -= 10;
				enemieHpBar->rectDst.x += 10;

				projectile[k].hit = 1;
			}

		}
		else if(strcmp(player,"P2") == 0)
		{
			if(colision(&projectile[k],enemie) && !projectile[k].hit) 
			{

				enemie->hp -= projectile[k].damage;
				//la bar de vie se racourcis au pourcentage de degats infligés
				enemieHpBar->rectDst.w -= 10;
				projectile[k].hit = 1;
			}

		}

		else
{
			printf("unkowned mode");
		}

					
		
		
	}
	if((int)playerImage->animation[FIRE].frame >= playerImage->animation[FIRE].last +1)
	{	

		if(tour == 9)
		{
			tour = 0;
		}
		if(tour < 9)
		{
			tour ++;		
		}
	}





	//affiche tout les projectiles

	for(j = 0 ; j < 10 ; j++)
	{
		SDL_SetTextureAlphaMod(projectile[j].texture,projectile[j].a);
	SDL_RenderCopyEx(renderer,projectile[j].texture,NULL,&projectile[j].rectDst,0,NULL,projectile[j].flipH);

//	printf("projectile P2 [%d] : shootedright = %d shootedleft :%d hit :%d \n",j,projectile[j].shootedRight,projectile[j].shootedLeft,projectile[j].hit);
	}

}

int colision(CC2D_Image* playerImage,CC2D_Image* player2_Image)
{
	int marginX = player2_Image->rectDst.w / 2;
	int marginY = player2_Image->rectDst.h ;

	if(playerImage->rectDst.x >= player2_Image->rectDst.x - marginX 
			&& playerImage->rectDst.x <= player2_Image->rectDst.x + marginX
			&&
			playerImage->rectDst.y <= player2_Image->rectDst.y + marginY 
			&& playerImage->rectDst.y >= player2_Image->rectDst.y- marginY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




