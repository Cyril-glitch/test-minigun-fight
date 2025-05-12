
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


int windowW = 1000;
int windowH = 1000;
int gameWidth = 1000;
int gameHeight = 1000;

//initialisation des objets textuels
CC2D_Texte titre = {
.font = NULL,
.texture = NULL,
.charTexte = "Mini-Gun-Fight",
.color.r = 255,
.color.g = 255,
.color.b = 255,
.color.a = blend,
.fontSize = 50,
.x = 0,
.y = 0,
.width = 0,
.height = 0,
};

CC2D_Texte timer = {
.font = NULL,
.texture = NULL,
.color.r = 255,
.color.g = 255,
.color.b = 255,
.color.a = blend,
.fontSize = 50,
.x = 785,
.y = 0,
.width = 0,
.height = 0,
};


//intialisation graphics                      pour obtenir centre faire :( windowW - windowH ) / 2
CC2D_Image indiana = {
.texture = NULL,
.x = 0,
.y =488 ,                          
.Width = 0,
.Height = 0,
.a = blend,
};

//initialisatioon des valeurs de temps
Uint32 frameStart = 0;
Uint32 now = 0 ;
double deltaTime = 0 ;
double elapsedTime = 0 ;

//initialisation des valeurs precises
Uint64 precise_fst = 0;
Uint64 P_now = 0;
double precise_dt = 0;
double precise_elapse = 0 ;




