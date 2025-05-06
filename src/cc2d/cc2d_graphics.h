#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef CC2DD_GRAPHICS_H 
#define CC2D_GRAPHICS_H

//création des objets
typedef struct CC2D_Texture
{
	SDL_Texture* texture;
	int x;
	int y;
	int Width;
	int Height;
}CC2D_Texture;

void loadBar();

int cc2d_init();

void cc2d_close();

int cc2d_beginDraw(SDL_Renderer* renderer);

void cc2d_enddraw(SDL_Renderer* renderer);

int cc2d_init_window(char* titre,int width,int height,int gameWidth,int gameHeigh,SDL_Renderer** renderer,SDL_Window** window);

SDL_Texture* cc2d_loadImage(SDL_Renderer *renderer,const char* path);

void cc2d_Draw(CC2D_Texture image,SDL_Renderer* renderer,int x, int y,int a);

SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path);

SDL_Texture* quickLoadTexture(SDL_Renderer *renderer,char* path);

void cc2d_drawRect(SDL_Renderer* renderer,const char* mode , int x ,int y ,int w , int h);

void cc2d_fpsLimiter(Uint32 frameStart , int fps);

void cc2d_Precise_FpsLimiter(Uint64 precise_fst , int fps);

void cc2d_printPerf(const char* perf,double Vperf,SDL_Renderer* renderer,TTF_Font* font);
#endif
