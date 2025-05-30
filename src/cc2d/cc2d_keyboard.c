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


void cc2d_playerMovement(CC2D_Image* playerImage,CC2D_Anime* playerAnime,CC2D_Image* player2_Image)
{

	if(cc2d_downKey(SDL_SCANCODE_D)||cc2d_downKey(SDL_SCANCODE_A)
	||cc2d_downKey(SDL_SCANCODE_S)||cc2d_downKey(SDL_SCANCODE_W)||cc2d_downKey(SDL_SCANCODE_SPACE))
	{

		playerAnime->loop = 1;

		//DROITE
		if(cc2d_downKey(SDL_SCANCODE_D)  )        
		{
		       if(playerImage->rectDst.x < (gameWidth - playerImage->rectDst.w )
		         && !colision(playerImage,player2_Image) 
			   || playerImage->pastColision.left 
			   || playerImage->pastColision.up  
			   || playerImage->pastColision.down ) 
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
			if(playerImage->rectDst.x > 0 && !colision(playerImage,player2_Image)
			   || playerImage->pastColision.right 
			   || playerImage->pastColision.up  
			   || playerImage->pastColision.down )
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
			if(playerImage->rectDst.y < gameHeight - playerImage->rectDst.h 
		             && !colision(playerImage,player2_Image) 
			   || playerImage->pastColision.right 
			   || playerImage->pastColision.left  
			   || playerImage->pastColision.up )

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
			if(playerImage->rectDst.y > 0 && !colision(playerImage,player2_Image)
				|| playerImage->pastColision.right 
				|| playerImage->pastColision.left  
				|| playerImage->pastColision.down )

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

		//JUMP
	}
	
	
	else
	{
		playerAnime->loop = 0;
	}

}

void cc2d_player2_Movement(CC2D_Image* player2_Image,CC2D_Anime* player2_Anime,CC2D_Image* playerImage)
{

	if(cc2d_downKey(SDL_SCANCODE_KP_6)||cc2d_downKey(SDL_SCANCODE_KP_4)
	||cc2d_downKey(SDL_SCANCODE_KP_5)||cc2d_downKey(SDL_SCANCODE_KP_8)||cc2d_downKey(SDL_SCANCODE_DOWN))
	{

		player2_Anime->loop = 1;

		//DROITE

		if(cc2d_downKey(SDL_SCANCODE_KP_6)  )        
		{
		       if(player2_Image->rectDst.x < (gameWidth - player2_Image->rectDst.w )
		         && !colision(playerImage,player2_Image) 
			   || player2_Image->pastColision.left 
			   || player2_Image->pastColision.up  
			   || player2_Image->pastColision.down ) 
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
			if(player2_Image->rectDst.x > 0 && !colision(player2_Image,playerImage)
			   || player2_Image->pastColision.right 
			   || player2_Image->pastColision.up  
			   || player2_Image->pastColision.down )
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
			if(player2_Image->rectDst.y < gameHeight - playerImage->rectDst.h 
		             && !colision(player2_Image,playerImage) 
			   || player2_Image->pastColision.right 
			   || player2_Image->pastColision.left  
			   || player2_Image->pastColision.up )

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
			if(player2_Image->rectDst.y > 0 && !colision(player2_Image,playerImage)
				|| player2_Image->pastColision.right 
				|| player2_Image->pastColision.left  
				|| player2_Image->pastColision.down )

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

	
	else
	{
		player2_Anime->loop = 0;
	}
}

int colision(CC2D_Image* playerImage,CC2D_Image* player2_Image)
{
	int marginX = player2_Image->rectDst.w / 2;
	int marginY = player2_Image->rectDst.h ;

   if(playerImage->rectDst.x >= player2_Image->rectDst.x - marginX && playerImage->rectDst.x <= player2_Image->rectDst.x + marginX
	   &&
      playerImage->rectDst.y <= player2_Image->rectDst.y + marginY && playerImage->rectDst.y >= player2_Image->rectDst.y- marginY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


	   
