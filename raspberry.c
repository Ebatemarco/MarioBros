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
            if (mapai[j][i]==BORDER || mapai[j][i]==EXIT0 || mapai[j][i]==EXIT2 || mapai[j][i]==EXIT4)
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

void draw_enemy_rpi (enemy * en, player * Mario)
{
    dcoord_t coord ;
    int i,j;
    coord.x= (uint8_t)((en->x)-(Mario->x-(BUFFER_H/2)));
    coord.y= (uint8_t)(en->y);
    
    if(coord.x<=15 && coord.x>=0)
    {
    
    if(Mario->n_mapa_actual== en->mapa)
    {    
        if (en->type == BOSS)
                {
                if (en->timer <= 0)
                    {
                    printf("explosion");/*
                    if (en->timer > -30*1) 
                    al_draw_bitmap(*(bitm->p_explosion1), (en->x)+5, (en->y)-6, 0);
                    else if (en->timer > -30*2)
                    al_draw_bitmap(*(bitm->p_explosion2), (en->x)+5, (en->y)-6, 0);
                    else if (en->timer > -30*3)
                    al_draw_bitmap(*(bitm->p_explosion3), (en->x)+5, (en->y)-6, 0);*/
                    }
                }

        if(en->active==true)
        {   
            if (en->type == FISH)
            {
                if(en->dodge == false)
                disp_write (coord,D_ON);
                else disp_write (coord,D_OFF);
            }

            if (en->type == REDFISH)
           {
                if(en->dodge == false)
                disp_write (coord,D_ON);
                else disp_write (coord,D_OFF);  
            }

            if (en->type == SQUID)
            {
                disp_write (coord,D_ON);
                coord.y++;
                disp_write (coord,D_ON);
                /*if(en->dodge == false)
                al_draw_bitmap(*(bitm->p_squid1), (en->x), (en->y), 0);
                else al_draw_bitmap(*(bitm->p_squid2), (en->x), (en->y), 0); */ 
            }

            if (en->type == BOSS)
            {
            coord.x++;
            coord.y--;
            for(i=0; i<=3;i++)
                {
                coord.y++;
                for(j=0; j<=3;j++)
                    {
                    coord.x--;
                    disp_write(coord, D_ON);
                    }
                coord.x= (coord.x)+ 4;
                }
            }
            if (en->type == MISIL1 ||en->type == MISIL2 ||en->type == MISIL3 ||en->type == MISIL4 ||en->type == MISIL5 ||en->type == MISIL6)
            disp_write (coord,D_ON);
        }
    
    }
    
    }
}

void draw_coin_rpi(player * Mario,coin* ncoin)
{
    dcoord_t coord ;
    coord.x= (uint8_t)((ncoin->x)-(Mario->x-(BUFFER_H/2)));
    coord.y= (uint8_t)(ncoin->y);

    if(((Mario->n_mapa_actual)== (ncoin->map)) && ((ncoin->active) == true))//se dibuja la moneda solo cuando esté activa y mario se encuentre en el mapa de la misma
       {
       disp_write (coord,D_ON);
       }
}

void print_post (bool pausa,player* Mario)
{
    dcoord_t coord={0,0};
    //Dibujo de otros mensajes
    if (pausa==true)
        {
        
        for (coord.y = 0; coord.y<BUFFER_H;coord.y++) 
            {
            for (coord.x = 0; coord.x<BUFFER_H;coord.x++) 
            disp_write(coord, D_OFF) ;
            }
        
        if(Mario->n_mapa_actual==MAPAINICIO && Mario->x==((float)XPANTALLA) )//pantalla de inicio
            {
            coord.x=4;
            for(coord.y = 4; coord.y<=11;coord.y++)
                disp_write(coord, D_ON);
            coord.x=5;
            for(coord.y = 4; coord.y<=11;coord.y++)
                disp_write(coord, D_ON);
            coord.x=10;
            for(coord.y = 4; coord.y<=11;coord.y++)
                disp_write(coord, D_ON);
            coord.x=11;
            for(coord.y = 4; coord.y<=11;coord.y++)
                disp_write(coord, D_ON);
            
            coord.y=6;
            for (coord.x = 6; coord.x<=9;coord.x++)
                disp_write(coord, D_ON);
            
            coord.x=6;
            coord.y=5;
            disp_write(coord, D_ON);
            coord.x=9;
            disp_write(coord, D_ON);
            coord.x=7;
            coord.y=7;
            disp_write(coord, D_ON);
            coord.x=8;
            disp_write(coord, D_ON);
            
            }
        else //pantalla de pausa
            {
            coord.x=6;
            for (coord.y=6; coord.y<=9;coord.y++) 
                disp_write(coord, D_ON);
            coord.x=9;
            for (coord.y=6; coord.y<=9;coord.y++) 
                disp_write(coord, D_ON);
            }
        }
    
    if (Mario->live==0) //Si se acabaron las vidas aparece el cartel de game over
    {
        for (coord.y = 0; coord.y<BUFFER_H;coord.y++) 
            {
            for (coord.x = 0; coord.x<BUFFER_H;coord.x++) 
            disp_write(coord, D_OFF) ;
            }
        for (coord.y = 0; coord.y<BUFFER_H;coord.y++) 
            {
            for (coord.x = 0; coord.x<BUFFER_H;coord.x++) 
            disp_write(coord, D_ON) ;
            }
        
        coord.x=5;
        coord.y=6;
        disp_write(coord, D_OFF);
        coord.x=9;
        disp_write(coord, D_OFF);

        coord.x=5;
        coord.y=10;
        disp_write(coord, D_OFF);
        coord.x=9;
        disp_write(coord, D_OFF);

        coord.y=9;
        for (coord.x=6; coord.x<=8;coord.x++) 
                    disp_write(coord, D_OFF);
    }
}


 


