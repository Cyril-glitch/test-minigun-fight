#include "cc2d_graphics.h"
#include "cc2d_keyboard.h"
#include "cc2d_font.h"

//intialisation de la condition de boucle

int true = 1;

//intialisation des valeurs Alpha
const int blend = 255;
const int semi_blend = 125;
const int alpha = 0;

//initialisation SDL + Fenetre

CC2D_Window myWindow = {
.sdlWindow = NULL,
.titreWindow = "Mini-Gun-Fight", 
.x = SDL_WINDOWPOS_CENTERED,
.y = SDL_WINDOWPOS_CENTERED,
.width = 1024,
.height = 768,
.flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE ,
};

SDL_Renderer* renderer = NULL;

int gameWidth = 512;
int gameHeight = 384;


//intialisation graphics                      pour obtenir centre faire :( windowW - image.x ) / 2
CC2D_Image indiana = {
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 25,
.rectSrc.h = 24, 

.rectDst.x = 0,
.rectDst.y = 179.5,
.rectDst.w = 50,
.rectDst.h = 48, 

.width = 50,
.height = 48,
.a = blend,
};

//variables graphics

float frame = 0;

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
.fontSize = 12.5,
.x = 455,
.y = 0,
.width = 0,
.height = 0,
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




