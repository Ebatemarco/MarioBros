

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>




#define FPS    60.0

#define BUFFER_W 3103
#define BUFFER_H 224
#define DISP_SCALE 3
#define SCREEN_W (BUFFER_H * DISP_SCALE)
#define SCREEN_H (BUFFER_H * DISP_SCALE)

#define MARIO_SIZE 15
#define MOVE_RATE  4.0
#define MARIO_W 16 //Tamaño del sprite
#define MARIO_H 16 //Tamaño del sprite

#define EXIT 6
#define COIN3 5
#define COIN2 4
#define COIN1 3
#define BORDER 2
#define BLOCKDEATH 1
#define EMPTY 0

#define COIN1_XLOC 100
#define COIN1_YLOC 100
#define COIN2_XLOC 130
#define COIN2_YLOC 100
#define COIN3_XLOC 150
#define COIN3_YLOC 100
#define COIN_SIZE 15

#define FISH_SIZE 15
#define FISH 1
#define MOVE_RATE_FISH  4.0

typedef struct
{
    char live;
    float x;
    float y;
    float salto;
    float salto_cooldown;
    char salto_lock;//Flag que bloquea el salto de Mario cuando se mantiene apretada la tecla para saltar
    bool coin1;
    bool coin2;
    bool coin3;
    
}player;

typedef struct
{
    bool active;
    char type;
    float x;
    float y;
}enemy;

void disp_pre_draw(ALLEGRO_BITMAP* buffer);

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* buffer,float x,float y);

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

bool collidewborder(player* , int ax1, int ay1, int ax2, int ay2,const char mapa [BUFFER_H][BUFFER_W]);

bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario);

void enemy_mov (enemy * en, player* Mario);

enum MYKEYS 
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT , KEY_P //arrow keys
};

char mapa2[BUFFER_H][BUFFER_W]={EMPTY};




