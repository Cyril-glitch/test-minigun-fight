#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"

#ifndef _MAIN_H_
#define _MAIN_H

//création du Booleen true
int true = 1;

//initialisation SDL + Fenetre


extern SDL_Window* window;
extern SDL_Renderer* renderer;


extern int windowWidth ;
extern int windowHeight ;
extern int gameWidth ;
extern int gameHeight ;

#endif
