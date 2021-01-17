

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define MAPA1 1
#define FINALMAPA 2
#define MAPA2 3

#define EXIT2 5
#define EXIT1 4
#define COIN 3
#define BORDER 2
#define BLOCKDEATH 1
#define EMPTY 0

#define COIN_SIZE 15.0

#define SQUID 3
#define REDFISH 2
#define FISH 1

#define MOVE_RATE_FISH  4.0
#define MOVE_RATE_REDFISH  2.0
#define MOVE_RATE_SQUID 2.0
#define DODGE_DIST 40

#define FISH_SIZE 16
#define SQUID_H 24
#define SQUID_W 16

typedef struct
{
    char live;//Vidas de Mario
    bool death;//Flag que indica si Mario acaba de morir
    float x;//Posicion x de Mario
    float y;//Posicion y de Mario
    char n_mapa_actual;
    float salto;
    float salto_cooldown;
    char salto_lock;//Flag que bloquea el salto de Mario cuando se mantiene apretada la tecla para saltar
    int coins;
    bool coin_obt;
    
}player;

typedef struct
{
    bool active; // Flag que indica si el enemigo esta activo o no
    char type;// Tipo de enemigo
    char mapa;//Mapa en el que está el enemigo
    float x;//Posicion x del enemigo
    float y;//Posicion y del enemigo
    float prev_pos;//Variable que guarda la posicion previa del pulpo antes de moverse lateralmente
    bool dodge;//Flag que utilizan los pulpos para indicar di deben ir hacia abajo o lateralmente
}enemy;

typedef struct
{
    bool active;
    float x;
    float y;
    char map;
}coin;

typedef struct
{
ALLEGRO_BITMAP *(*p_fish);
ALLEGRO_BITMAP *(*p_redfish);
ALLEGRO_BITMAP *(*p_squid);
ALLEGRO_BITMAP *(*p_coin);
}bitmaps_t;
    

void disp_pre_draw(ALLEGRO_BITMAP* buffer);

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* buffer,float x,float y);

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

bool collidewborder(player* , int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W],ALLEGRO_BITMAP *(*p_background)); //mapa, p_background y n_mapa_actual son siempre las mismas que se mandan

bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario);

void enemy_mov (enemy * en, player* Mario);

void enemy_start (enemy * en,bool active,char type,char mapa,float x,float y,float prev_pos,bool dodge);

void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]);

void draw_enemy (enemy * en, player * Mario, bitmaps_t * bit);

void fcoin(player * Mario,coin* ncoin);

void coin_start(coin* ncoin,float x,float y,char map, bool startup);

void draw_coin(player * Mario,coin* ncoin,bitmaps_t * bitm);

enum MYKEYS 
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT , KEY_P //arrow keys
};

char mapa1[BUFFER_H][BUFFER_W]={EMPTY};
char finalmapa[BUFFER_H][BUFFER_W]={EMPTY};
char mapa2[BUFFER_H][BUFFER_W]={EMPTY};

char mapa[BUFFER_H][BUFFER_W]={EMPTY};




