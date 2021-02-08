/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "raspberry.h"

void printmatrp (char mapa[BUFFER_H][BUFFER_H])
{
int i, j;
jcoord_t coord = {0,0};


    for(j=0; j<BUFFER_H ;j++)
    {
        for(i=0; i <BUFFER_H;i++)
        {
            if (mapa[j][i]==BORDER)
            {
            coord.x=j;
            coord.y=i;
            disp_write (coord,D_ON);
            }
            else if (mapa[j][i]==EMPTY)
            {
            coord.x=j;
            coord.y=i;
            disp_write (coord,D_OFF);
            }
        }
    }
}

void printmario(player* Mario)
{
    jcoord_t coord ;
    coord.x= Mario->x;
    coord.y= Mario->y;
    disp_write (coord,D_ON);
}
