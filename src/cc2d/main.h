#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_game.h"

#ifndef _MAIN_H_
#define _MAIN_H

//création du Booleen true
extern int true;

//initialisation SDL + Fenetre


extern SDL_Window* window;
extern SDL_Renderer* renderer;


extern int windowWidth ;
extern int windowHeight ;
extern int gameWidth ;
extern int gameHeight ;

//intialisation graphics
extern SDL_Texture* texidiana;
extern int idianaX ;
extern int idianaY ;
extern int idianaWidth;
extern int idianaHeight;

//initialisation font et textes
extern int sizeFont1 ;
extern TTF_Font* retroFont;
extern int retroFontWidth;
extern int retroFontHeight;
extern SDL_Texture* Titre;


//initialisatioon des valeurs de temps
extern Uint32 frameStart ;
extern float deltaTime ;
extern float elapsedTime ;

//initialisation des valeurs precises
extern Uint64 precise_fst ;
extern double precise_dt ;
extern double precise_elapse ;
#endif