int main(void) 
{
    //INICIALIZACION 
    // init_display();
    // init_buffer();
    
    //Inicializacion de Mario
    
    player Mario =  {3,false, 0, 0,MAPA1, 0, 0, 0,0,false}; 
    player * pMario = &Mario;
    
    /*bool coin1;
    bool coin2;
    bool coin3;*/
    
    coin coin1;
    coin * pcoin1=&coin1;
    
    coin coin2;
    coin * pcoin2=&coin2;
    
    coin coin3;
    coin * pcoin3=&coin3;
    
    //Inicializacion de enemigos
    
    enemy F1;
    enemy * F1p = &F1;
    
    enemy RF1;
    enemy * RF1p = &RF1;
    
    enemy S1;
    enemy * S1p = &S1;
    
    //Inicializacion de otras variables
    bool pausa= false;
    bool pausa_lock = false;
    bool startup=true;//flag que indica si el juego se acaba de iniciar
    
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    
    ALLEGRO_BITMAP *buffer = NULL;
    ALLEGRO_BITMAP *mario = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *game_over = NULL;
    
    ALLEGRO_BITMAP *fish = NULL;
    ALLEGRO_BITMAP *redfish = NULL;
    ALLEGRO_BITMAP *squid = NULL;
    ALLEGRO_BITMAP *coin = NULL;

    ALLEGRO_BITMAP *(*p_background) = &background;
    

    
    bitmaps_t bitmaps = {&fish,&redfish,&squid,&coin};
    bitmaps_t * p_bitmaps_t = &bitmaps;
    
    //ALLEGRO_COLOR grey;
      // grey = al_map_rgb(255, 0, 0);

   
    bool key_pressed[5] = {false, false, false, false, false}; //Estado de teclas, true cuando esta apretada
    bool redraw = false;
    bool do_exit = false;
     

   //Zona de creacion de barrera
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
   
   putbarrier (1072, 200, 1151, 223,  mapa1, EMPTY);
   putbarrier (1072, 219, 1151, 223,  mapa1, BLOCKDEATH);
   putbarrier (3039, 107, 3048, 135,  mapa1, EXIT1);
   
   putbarrier (0, 200, 563, 223, finalmapa, BORDER);
   putbarrier (447, 168, 463, 198, finalmapa, EXIT2);
   
   putbarrier (0, 207, 2199, 239, mapa2, BORDER);
    
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
    
    mario = al_load_bitmap("Mario.png");
    if (!mario) {
        fprintf(stderr, "failed to create mario bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    }
    
    fish = al_load_bitmap("fish2.png");
    if (!fish) {
        fprintf(stderr, "failed to create f2 bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    } 
    
    redfish = al_load_bitmap("fish.png");
    if (!fish) {
        fprintf(stderr, "failed to create mario bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    } 
    
    squid = al_load_bitmap("squid.png");
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

    clonarMatriz( mapa1,mapa);//se carga el primer mapa
    
    
    while (!do_exit) 
    {

        
            
        ALLEGRO_EVENT ev;
        if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if (ev.type == ALLEGRO_EVENT_TIMER) {
  
            if (pausa==false) //Las funciones de movimiento solo funcionaran cuando el juego no esté en pausa
            {          
                
                //Muerte de Mario
                if((Mario.death == true)|| startup==true)
                {
                    if(startup==false)
                    {
                    Mario.live-=1;
                    Mario.death=false;
                    }
                    Mario.x=0;
                    Mario.y=0;
                    
                    //Estado inicial de los enemigos
                    enemy_start(F1p,false,FISH,MAPA1,400,100,0,false);
                    enemy_start(RF1p,false,REDFISH,MAPA1,500,100,0,false);
                    enemy_start(S1p,false,SQUID,MAPA1,700,100,100,false);
                    
                    //Estado inicial de las monedas
                    coin_start(pcoin1,100,100,MAPA1,startup);
                    coin_start(pcoin2,130,100,MAPA1,startup);
                    coin_start(pcoin3,150,100,MAPA1,startup);
                    if(startup==true)
                    {
                    clonarMatriz( mapa1,mapa);
                    startup=false;
                    }
                }
        
                //Colision con las monedas
                fcoin(pMario,pcoin1);
                fcoin(pMario,pcoin2);
                fcoin(pMario,pcoin3);
                Mario.coin_obt=false;
                
                //Movimiento de enemigos
                enemy_mov(F1p, pMario);
                enemy_mov(RF1p, pMario);
                enemy_mov(S1p, pMario);
        
                
                //Teclas de movimiento
 
                if (key_pressed[KEY_UP] && (Mario.y) >= MOVE_RATE && collidewborder(pMario ,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa,p_background ))
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
                 
                        
                if (key_pressed[KEY_DOWN]  && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa,p_background))
                    (Mario.y) += MOVE_RATE;
                else if(key_pressed[KEY_DOWN]  && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)+1, (Mario.x)+MARIO_SIZE , (Mario.y)+1+MARIO_SIZE, mapa,p_background))
                    (Mario.y) += 1;

                if (key_pressed[KEY_LEFT] && (Mario.x) >= MOVE_RATE && collidewborder(pMario,(Mario.x)-MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE-MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa,p_background))
                    (Mario.x) -= MOVE_RATE;
                else if (key_pressed[KEY_LEFT] && (Mario.x) >= MOVE_RATE && collidewborder(pMario,(Mario.x)-1, (Mario.y), (Mario.x)+MARIO_SIZE-1 , (Mario.y)+MARIO_SIZE, mapa,p_background))
                    (Mario.x) -= 1;
                    
                if (key_pressed[KEY_RIGHT] && collidewborder(pMario,(Mario.x)+MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE+MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa,p_background))
                    (Mario.x) += MOVE_RATE;
                else if (key_pressed[KEY_RIGHT] && collidewborder(pMario,(Mario.x)+1, (Mario.y), (Mario.x)+MARIO_SIZE+1 , (Mario.y)+MARIO_SIZE, mapa,p_background))
                    (Mario.x) += 1;
                
                
                //Salto de Mario
                
                if ((Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE  && collidewborder(pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa,p_background)) //Mario cae siempre que no detecte nada abajo de él
                    (Mario.y) += MOVE_RATE/3; 
                
                
                if((Mario.salto_cooldown)>0 ) //Se disminuye la variable (Mario.salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
                    (Mario.salto_cooldown)--;
                
                if ((Mario.y) >= MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa,p_background) && (Mario.salto>0) ) //Mario salta lo determinado por la variable saltito
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
        //Dibujo de bitmaps
        if (redraw && al_is_event_queue_empty(event_queue)) 
        {
            redraw = false;
            disp_pre_draw(buffer);
            
            //Dibujo del mapa
            al_draw_bitmap(background,0,0,0);

            if ((Mario.live)==0)//Si se acabaron las vidas Mario se bloquea en una posicion y se pausa el juego
            {
             Mario.x= BUFFER_H/2; 
             pausa=true;
            }
            
            //Dibujo de Mario
            al_draw_bitmap(mario, (Mario.x), (Mario.y), 0);
            
            //Dibujo de enemigos
            draw_enemy (F1p, pMario, p_bitmaps_t);
            draw_enemy (RF1p, pMario, p_bitmaps_t);
            draw_enemy (S1p, pMario, p_bitmaps_t);
            
            //Dibujo de monedas
            draw_coin(pMario,pcoin1,p_bitmaps_t);
            draw_coin(pMario,pcoin2,p_bitmaps_t);
            draw_coin(pMario,pcoin3,p_bitmaps_t);

            if ((Mario.live)==0) //Si se acabaron las vidas aparece el cartel de game over
            {
             al_draw_scaled_bitmap(game_over,0,0,240,210,0,0,BUFFER_H,BUFFER_H,0);
             //al_draw_filled_rectangle(x1, y1, x2, y2, black);
             //al_draw_filled_rectangle(0, 0, 200, 200, grey);
            } 
            disp_post_draw(display, buffer, (Mario.x), (Mario.y)); 
        }
        
        
        
    }

    al_destroy_bitmap(mario);
    al_destroy_bitmap(fish);
    al_destroy_bitmap(redfish);
    al_destroy_bitmap(squid);
    al_destroy_bitmap(coin);
    
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
            if(mapa[j][i]== EXIT1)
            {
             *p_background = al_load_bitmap("mapa-final.png");
              clonarMatriz(finalmapa,mapa);
              Mario->x=0;
              Mario->y=0;
              Mario->n_mapa_actual=FINALMAPA;
               return false;
            }
            if(mapa[j][i]== EXIT2)
            {
             *p_background = al_load_bitmap("mapa2.png");
              clonarMatriz(mapa2,mapa);
              Mario->x=0;
              Mario->y=0;
              Mario->n_mapa_actual=MAPA2;
               return false;
            }
        }
    }

    return true;
}


void enemy_mov (enemy * en, player* Mario ) 
{
if((Mario->n_mapa_actual)== en->mapa)
{
    //Generacion de enemigos
    if ( (Mario->x) >= (en->x - (BUFFER_H/2)) )//solo se activará el enemigo cuando se encuentre en el campo de vision de mario
            (en->active) =true;

    //Movimiento de enemigos

    if (en->active == true)
        {

            if (en->type == FISH || en->type == REDFISH) //Movimiento de los peces
                {
                if ( collide_entity(en->x, en->y, (en->x)+FISH_SIZE, (en->y)+FISH_SIZE, Mario) )
                    {
                    Mario->death=true; 
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

        }
}
}


void enemy_start (enemy * en,bool active,char type,char ma,float x,float y,float prev_pos,bool dodge)
{
    en->active= active; // Flag que indica si el enemigo esta activo o no
    en->type= type;// Tipo de enemigo
    en->mapa= ma;//Mapa en el que está el enemigo
    en->x= x;//Posicion x del enemigo
    en->y= y;//Posicion y del enemigo
    en->prev_pos= prev_pos;//Variable que guarda la posicion previa del pulpo antes de moverse lateralmente
    en->dodge= dodge;//Flag que utilizan los pulpos para indicar di deben ir hacia abajo o lateralmente
}

void draw_enemy (enemy * en, player * Mario, bitmaps_t * bitm)
{
    if((Mario->n_mapa_actual)== en->mapa)
    {
        
        if (en->type == FISH)
        al_draw_bitmap(*(bitm->p_fish), (en->x), (en->y), 0);
        if (en->type == REDFISH)
        al_draw_bitmap(*(bitm->p_redfish), (en->x), (en->y), 0);
        if (en->type == SQUID)
        al_draw_bitmap(*(bitm->p_squid), (en->x), (en->y), 0);
    }
}

void fcoin(player * Mario,coin* ncoin)
{
        if(Mario->coin_obt) //Solo se escanea si mario tocó la moneda cuando el flag de coin_obtenida se encuentra prendida
            {
                if(Mario->n_mapa_actual== (ncoin->map))
                    {
                    if(collide_entity(ncoin->x, ncoin->y, (ncoin->x)+COIN_SIZE, (ncoin->y)+COIN_SIZE, Mario))
                    ncoin->active=false;//Si mario tocó la moneda esta se desactiva y se aumenta el contador de monedas
                    Mario->coins ++;
                    }
            }

        if((Mario->n_mapa_actual) != (ncoin->map)) //Si Mario no está en el mapa de la moneda esta se desactiva
            {
            ncoin->active=false;
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
    if(map==MAPA1)
    putbarrier ((int)x, (int)y, (int)(x+COIN_SIZE), (int)(y+COIN_SIZE), mapa1, COIN);
    }
}

void draw_coin(player * Mario,coin* ncoin,bitmaps_t * bitm)
{
     if(((Mario->n_mapa_actual)== (ncoin->map)) && ((ncoin->active) == true))//se dibuja la moneda solo cuando esté activa y mario se encuentre en el mapa de la misma
        {
        al_draw_bitmap(*(bitm->p_coin), ncoin->x, ncoin->y, 0);
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