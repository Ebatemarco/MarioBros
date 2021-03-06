///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  enemigos_y_monedas.c
 */
///////////////////////////////////////////////////////////////////////////////

#include "enemigos_y_monedas.h"


void enemy_mov (enemy * en, player* Mario ) 
{
if((Mario->n_mapa_actual)== en->mapa)
{
    float xhitbox;
    float yhitbox;
    
    #ifdef RPI
    xhitbox= floor(en->x);
    yhitbox= floor(en->y);
    if (en->type==BOSS)
    {
    xhitbox= xhitbox-4;
    yhitbox--;
    }
    #endif
    
    #ifdef ALLEGRO
    xhitbox= en->x;
    yhitbox= en->y;
    #endif
    
    //Generacion de enemigos
    if (((Mario->x) >= (en->x - (BUFFER_H/2)) ) || (Mario->n_mapa_actual == MAPA3))//solo se activará el enemigo cuando se encuentre en el campo de vision de mario
    {
        (en->active) =true;
 
            if(en->type == BOSS )
            {
                en->timer --;
                if(en->timer <= 0)
                    (en->active)=false;
            }
            else 
            {
                if(en->timer > 0)
                {
                en->timer --;
                (en->active)=false;
                }
                else if (en->type == MISIL6)
                en->timer --; 
            #ifdef ALLEGRO   
            if (en->type==MISIL6 && en->timer<=-60*19)
                    en->active=false;
            #endif
            #ifdef RPI                
            if (en->timer <= (-60*19*TIME_SCALE))
                            en->active=false;
            #endif
            }
    }
        
    //Movimiento de enemigos

    if (en->active == true)
        {

            if (en->type == FISH || en->type == REDFISH) //Movimiento de los peces
                {
                if ( collide_entity(xhitbox, yhitbox, xhitbox+FISH_SIZE, yhitbox+FISH_SIZE, Mario) )
                    {
                    Mario->death=true; 
                    }
                if (en->x < (en->prev_pos - FISH_DIST))
                    {
                    en->prev_pos = en->x;
                    if (en->dodge == false)
                        en->dodge =true;
                    else en->dodge =false;
                    }
                if (en->type == FISH)
                (en->x) -= (1/MOVE_RATE_FISH);

                if (en->type == REDFISH)
                (en->x) -= (1/MOVE_RATE_REDFISH);
                }

            if (en->type == SQUID)//Movimiento de los pulpos
                {
                if ( collide_entity(xhitbox, yhitbox, xhitbox+SQUID_W, yhitbox+SQUID_H, Mario) )
                    {
                    Mario->death=true;
                    }
                if (((en->y) > (en->prev_pos - DODGE_DIST))&&(en->dodge == false))
                    {
                    if((Mario->x)<=(en->x))
                        {
                        (en->x) -= (0.8/MOVE_RATE_SQUID);
                        (en->y) -= (0.8/MOVE_RATE_SQUID);
                        }
                    if((Mario->x)>(en->x))
                        {
                        (en->x) += (0.8/MOVE_RATE_SQUID);
                        (en->y) -= (0.8/MOVE_RATE_SQUID);
                        }
                    }
                else 
                    {
                    if (en->dodge == false)
                        {
                        en->dodge = true;
                        }
                    else
                        {
                        (en->y) += (2/MOVE_RATE_SQUID);
                        if ((en->y) > (en->prev_pos))
                            {
                            en->dodge = false;
                            en->prev_pos = en->y;
                            }
                        }
                    }
                }
                if (en->type == BOSS) //Movimiento del boss submarino
                {
                    if ( collide_entity(xhitbox, yhitbox, xhitbox+BOSS_W, yhitbox+BOSS_H, Mario) )
                    {
                    Mario->death=true; 
                    }
                    if ((en->x)> (en->prev_pos)+BOSS_STOP)
                    (en->x) -= (1/MOVE_RATE_FISH);
                }
                if (en->type == MISIL1 || en->type == MISIL2 ||en->type == MISIL3 ||en->type == MISIL4 ||en->type == MISIL5 ||en->type == MISIL6 ) //Movimiento de los misiles del submarino
                {
                    if ( collide_entity(xhitbox, yhitbox, xhitbox+MISIL_SIZE, yhitbox+MISIL_SIZE, Mario) )
                    {
                    Mario->death=true; 
                    }
                    if (en->type == MISIL1)
                        {
                        if ((en->y)> (en->prev_pos)+MISIL1_TURN_COORD) 
                            {
                            (en->y) -= (1/MOVE_RATE_MISIL);
                            }
                        else
                            {
                            (en->x) -= (1/MOVE_RATE_MISIL);
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL2)
                        {
                        if ((en->y)> (en->prev_pos)+MISIL2_TURN_COORD)
                            {
                            (en->y) -= (1/MOVE_RATE_MISIL);
                            }
                        else
                            {
                            (en->x) -= (1/MOVE_RATE_MISIL);
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL3)
                        {
                        (en->x) -= (1/MOVE_RATE_MISIL);
                        }
                    else if (en->type == MISIL4)
                        {
                        if ((en->y)< (en->prev_pos)+MISIL4_TURN_COORD)
                            {
                            (en->y) += (1/MOVE_RATE_MISIL);
                            }
                        else
                            {
                            (en->x) -= (1/MOVE_RATE_MISIL);
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL5)
                        {
                        if ((en->y)< (en->prev_pos)+MISIL5_TURN_COORD)
                            {
                            (en->y) += (1/MOVE_RATE_MISIL);
                            }
                        else
                            {
                            (en->x) -= (1/MOVE_RATE_MISIL);
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL6)//el misil6 gira en base a un temporizador
                        
                    #ifdef ALLEGRO
                        {
                        if ((en->timer > -60*2) && (en->timer < 0))
                            {
                            (en->y) -= (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer > -60*10) 
                            {
                            (en->x) -= (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer > -60*12)
                            {
                            (en->y) += (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer > -60*19) 
                            {
                            (en->x) += (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer <= -60*19)
                            en->active=false;
                        
                        }
                    #endif /*ALLEGRO*/

                    #ifdef RPI
                        {
                        if ((en->timer > -60*2*TIME_SCALE) && (en->timer < 0))
                            {
                            (en->y) -= (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer > -60*10*TIME_SCALE) 
                            {
                            (en->x) -= (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer > -60*12*TIME_SCALE)
                            {
                            (en->y) += (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer > -60*19*TIME_SCALE) 
                            {
                            (en->x) += (1/MOVE_RATE_MISIL);
                            }
                        else if (en->timer <= -60*19*TIME_SCALE)
                            en->active=false;
                        }
                    #endif /*RPI*/
                }

        }
}
}


void enemy_start (enemy * en,bool active,char type,char ma,float x,float y,bool dodge,int time)
{
    en->active= active;
    en->type= type;
    en->mapa= ma;
    en->dodge= dodge;

    if (en->type == MISIL1 || en->type == MISIL2 || en->type == MISIL3|| en->type == MISIL6)//posiciones default de los misiles
    {
        x=277;
        y=114;
        if (en->type == MISIL3)
        {
            y=117;
            en->dodge=true;
        }
    }
    if (en->type == MISIL4 || en->type == MISIL5)
    {
        x=260;
        y=157;
    }
                       
    #ifdef ALLEGRO
    en->x= x;
    en->y= y;
    en->timer=time;
    #endif /*ALLEGRO*/

    #ifdef RPI
    en->x=(int)(x*COORDSCALE);
    en->y=(int)(y*COORDSCALE);
    en->timer=(time*TIME_SCALE);
    #endif /*RPI*/
    
    if (en->type == FISH || en->type == REDFISH || en->type == BOSS)
        en->prev_pos = en->x;
    else en->prev_pos = en->y;
}



void fcoin(player * Mario,coin* ncoin)
{ 
        if((Mario->coin_obt ==true)&&(Mario->n_mapa_actual == ncoin->map)) //Solo se escanea si mario tocó la moneda cuando el flag de coin_obtenida se encuentra prendida
            {
                if( (collide_coin(ncoin->x, ncoin->y, ncoin->x+COIN_SIZE,ncoin->y+COIN_SIZE, Mario)) && (ncoin->active == true) )
                    {
                    ncoin->active=false;//Si mario tocó la moneda esta se desactiva y se aumenta el contador de monedas
                    Mario->coins ++;
                    Mario->score += 300;
                    }
            }
}

void coin_start(coin* ncoin,float x,float y,char map,bool startup)
{
    ncoin->active=true;
    ncoin->map=map;

    #ifdef ALLEGRO
    ncoin->x= x;
    ncoin->y= y;
    #endif /*ALLEGRO*/
    

    if(startup==true)//Si se acaba de iniciar el juego se rellena la matriz en donde se encuentra la moneda
    {
    switch(map)
        {
        case MAPA1:
            putbarrier ((int)x, (int)y, (int)(x+COIN_SIZE), (int)(y+COIN_SIZE), mapa1, COIN);
            break;
        case MAPA2:
            putbarrier ((int)x, (int)y, (int)(x+COIN_SIZE), (int)(y+COIN_SIZE), mapa2, COIN);
            break;
        case MAPA3:
            putbarrier ((int)x, (int)y, (int)(x+COIN_SIZE), (int)(y+COIN_SIZE), mapa3, COIN);
            break;
        default:
            break;
        }
    }
    
    #ifdef RPI
    x=floor(x);
    ncoin->x=floor(x*COORDSCALE);
    y=floor(y);
    ncoin->y=floor(y*COORDSCALE);
    #endif /*RPI*/
    
}



bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario)
{
    if(ax1 > ((Mario->x)+ MARIO_SIZE)) return false;
    if(ax2 < (Mario->x)) return false;
    if(ay1 > ((Mario->y)+ MARIO_SIZE)) return false;
    if(ay2 < (Mario->y)) return false;

    return true;
}

bool collide_coin(float ax1, float ay1, float ax2, float ay2, player* Mario)
{
    #ifdef ALLEGRO
    if(ax1 > ((Mario->x)+ MARIO_SIZE)) return false;
    if(ax2 < (Mario->x)) return false;
    if(ay1 > ((Mario->y)+ MARIO_SIZE)) return false;
    if(ay2 < (Mario->y)) return false;
    #endif /*ALLEGRO*/

    #ifdef RPI
    if(ax1 > ((Mario->x)+ 1)) return false;
    if(ax2 < (Mario->x)) return false;
    if(ay1 > ((Mario->y)+ 1)) return false;
    if(ay2 < (Mario->y)) return false;
    #endif /*RPI*/
    return true;
}