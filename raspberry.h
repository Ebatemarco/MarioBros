///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  raspberry.h
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef RASPBERRY_H
#define RASPBERRY_H

/***********************************************************
			Headers
***********************************************************/
#include "constantes.h"
#include "libs/termlib.h"
#include "libs/disdrv.h"
#include "libs/joydrv.h"

/***********************************************************
	Prototipos de funciones globales
***********************************************************/
void printmatrp (char mapai[BUFFER_H][BUFFER_W],player* Mario);
void printmario(player* Mario);
void draw_enemy_rpi (enemy * en, player * Mario);
void draw_coin_rpi (player * Mario,coin* ncoin);
void print_post (bool pausa,player* Mario);

#endif /* RASPBERRY_H */

