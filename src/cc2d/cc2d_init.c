#include "cc2d_graphics.h"
#include "cc2d_keyboard.h"
#include "cc2d_font.h"

//BOUCLE

int true = 1;




//VALEURS APLHA
const int blend = 255;
const int semi_blend = 125;
const int alpha = 0;




//SDL + WINDOW

CC2D_Window myWindow = {
.sdlWindow = NULL,
.titreWindow = "Mini-Gun-Fight", 
.x = SDL_WINDOWPOS_CENTERED,
.y = SDL_WINDOWPOS_CENTERED,
.width = 1024,
.height = 768,
.flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE ,
};

SDL_Renderer* renderer = NULL;

int gameWidth = 1024;
int gameHeight = 768;

//MAP

PIXEL map[768][1024]={0};



//FOND
CC2D_Image land = {
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 0,
.rectSrc.h = 0, 

.rectDst.x = 0,
.rectDst.y = 0,
.rectDst.w = 1024,
.rectDst.h = 768, 

.realWidth = 0,
.realHeight = 0,
.a = blend,
.angle = 0,
.center = {0,0},
.flipH = 0,
.flipV = 0,
.pastColision = {0,0,0,0},

};






//player 1

CC2D_Image player1 = {

//coordonees et dimensions
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 25,
.rectSrc.h = 24, 

.rectDst.x = 0,
.rectDst.y = 359,
.rectDst.w = 100,
.rectDst.h = 96, 
.speed = 2,

.realWidth = 50,
.realHeight = 48,

//animations
.animation = {

	[WALK] ={
		.first = 0,
		.last = 7,
		.frame = 0,
		.speed = 0.1f,
		.loop = 0,
	},
	[FIRE] ={
		.first = 8,
		.last = 11,
		.frame = 8,
		.speed = 0.1f,
		.loop = 0,
	},
	[DIE] ={
		.first = 12,
		.last = 17,
		.frame = 12,
		.speed = 0.1f,
		.loop = 0,
	},
	[IDLE] ={
		.first = 12,
		.last = 12,
		.frame = 12,
		.speed = 0.0f,
		.loop = 0,
	}
},
.animationState = IDLE,

//rotations
.a = blend,
.angle = 0,
.center = {0,0},
.flipH = 0,
.flipV = 0,
.pastColision = {0,0,0,0},

//etats et stats

.state = {200,3,0,0},

};








//player 2

CC2D_Image player2 = {

//coordonnées et taille
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 25,
.rectSrc.h = 24, 

.rectDst.x = 924,
.rectDst.y = 359,
.rectDst.w = 100,
.rectDst.h = 96, 
.speed= 2,

.realWidth = 0,
.realHeight = 0,
.a = blend,

//animation
.animation = {

	[WALK] ={
		.first = 0,
		.last = 7,
		.frame = 0,
		.speed = 0.1f,
		.loop = 0,
	},
	[FIRE] ={
		.first = 8,
		.last = 11,
		.frame = 8,
		.speed = 0.1f,
		.loop = 0,
	},
	[DIE] ={
		.first = 12,
		.last = 17,
		.frame = 12,
		.speed = 0.1f,
		.loop = 0,
	},
	[IDLE] ={
		.first = 12,
		.last = 12,
		.frame = 12,
		.speed = 0.0f,
		.loop = 0,
	}
},
.animationState = IDLE,

//angles
.angle = 0,
.center = {0,0},
.flipH = 1,
.flipV = 0,
.pastColision = {0,0,0,0},

//stats
.state = {200,3,0,0},
};









//HP BAR P1


CC2D_Image hpBar_out_p1 = {
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 0,
.rectSrc.h = 0, 

.rectDst.x = 40,
.rectDst.y = 30,
.rectDst.w = 244,
.rectDst.h = 36, 

.realWidth = 0,
.realHeight = 0,
.a = blend,
.angle = 0,
.center = {0,0},
.flipH = 0,
.flipV = 0,
.pastColision = {0,0,0,0},

};

CC2D_Image hpBar_in_p1 = {
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 0,
.rectSrc.h = 0, 

.rectDst.x = 78,
.rectDst.y = 42,
.rectDst.w = 200,
.rectDst.h = 12, 

.realWidth = 0,
.realHeight = 0,
.a = blend,
.angle = 0,
.center = {0,0},
.flipH = 0,
.flipV = 0,
.pastColision = {0,0,0,0},

};








//HP BAR P2


CC2D_Image hpBar_out_p2 = {
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 0,
.rectSrc.h = 0, 

.rectDst.x = 728,
.rectDst.y = 30,
.rectDst.w = 244,
.rectDst.h = 36, 

.realWidth = 0,
.realHeight = 0,
.a = blend,
.angle = 0,
.center = {0,0},
.flipH = 0,
.flipV = 0,
.pastColision = {0,0,0,0},

};

CC2D_Image hpBar_in_p2 = {
.texture = NULL,
.rectSrc.x = 0,
.rectSrc.y = 0,
.rectSrc.w = 0,
.rectSrc.h = 0, 

.rectDst.x = 734,
.rectDst.y = 42,
.rectDst.w = 200,
.rectDst.h = 12, 

.realWidth = 0,
.realHeight = 0,
.a = blend,
.angle = 0,
.center = {0,0},
.flipH = 0,
.flipV = 0,
.pastColision = {0,0,0,0},

};

SDL_Rect hitBox1 ={
.x = 0,
.y = 0,
.w = 80,
.h = 100
};

SDL_Rect hitBox2 ={
.x = 0,
.y = 0,
.w = 80,
.h = 100
};




//PROJECTILE
CC2D_Image bulletP1[10];
CC2D_Image bulletP2[10];





//TEXTE
CC2D_Texte titre = {
.font = NULL,
.texture = NULL,
.charTexte = "Mini-Gun-Fight",
.color.r = 255,
.color.g = 0,
.color.b = 0,
.color.a = blend,
.fontSize = 50,
.x = 410,
.y = 0,
.width = 0,
.height = 0,
};

CC2D_Texte timer = {
.font = NULL,
.texture = NULL,
.color.r = 255,
.color.g = 255,
.color.b = 255,
.color.a = blend,
.fontSize = 25,
.x = 910,
.y =740,
.width = 0,
.height = 0,
};





//VALEURS DE TEMPS
Uint32 frameStart = 0;
Uint32 now = 0 ;
double deltaTime = 0 ;
double elapsedTime = 0 ;





//VALEURS DE TEMPS PRECISES
Uint64 precise_fst = 0;
Uint64 P_now = 0;
double precise_dt = 0;
double precise_elapse = 0 ;




