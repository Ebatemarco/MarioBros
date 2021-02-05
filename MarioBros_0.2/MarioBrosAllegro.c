/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MarioAllegro.h"


extern char mapainicio[BUFFER_H][BUFFER_W];
extern char mapa3[BUFFER_H][BUFFER_W];
extern char finalmapa2[BUFFER_H][BUFFER_W];
extern char mapa1[BUFFER_H][BUFFER_W];
extern char finalmapa1[BUFFER_H][BUFFER_W];
extern char mapa2[BUFFER_H][BUFFER_W];

extern char mapa[BUFFER_H][BUFFER_W]; 

void draw_coin(player * Mario,coin* ncoin,bitmaps_t * bitm)
{
     if(((Mario->n_mapa_actual)== (ncoin->map)) && ((ncoin->active) == true))//se dibuja la moneda solo cuando esté activa y mario se encuentre en el mapa de la misma
        {
        al_draw_bitmap(*(bitm->p_coin), ncoin->x, ncoin->y, 0);
        }
}

void draw_enemy (enemy * en, player * Mario, bitmaps_t * bitm)
{
    if(Mario->n_mapa_actual== en->mapa)
    {    
        if (en->type == BOSS)
                {
                if (en->timer <= 0)
                    {
                    if (en->timer > -30*1) 
                    al_draw_bitmap(*(bitm->p_explosion1), (en->x)+5, (en->y)-6, 0);
                    else if (en->timer > -30*2)
                    al_draw_bitmap(*(bitm->p_explosion2), (en->x)+5, (en->y)-6, 0);
                    else if (en->timer > -30*3)
                    al_draw_bitmap(*(bitm->p_explosion3), (en->x)+5, (en->y)-6, 0);
                    }
                }

        if(en->active==true)
        {   
            if (en->type == FISH)
            {
                if(en->dodge == false)
                al_draw_bitmap(*(bitm->p_fish1), (en->x), (en->y), 0);
                else al_draw_bitmap(*(bitm->p_fish2), (en->x), (en->y), 0);  
            }

            if (en->type == REDFISH)
           {
                if(en->dodge == false)
                al_draw_bitmap(*(bitm->p_redfish1), (en->x), (en->y), 0);
                else al_draw_bitmap(*(bitm->p_redfish2), (en->x), (en->y), 0);  
            }

            if (en->type == SQUID)
            {
                if(en->dodge == false)
                al_draw_bitmap(*(bitm->p_squid1), (en->x), (en->y), 0);
                else al_draw_bitmap(*(bitm->p_squid2), (en->x), (en->y), 0);  
            }

            if (en->type == BOSS)
            al_draw_bitmap(*(bitm->p_boss), (en->x), (en->y), 0);

            if (en->type == MISIL1 ||en->type == MISIL2 ||en->type == MISIL3 ||en->type == MISIL4 ||en->type == MISIL5 ||en->type == MISIL6)
                {
                if (en->dodge == false)
                    {
                    if (en->type == MISIL4 ||en->type == MISIL5 )
                    al_draw_rotated_bitmap(*(bitm->p_misil),MISIL_SIZE/2,MISIL_SIZE/2, (en->x)+MISIL_SIZE/2, (en->y), 3*(ALLEGRO_PI/2),0);

                    else if (en->type == MISIL6)
                            {
                            if ((en->timer > -60*2) && (en->timer < 0))
                                {
                                al_draw_rotated_bitmap(*(bitm->p_misil),MISIL_SIZE/2,MISIL_SIZE/2, (en->x), (en->y), ALLEGRO_PI/2,0);
                                }
                            else if (en->timer > -60*10) 
                                {
                                al_draw_bitmap(*(bitm->p_misil), (en->x), (en->y), 0);
                                }
                            else if (en->timer > -60*12)
                                {
                                al_draw_rotated_bitmap(*(bitm->p_misil),MISIL_SIZE/2,MISIL_SIZE/2, (en->x)+MISIL_SIZE/2, (en->y), 3*(ALLEGRO_PI/2),0);
                                }
                            else if (en->timer > -60*19) 
                                {
                                al_draw_bitmap(*(bitm->p_misil), (en->x), (en->y), ALLEGRO_FLIP_HORIZONTAL);
                                }
                            }
                    else al_draw_rotated_bitmap(*(bitm->p_misil),MISIL_SIZE/2,MISIL_SIZE/2, (en->x), (en->y), ALLEGRO_PI/2,0);
                    }
                else al_draw_bitmap(*(bitm->p_misil), (en->x), (en->y), 0);
                }
        }
    
    }
}

