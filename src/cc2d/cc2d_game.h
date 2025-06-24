#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "cc2d_graphics.h"

#ifndef _CC2D_GAME_H
#define _CC2D_GAME_H 

//forward declartions 
typedef struct CC2D_Image CC2D_Image;



void cc2d_gameLoad(void);

void cc2d_gameDraw(void);

void cc2d_gameClose(void);

void cc2d_gameUpdate(void);

void initAmmo(void);

void hitBoxAmmo(CC2D_Image* projectile);

void mapPlayer(PIXEL map[768][1024],SDL_Renderer* renderer);

void mapPx(PIXEL map[768][1024],SDL_Rect h,SDL_Renderer* renderer);

void freshMap(PIXEL map[768][1024]);

int frontColision(PIXEL map[768][1024],CC2D_Image* h);

int backColision(PIXEL map[768][1024],CC2D_Image* h);

int downColision(PIXEL map[768][1024],CC2D_Image* h);

int upColision(PIXEL map[768][1024],CC2D_Image* h);

int bulletDamage(PIXEL map[768][1024],CC2D_Image* projectile);
#endif
