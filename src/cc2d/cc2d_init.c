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

//intialisation des valeurs Alpha
const int blend = 255;
const int semi_blend = 125;
const int alpha = 0;

//initialisation SDL + Fenetre

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


int windowWidth = 1000;
int windowHeight = 1000;
int gameWidth = 1000;
int gameHeight = 1000;

/*
//intialisation graphics
CC2D_Texture idiana;
idiana.texture = NULL;
idiana.x = 0;
idiana.y = 0;
idiana.Width = 0;
idiana.Height = 0;

//Pour centrer une texture exemples : int centered_planetX = (windowWidth - planetWidth) / 2 ;
CC2D_Texture titre;
titre.texIdiana = NULL;
titre.x = 0;
titre.y = 0;
titre.Width = 0;
titre.Height = 0;
*/

//initialisation font et textes
TTF_Font* retroFont = NULL;

int sizeFont1 = 100;
int retroFontWidth =0 ;
int retroFontHeight =0 ;


//initialisatioon des valeurs de temps
Uint32 frameStart = 0;
Uint32 now = 0 ;
float deltaTime = 0 ;
float elapsedTime = 0 ;

//initialisation des valeurs precises
Uint64 precise_fst = 0;
Uint64 P_now = 0;
double precise_dt = 0;
double precise_elapse = 0 ;




