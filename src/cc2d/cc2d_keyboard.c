#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "cc2d_keyboard.h"
#include "cc2d_graphics.h"

float speed = 0.1;

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
void cc2d_playerMovement(CC2D_Image* playerImage,CC2D_Anime* playerAnime)
{

	if(cc2d_downKey(SDL_SCANCODE_D)||cc2d_downKey(SDL_SCANCODE_A)||cc2d_downKey(SDL_SCANCODE_S)||cc2d_downKey(SDL_SCANCODE_W)||cc2d_downKey(SDL_SCANCODE_SPACE))
	{

		playerAnime->loop = 1;

		//DROITE

		if(cc2d_downKey(SDL_SCANCODE_D))        
		{
			if(playerImage->rectDst.x < gameWidth - playerImage->rectDst.w ) 
			{
				playerImage->rectDst.x++;
			}
		}

		//GAUCHE

		if(cc2d_downKey(SDL_SCANCODE_A))
		{
			if(playerImage->rectDst.x > 0)
			{
				playerImage->rectDst.x--;
			}		
		}

		//BAS

		if(cc2d_downKey(SDL_SCANCODE_S))
		{
			if(playerImage->rectDst.y < gameHeight - playerImage->rectDst.h ) 
			{
				playerImage->rectDst.y++;
			}
		}

		//HAUT

		if(cc2d_downKey(SDL_SCANCODE_W))
		{
			if(playerImage->rectDst.y > 0)
			{
				playerImage->rectDst.y--;
			}
		}

		//JUMP
	
	
	else
	{
		playerAnime->loop = 0;
	}
}
