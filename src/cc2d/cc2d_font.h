#ifndef CC2D_FONT_H
#define CC2D_FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//initialisation des objets textuels

typedef struct CC2D_Texte
{
	TTF_Font* font;
	SDL_Texture* texture;
	SDL_Color color;
	char charTexte[100];
	int r;
	int g;
	int b;
	int a;
	int fontSize;
	int x;
	int y;
	int width;
	int height;
}CC2D_Texte;

//variables

extern CC2D_Texte titre;
extern CC2D_Texte timer;

//fontions

int cc2d_loadFont(const char* path ,CC2D_Texte* texte);

int cc2d_textureTexte(SDL_Renderer* renderer,CC2D_Texte* texte);

int cc2d_DrawTexte(SDL_Renderer* renderer,CC2D_Texte texte);

int cc2d_DrawCenteredTexte(SDL_Renderer* renderer,CC2D_Texte texte,SDL_Window* windoWidth,SDL_Window* windowHeight);


#endif



