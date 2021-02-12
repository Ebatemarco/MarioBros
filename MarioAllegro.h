/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MarioAllegro.h
 * Author: ebatemarco
 *
 * Created on February 5, 2021, 4:01 PM
 */

#ifndef MARIOALLEGRO_H
#define MARIOALLEGRO_H

#include "Header.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct
{
ALLEGRO_BITMAP *(*p_fish1);
ALLEGRO_BITMAP *(*p_fish2);
ALLEGRO_BITMAP *(*p_redfish1);
ALLEGRO_BITMAP *(*p_redfish2);
ALLEGRO_BITMAP *(*p_squid1);
ALLEGRO_BITMAP *(*p_squid2);
ALLEGRO_BITMAP *(*p_coin);
ALLEGRO_BITMAP *(*p_boss);
ALLEGRO_BITMAP *(*p_misil);
ALLEGRO_BITMAP *(*p_explosion1);
ALLEGRO_BITMAP *(*p_explosion2);
ALLEGRO_BITMAP *(*p_explosion3);
}bitmaps_t;

void draw_coin(player * Mario,coin* ncoin,bitmaps_t * bitm);

void disp_pre_draw(ALLEGRO_BITMAP* buffer);

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* buffer,ALLEGRO_BITMAP* menupausa,ALLEGRO_BITMAP* gameover, player* Mario, ALLEGRO_FONT * font,bool pausa);

void draw_enemy (enemy * en, player * Mario, bitmaps_t * bit);

bool collidewborder(player* , int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W],ALLEGRO_BITMAP *(*p_background)); //mapa, p_background y n_mapa_actual son siempre las mismas que se mandan


#endif /* MARIOALLEGRO_H */

