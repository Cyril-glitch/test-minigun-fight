#include <stdlib.h>
#include <stdio.h>
#include "cc2d/main.h" 

int main( int agrc , const char argv [])
{ 

	//intialisation SDL puis fenetre de jeu
	cc2d_init();
	cc2d_init_window("window test",windowWidth,windowHeight,gameWidth,gameHeight,&renderer,&window);

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


		cc2d_Draw(titre.texture,renderer,0,0,planetWidth,planetHeight,blend);
//		cc2d_Draw(titre,renderer,titre.x,titre.y,blend);

		//	cc2d_printPerf("Pfps",precise_dt,renderer,retroFont);      //affichage des performances

		cc2d_enddraw(renderer);    //affiche le rendu

		//	cc2d_Precise_FpsLimiter(precise_fst ,60);

	}

	cc2d_close(window,renderer);       //libere la memoire
}
