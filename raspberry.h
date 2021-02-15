/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raspberry.h
 * Author: matias
 *
 * Created on 8 de febrero de 2021, 17:22
 */

#ifndef RASPBERRY_H
#define RASPBERRY_H

#include "constantes.h"
#include "libs/termlib.h"
#include "libs/disdrv.h"
#include "libs/joydrv.h"

void printmatrp (char mapai[BUFFER_H][BUFFER_W],player* Mario);
void printmario(player* Mario);
void draw_enemy_rpi (enemy * en, player * Mario);
void draw_coin_rpi (player * Mario,coin* ncoin);
void print_post (bool pausa,player* Mario);

#endif /* RASPBERRY_H */

