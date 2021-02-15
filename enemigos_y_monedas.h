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

#ifndef ENEMIGOS_Y_MONEDAS_H
#define ENEMIGOS_Y_MONEDAS_H

#include "constantes.h"
#include "mapas.h"

bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario);

void enemy_mov (enemy * en, player* Mario);

void enemy_start (enemy * en,bool active,char type,char mapa,float x,float y,bool dodge,int time);

void fcoin(player * Mario,coin* ncoin);

void coin_start(coin* ncoin,float x,float y,char map, bool startup);




#endif /* ENEMIGOS_Y_MONEDAS_H */

