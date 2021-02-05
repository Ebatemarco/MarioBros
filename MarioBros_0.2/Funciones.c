/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MarioAllegro.h"
//FUNCIONES

 char mapainicio[BUFFER_H][BUFFER_W]={EMPTY};
 char mapa3[BUFFER_H][BUFFER_W]={EMPTY};
 char finalmapa2[BUFFER_H][BUFFER_W]={EMPTY};
 char mapa1[BUFFER_H][BUFFER_W]={EMPTY};
 char finalmapa1[BUFFER_H][BUFFER_W]={EMPTY};
 char mapa2[BUFFER_H][BUFFER_W]={EMPTY};

 char mapa[BUFFER_H][BUFFER_W]={EMPTY}; 

void clonarMatrizMain()
{
    clonarMatriz(mapainicio,mapa);
}

void Barriers()
{
   //Zona de creacion de barreras
    
    //Mapa inicial
   putbarrier (0, 200, 563, 223, mapainicio, BORDER);
   putbarrier (MAPAINICIO_W-1, 0 , MAPAINICIO_W, BUFFER_H, mapainicio, BORDER);
   putbarrier (404, 173, 414, 199, mapainicio, EXIT0);
   
    //Mapa 1
   //putbarrier (0 , 0, 3102, 23,  mapa1, BORDER); // Borde de la parte de arriba 
   putbarrier (0 , 200, 3101, 223,  mapa1, BORDER);
   putbarrier (175, 152, 190, 199,  mapa1, BORDER);
   putbarrier (288, 136, 335, 151,  mapa1, BORDER);
   putbarrier (544, 120, 559, 199,  mapa1, BORDER);
   putbarrier (688, 104, 703, 135,  mapa1, BORDER);
   putbarrier (688, 136, 719, 151,  mapa1, BORDER);
   putbarrier (816, 136, 831, 199,  mapa1, BORDER);
   putbarrier (1040, 152, 1055, 199,  mapa1, BORDER);
   putbarrier (1056, 120, 1071, 199,  mapa1, BORDER);
   putbarrier (1152, 120, 1167, 199,  mapa1, BORDER);
   putbarrier (1168, 152, 1183, 199,  mapa1, BORDER);
   putbarrier (1264, 152, 1295, 199,  mapa1, BORDER);
   putbarrier (1264, 24, 1295, 71,  mapa1, BORDER);
   putbarrier (1328, 72, 1375, 87,  mapa1, BORDER);
   putbarrier (1344, 40, 1359, 71,  mapa1, BORDER);
   putbarrier (1440, 152, 1455, 199,  mapa1, BORDER);
   putbarrier (1648, 72, 1663, 135,  mapa1, BORDER);
   putbarrier (1648, 136, 1679, 151,  mapa1, BORDER);
   putbarrier (1855, 120, 1886, 135,  mapa1, BORDER);
   putbarrier (1935, 136, 1950, 199,  mapa1, BORDER);
   putbarrier (2079, 136, 2094, 199,  mapa1, BORDER);
   putbarrier (2095, 168, 2110, 199,  mapa1, BORDER);
   
   putbarrier (2111, 24, 2126, 55,  mapa1, BORDER);
   putbarrier (2111, 56, 2254, 71,  mapa1, BORDER);
   putbarrier (2255, 168, 2286, 199,  mapa1, BORDER);
   putbarrier (2271, 136, 2286, 168,  mapa1, BORDER);
   putbarrier (2364, 186, 2382, 199,  mapa1, BORDER);
   putbarrier (2399, 152, 2414, 199,  mapa1, BORDER);
   putbarrier (2511, 72, 2525, 199,  mapa1, BORDER);
   putbarrier (2527, 72, 2558, 87,  mapa1, BORDER);
   putbarrier (2607, 72, 2654, 87,  mapa1, BORDER);
   putbarrier (2639, 88, 2654, 199,  mapa1, BORDER);
   putbarrier (2767, 72, 2845, 87,  mapa1, BORDER);
   putbarrier (2783, 40, 2798, 71,  mapa1, BORDER);
   putbarrier (2894, 72, 2956, 87,  mapa1, BORDER);
   putbarrier (2767, 136, 2845, 151,  mapa1, BORDER);
   putbarrier (2894, 136, 2956, 151,  mapa1, BORDER);
   
   putbarrier (3022, 24, 3101, 87,  mapa1, BORDER);
   putbarrier (3054, 88, 3101, 223,  mapa1, BORDER);
   putbarrier (3022, 136, 3070, 223,  mapa1, BORDER);
   putbarrier (3006, 152, 3037, 199,  mapa1, BORDER);
   putbarrier (2990, 168, 3021, 199,  mapa1, BORDER);
   putbarrier (2974, 184, 2989, 199,  mapa1, BORDER);
   putbarrier (MAPA1_W-1, 0 , MAPA1_W, BUFFER_H, mapa1, BORDER);
   
   putbarrier (1072, 200, 1151, 223,  mapa1, BLOCKDEATH);
   putbarrier (2111, 168, 2254, 223,  mapa1, EMPTY);
   putbarrier (2111, 206, 2254, 223,  mapa1, BLOCKDEATH);
   putbarrier (2527, 139, 2638, 223,  mapa1, EMPTY);
   putbarrier (2527, 210, 2638, 223,  mapa1, BLOCKDEATH);
   putbarrier (3039, 107, 3048, 135,  mapa1, EXIT1);
   
   //Final del mapa 1
   putbarrier (0, 200, 563, 223, finalmapa1, BORDER);
   putbarrier (192,72, 223, 199, finalmapa1, BORDER);
   putbarrier (144,120,159,199, finalmapa1, BORDER);
   putbarrier (176,88, 191, 199, finalmapa1, BORDER);
   putbarrier (160,104,175,199, finalmapa1, BORDER);
   putbarrier (128,136,143,199, finalmapa1, BORDER);
   putbarrier (112,152,127,199, finalmapa1, BORDER);
   putbarrier (96, 168,111, 199, finalmapa1, BORDER);
   putbarrier (80, 184 , 95, 199, finalmapa1, BORDER);
   putbarrier (48, 168 , 79, 199, finalmapa1, BORDER);
   putbarrier (352, 184 , 367, 199, finalmapa1, BORDER);
   putbarrier (FINALMAPA1_W-1, 0 , FINALMAPA1_W, BUFFER_H, finalmapa1, BORDER);
   putbarrier (447, 168, 463, 198, finalmapa1, EXIT2);
   
   //Mapa2
   
   putbarrier (0,32,31,207, mapa2, BORDER);
   putbarrier (0,208,2199,239, mapa2, BORDER);
   putbarrier (32,32,95,39, mapa2, BORDER);
   putbarrier (96,32,287,79, mapa2, BORDER);
   putbarrier (176,80,287,95, mapa2, BORDER);
   putbarrier (96,160,287,207, mapa2, BORDER);
   putbarrier (176,144,287,159, mapa2, BORDER);
   putbarrier (48,176,79,207, mapa2, BORDER);
   putbarrier (288,32,2199,207, mapa2, BORDER);

   putbarrier (288,48,623,207, mapa2, EMPTY);
   putbarrier (624,96,1823,159, mapa2, EMPTY);
   putbarrier (672,48,1007,207, mapa2, EMPTY);
   putbarrier (1056,48,1391,207, mapa2, EMPTY);
   putbarrier (1440,38,1775,207, mapa2, EMPTY);
   putbarrier (1824,48,2120,207, mapa2, EMPTY);
   putbarrier (2121,96,2136,143, mapa2, EMPTY);
   putbarrier (2137,96,2152,111, mapa2, EMPTY);
   putbarrier (0, 207, 2199, 239, mapa2, BORDER);
   putbarrier (2137, 114, 2150, 142, mapa2, EXIT3);
   putbarrier (MAPA2_W-1, 0 , MAPA2_W, BUFFER_H, mapa2, BORDER);
   
   //Final del mapa 2
   putbarrier (0, 200, 563, 223, finalmapa2, BORDER);
   putbarrier (192,72, 223, 199, finalmapa2, BORDER);
   putbarrier (144,120,159,199, finalmapa2, BORDER);
   putbarrier (176,88, 191, 199, finalmapa2, BORDER);
   putbarrier (160,104,175,199, finalmapa2, BORDER);
   putbarrier (128,136,143,199, finalmapa2, BORDER);
   putbarrier (112,152,127,199, finalmapa2, BORDER);
   putbarrier (96, 168,111, 199, finalmapa2, BORDER);
   putbarrier (80, 184 , 95, 199, finalmapa2, BORDER);
   putbarrier (48, 168 , 79, 199, finalmapa2, BORDER);
   putbarrier (352, 184 , 367, 199, finalmapa2, BORDER);
   putbarrier (0, 200, 563, 223, finalmapa2, BORDER);
   putbarrier (FINALMAPA2_W-1, 0 , FINALMAPA2_W, BUFFER_H, finalmapa2, BORDER);
   putbarrier (447, 168, 463, 198, finalmapa2, EXIT4);
   
   //Mapa 3
   putbarrier (0, 0, 337, 239, mapa3, BORDER);
   putbarrier (12, 22, 289, 207, mapa3, EMPTY);
   putbarrier (290, 96, 337, 159, mapa3, EMPTY);
}



