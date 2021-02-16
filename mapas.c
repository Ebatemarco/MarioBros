///////////////////////////////////////////////////////////////////////////////
/*
 * Trabajo Práctico Final Programación I.
 * MarioBros Underwater Edition
 * File:  mapas.c
 */
///////////////////////////////////////////////////////////////////////////////

#include "mapas.h"

char mapainicio[BUFFER_H][BUFFER_W]={EMPTY};
char mapa3[BUFFER_H][BUFFER_W]={EMPTY};
char finalmapa2[BUFFER_H][BUFFER_W]={EMPTY};
char mapa1[BUFFER_H][BUFFER_W]={EMPTY};
char finalmapa1[BUFFER_H][BUFFER_W]={EMPTY};
char mapa2[BUFFER_H][BUFFER_W]={EMPTY};

char mapa[BUFFER_H][BUFFER_W]={EMPTY}; 



void barriers()
{
    
//#ifdef ALLEGRO    
   //Zona de creacion de barreras
    
    //Mapa inicial
   putbarrier (0, 0, 2, 223, mapainicio, BORDER);
   putbarrier (0, 200, 563, 223, mapainicio, BORDER);
   putbarrier (MAPAINICIO_W-4, 0 , 500, 223, mapainicio, BORDER);
   putbarrier (404, 173, 414, 199, mapainicio, EXIT0);
   
    //Mapa 1
   //putbarrier (0 , 0, 3102, 23,  mapa1, BORDER); // Borde de la parte de arriba 
   putbarrier (0,0, 2, 223,  mapa1, BORDER);
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
   putbarrier (MAPA1_W-1, 0 , MAPA1_W, 223, mapa1, BORDER);
   
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
   putbarrier (FINALMAPA1_W-4, 0 , 500, 223, finalmapa1, BORDER);
   putbarrier (0, 0, 2, 223, finalmapa1, BORDER);
   putbarrier (447, 168, 463, 198, finalmapa1, EXIT2);
   
   //Mapa2
   
   putbarrier (0,0,287,42, mapa2, BORDER);
   putbarrier (0,32,31,207, mapa2, BORDER);
   putbarrier (0,208,2199,239, mapa2, BORDER);
   putbarrier (32,32,95,39, mapa2, BORDER);
   putbarrier (96,32,287,79, mapa2, BORDER);
   putbarrier (176,80,287,95, mapa2, BORDER);
   putbarrier (96,160,287,207, mapa2, BORDER);
   putbarrier (176,144,287,159, mapa2, BORDER);
   putbarrier (48,176,79,207, mapa2, BORDER);
   putbarrier (288,1,2199,207, mapa2, BORDER);

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
   putbarrier (MAPA2_W-4, 0 , MAPA2_W, 223, mapa2, BORDER);
   
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
   putbarrier (FINALMAPA2_W-4, 0 , 500, 223, finalmapa2, BORDER);
   putbarrier (0, 0, 2, 223, finalmapa2, BORDER);
   putbarrier (447, 168, 463, 198, finalmapa2, EXIT4);
   
   //Mapa 3
   putbarrier (0, 0, 337, 239, mapa3, BORDER);
   putbarrier (12, 22, 289, 207, mapa3, EMPTY);
   putbarrier (290, 96, 337, 159, mapa3, EMPTY);
   putbarrier (0, 0, 11, 239, mapa3, BORDER);
   putbarrier (331, 96, 337, 159, mapa3, EXIT5);
//#endif /* ALLEGRO */
   
//#ifdef RPI

   
   
//#endif /* RPI */
}



void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento) //esta funcion modifica la matriz en las coordenadas dadas, con el elelmento dado 
{
    int i, j;
    
#ifdef RPI
    ax= (int)(ax*COORDSCALE);
    ay= (int)(ay*COORDSCALE);
    bx= (int)(bx*COORDSCALE);
    by= (int)(by*COORDSCALE);
    
#endif /*RPI*/
    
    for(j=ay; j<= by ;j++)
    {
        for(i=ax; i <= bx;i++)
        {
            mapa[j][i]= elemento;
        }
    }
    
}

void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]) 
{
    memcpy(destino, origen, sizeof(char)*BUFFER_H*BUFFER_W);
}

bool collidewborder(player* Mario,int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W]) //esta funcion detecta si hubo una colision entre 2 elementos
{

    int i, j;
    for(j=ay1; j<= ay2;j++)
    {
        for(i=ax1; i <= ax2;i++)
        {
            switch(mapa[j][i]) 
            {
                
            case BORDER:
                return false;
                break;
                
            case BLOCKDEATH:
                {
                Mario->death=true;
                return false;
                }
                break;
                
            case COIN:
                {
                Mario->coin_obt=true;
                }
                break;
                
            case EXIT4:
                {
                Mario->exit_pass=true;
                clonarMatriz(mapa1,mapa);
                Mario->x=XINICIAL;
                Mario->y=YINICIAL;
                Mario->n_mapa_actual=MAPA1;
                return false;
                }
                break;
                
            case EXIT1:
                {
                Mario->exit_pass=true;
                clonarMatriz(finalmapa1,mapa);
                Mario->x=XINICIAL;
                Mario->y=YINICIAL;
                Mario->n_mapa_actual=FINALMAPA1;
                return false;
                }
                break;
                
            case EXIT2:
                {
                Mario->exit_pass=true;
                clonarMatriz(mapa2,mapa);
                Mario->x=XINICIAL;
                Mario->y=YINICIAL;
                Mario->n_mapa_actual=MAPA2;
                Mario->score = (Mario->timer)*100;
                Mario->timer=LEVEL_TIME;
                return false;
                }
                break;
                
            case EXIT3:
                {
                Mario->exit_pass=true;
                clonarMatriz(finalmapa2,mapa);
                Mario->x=XINICIAL;
                Mario->y=YINICIAL;
                Mario->n_mapa_actual=FINALMAPA2;
                return false;
                }
                break;
                
            case EXIT0:
                {
                Mario->exit_pass=true;
                clonarMatriz(mapa3,mapa);
                Mario->x=XINICIAL;
                Mario->y=YINICIAL;
                Mario->n_mapa_actual=MAPA3;
                Mario->score = (Mario->timer)*100;
                Mario->timer=LEVEL_TIME;
                return false;
                }
                break;
                
            case EXIT5:
                {
                Mario->score = (Mario->timer)*100;
                Mario->x=XINICIAL;
                Mario->y=YINICIAL;
                Mario->win=true;
                printf("GANASTE !!!\nTu puntaje: %u\n",Mario->score);
                return false;
                }
                break;
                
            default:
                break;
            
            }

        }
    }

    return true;
}