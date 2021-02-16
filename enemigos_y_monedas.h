///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  enemigos_y_monedas.h
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ENEMIGOS_Y_MONEDAS_H
#define ENEMIGOS_Y_MONEDAS_H

/***********************************************************
			Headers
***********************************************************/
#include "constantes.h"
#include "mapas.h"

/***********************************************************
	Prototipos de funciones globales
***********************************************************/

/*
 * @brief activa el movimiento de un enemigo
 * @param param1 puntero del enemigo
 * @param param2 puntero de mario
*/
void enemy_mov (enemy * en, player* Mario);

/*
 * @brief activa un enemigo y le asigna sus valores
 * @param param1 puntero del enemigo
 * @param param2 estado de actividad del enemigo
 * @param param3 tipo de enemigo
 * @param param4 mapa en el que se encuentra 
 * @param param5 coordenada x del enemigo
 * @param param6 coordenada y del enemigo
 * @param param7 flag con diferentes usos dependiendo el enemigo
 * @param param8 temporizador con diferentes usos dependiendo el enemigo
*/
void enemy_start (enemy * en,bool active,char type,char mapa,float x,float y,bool dodge,int time);

/*
 * @brief activa el escaneo de colisiones de una moneda
 * @param param1 puntero de mario
 * @param param2 puntero de la moneda
*/
void fcoin(player * Mario,coin* ncoin);

/*
 * @brief activa una moneda y le asigna sus valores
 * @param param1 puntero de la moneda
 * @param param2 coordenada x de la moneda
 * @param param3 coordenada y de la moneda
 * @param param4 mapa en el que se encuentra la moneda
 * @param param5 flag que indica si acaba de empezar el juego
*/
void coin_start(coin* ncoin,float x,float y,char map, bool startup);

/*
 * @brief Destecta si mario choco con un enemigo
 * @param param1 coordenada x de la esquina superior izquierda del objeto
 * @param param2 coordenada y de la esquina superior izquierda del objeto
 * @param param3 coordenada x de la esquina inferior derecha del objeto
 * @param param4 coordenada y de la esquina inferior derecha del objeto
 * @param param5 puntero de mario
 * @return devuelve 1 si choco o 0 si no lo hizo
*/
bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario);

/*
 * @brief Destecta si mario choco con una moneda
 * @param param1 coordenada x de la esquina superior izquierda del objeto
 * @param param2 coordenada y de la esquina superior izquierda del objeto
 * @param param3 coordenada x de la esquina inferior derecha del objeto
 * @param param4 coordenada y de la esquina inferior derecha del objeto
 * @param param5 puntero de mario
 * @return Devuelve 1 si choco o 0 si no lo hizo
*/
bool collide_coin(float ax1, float ay1, float ax2, float ay2, player* Mario);

/***********************************************************
           Prototipos de variables globales
***********************************************************/
extern char mapa1[BUFFER_H][BUFFER_W];
extern char mapa2[BUFFER_H][BUFFER_W];
extern char mapa3[BUFFER_H][BUFFER_W];

#endif /* ENEMIGOS_Y_MONEDAS_H */

