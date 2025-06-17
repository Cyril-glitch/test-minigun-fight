#ifndef CC2D_GRAPHICS_H 
#define CC2D_GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//création des objets

typedef struct CC2D_PastColision
{
	int right;
	int left;
	int up;
	int down;
}CC2D_PastColision;

typedef struct CC2D_Anime 
{
	int first;
	int last;
	float frame;
	float speed;
	int loop;

}CC2D_Anime;

 enum AnimationState{

	 WALK,
	 FIRE,
	 DIE,
	 IDLE,
	 STATE_MAX
};

typedef struct CC2D_PlayerState
{
	int hp;
	int heart;
	int dead;
	int deathCounter;

}CC2D_PlayerState;

typedef struct CC2D_Image
{
	SDL_Texture* texture;
	SDL_Rect rectSrc;
	SDL_Rect rectDst;
	CC2D_Anime animation[STATE_MAX];
	int animationState;

	int realWidth;
	int realHeight;

	int a; 

	double angle;
	SDL_Point center;
	int flipH;
	int flipV;
	CC2D_PastColision pastColision;

	int affichable;
	int shootedRight;
	int shootedLeft;
	int damage;
	int bulletSpeed;
	int hit;

	
	CC2D_PlayerState state;


}CC2D_Image;



typedef struct CC2D_Window 
{
SDL_Window* sdlWindow;
const char* titreWindow;
int x;
int y;
int width ;
int height ;
Uint32 flags ;
}CC2D_Window;



//forward declartions 
typedef struct CC2D_Texte CC2D_Texte;

//intialisation des valeurs Alpha
extern const int blend ;
extern const int semi_blend ;
extern  const int alpha ;

//initialisation SDL + Fenetre


extern CC2D_Window myWindow;
extern SDL_Renderer* renderer;


extern int gameWidth ;
extern int gameHeight ;

//intialisation des objets graphics
extern CC2D_Image land;
extern CC2D_Image indiana;
extern CC2D_Image indiana_2;

extern CC2D_Image bulletP1[10];
extern CC2D_Image bulletP2[10];

extern CC2D_Image hpBar_out_p1;
extern CC2D_Image hpBar_in_p1;

extern CC2D_Image hpBar_out_p2;
extern CC2D_Image hpBar_in_p2;

//variables graphics



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

int cc2d_init_window(CC2D_Window* window,SDL_Renderer** renderer,int gameWidht,int gameHeight);

int cc2d_loadImage(const char* path,SDL_Renderer *renderer,CC2D_Image* image);

void cc2d_draw(SDL_Renderer* renderer,CC2D_Image image);

void cc2d_drawQuad(SDL_Renderer* renderer,CC2D_Image image);

void cc2d_drawAnime(SDL_Renderer* renderer,CC2D_Image* image );

void cc2d_drawAnimeLoop(SDL_Renderer* renderer,CC2D_Image* image);

SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path);

SDL_Texture* quickLoadTexture(SDL_Renderer *renderer,char* path);

void cc2d_drawRect(SDL_Renderer* renderer,const char* mode , int x ,int y ,int w , int h);

void cc2d_fpsLimiter(Uint32 frameStart , int fps);

void cc2d_Precise_FpsLimiter(Uint64 precise_fst , int fps);

int cc2d_printPerf(const char* perf,SDL_Renderer* renderer,CC2D_Texte* texte,double valeurDeTemps);

void loadBar();

#endif
