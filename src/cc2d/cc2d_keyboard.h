#include <SDL2/SDL.h>

#ifndef CC2D_KEYBOARD_H
#define CC2D_KEYBOARD_H


#include <SDL2/SDL.h>

//forward declaration

typedef struct CC2D_Image CC2D_Image;
typedef struct CC2D_Anime CC2D_Anime;

//fonctions 

int cc2d_downKey(SDL_Scancode key);


void cc2d_playerMovement(CC2D_Image* p1,CC2D_Image* hpBar);

void cc2d_player2_Movement(CC2D_Image* p2,CC2D_Image* hpBar);

void cc2d_shoot(SDL_Renderer* renderer,CC2D_Image* projectile,CC2D_Image* playerImage,CC2D_Image* enemie,CC2D_Image* enemieHpBari,const char* player);

#endif


