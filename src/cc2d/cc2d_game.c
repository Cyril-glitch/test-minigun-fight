#include <stdio.h>
#include <stdlib.h>


void cc2d_gameInit(void)
{
	
}
/*
void cc2d_gameUpdate(void)
{
	//initialisatioon des valeurs de temps
	Uint32 frameStart = 0;
	float deltaTime = 0 ;
	float elapsedTime = 0 ;

	//initialisation des valeurs precises
	Uint64 precise_fst = 0;
	double precise_dt = 0;
	double precise_elapse = 0 ;

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
}
*/
void cc2d_gameDraw(void)
{
}
/*
void cc2d_gameClose(void)
{

	SDL_DestroyTexture(texplanet);
	SDL_DestroyTexture(titre);
}
*/
