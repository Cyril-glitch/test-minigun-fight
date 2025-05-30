#ifndef CC2D_KEYBOARD_H
#define CC2D_KEYBOARD_H

#include <SDL2/SDL.h>

//forward declaration

typedef struct CC2D_Image CC2D_Image;
typedef struct CC2D_Anime CC2D_Anime;

//fonctions 

int cc2d_downKey(SDL_Scancode key);

void cc2d_playerMovement(CC2D_Image* playerImage,CC2D_Anime* playerAnime,CC2D_Image* player2_Image);

void cc2d_player2_Movement(CC2D_Image* player2_Image,CC2D_Anime* player2_Anime, CC2D_Image* playerImage);

int colision(CC2D_Image* playerImage,CC2D_Image* player2_Image);
#endif


