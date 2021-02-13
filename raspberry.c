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


    for(j=0; j <BUFFER_H;j++)
    {
        for(i=((Mario->x)-(BUFFER_H/2)); i<((Mario->x)+(BUFFER_H/2)) ;i++)
        {
            if (mapai[j][i]==BORDER)
            {
            coord.x=i-((Mario->x)-(BUFFER_H/2));
            coord.y=j;
            disp_write (coord,D_ON);
            }
            else if (mapai[j][i]==EMPTY)
            {
            coord.x=i-((Mario->x)-(BUFFER_H/2));
            coord.y=j;
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
