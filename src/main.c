#include "cc2d/cc2d_graphics.h"
#include "cc2d/cc2d_font.h"
#include "cc2d/cc2d_game.h"
#include "cc2d/cc2d_keyboard.h"


int main( int agrc , const char argv [])
{ 
	int true = 1;


	//intialisation SDL puis fenetre de jeu
	cc2d_init();
	cc2d_init_window(&myWindow,&renderer,gameWidth,gameHeight);
	

	//chargement des textures
	cc2d_gameLoad();

	//depart de la gameloop
	while(true)
	{
		cc2d_gameUpdate();                                        //depart du comptage des valeurs de temps

		SDL_SetRenderDrawColor(renderer,0,0,0,255);               //initialise le render en bleu

		if(cc2d_beginDraw(renderer) == 0 )                         //efface le rendu ,initialise le poll event 
		{
			break;
		}

		//dessins

		cc2d_drawTexte(renderer,titre);
		cc2d_printPerf("fps",renderer,&timer,deltaTime);

		cc2d_drawAnime(renderer,&indiana);
		cc2d_drawAnime(renderer,&indiana_2);

		//movement
		cc2d_playerMovement(&indiana,&indiana_2);
		cc2d_player2_Movement(&indiana_2,&indiana);

		



				cc2d_enddraw(renderer);    //affiche le rendu


	}

	cc2d_close(myWindow.sdlWindow,renderer);       //libere la memoire
	cc2d_gameClose();
}
