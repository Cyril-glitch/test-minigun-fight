#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "cc2d/cc2d_graphics.h"
#include "cc2d/cc2d_font.h"
#include "cc2d/cc2d_game.h"
#include "cc2d/cc2d_keyboard.h"

int main( int agrc , const char argv [])
{ 
	int true = 1;


	//intialisation SDL puis fenetre de jeu
	cc2d_init();
	cc2d_init_window("window test",windowW,windowH,gameWidth,gameHeight,&renderer,&window);

	//chargement des textures
	cc2d_gameLoad();

	//depart de la gameloop
	while(true)
	{
		cc2d_gameUpdate();                                        //depart du comptage des valeurs de temps

		SDL_SetRenderDrawColor(renderer,0,0,10,255);               //initialise le render en bleu

		if(cc2d_beginDraw(renderer) == 0 )                         //efface le rendu ,initialise le poll event 
		{
			break;
		}
		//dessins

		cc2d_DrawTexte(renderer,titre);
		cc2d_Draw(idiana,renderer,0,0,255);





		cc2d_enddraw(renderer);    //affiche le rendu


	}

	cc2d_close(window,renderer);       //libere la memoire
}
