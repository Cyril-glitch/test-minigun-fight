#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "cc2d_font.h"
#ifndef CC2DD_GRAPHICS_H 
#define CC2D_GRAPHICS_H

//création des objets
typedef struct CC2D_Image
{
	SDL_Texture* texture;
	int x;
	int y;
	int Width;
	int Height;
	int a; 
}CC2D_Image;

//intialisation des valeurs Alpha
extern const int blend ;
extern const int semi_blend ;
extern  const int alpha ;

//initialisation SDL + Fenetre


extern SDL_Window* window;
extern SDL_Renderer* renderer;


extern int windowW ;
extern int windowH ;
extern int gameWidth ;
extern int gameHeight ;


//intialisation des objets graphics
extern CC2D_Image indiana;


//initialisatioon des valeurs de temps
extern Uint32 frameStart ;
extern Uint32 now ;
extern double deltaTime ;
extern double elapsedTime ;

//initialisation des valeurs precises
extern Uint64 precise_fst ;
extern Uint64 P_now;
extern double precise_dt ;
extern double precise_elapse ;

int cc2d_init();

void cc2d_close();

int cc2d_beginDraw(SDL_Renderer* renderer);

void cc2d_enddraw(SDL_Renderer* renderer);

int cc2d_init_window(char* titre,int width,int height,int gameWidth,int gameHeigh,SDL_Renderer** renderer,SDL_Window** window);

int cc2d_loadImage(const char* path,SDL_Renderer *renderer,CC2D_Image* image);

void cc2d_Draw(SDL_Renderer* renderer,CC2D_Image image);

SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path);

SDL_Texture* quickLoadTexture(SDL_Renderer *renderer,char* path);

void cc2d_drawRect(SDL_Renderer* renderer,const char* mode , int x ,int y ,int w , int h);

void cc2d_fpsLimiter(Uint32 frameStart , int fps);

void cc2d_Precise_FpsLimiter(Uint64 precise_fst , int fps);


void cc2d_printPerf(const char* perf,SDL_Renderer* renderer,CC2D_Texte* texte,double valeurDeTemps);

void loadBar();
#endif
