///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  raspberry.c
 */
///////////////////////////////////////////////////////////////////////////////
#include "raspberry.h"

void printmatrp (char mapai[BUFFER_H][BUFFER_W],player* Mario)
{
int i, j;
dcoord_t coord = {0,0};


    for(j=0; j <BUFFER_H;j++)
    {
        for(i=((Mario->x)-(BUFFER_H/2)); i<((Mario->x)+(BUFFER_H/2)) ;i++)
        {
            if (mapai[j][i]==BORDER || mapai[j][i]==EXIT0 || mapai[j][i]==EXIT1 || mapai[j][i]==EXIT2|| mapai[j][i]==EXIT3 || mapai[j][i]==EXIT4)
            {
            coord.x=i-((Mario->x)-(BUFFER_H/2));
            coord.y=j;
            disp_write (coord,D_ON);
            }
            else if (mapai[j][i]==EMPTY|| mapai[j][i]==COIN || mapai[j][i]==BLOCKDEATH)
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
    
    if(coord.x<=15 && coord.x>=0 && ((Mario->x) < (en->x + (BUFFER_H/2))))
    {
    
    if(Mario->n_mapa_actual== en->mapa)
    {    
        if(en->active==true)
        {   
            if (en->type == FISH)//dibujo de los peces
            {
                if(en->dodge == false)
                disp_write (coord,D_ON);
                else disp_write (coord,D_OFF);
            }

            if (en->type == REDFISH)//dibujo de los peces rojos
           {
                if(en->dodge == false)
                disp_write (coord,D_ON);
                else disp_write (coord,D_OFF);  
            }

            if (en->type == SQUID)//dibujo de los pulpos
            {
                disp_write (coord,D_ON);
                coord.y++;
                disp_write (coord,D_ON);
            }

            if (en->type == BOSS)//dibujo del boss
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
            if (en->type == MISIL1 ||en->type == MISIL2 ||en->type == MISIL3 ||en->type == MISIL4 ||en->type == MISIL5 ||en->type == MISIL6)//dibujo de los misiles
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
    
    if(((Mario->n_mapa_actual)== (ncoin->map)) && ((ncoin->active) == true) && ((Mario->x) > (ncoin->x - (BUFFER_H/2))) && ((Mario->x) < (ncoin->x + (BUFFER_H/2))) )//se dibuja la moneda solo cuando esté activa y mario se encuentre en el mapa de la misma
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
    
    if (Mario->live==0) //Si se acabaron las vidas aparece la pantalla de game over
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
    if (Mario->win==true)//pantalla de victoria
    {
        for (coord.y = 0; coord.y<BUFFER_H;coord.y++) 
            {
            for (coord.x = 0; coord.x<BUFFER_H;coord.x++) 
            disp_write(coord, D_OFF) ;
            }
        for (coord.y = 2; coord.y<=9;coord.y++) 
            {
            for (coord.x = 4; coord.x<=11;coord.x++) 
            disp_write(coord, D_ON) ;
            }
        for (coord.y = 10; coord.y<=11;coord.y++) 
            {
            for (coord.x = 6; coord.x<=9;coord.x++) 
            disp_write(coord, D_ON) ;
            }
        for (coord.y = 12; coord.y<=13;coord.y++) 
            {
            for (coord.x = 4; coord.x<=11;coord.x++) 
            disp_write(coord, D_ON) ;
            }
        for (coord.y = 3; coord.y<=7;coord.y++) 
            {
            for (coord.x = 2; coord.x<=3;coord.x++) 
            disp_write(coord, D_ON) ;
            }
        for (coord.y = 3; coord.y<=7;coord.y++) 
            {
            for (coord.x = 12; coord.x<=13;coord.x++) 
            disp_write(coord, D_ON) ;
            }
        coord.x=3; 
        for (coord.y = 4; coord.y<=6;coord.y++) 
            {  
            disp_write(coord, D_ON) ;
            }
        coord.x=12;
        for (coord.y = 4; coord.y<=6;coord.y++) 
            {
            disp_write(coord, D_ON) ;
            }
        coord.x=4;
        coord.y=9;
        disp_write(coord, D_OFF) ;
        coord.x=11;
        disp_write(coord, D_OFF) ;
    }
}


 


