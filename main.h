///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  main.h
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef MAIN_H
#define MAIN_H

/***********************************************************
			Headers
***********************************************************/
#include "enemigos_y_monedas.h"
#include "mapas.h"

#ifdef RPI
#include "raspberry.h"
#endif

#ifdef ALLEGRO
#include "allegro.h"
#endif /*ALLEGRO*/

/***********************************************************
           Prototipos de variables globales
***********************************************************/
extern char mapa[BUFFER_H][BUFFER_W]; 
extern char mapainicio[BUFFER_H][BUFFER_W]; 

#endif /* MAIN_H */

