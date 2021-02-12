/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estructuras.h
 * Author: matias
 *
 * Created on 7 de febrero de 2021, 14:24
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

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
    int coins;
    bool coin_obt;
    unsigned int timer;
    unsigned int score;
    bool exit_pass;
    
}player;

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

typedef struct
{
    bool active;
    float x;
    float y;
    char map;
}coin;



#endif /* ESTRUCTURAS_H */

