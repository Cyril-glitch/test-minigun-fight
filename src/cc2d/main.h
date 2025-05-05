#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_game.h"
#include "cc2d_keyboard.h"

#ifndef _MAIN_H_
#define _MAIN_H

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

//intialisation graphics
extern SDL_Texture* texPlanet;

extern int planetX ;
extern int planetY ;
extern int planetWidth;
extern int planetHeight;
extern int centered_planetX ;
extern int centered_planetY ;
extern int new_planetWidth ;
extern int new_planetHeight ;

extern SDL_Texture* texTitre;

extern int titreWidth;
extern int titreX ;
extern int titreY ;
extern int titreWidth;
extern int titreHeight;
extern int centered_titreX ;
extern int centered_titreY ;

//initialisation font et textes
extern int sizeFont1 ;
extern TTF_Font* retroFont;
extern int retroFontWidth;
extern int retroFontHeight;


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
