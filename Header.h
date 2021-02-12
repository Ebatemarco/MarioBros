/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Header.h
 * Author: ebatemarco
 *
 * Created on February 5, 2021, 3:26 PM
 */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



#define FPS    60.0

#define BUFFER_W 3103
#define BUFFER_H 224
#define DISP_SCALE 4
#define SCREEN_W (BUFFER_H * DISP_SCALE)
#define SCREEN_H (BUFFER_H * DISP_SCALE)

#define MARIO_SIZE 15
#define MOVE_RATE  2.0
#define SALTO_H 25 //Altura del salto de mario
#define SALTO_SPEED 1 //Velocidad de la subida al saltar
#define MARIO_W 16 //Tamaño del sprite
#define MARIO_H 16 //Tamaño del sprite
#define MARIO_LIVES 10
#define XINICIAL 55
#define YINICIAL 70
#define LEVEL_TIME 240

#define MAPAINICIO 0
#define MAPA1 1
#define FINALMAPA1 (MAPA1+10)
#define MAPA2 2
#define FINALMAPA2 (MAPA2+10)
#define MAPA3 3

#define MAPAINICIO_W 500
#define MAPA1_W 3103
#define FINALMAPA1_W  564
#define MAPA2_W  2200
#define FINALMAPA2_W  564
#define MAPA3_W  338

#define EXIT4 8
#define EXIT3 7
#define EXIT2 6
#define EXIT1 5
#define EXIT0 4
#define COIN 3
#define BORDER 2
#define BLOCKDEATH 1
#define EMPTY 0

#define COIN_SIZE 15.0

#define MISIL6 10
#define MISIL5 9
#define MISIL4 8
#define MISIL3 7
#define MISIL2 6
#define MISIL1 5
#define BOSS 4
#define SQUID 3
#define REDFISH 2
#define FISH 1

#define MOVE_RATE_FISH  4.0
#define MOVE_RATE_REDFISH  2.0
#define MOVE_RATE_SQUID 2.0
#define DODGE_DIST 40
#define FISH_DIST 15

#define FISH_SIZE 16
#define SQUID_H 24
#define SQUID_W 16
#define BOSS_H 50
#define BOSS_W 75
#define MISIL_SIZE 10

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

enum MYKEYS 
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT , KEY_P ,KEY_R
};



void clonarMatrizMain(); 
   
void Barriers ();     

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario);

void enemy_mov (enemy * en, player* Mario);

void enemy_start (enemy * en,bool active,char type,char mapa,float x,float y,bool dodge,int time);

void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]);

void fcoin(player * Mario,coin* ncoin);

void coin_start(coin* ncoin,float x,float y,char map, bool startup);








#endif /* HEADER_H */