void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento) //esta funcion modifica la matriz en las coordenadas dadas, con el elelmento dado 
{
    int i, j;
    for(j=ay; j<= by ;j++)
    {
        for(i=ax; i <= bx;i++)
        {
            mapa[j][i]= elemento;
        }
    }
    
}


void enemy_mov (enemy * en, player* Mario ) 
{
if((Mario->n_mapa_actual)== en->mapa)
{
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
            }
    }
        
    //Movimiento de enemigos

    if (en->active == true)
        {

            if (en->type == FISH || en->type == REDFISH) //Movimiento de los peces
                {
                if ( collide_entity(en->x, en->y, (en->x)+FISH_SIZE, (en->y)+FISH_SIZE, Mario) )
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
                (en->x) -= 1/MOVE_RATE_FISH;

                if (en->type == REDFISH)
                (en->x) -= 1/MOVE_RATE_REDFISH;
                }

            if (en->type == SQUID)//Movimiento de los pulpos
                {
                if ( collide_entity(en->x, en->y, (en->x)+SQUID_W, (en->y)+SQUID_H, Mario) )
                    {
                    Mario->death=true;
                    }
                if (((en->y) > (en->prev_pos - DODGE_DIST))&&(en->dodge == false))
                    {
                    if((Mario->x)<=(en->x))
                        {
                        (en->x) -= 0.8/MOVE_RATE_SQUID;
                        (en->y) -= 0.8/MOVE_RATE_SQUID;
                        }
                    if((Mario->x)>(en->x))
                        {
                        (en->x) += 0.8/MOVE_RATE_SQUID;
                        (en->y) -= 0.8/MOVE_RATE_SQUID;
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
                        (en->y) += 2/MOVE_RATE_SQUID;
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
                    if ( collide_entity(en->x, en->y, (en->x)+BOSS_W, (en->y)+BOSS_H, Mario) )
                    {
                    Mario->death=true; 
                    }
                    if ((en->x)> (en->prev_pos)-50)
                    (en->x) -= 1/MOVE_RATE_FISH;
                }
                if (en->type == MISIL1 || en->type == MISIL2 ||en->type == MISIL3 ||en->type == MISIL4 ||en->type == MISIL5 ||en->type == MISIL6 ) //Movimiento de los misiles del submarino
                {
                    if ( collide_entity(en->x, en->y, (en->x)+MISIL_SIZE, (en->y)+MISIL_SIZE, Mario) )
                    {
                    Mario->death=true; 
                    }
                    if (en->type == MISIL1)
                        {
                        if ((en->y)> (en->prev_pos)-80)
                            {
                            (en->y) -= 1/MOVE_RATE_SQUID;
                            }
                        else
                            {
                            (en->x) -= 1/MOVE_RATE_SQUID;
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL2)
                        {
                        if ((en->y)> (en->prev_pos)-40)
                            {
                            (en->y) -= 1/MOVE_RATE_SQUID;
                            }
                        else
                            {
                            (en->x) -= 1/MOVE_RATE_SQUID;
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL3)
                        {
                        (en->x) -= 1/MOVE_RATE_SQUID;
                        }
                    else if (en->type == MISIL4)
                        {
                        if ((en->y)< (en->prev_pos)+10)
                            {
                            (en->y) += 1/MOVE_RATE_SQUID;
                            }
                        else
                            {
                            (en->x) -= 1/MOVE_RATE_SQUID;
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL5)
                        {
                        if ((en->y)< (en->prev_pos)+30)
                            {
                            (en->y) += 1/MOVE_RATE_SQUID;
                            }
                        else
                            {
                            (en->x) -= 1/MOVE_RATE_SQUID;
                            en->dodge = true;
                            }
                        }
                    else if (en->type == MISIL6)//el misil6 gira en base a un temporizador
                        {
                        if ((en->timer > -60*2) && (en->timer < 0))
                            {
                            (en->y) -= 1/MOVE_RATE_SQUID;
                            }
                        else if (en->timer > -60*10) 
                            {
                            (en->x) -= 1/MOVE_RATE_SQUID;
                            }
                        else if (en->timer > -60*12)
                            {
                            (en->y) += 1/MOVE_RATE_SQUID;
                            }
                        else if (en->timer > -60*19) 
                            {
                            (en->x) += 1/MOVE_RATE_SQUID;
                            }

                        }
                }

        }
}
}


void enemy_start (enemy * en,bool active,char type,char ma,float x,float y,bool dodge,int time)
{
    en->active= active;
    en->type= type;
    en->mapa= ma;
    en->x= x;
    en->y= y;
    en->dodge= dodge;
    en->timer=time;
    if (en->type == FISH || en->type == REDFISH || en->type == BOSS)
        en->prev_pos = x;
    else en->prev_pos = y;
}



void fcoin(player * Mario,coin* ncoin)
{
        if((Mario->coin_obt)&&(Mario->n_mapa_actual == ncoin->map)) //Solo se escanea si mario tocó la moneda cuando el flag de coin_obtenida se encuentra prendida
            {
                if(Mario->n_mapa_actual== ncoin->map && collide_entity(ncoin->x, ncoin->y, (ncoin->x)+COIN_SIZE, (ncoin->y)+COIN_SIZE, Mario) && (ncoin->active == true))
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
    ncoin->x=x;
    ncoin->y=y;
    ncoin->map=map;
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
}



bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario)
{
    if(ax1 > ((Mario->x)+ MARIO_SIZE)) return false;
    if(ax2 < (Mario->x)) return false;
    if(ay1 > ((Mario->y)+ MARIO_SIZE)) return false;
    if(ay2 < (Mario->y)) return false;

    return true;
}

void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]) 
{
    memcpy(destino, origen, sizeof(char)*BUFFER_H*BUFFER_W);
}