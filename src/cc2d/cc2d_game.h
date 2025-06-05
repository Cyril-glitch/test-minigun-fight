#ifndef _CC2D_GAME_H
#define _CC2D_GAME_H 

//forward declartions 
typedef struct CC2D_Image CC2D_Image;

void cc2d_gameLoad(void);

void cc2d_gameDraw(void);

void cc2d_gameClose(void);

void cc2d_gameUpdate(void);

void initAmmo(CC2D_Image *projectile);

#endif
