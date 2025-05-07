#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_game.h"

#ifndef _MAIN_H_
#define _MAIN_H_



//création du Booleen true
extern int true;

//intialisation des valeurs Alpha
extern const int blend ;
extern const int semi_blend ;
extern  const int alpha ;

//initialisation SDL + Fenetre


extern SDL_Window* window;
extern SDL_Renderer* renderer;


extern int windowWidth ;
extern int windowHeight ;
extern int gameWidth ;
extern int gameHeight ;


//intialisation des objets graphics
extern CC2D_Texture idiana;

//initialisation des objets textuels
extern CC2D_texte titre;

//initialisatioon des valeurs de temps
extern Uint32 frameStart ;
extern Uint32 now ;
extern float deltaTime ;
extern float elapsedTime ;

//initialisation des valeurs precises
extern Uint64 precise_fst ;
extern Uint64 P_now;
extern double precise_dt ;
extern double precise_elapse ;
#endif
