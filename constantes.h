/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   constantes.h
 * Author: matias
 *
 * Created on 7 de febrero de 2021, 14:21
 */

#ifndef CONSTANTES_H
#define CONSTANTES_H

#define _DEFAULT_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include "estructuras.h"

#ifdef ALLEGRO

#define BUFFER_W 3103
#define BUFFER_H 224

#define DISP_SCALE 4
#define SCREEN_W (BUFFER_H * DISP_SCALE)
#define SCREEN_H (BUFFER_H * DISP_SCALE)

#define MARIO_SIZE 15
#define SALTO_H 25 //Altura del salto de mario
#define SALTO_SPEED 1 //Velocidad de la subida al saltar
#define SALTO_COOLDOWN 30
#define MARIO_W 16 //Tamaño del sprite
#define MARIO_H 16 //Tamaño del sprite
#define MOVE_RATE  2.0
#define XINICIAL 55
#define YINICIAL 70
#define XPANTALLA 118
#define YPANTALLA 183

#define COIN_SIZE 15.0

#define MOVE_RATE_FISH  4.0
#define MOVE_RATE_REDFISH  2.0
#define MOVE_RATE_SQUID 2.0
#define MOVE_RATE_MISIL 2.0
#define DODGE_DIST 40
#define FISH_DIST 15

#define MISIL1_TURN_COORD -80
#define MISIL2_TURN_COORD -40
#define MISIL4_TURN_COORD 10
#define MISIL5_TURN_COORD 30
#define BOSS_STOP -50

#define FISH_SIZE 16
#define SQUID_H 24
#define SQUID_W 16
#define BOSS_H 50
#define BOSS_W 75
#define MISIL_SIZE 10



#endif /* ALLEGRO */


#ifdef RPI

#define TIEMPO 16677
#define MINX 60
#define MAXX 127
#define MINY 60
#define MAXY 127
#define COORDSCALE 0.07142

#define BUFFER_W 222
#define BUFFER_H 16

#define DISP_SCALE 4
#define SCREEN_W (BUFFER_H * DISP_SCALE)
#define SCREEN_H (BUFFER_H * DISP_SCALE)

#define MARIO_SIZE 0
#define SALTO_H 4 //Altura del salto de mario
#define SALTO_SPEED 2 //Velocidad de la subida al saltar
#define SALTO_COOLDOWN 20
#define MARIO_W 1 //Tamaño del sprite
#define MARIO_H 1 //Tamaño del sprite
#define MOVE_RATE  1.0
#define XINICIAL 5
#define YINICIAL 8
#define XPANTALLA 5
#define YPANTALLA 8

#define COIN_SIZE 1

#define MOVE_RATE_FISH  16.0
#define MOVE_RATE_REDFISH  8.0
#define MOVE_RATE_SQUID 16.0
#define MOVE_RATE_MISIL 16.0
#define DODGE_DIST 2
#define FISH_DIST 0.3

#define MISIL1_TURN_COORD -6
#define MISIL2_TURN_COORD -3
#define MISIL4_TURN_COORD 1
#define MISIL5_TURN_COORD 2
#define BOSS_STOP +5


#define FISH_SIZE 1
#define SQUID_H 2
#define SQUID_W 1
#define BOSS_H 4
#define BOSS_W 5
#define MISIL_SIZE 1

/*#define MAPAINICIO_W 35
#define MAPA1_W 220
#define FINALMAPA1_W  40
#define MAPA2_W  156
#define FINALMAPA2_W  40
#define MAPA3_W  23*/

#endif /* RPI */

#define FPS    60.0
#define MARIO_LIVES 10
#define LEVEL_TIME 240

#define MAPAINICIO 0
#define MAPA1 1
#define FINALMAPA1 (MAPA1+10)
#define MAPA2 2
#define FINALMAPA2 (MAPA2+10)
#define MAPA3 3

#define EXIT4 8
#define EXIT3 7
#define EXIT2 6
#define EXIT1 5
#define EXIT0 4
#define COIN 3
#define BORDER 2
#define BLOCKDEATH 1
#define EMPTY 0

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

#define MAPAINICIO_W 500
#define MAPA1_W 3103
#define FINALMAPA1_W  564
#define MAPA2_W  2200
#define FINALMAPA2_W  564
#define MAPA3_W  338


#endif /* CONSTANTES_H */

