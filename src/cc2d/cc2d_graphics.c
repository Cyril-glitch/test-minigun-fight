#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>

#include "cc2d_graphics.h"
#include "cc2d_font.h"



int cc2d_init()
{

	//ici on initialise toutes les fonction de SDL en entrant le flag "EVERYTHING"

	printf("🛠️ Initialisation la librairie SDL...");
	loadBar();

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{

		printf("⛔ Impossible d'initialiserSDL \n");
		return -1;
	}
	else
	{
		printf("✅ SDL initialisée avec succés !\n");
		return 0;
	}
}

int cc2d_beginDraw(SDL_Renderer* renderer)
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			return 0 ;
		}
	}
	SDL_RenderClear(renderer);

	return 1;
}

void cc2d_enddraw(SDL_Renderer* renderer)
{
	SDL_RenderPresent(renderer);
}

void cc2d_close(SDL_Renderer* renderer,SDL_Window* window)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	printf("🔒 Fermeture du programme\n");
}


int cc2d_init_window(char* titre,int width,int height,int gameWidth,int gameHeight,SDL_Renderer** renderer,SDL_Window** window)
{

	//window = l'adresse du pointeur 
	//*window = la valeur du premier pointeur SDL_window *window
	//**window = la valeur pointé par le premier pointeur (les donnèes de la struct)

	*window = SDL_CreateWindow(
			titre,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
			);

	if(*window == NULL)
	{
		printf("⛔ Impossible de créer la fenetre %s\n",SDL_GetError());
		return-1;
	}

	*renderer = SDL_CreateRenderer(*window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if(*renderer == NULL)
	{
		printf("⛔ Impossible de créer le renderer  %s\n",SDL_GetError());
		return-1;
	}
	else
	{
		int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG ;

		if(!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("⛔ Impossible d'initialiser SDL_Image : SDL_Image error : %s\n",SDL_GetError());
			return -1;
		}

	}

	if(TTF_Init() == -1)
	{
		printf("⛔ Impossible d'intialiser la TTF : TTF error : %s\n",TTF_GetError());
		return -1;

	}
	else
	{
		printf("✅ TTF initialisée avec succés !\n");
	}


	SDL_SetWindowMinimumSize(*window,gameWidth,gameHeight);
	SDL_RenderSetLogicalSize(*renderer,gameWidth,gameHeight);
	SDL_RenderSetIntegerScale(*renderer,SDL_TRUE);
	SDL_SetRenderDrawBlendMode(*renderer,SDL_BLENDMODE_BLEND);
}


SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path);

	if(loadedSurface == NULL )
	{
		printf("IMG %s can't be loaded error . %s\n",path,IMG_GetError());
		return NULL;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer,loadedSurface); 

		if(texture == NULL)
		{
			printf("texture From %s can't be creat error . %s\n",path,IMG_GetError());
			return NULL;
		}
		else
		{
			SDL_FreeSurface(loadedSurface);
			loadedSurface = NULL;
		}
	}
	return texture;
}

SDL_Texture* quickLoadTexture(SDL_Renderer *renderer,char* path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer,path);


	if(texture == NULL)
	{
		printf("SDL can't creat texture From %s error : %s\n",path,IMG_GetError());
		return NULL;
	}

	return texture;
}

SDL_Texture* cc2d_loadImage(SDL_Renderer *renderer,const char* path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer,path);


	if(texture == NULL)
	{
		printf("SDL can't creat texture From %s error : %s\n",path,IMG_GetError());



	}

	return texture;

}
//on a besoin d'une fonction qui defini le rectangle de destinantion puis l'affiche

void cc2d_Draw(SDL_Renderer* renderer,CC2D_Texture image)
{

	SDL_Rect rectDst;
	rectDst.x = image.x;
	rectDst.y = image.y;
	rectDst.w = image.Width;
	rectDst.h = image.Height;
	SDL_SetTextureAlphaMod(image.texture,image.a);
	SDL_RenderCopy(renderer,image.texture,NULL,&rectDst);
}

void cc2d_drawRect(SDL_Renderer* renderer,const char* mode , int x ,int y ,int w , int h)
{
	SDL_Rect rect = {x,y,w,h}; 

	if(strcmp(mode,"line") == 0)
	{
		SDL_RenderDrawRects(renderer,&rect,1);
	}
	else if(strcmp(mode,"fill") == 0)
	{
		SDL_RenderFillRects(renderer,&rect,1);
	}
}



