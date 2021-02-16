///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  mapas.h
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef MAPAS_H
#define MAPAS_H

/***********************************************************
			Headers
***********************************************************/
#include "constantes.h"

/***********************************************************
	Prototipos de funciones globales
***********************************************************/
/*
 * @brief carga todas las barreras de los mapas
*/
void barriers ();     

/*
 * @brief carga un tipo de borde en el mapa solicitado
 * @param param1 coordenada x de la esquina superior izquierda 
 * @param param2 coordenada y de la esquina superior izquierda
 * @param param3 coordenada x de la esquina inferior derecha
 * @param param4 coordenada y de la esquina inferior derecha 
 * @param param5 mapa
 * @param param6 tipo de borde
*/
void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

/*
 * @brief clona una matriz
 * @param param1 matriz origen
 * @param param2 matriz destino
*/
void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]);

/*
 * @brief Destecta si mario choco co un borde del mapa
 * @param param1 coordenada x de la esquina superior izquierda de mario
 * @param param2 coordenada y de la esquina superior izquierda de de mario
 * @param param3 coordenada x de la esquina inferior derecha de de mario
 * @param param4 coordenada y de la esquina inferior derecha de de mario
 * @param param5 mapa actual de amario
 * @return devuelve 1 si chco o 0 si no lo hizo
*/
bool collidewborder(player* , int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W]); 

#endif /* MAPAS_H */

