#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_keyboard.h"


int main( int agrc , const char argv [])
{
	//initialisation SDL + Fenetre
	int true = 1;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	int gameWidth = 250;
	int gameHeight = 250;


	cc2d_init();
	cc2d_init_window("window test" ,1000,1000, gameWidth,gameHeight,&renderer,&window);
	
	//intialisation graphics
	SDL_Texture* texplanet = cc2d_loadImage(renderer,"../img/planet.png");
	int xp = 0;
	int yp = 0;
	int planetWidth = 100 ;
	int planetHeight = 100 ;

	//initialisation font et textes
	TTF_Font* font = cc2d_loadFont("../font/PixelMaster.ttf",50);
	SDL_Texture* titre  = cc2d_textureTexte("Hello World !",renderer,font,100,100,255,255,255,255);
	

	//initialisatioon des valeurs de temps
	Uint32 frameStart = 0;
	float deltaTime = 0 ;
	float elapsedTime = 0 ;

	//initialisation des valeurs precises
	Uint64 precise_fst = 0;
	double precise_dt = 0;
	double precise_elapse = 0 ;

	//depart de la gameloop
	while(true)
	{

		 //recupération du delta Time
		 Uint32 now = SDL_GetTicks();
		 elapsedTime  = now / 1000;		
		 deltaTime = (now- frameStart) / 1000.0;
		 frameStart = now ;

		 //recuperation des valeurs precises
		 Uint64 P_now = SDL_GetPerformanceCounter();
		 precise_elapse = (double)P_now / SDL_GetPerformanceFrequency();
		 precise_dt = (double)(P_now - precise_fst) / SDL_GetPerformanceFrequency();
		 precise_fst = P_now ;

		
		SDL_SetRenderDrawColor(renderer,0,0,10,255);        //initialise le render en bleu
		if(cc2d_beginDraw(renderer) == 0 )                  //efface le renderer
		{
			break;
		}
		
		//chargement du contenue
		SDL_SetRenderDrawColor(renderer,255,0,255,255);      //dessine la ligne
		SDL_RenderDrawLine(renderer,0,0,250,250);

		cc2d_Draw(texplanet,renderer,xp,yp,planetWidth,planetHeight,255);     //affiche la planet 
		cc2d_Draw(titre,renderer,100,100,50,50,255);

		//cc2d_printPerf("fps",deltaTime,renderer,font);
		
		
			if(cc2d_downKey(SDL_SCANCODE_D))
			{
				if(xp < gameWidth - planetWidth) 
				{
					xp++;
				}
			}
			if(cc2d_downKey(SDL_SCANCODE_A))
			{
				if(xp > 0)
				{
					xp--;
				}
			}
			if(cc2d_downKey(SDL_SCANCODE_S))
			{

				if(yp < gameWidth - planetWidth ) 
				{

					yp++;
				}
			}
			if(cc2d_downKey(SDL_SCANCODE_W))
			{

				if(yp > 0)
				{
					yp--;
				}
			}


		cc2d_enddraw(renderer);    //affiche le resultat


	//	cc2d_fpsLimiter(frameStart , 60);

//		cc2d_Precise_FpsLimiter(precise_fst , 60);


	}

	cc2d_close(window,renderer);       //libere la memoire
	SDL_DestroyTexture(texplanet);
	SDL_DestroyTexture(titre);
}
