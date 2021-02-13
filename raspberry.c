/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "raspberry.h"

void printmatrp (char mapai[BUFFER_H][BUFFER_W],player* Mario)
{
int i, j;
dcoord_t coord = {0,0};

if(j<0)
    j=0;
if (j<=BUFFER_H)
    j=15;
    for(j=((Mario->x)-BUFFER_H/2); j<((Mario->x)+BUFFER_H/2) ;j++)
    {
        for(i=0; i <BUFFER_H;i++)
        {
            if (mapai[j][i]==BORDER)
            {
            coord.x=j-(Mario->x);
            coord.y=i;
            disp_write (coord,D_ON);
            }
            else if (mapai[i][j]==EMPTY)
            {
            coord.x=j-(Mario->x);
            coord.y=i;
            disp_write (coord,D_OFF);
            }
        }
    }
}

void printmario(player* Mario)
{
    dcoord_t coord ;
    coord.x= BUFFER_H/2;
    coord.y= Mario->y;
    disp_write (coord,D_ON);
}