void cc2d_fpsLimiter(Uint32 frameStart , int fps)
{
	//le temps écoulé pour afficher une image
	Uint32 frameTime = SDL_GetTicks() - frameStart;
	//	printf("frameTime = %.6f\n",(double)frameTime / 1000 );

	//temps par frame rechercher 
	Uint32 targetFrameTime = 1000.0 / fps;

	if(frameTime < targetFrameTime)
	{
		Uint32 delay = targetFrameTime - frameTime;
		if(delay > 0)
		{
			SDL_Delay(delay);
		}
	}
}

void cc2d_Precise_FpsLimiter(Uint64 precise_fst , int fps)
{
	//Nombre de ticks emis pendant une frame
	Uint64 frameTime = SDL_GetPerformanceCounter() - precise_fst; 
	//on convertis le frame time en senconde
	double sFrameTime =(double)frameTime / SDL_GetPerformanceFrequency();

	//	printf("frameTime = %.6f\n",sFrameTime);

	double targetFrameTime = 1.0 / fps;

	if(sFrameTime < targetFrameTime)
	{
		//on convertie le delay en milliseconde pour le passer a SDL_delay
		double delaySeconde = targetFrameTime - sFrameTime;
		Uint32 delayMili = (Uint32)(delaySeconde *1000);
		if(delayMili > 0)
		{
			SDL_Delay(delayMili);
		}

	}
}


void cc2d_printPerf(const char* perf,SDL_Renderer* renderer,CC2D_Texte* texte,double valeurDeTemps)
{

	if(strcmp(perf,"timer")== 0)  
	{

		cc2d_loadFont("../font/PixelMaster.ttf",&timer);    

		sprintf(texte->charTexte,"timer : %.3f",valeurDeTemps);

		if((TTF_SizeText(timer.font,timer.charTexte, &timer.width, &timer.height)) != 0)  
		{
			printf("TTF_SizeText Error : %s\n",TTF_GetError());
		}	
		cc2d_textureTexte(renderer,&timer);                                          
		SDL_QueryTexture(timer.texture,NULL, NULL, &timer.width,&timer.height);    
		cc2d_DrawTexte(renderer,timer);

		TTF_CloseFont(timer.font);
		SDL_DestroyTexture(timer.texture);

	}	
	if(strcmp(perf,"deltaTime")== 0)  
	{

		cc2d_loadFont("../font/PixelMaster.ttf",&timer);    

		sprintf(texte->charTexte,"deltatime : %.3f",valeurDeTemps);

		if((TTF_SizeText(timer.font,timer.charTexte, &timer.width, &timer.height)) != 0)  
		{
			printf("TTF_SizeText Error : %s\n",TTF_GetError());
		}	
		cc2d_textureTexte(renderer,&timer);                                          
		SDL_QueryTexture(timer.texture,NULL, NULL, &timer.width,&timer.height);    
		cc2d_DrawTexte(renderer,timer);

		TTF_CloseFont(timer.font);
		SDL_DestroyTexture(timer.texture);

	}
	if(strcmp(perf,"fps")== 0)  
	{

		cc2d_loadFont("../font/PixelMaster.ttf",&timer);    

		sprintf(texte->charTexte,"fps : %.3f", 1.0 / valeurDeTemps);

		if((TTF_SizeText(timer.font,timer.charTexte, &timer.width, &timer.height)) != 0)  
		{
			printf("TTF_SizeText Error : %s\n",TTF_GetError());
		}	
		cc2d_textureTexte(renderer,&timer);                                          
		SDL_QueryTexture(timer.texture,NULL, NULL, &timer.width,&timer.height);    
		cc2d_DrawTexte(renderer,timer);

		TTF_CloseFont(timer.font);
		SDL_DestroyTexture(timer.texture);

	}
	else
	{
		printf("unknown mode\n");
	}

}

void loadBar()
{
	// Boucle pour afficher la barre de chargement
	for (int i = 0; i < 10; i++) 
	{
		// Affiche le caractère en vert clair
		printf("\033[1;92m▓\033[0m");  // \033[1;92m est pour le vert clair (bright green)
		fflush(stdout);  // Assure que le caractère s'affiche sans délai
		usleep(100000);  // Pause de 100000 microsecondes (0,1 seconde)
	}
	printf("\n");
}


