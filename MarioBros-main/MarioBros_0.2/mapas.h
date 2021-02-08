/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapas.h
 * Author: matias
 *
 * Created on 7 de febrero de 2021, 23:46
 */

#ifndef MAPAS_H
#define MAPAS_H

#include "constantes.h"
   
void barriers ();     

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]);

bool collidewborder(player* , int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W]); 

#endif /* MAPAS_H */

