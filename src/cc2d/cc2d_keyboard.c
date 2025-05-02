#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include "cc2d_keyboard.h"

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
