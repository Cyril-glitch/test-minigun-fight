#ifndef CC2D_FONT_H
#define CC2D_FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "cc2d_graphics.h"


TTF_Font* cc2d_loadFont(const char* path ,int ftsize);

SDL_Texture* cc2d_textureTexte(char* texte ,SDL_Renderer* renderer,TTF_Font* font,int x,int y,int r,int g,int b,int a);

#endif



