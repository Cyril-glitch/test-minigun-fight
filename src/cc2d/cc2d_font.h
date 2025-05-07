#ifndef CC2D_FONT_H
#define CC2D_FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct CC2D_Texte
{
	TTF_font* font;
	SDL_Texture* texture;
	SDL_Color color;
	int r;
	int g;
	int b;
	int a;
	int fontSize;
	int x;
	int y;
	int width;
	int height;
	int centerX;
	int centerY;
}CC2D_Texte;

TTF_Font* cc2d_loadFont(const char* path ,CC2D_Texte texte);

SDL_Texture* cc2d_textureTexte(char* texte ,SDL_Renderer* renderer,TTF_Font* font,CC2D_texte texte);

#endif



