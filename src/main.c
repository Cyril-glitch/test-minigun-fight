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



		cc2d_Draw(texPlanet,renderer,centered_planetX,centered_planetY,planetWidth,planetHeight,blend);
		cc2d_Draw(texTitre,renderer,centered_titreX,centered_titreY,titreWidth,titreHeight,blend);

		//	cc2d_printPerf("Pfps",precise_dt,renderer,retroFont);      //affichage des performances

		if(cc2d_downKey(SDL_SCANCODE_D))
		{
			if(centered_planetX < gameWidth - planetWidth) 
			{
				centered_planetX++;
			}
		}
		if(cc2d_downKey(SDL_SCANCODE_A))
		{
			if(centered_planetX > 0)
			{
				centered_planetX--;
			}
		}
		if(cc2d_downKey(SDL_SCANCODE_S))
		{

			if(centered_planetY < gameWidth - planetWidth ) 
			{

				centered_planetY++;
			}
		}
		if(cc2d_downKey(SDL_SCANCODE_W))
		{

			if(centered_planetY > 0)
			{
				centered_planetY--;
			}
		}


		cc2d_enddraw(renderer);    //affiche le rendu

		//	cc2d_Precise_FpsLimiter(precise_fst ,60);



	}

	cc2d_close(window,renderer);       //libere la memoire
}
