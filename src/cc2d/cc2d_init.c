#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_keyboard.h"

//intialisation de la condition de boucle

int true = 1;

//initialisation SDL + Fenetre

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


int windowWidth = 1000;
int windowHeight = 1000;
int gameWidth = 250;
int gameHeight = 250;


//intialisation graphics
int planetX = 0;
int planetY = 0;
int planetWidth = 100 ;
int planetHeight = 100 ;

//initialisation font et textes
TTF_Font* retroFont = NULL;
int sizeFont1 = 50 ;
int retroFontWidth = 100;
int retroFontHeight = 100;


//initialisatioon des valeurs de temps
Uint32 frameStart = 0;
float deltaTime = 0 ;
float elapsedTime = 0 ;

//initialisation des valeurs precises
Uint64 precise_fst = 0;
double precise_dt = 0;
double precise_elapse = 0 ;




