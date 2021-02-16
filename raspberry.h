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

/*
 * @brief Imprime la parte visible de la matriz en el display 
 * @param1 Mapa en el que estamos
 * @param2 Jugador en el mapa
*/
void printmatrp (char mapai[BUFFER_H][BUFFER_W],player* Mario);

/*
 * @brief Dibuja al jugador en el display
 * @param1 Jugador a imprimir/dibujar
*/
void printmario(player* Mario);

/*
 * @brief Dibuja a los enemigos si estan cerca del jugador
 * @param1 Enemigo a dibujar
 * @param2 Jugador para cargar los enemigos
*/
void draw_enemy_rpi (enemy * en, player * Mario);

/*
 * @brief Dibuja una moneda si hay un jugador cerca
 * @param1 Moneda
 * @param2 Jugador para cargar la moneda
*/
void draw_coin_rpi (player * Mario,coin* ncoin);

/*
 * @brief Imprime mensajes y menus en el display
 * @param1 Flag de pausa
 * @param2 Jugador
*/
void print_post (bool pausa,player* Mario);

#endif /* RASPBERRY_H */

