///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  allegro.h
 */
///////////////////////////////////////////////////////////////////////////////


#ifndef ALLEGRO_H
#define ALLEGRO_H

/***********************************************************
			Headers
***********************************************************/
#include "constantes.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

/***********************************************************
                Definición de Estructura
***********************************************************/
typedef struct
{
ALLEGRO_BITMAP *(*p_fish1);
ALLEGRO_BITMAP *(*p_fish2);
ALLEGRO_BITMAP *(*p_redfish1);
ALLEGRO_BITMAP *(*p_redfish2);
ALLEGRO_BITMAP *(*p_squid1);
ALLEGRO_BITMAP *(*p_squid2);
ALLEGRO_BITMAP *(*p_coin);
ALLEGRO_BITMAP *(*p_boss);
ALLEGRO_BITMAP *(*p_misil);
ALLEGRO_BITMAP *(*p_explosion1);
ALLEGRO_BITMAP *(*p_explosion2);
ALLEGRO_BITMAP *(*p_explosion3);
}bitmaps_t;

enum MYKEYS 
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT , KEY_P ,KEY_R
};

/***********************************************************
	Prototipos de funciones globales
***********************************************************/

/*
 * @brief dibuja una moneda con las funciones de allegro
 * @param param1 puntero de mario
 * @param param2 puntero de la moneda
 * @param param3 puntero a los bitmaps
*/
void draw_coin(player * Mario,coin* ncoin,bitmaps_t * bitm);

/*
 * @brief dibuja el background con las funciones de allegro
 * @param param1 puntero del buffer
 * @param param2 puntero de mario
 * @param param3 puntero a los bitmaps
*/
void disp_pre_draw(ALLEGRO_BITMAP* buffer, player* Mario,ALLEGRO_BITMAP *(*p_background));

/*
 * @brief dibuja con las funciones de allegro el HUD, mensajes y otras pantallas
 * @param param1 puntero del display
 * @param param2 puntero del buffer
 * @param param3 puntero a bitmap
 * @param param4 puntero a bitmap
 * @param param5 puntero a mario 
 * @param param6 fuente de allegro
 * @param param7 flag de pausa
*/
void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* buffer,ALLEGRO_BITMAP* menupausa,ALLEGRO_BITMAP* gameover,ALLEGRO_BITMAP* winscreen, player* Mario, ALLEGRO_FONT * font,bool pausa);

/*
 * @brief dibuja un enemigo con las funciones de allegro
 * @param param1 puntero de mario
 * @param param2 puntero del enemigo
 * @param param3 puntero a los bitmaps
*/
void draw_enemy (enemy * en, player * Mario, bitmaps_t * bit);

/***********************************************************
           Prototipos de variables globales
***********************************************************/
extern char mapainicio[BUFFER_H][BUFFER_W];
extern char mapa3[BUFFER_H][BUFFER_W];
extern char finalmapa2[BUFFER_H][BUFFER_W];
extern char mapa1[BUFFER_H][BUFFER_W];
extern char finalmapa1[BUFFER_H][BUFFER_W];
extern char mapa2[BUFFER_H][BUFFER_W];
extern char mapa[BUFFER_H][BUFFER_W]; 

#endif /* ALLEGRO_H */

