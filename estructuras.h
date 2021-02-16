///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  estructuras.h
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

/***********************************************************
                Definición de Estructuras
***********************************************************/

//JUGADOR
typedef struct
{
    char live;//Vidas de Mario
    bool death;//Flag que indica si Mario acaba de morir
    float x;//Posicion x de Mario
    float y;//Posicion y de Mario
    char n_mapa_actual;
    int salto;//variable que indica cuanto debe subir mario tras saltar
    int salto_cooldown;//temporizador que indica cuanto falta para hacer un nuevo salto
    bool salto_lock;//Flag que bloquea el salto de Mario cuando se mantiene apretada la tecla para saltar
    int coins;//cantidad de monedas de mario
    bool coin_obt;//flag que indica si se acaba de obtener una moneda
    unsigned int timer; //timer del nivel
    unsigned int score;//puntuacion actual
    bool exit_pass;//flag para actualizar el background
    bool win;//flag que inidica si ganaste
    
}player;

//ENEMIGO
typedef struct
{
    bool active; // Flag que indica si el enemigo esta activo o no
    char type;// Tipo de enemigo
    char mapa;//Mapa en el que está el enemigo
    float x;//Posicion x del enemigo
    float y;//Posicion y del enemigo
    float prev_pos;//Variable que guarda la posicion previa del pulpo antes de moverse lateralmente
    bool dodge;//Flag que utilizan los pulpos para indicar di deben ir hacia abajo o lateralmente
    int timer;//Temporizador de los misiles que indica cuanto falta para que se activen
}enemy;

//MONEDA
typedef struct
{
    bool active;// Flag que indica si la moneda esta activa o no
    float x;;//Posicion x de la moneda
    float y;//Posicion y de la moneda
    char map;//mapa de la moneda
}coin;



#endif /* ESTRUCTURAS_H */