void disp_pre_draw(ALLEGRO_BITMAP* b)
{
    al_set_target_bitmap(b);
}

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* b,ALLEGRO_BITMAP* menu,ALLEGRO_BITMAP* gameover, player* Mario, ALLEGRO_FONT * font,bool pausa)//dibujo de cosas en la pantalla,no en el buffer
{
    //Dibujo del buffer
    al_set_target_backbuffer(disp);
    
    if((Mario->x) < (BUFFER_H/2))
    al_draw_scaled_bitmap(b,0, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
     
    else if (((Mario->n_mapa_actual)== MAPA1) &&((Mario->x) > (MAPA1_W-(BUFFER_H/2))))
    al_draw_scaled_bitmap(b, MAPA1_W-BUFFER_H, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    else if (((Mario->n_mapa_actual)== FINALMAPA1) &&((Mario->x) > (FINALMAPA1_W-(BUFFER_H/2))))
    al_draw_scaled_bitmap(b, FINALMAPA1_W-BUFFER_H, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    else if (((Mario->n_mapa_actual)== MAPA2) &&((Mario->x) > (MAPA2_W-(BUFFER_H/2))))
    al_draw_scaled_bitmap(b, MAPA2_W-BUFFER_H, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    else if (((Mario->n_mapa_actual)== FINALMAPA2) &&((Mario->x) > (FINALMAPA2_W-(BUFFER_H/2))))
    al_draw_scaled_bitmap(b, FINALMAPA2_W-BUFFER_H, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    else if (((Mario->n_mapa_actual)== MAPA3) &&((Mario->x) > (MAPA3_W-(BUFFER_H/2))))
    al_draw_scaled_bitmap(b, MAPA3_W-BUFFER_H, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    else if (((Mario->n_mapa_actual)== MAPAINICIO) &&((Mario->x) > (MAPAINICIO_W-(BUFFER_H/2))))
    al_draw_scaled_bitmap(b, MAPAINICIO_W-BUFFER_H, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    else
    al_draw_scaled_bitmap(b, (Mario->x)-(BUFFER_H/2), 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    //Dibujo del HUD
    al_draw_text(font, al_map_rgb(255, 255, 255), (50) ,(10), ALLEGRO_ALIGN_LEFT, "SCORE  COINS  WORLD  TIME  LIVES");
    al_draw_textf(font, al_map_rgb(255, 255, 255), 3*(SCREEN_W/20) ,(40), ALLEGRO_ALIGN_CENTER, "%d",Mario->score);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 7*(SCREEN_W/20) ,(40), ALLEGRO_ALIGN_CENTER, "%d",Mario->coins);
    if(Mario->n_mapa_actual<10)
    al_draw_textf(font, al_map_rgb(255, 255, 255), 11*(SCREEN_W/20) ,(40), ALLEGRO_ALIGN_CENTER, "%d",Mario->n_mapa_actual);
    else
    al_draw_textf(font, al_map_rgb(255, 255, 255), 11*(SCREEN_W/20) ,(40), ALLEGRO_ALIGN_CENTER, "%d",Mario->n_mapa_actual-10);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 14*(SCREEN_W/20) ,(40), ALLEGRO_ALIGN_CENTER, "%d",Mario->timer);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 18*(SCREEN_W/20) ,(40), ALLEGRO_ALIGN_CENTER, "%d",Mario->live);
    
    //Dibujo de otros mensajes
    if (pausa==true)
        {
        if(Mario->n_mapa_actual==MAPAINICIO && Mario->x==118)//pantalla de inicio
            {
            al_draw_textf(font, al_map_rgb(255, 255, 255), 9*(SCREEN_W/20) ,13*(SCREEN_H/20), ALLEGRO_ALIGN_LEFT, "Presiona");
            al_draw_textf(font, al_map_rgb(255, 255, 255), 9*(SCREEN_W/20) ,14*(SCREEN_H/20), ALLEGRO_ALIGN_LEFT, "la tecla P ");
            al_draw_textf(font, al_map_rgb(255, 255, 255), 9*(SCREEN_W/20) ,15*(SCREEN_H/20), ALLEGRO_ALIGN_LEFT, "para empezar");
            }
        else al_draw_scaled_bitmap(menu,0, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);//pantalla de pausa
        }
    if (Mario->live==0) //Si se acabaron las vidas aparece el cartel de game over
    al_draw_scaled_bitmap(gameover,0, 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    
    al_flip_display();
}

bool collidewborder(player* Mario,int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W],ALLEGRO_BITMAP *(*p_background)) //esta funcion detecta si hubo una colision entre 2 elementos
{
    
    int i, j;
    for(j=ay1; j<= ay2;j++)
    {
        for(i=ax1; i <= ax2;i++)
        {
            if(mapa[j][i]== BORDER)
            {
                return false;
            }
            if(mapa[j][i]== BLOCKDEATH)
            {
                Mario->death=true;
                return false;
            }
            if(mapa[j][i]== COIN)
            {
                Mario->coin_obt=true;
            }
             if(mapa[j][i]== EXIT0)
            {
             *p_background = al_load_bitmap("mapa1.png");
              clonarMatriz(mapa1,mapa);
              Mario->x=XINICIAL;
              Mario->y=YINICIAL;
              Mario->n_mapa_actual=MAPA1;
               return false;
            }
            if(mapa[j][i]== EXIT1)
            {
             *p_background = al_load_bitmap("mapa-final.png");
              clonarMatriz(finalmapa1,mapa);
              Mario->x=XINICIAL;
              Mario->y=YINICIAL;
              Mario->n_mapa_actual=FINALMAPA1;
               return false;
            }
            if(mapa[j][i]== EXIT2)
            {
             *p_background = al_load_bitmap("mapa2.png");
              clonarMatriz(mapa2,mapa);
              Mario->x=XINICIAL;
              Mario->y=YINICIAL;
              Mario->n_mapa_actual=MAPA2;
              Mario->score = (Mario->timer)*100;
              Mario->timer=LEVEL_TIME;
               return false; 
            }
            if(mapa[j][i]== EXIT3)
            {
             *p_background = al_load_bitmap("mapa-final.png");
              clonarMatriz(finalmapa2,mapa);
              Mario->x=XINICIAL;
              Mario->y=YINICIAL;
              Mario->n_mapa_actual=FINALMAPA2;
               return false;
            }
            if(mapa[j][i]== EXIT4)
            {
             *p_background = al_load_bitmap("mapa3.png");
              clonarMatriz(mapa3,mapa);
              Mario->x=XINICIAL;
              Mario->y=YINICIAL;
              Mario->n_mapa_actual=MAPA3;
              Mario->score = (Mario->timer)*100;
              Mario->timer=LEVEL_TIME;
               return false;
            }
        }
    }

    return true;
}