int main(void) 
{
    //INICIALIZACION 
    // init_display();
    // init_buffer();
    
    player Mario =  {3, 0, 0, 0, 0, 0,true,true,true}; 
    player * pMario = &Mario;
    
    enemy F1 = {0,FISH,400,100};
    enemy * F1p = &F1;
    
    bool pausa= false;
    bool pausa_lock = false;
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    
    ALLEGRO_BITMAP *buffer = NULL;
    ALLEGRO_BITMAP *mario = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *game_over = NULL;
    
    ALLEGRO_BITMAP *fish = NULL;
    ALLEGRO_BITMAP *coin = NULL;

    
    //ALLEGRO_COLOR grey;
      // grey = al_map_rgb(255, 0, 0);

   
    bool key_pressed[5] = {false, false, false, false, false}; //Estado de teclas, true cuando esta apretada
    bool redraw = false;
    bool do_exit = false;
     

   //Zona de creacion de barrera
   putbarrier (0 , 200, 3101, 223, mapa2, BORDER);
   putbarrier (175, 152, 190, 199, mapa2, BORDER);
   putbarrier (288, 136, 335, 151, mapa2, BORDER);
   putbarrier (544, 120, 559, 199, mapa2, BORDER);
   putbarrier (688, 104, 703, 135, mapa2, BORDER);
   putbarrier (688, 136, 719, 151, mapa2, BORDER);
   putbarrier (816, 136, 831, 199, mapa2, BORDER);
   putbarrier (1040, 152, 1055, 199, mapa2, BORDER);
   putbarrier (1056, 120, 1071, 199, mapa2, BORDER);
   putbarrier (1152, 120, 1167, 199, mapa2, BORDER);
   putbarrier (1168, 152, 1183, 199, mapa2, BORDER);
   putbarrier (1264, 152, 1295, 199, mapa2, BORDER);
   putbarrier (1264, 24, 1295, 71, mapa2, BORDER);
   putbarrier (1328, 72, 1375, 87, mapa2, BORDER);
   putbarrier (1344, 40, 1359, 71, mapa2, BORDER);
   putbarrier (1440, 152, 1455, 199, mapa2, BORDER);
   putbarrier (1648, 72, 1663, 135, mapa2, BORDER);
   putbarrier (1648, 136, 1679, 151, mapa2, BORDER);
   putbarrier (1855, 120, 1886, 135, mapa2, BORDER);
   putbarrier (1935, 136, 1950, 199, mapa2, BORDER);
   putbarrier (2079, 136, 2094, 199, mapa2, BORDER);
   putbarrier (2095, 168, 2110, 199, mapa2, BORDER);
   
   putbarrier (2111, 24, 2126, 55, mapa2, BORDER);
   putbarrier (2111, 56, 2254, 71, mapa2, BORDER);
   putbarrier (2255, 168, 2286, 199, mapa2, BORDER);
   putbarrier (2271, 136, 2286, 168, mapa2, BORDER);
   putbarrier (2364, 186, 2382, 199, mapa2, BORDER);
   putbarrier (2399, 152, 2414, 199, mapa2, BORDER);
   putbarrier (2511, 72, 2525, 199, mapa2, BORDER);
   putbarrier (2527, 72, 2558, 87, mapa2, BORDER);
   putbarrier (2607, 72, 2654, 87, mapa2, BORDER);
   putbarrier (2639, 88, 2654, 199, mapa2, BORDER);
   putbarrier (2767, 72, 2845, 87, mapa2, BORDER);
   putbarrier (2783, 40, 2798, 71, mapa2, BORDER);
   putbarrier (2894, 72, 2956, 87, mapa2, BORDER);
   putbarrier (2767, 136, 2845, 151, mapa2, BORDER);
   putbarrier (2894, 136, 2956, 151, mapa2, BORDER);
   
   putbarrier (3022, 24, 3101, 87, mapa2, BORDER);
   putbarrier (3054, 88, 3101, 223, mapa2, BORDER);
   putbarrier (3022, 136, 3070, 223, mapa2, BORDER);
   putbarrier (3006, 152, 3037, 199, mapa2, BORDER);
   putbarrier (2990, 168, 3021, 199, mapa2, BORDER);
   putbarrier (2974, 184, 2989, 199, mapa2, BORDER);
   
   putbarrier (1072, 200, 1151, 223, mapa2, EMPTY);
   putbarrier (1072, 219, 1151, 223, mapa2, BLOCKDEATH);
   putbarrier (COIN1_XLOC, COIN1_YLOC, COIN1_XLOC+COIN_SIZE, COIN1_YLOC+COIN_SIZE, mapa2, COIN1);
   putbarrier (COIN2_XLOC, COIN2_YLOC, COIN2_XLOC+COIN_SIZE, COIN2_YLOC+COIN_SIZE, mapa2, COIN2);
   putbarrier (COIN3_XLOC, COIN3_YLOC, COIN3_XLOC+COIN_SIZE, COIN3_YLOC+COIN_SIZE, mapa2, COIN3);
    
    /*Los if... se pueden reemplazar por la funcion must_init del github, quien quiera que lo haga*/
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if (!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    
        if (!al_init_image_addon()) {
        fprintf(stderr, "Unable to start image addon \n"); //Igual que printf pero imprime al error std 
        al_uninstall_system();
        return -1;
    }
    
    display = al_create_display(SCREEN_W, SCREEN_H);
    if (!display) 
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        al_destroy_bitmap(mario);
        al_destroy_event_queue(event_queue);
        return -1;
    }
    
    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
    if (!buffer) {
        fprintf(stderr, "failed to create Mario bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    }
    
    mario = al_load_bitmap("Mario.png");//al_create_bitmap(MARIO_SIZE, MARIO_SIZE);
    if (!mario) {
        fprintf(stderr, "failed to create mario bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    }
    
    fish = al_load_bitmap("fish.png");
    if (!fish) {
        fprintf(stderr, "failed to create mario bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    } 
    
    coin = al_load_bitmap("coin.png");
    if (!coin) {
        fprintf(stderr, "failed to create mario bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    }
    
    
    if (!(background = al_load_bitmap("NES - Super Mario Bros - World 2-2.png"))) {
        fprintf(stderr, "Unable to load logo\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    
    game_over = al_load_bitmap("gameover.png");
    if (!game_over) {
        fprintf(stderr, "failed to create gameover bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    }
    
   
    event_queue = al_create_event_queue();
    if (!event_queue) 
    {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_bitmap(mario);
        al_destroy_timer(timer);
        return -1;
    }

al_init_primitives_addon();//inicia la parte de alegro que dibuja cosas simples
    
    al_set_target_bitmap(al_get_backbuffer(display));

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO

    al_clear_to_color(al_map_rgb(0, 0, 0));
    
    al_set_target_backbuffer(display);
    al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    al_flip_display();
    al_start_timer(timer);

    while (!do_exit) 
    {

        
            
        ALLEGRO_EVENT ev;
        if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if (ev.type == ALLEGRO_EVENT_TIMER) {
  
            if (pausa==false) //Las funciones de movimiento solo funcionaran cuando el juego no esté en pausa
            {          

               //Movimiento de enemigos
               enemy_mov(F1p, pMario);
        
                
                //Teclas de movimiento
 
                if (key_pressed[KEY_UP] && (Mario.y) >= MOVE_RATE && collidewborder(pMario ,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa2) )
                    {
                    if ((Mario.salto_cooldown)==0 && (Mario.salto_lock)==0)
                        {
                        (Mario.salto_cooldown)= 30;
                        (Mario.salto) = 18;
                        (Mario.salto_lock)=1;
                        }                    
                    }
                 
                    if (!key_pressed[KEY_UP])
                        (Mario.salto_lock)=0;
                 
                        
                if (key_pressed[KEY_DOWN]  && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa2))
                    (Mario.y) += MOVE_RATE;
                else if(key_pressed[KEY_DOWN]  && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)+1, (Mario.x)+MARIO_SIZE , (Mario.y)+1+MARIO_SIZE, mapa2))
                    (Mario.y) += 1;

                if (key_pressed[KEY_LEFT] && (Mario.x) >= MOVE_RATE && collidewborder(pMario,(Mario.x)-MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE-MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa2))
                    (Mario.x) -= MOVE_RATE;
                else if (key_pressed[KEY_LEFT] && (Mario.x) >= MOVE_RATE && collidewborder(pMario,(Mario.x)-1, (Mario.y), (Mario.x)+MARIO_SIZE-1 , (Mario.y)+MARIO_SIZE, mapa2))
                    (Mario.x) -= 1;
                    
                if (key_pressed[KEY_RIGHT] && collidewborder(pMario,(Mario.x)+MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE+MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa2))
                    (Mario.x) += MOVE_RATE;
                else if (key_pressed[KEY_RIGHT] && collidewborder(pMario,(Mario.x)+1, (Mario.y), (Mario.x)+MARIO_SIZE+1 , (Mario.y)+MARIO_SIZE, mapa2))
                    (Mario.x) += 1;
                
                
                //Salto de Mario
                
                if ((Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE  && collidewborder(pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa2)) //Mario cae siempre que no detecte nada abajo de él
                    (Mario.y) += MOVE_RATE/3; 
                
                
                if((Mario.salto_cooldown)>0 ) //Se disminuye la variable (Mario.salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
                    (Mario.salto_cooldown)--;
                
                if ((Mario.y) >= MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa2) && (Mario.salto>0) ) //Mario salta lo determinado por la variable saltito
                   {
                    (Mario.salto)-=1;
                    (Mario.y) -= MOVE_RATE;
                   }
                
                }
                
                //Boton de pausa
                if (key_pressed[KEY_P])
                {
                    if  (pausa_lock== false)
                    {
                        if (pausa== false )
                            {
                            pausa= true;
                            pausa_lock = true;
                            }
                        else
                            {
                            pausa = false;
                            pausa_lock = true;
                            }
                    }
                }
                if (!key_pressed[KEY_P])
                    pausa_lock= false;

                redraw = true;
            }
            else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                do_exit = true;

            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                        key_pressed[KEY_UP] = true;
                        break;

                    case ALLEGRO_KEY_DOWN:
                        key_pressed[KEY_DOWN] = true;
                        break;

                    case ALLEGRO_KEY_LEFT:
                        key_pressed[KEY_LEFT] = true;
                        break;

                    case ALLEGRO_KEY_RIGHT:
                        key_pressed[KEY_RIGHT] = true;
                        break;
                        
                    case ALLEGRO_KEY_P:
                        key_pressed[KEY_P] = true;
                        break;
                }
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                        key_pressed[KEY_UP] = false;
                        break;

                    case ALLEGRO_KEY_DOWN:
                        key_pressed[KEY_DOWN] = false;
                        break;

                    case ALLEGRO_KEY_LEFT:
                        key_pressed[KEY_LEFT] = false;
                        break;

                    case ALLEGRO_KEY_RIGHT:
                        key_pressed[KEY_RIGHT] = false;
                        break;
                        
                    case ALLEGRO_KEY_P:
                        key_pressed[KEY_P] = false;
                        break;

                    case ALLEGRO_KEY_ESCAPE:
                        do_exit = true;
                        break;
                }
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) 
        {
            redraw = false;
            disp_pre_draw(buffer);
            
            al_draw_bitmap(background,0,0,0);

            al_draw_bitmap(mario, (Mario.x), (Mario.y), 0);
            
            al_draw_bitmap(fish, (F1.x), (F1.y), 0);
            
            if (Mario.coin1 == true)
            al_draw_bitmap(coin, COIN1_XLOC, COIN1_YLOC, 0);
            if (Mario.coin2 == true)
            al_draw_bitmap(coin, COIN2_XLOC, COIN2_YLOC, 0);
            if (Mario.coin3 == true)
            al_draw_bitmap(coin, COIN3_XLOC, COIN3_YLOC, 0);

        if ((Mario.live)<=1) //Si se acabaron las vidas 
        {
         al_draw_scaled_bitmap(game_over,0,0,240,210,0,0,BUFFER_H,BUFFER_H,0);
         //al_draw_filled_rectangle(x1, y1, x2, y2, black);
         //al_draw_filled_rectangle(0, 0, 200, 200, grey);
        } 
            
            disp_post_draw(display, buffer, (Mario.x), (Mario.y)); 
            //disp_post_draw(display, buffer, (F1.x), (F1.y));
        }
        
        
        
    }

    al_destroy_bitmap(mario);
    al_destroy_bitmap(fish);
    
    al_destroy_timer(timer);
    al_destroy_display(display);
    return 0;
}

//FUNCIONES

void disp_pre_draw(ALLEGRO_BITMAP* b)
{
    al_set_target_bitmap(b);
}

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* b,float x,float y)
{
    al_set_target_backbuffer(disp);
    al_draw_scaled_bitmap(b, x-(BUFFER_H/2), 0, BUFFER_H, BUFFER_H, 0, 0, SCREEN_W, SCREEN_H, 0);
    al_flip_display();
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
/*Para los enemigos crear una funcion "draw_enemi()" que modifique la
 *matriz mapa, esta funcion antes de actualizar al jugador*/


bool collidewborder(player* Mario,int ax1, int ay1, int ax2, int ay2, const char mapa [BUFFER_H][BUFFER_W]) //esta funcion detecta si hubo una colision entre 2 elementos
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
                Mario->live-=1;
                Mario->x=0;
                Mario->y=0;
                return false;
            }
            if(mapa[j][i]== COIN1)
            {
                Mario->coin1 = false;
            }
            if(mapa[j][i]== COIN2)
            {
                Mario->coin2 = false;
            }
            if(mapa[j][i]== COIN3)
            {
                Mario->coin3 = false;
            }
        }
    }

    return true;
}


void enemy_mov (enemy * en, player* Mario ) 
{
//Generacion de enemigos
if ( (Mario->x) >= (en->x - (BUFFER_H/2)) )
        (en->active) =1;

//Movimiento de enemigos

if (en->active == 1)
    {
        if (en->type == FISH)
        (en->x) -= 1/MOVE_RATE_FISH;
        
        if ( collide_entity(en->x, en->y, (en->x)+FISH_SIZE, (en->y)+FISH_SIZE, Mario) )
            {
            Mario->live-=1;
            Mario->x=0;
            Mario->y=0;  
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

