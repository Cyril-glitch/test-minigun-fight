#include "cc2d/cc2d_graphics.h"
#include "cc2d/cc2d_font.h"
#include "cc2d/cc2d_game.h"
#include "cc2d/cc2d_keyboard.h"


int main( int argc ,char *argv [])
{ 
	(void)argc;
	(void)argv;

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

		//dessine le jeu
		cc2d_gameDraw();




		cc2d_enddraw(renderer);    //affiche le rendu


	}

	cc2d_close(myWindow.sdlWindow,renderer);       //libere la memoire
	cc2d_gameClose();

	return  0;
}
