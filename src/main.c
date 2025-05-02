#include <stdlib.h>
#include <stdio.h>
#include "cc2d/main.h"

int main( int agrc , const char argv [])
{ 

        //intialisation SDL puis fenetre de jeu
	cc2d_init();
	cc2d_init_window("window test",windowWidth,windowHeight,gameWidth,gameHeight,&renderer,&window);

	//depart de la gameloop
	while(true)
	{
		SDL_SetRenderDrawColor(renderer,0,0,10,255);        //initialise le render en bleu
		if(cc2d_beginDraw(renderer) == 0 )                //efface le renderer
		{
			break;
		}

		cc2d_enddraw(renderer);    //affiche le resultat



	}

	cc2d_close(window,renderer);       //libere la memoire
}
