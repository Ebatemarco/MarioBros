

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>




#define FPS    60.0

#define BUFFER_W 3103
#define BUFFER_H 224
#define DISP_SCALE 4
#define SCREEN_W (BUFFER_H * DISP_SCALE)
#define SCREEN_H (BUFFER_H * DISP_SCALE)

#define MARIO_SIZE 15
#define MOVE_RATE  2.0
#define SALTO_H 25 //Altura del salto de mario
#define SALTO_SPEED 1 //Velocidad de la subida al saltar
#define MARIO_W 16 //Tamaño del sprite
#define MARIO_H 16 //Tamaño del sprite
#define MARIO_LIVES 3
#define XINICIAL 55
#define YINICIAL 70
#define LEVEL_TIME 240

#define MAPAINICIO 0
#define MAPA1 1
#define FINALMAPA1 (MAPA1+10)
#define MAPA2 2
#define FINALMAPA2 (MAPA2+10)
#define MAPA3 3

#define MAPAINICIO_W 500
#define MAPA1_W 3103
#define FINALMAPA1_W  564
#define MAPA2_W  2200
#define FINALMAPA2_W  564
#define MAPA3_W  338

#define EXIT4 8
#define EXIT3 7
#define EXIT2 6
#define EXIT1 5
#define EXIT0 4
#define COIN 3
#define BORDER 2
#define BLOCKDEATH 1
#define EMPTY 0

#define COIN_SIZE 15.0

#define MISIL6 10
#define MISIL5 9
#define MISIL4 8
#define MISIL3 7
#define MISIL2 6
#define MISIL1 5
#define BOSS 4
#define SQUID 3
#define REDFISH 2
#define FISH 1

#define MOVE_RATE_FISH  4.0
#define MOVE_RATE_REDFISH  2.0
#define MOVE_RATE_SQUID 2.0
#define DODGE_DIST 40
#define FISH_DIST 15

#define FISH_SIZE 16
#define SQUID_H 24
#define SQUID_W 16
#define BOSS_H 50
#define BOSS_W 75
#define MISIL_SIZE 10

typedef struct
{
    char live;//Vidas de Mario
    bool death;//Flag que indica si Mario acaba de morir
    float x;//Posicion x de Mario
    float y;//Posicion y de Mario
    char n_mapa_actual;
    int salto;//variable que indica cuanto debe subir mario tras saltar
    int salto_cooldown;//temporizador que indica cuanto falta para hacer un nuevo salto
    bool salto_lock;//Flag que bloquea el salto de Mario cuando se mantiene apretada la tecla para saltar
    int coins;
    bool coin_obt;
    unsigned int timer;
    unsigned int score;
    
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
    int timer;//Temporizador de los misiles que indica cuanto falta para que se activen
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
    

void disp_pre_draw(ALLEGRO_BITMAP* buffer);

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* buffer,ALLEGRO_BITMAP* menupausa,ALLEGRO_BITMAP* gameover, player* Mario, ALLEGRO_FONT * font,bool pausa);

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

bool collidewborder(player* , int ax1, int ay1, int ax2, int ay2,char mapa [BUFFER_H][BUFFER_W],ALLEGRO_BITMAP *(*p_background)); //mapa, p_background y n_mapa_actual son siempre las mismas que se mandan

bool collide_entity(float ax1, float ay1, float ax2, float ay2, player* Mario);

void enemy_mov (enemy * en, player* Mario);

void enemy_start (enemy * en,bool active,char type,char mapa,float x,float y,bool dodge,int time);

void clonarMatriz(char origen[BUFFER_H][BUFFER_W], char destino[BUFFER_H][BUFFER_W]);

void draw_enemy (enemy * en, player * Mario, bitmaps_t * bit);

void fcoin(player * Mario,coin* ncoin);

void coin_start(coin* ncoin,float x,float y,char map, bool startup);

void draw_coin(player * Mario,coin* ncoin,bitmaps_t * bitm);

enum MYKEYS 
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT , KEY_P ,KEY_R
};

char mapainicio[BUFFER_H][BUFFER_W]={EMPTY};
char mapa3[BUFFER_H][BUFFER_W]={EMPTY};
char finalmapa2[BUFFER_H][BUFFER_W]={EMPTY};
char mapa1[BUFFER_H][BUFFER_W]={EMPTY};
char finalmapa1[BUFFER_H][BUFFER_W]={EMPTY};
char mapa2[BUFFER_H][BUFFER_W]={EMPTY};



char mapa[BUFFER_H][BUFFER_W]={EMPTY};




int main(void) 
{
    //INICIALIZACION 
    
    //Inicializacion de Mario
    
    player Mario;
    player * pMario = &Mario;
    
    //Inicializacion de monedas
    
    coin coin1;
    coin * pcoin1=&coin1;
    coin coin2;
    coin * pcoin2=&coin2;
    coin coin3;
    coin * pcoin3=&coin3;
    coin coin4;
    coin * pcoin4=&coin4;
    coin coin5;
    coin * pcoin5=&coin5;
    coin coin6;
    coin * pcoin6=&coin6;
    coin coin7;
    coin * pcoin7=&coin7;
    coin coin8;
    coin * pcoin8=&coin8;
    coin coin9;
    coin * pcoin9=&coin9;
    coin coin10;
    coin * pcoin10=&coin10;
    coin coin11;
    coin * pcoin11=&coin11;
    coin coin12;
    coin * pcoin12=&coin12;
    coin coin13;
    coin * pcoin13=&coin13;
    coin coin14;
    coin * pcoin14=&coin14;
    coin coin15;
    coin * pcoin15=&coin15;
    coin coin16;
    coin * pcoin16=&coin16;
    coin coin17;
    coin * pcoin17=&coin17;
    coin coin18;
    coin * pcoin18=&coin18;
    coin coin19;
    coin * pcoin19=&coin19;
    coin coin20;
    coin * pcoin20=&coin20;
    coin coin21;
    coin * pcoin21=&coin21;
    coin coin22;
    coin * pcoin22=&coin22;
    coin coin23;
    coin * pcoin23=&coin23;
    coin coin24;
    coin * pcoin24=&coin24;
    coin coin25;
    coin * pcoin25=&coin25;
    coin coin26;
    coin * pcoin26=&coin26;
    coin coin27;
    coin * pcoin27=&coin27;
    coin coin28;
    coin * pcoin28=&coin28;
    coin coin29;
    coin * pcoin29=&coin29;
    coin coin30;
    coin * pcoin30=&coin30;
    coin coin31;
    coin * pcoin31=&coin31;
    coin coin32;
    coin * pcoin32=&coin32;
    coin coin33;
    coin * pcoin33=&coin33;
    coin coin34;
    coin * pcoin34=&coin34;
    coin coin35;
    coin * pcoin35=&coin35;
    
    
    //Inicializacion de enemigos MAPA 1
    enemy F1;
    enemy * F1p = &F1;
    enemy F2;
    enemy * F2p = &F2;
    enemy F3;
    enemy * F3p = &F3;
    enemy F4;
    enemy * F4p = &F4;
    enemy F5;
    enemy * F5p = &F5;
    enemy F6;
    enemy * F6p = &F6;
    enemy F7;
    enemy * F7p = &F7;
    enemy F8;
    enemy * F8p = &F8;
    enemy F9;
    enemy * F9p = &F9;
    enemy F10;
    enemy * F10p = &F10;
    enemy F11;
    enemy * F11p = &F11;
    enemy F12;
    enemy * F12p = &F12;
    
    
    enemy RF1;
    enemy * RF1p = &RF1;
    enemy RF2;
    enemy * RF2p = &RF2;
    enemy RF3;
    enemy * RF3p = &RF3;
    enemy RF4;
    enemy * RF4p = &RF4;
    enemy RF5;
    enemy * RF5p = &RF5;
    enemy RF6;
    enemy * RF6p = &RF6;
    enemy RF7;
    enemy * RF7p = &RF7;
    enemy RF8;
    enemy * RF8p = &RF8;
    enemy RF9;
    enemy * RF9p = &RF9;
    
    enemy S1;
    enemy * S1p = &S1;
    enemy S2;
    enemy * S2p = &S2;
    enemy S3;
    enemy * S3p = &S3;
    enemy S4;
    enemy * S4p = &S4;
    enemy S5;
    enemy * S5p = &S5;
    enemy S6;
    enemy * S6p = &S6;
    enemy S7;
    enemy * S7p = &S7;
    
    // Inicializacion enemigos MAPA 3 - BOSS
    enemy Boss;
    enemy * Bossp = &Boss;
    
    enemy M1;
    enemy * M1p = &M1;
    
    enemy M2;
    enemy * M2p = &M2;
    
    enemy M3;
    enemy * M3p = &M3;
    
    enemy M4;
    enemy * M4p = &M4;
    
    enemy M5;
    enemy * M5p = &M5;
    
    enemy M6;
    enemy * M6p = &M6;
    
    
    
    //Inicializacion de otras variables
    
    bool pausa= false;
    bool pausa_lock = false;
    bool restart=true;//flag que indica si el juego se reinicio
    
    int timemarker=0;
    
    bool key_pressed[5] = {false, false, false, false, false}; //Estado de teclas, true cuando esta apretada
    bool redraw = false;
    bool do_exit = false;
    
    //Variables relacionadas solo con el dibujo de mario
    int mariomove=0;//variable utilizada para alternar entre las animaciones 
    bool marioright=true;//flag que indica si mario esta mirando hcia la derecha
    bool mariosteady=false;//flag que indica si mario esta quieto
    
    
    //Inicializacion de bitmaps y otras variables de allegro
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT * font = NULL;
    
    ALLEGRO_BITMAP *buffer = NULL;
    
    ALLEGRO_BITMAP *mario1 = NULL;
    ALLEGRO_BITMAP *mario2 = NULL;
    ALLEGRO_BITMAP *mario3 = NULL;
    ALLEGRO_BITMAP *mario4 = NULL;
    ALLEGRO_BITMAP *mario5 = NULL;
    ALLEGRO_BITMAP *mario6 = NULL;
    
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *game_over = NULL;
    ALLEGRO_BITMAP *menupausa = NULL;
    
    ALLEGRO_BITMAP *fish1 = NULL;
    ALLEGRO_BITMAP *fish2 = NULL;
    
    ALLEGRO_BITMAP *redfish1 = NULL;
    ALLEGRO_BITMAP *redfish2 = NULL;
    
    ALLEGRO_BITMAP *squid1 = NULL;
    ALLEGRO_BITMAP *squid2 = NULL;
    
    ALLEGRO_BITMAP *coin = NULL;
    ALLEGRO_BITMAP *boss = NULL;
    ALLEGRO_BITMAP *misil = NULL;
    
    ALLEGRO_BITMAP *explosion1 = NULL;
    ALLEGRO_BITMAP *explosion2 = NULL;
    ALLEGRO_BITMAP *explosion3 = NULL;

    ALLEGRO_BITMAP *(*p_background) = &background;
    

    
    bitmaps_t bitmaps = {&fish1,&fish2,&redfish1,&redfish2,&squid1,&squid2,&coin,&boss,&misil,&explosion1,&explosion2,&explosion3};//se utiliza una estructura de bitmaps para hacer más simple el uso de funciones de animación
    bitmaps_t * p_bitmaps_t = &bitmaps;
    

   //Zona de creacion de barreras
    
    //Mapa inicial
   putbarrier (0, 200, 563, 223, mapainicio, BORDER);
   putbarrier (MAPAINICIO_W-1, 0 , MAPAINICIO_W, BUFFER_H, mapainicio, BORDER);
   putbarrier (404, 173, 414, 199, mapainicio, EXIT0);
   
    //Mapa 1
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
   putbarrier (0, 200, 563, 223, mapa3, BORDER);
   putbarrier (MAPA3_W-1, 0 , MAPA3_W, BUFFER_H, mapa3, BORDER);
   
   
    //Carga de bitmaps, y otras variables de allegro
   
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
        al_destroy_bitmap(mario1);
        al_destroy_event_queue(event_queue);
        return -1;
    }
    al_set_window_title(display,"SUPER Mario Bros - Underwater Edition");
    
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
    
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    font = al_load_ttf_font("mariobros.ttf", DISP_SCALE*7.5, 0);
    if (!font) {
        fprintf(stderr, "Could not load 'mariofont.ttf'.\n");
        return -1;
    }
    
    
    mario1 = al_load_bitmap("Mario1.png");
    mario2 = al_load_bitmap("Mario2.png");
    mario3 = al_load_bitmap("Mario3.png");
    mario4 = al_load_bitmap("Mario4.png");
    mario5 = al_load_bitmap("Mario5.png");
    mario6 = al_load_bitmap("Mario6.png");
    
    fish1 = al_load_bitmap("fish1.png");

    
    fish2 = al_load_bitmap("fish2.png");

    
    redfish1 = al_load_bitmap("redfish1.png");
 
    
    redfish2 = al_load_bitmap("redfish2.png");

    
    squid1 = al_load_bitmap("squid1.png");

    
    squid2 = al_load_bitmap("squid2.png");

    
    coin = al_load_bitmap("coin.png");

    boss = al_load_bitmap("boss.png");

    misil = al_load_bitmap("bala.png");

    
    
    if (!(background = al_load_bitmap("mapa-inicio.png"))) {
        fprintf(stderr, "Unable to load logo\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    
    
    game_over = al_load_bitmap("gameover.png");
    menupausa = al_load_bitmap("menu de pausa.png");

    explosion1 = al_load_bitmap("explosion1.png");

    
    explosion2 = al_load_bitmap("explosion2.png");

    
    explosion3 = al_load_bitmap("explosion3.png");

   
    event_queue = al_create_event_queue();
    if (!event_queue) 
    {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_bitmap(mario1);
        al_destroy_timer(timer);
        return -1;
    }


    //Registro de eventos

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO

    al_start_timer(timer);//inicio del timer

   
    while (!do_exit) 
    {    
        ALLEGRO_EVENT ev;
        if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if (ev.type == ALLEGRO_EVENT_TIMER) {
                
                
            if (restart==true)
            {
                //Estado inicial de Mario
                Mario.live=MARIO_LIVES;
                Mario.death=false;
                Mario.x=118;
                Mario.y=183;
                Mario.n_mapa_actual=MAPAINICIO;
                Mario.salto=0;
                Mario.salto_cooldown=0;
                Mario.salto_lock=false;
                Mario.coins=0;
                Mario.coin_obt=false;
                Mario.timer=LEVEL_TIME;
                Mario.score=0;
                
               //Estado inicial de las monedas MAPA 1
                coin_start(pcoin1,100,100,MAPA1,restart);
                coin_start(pcoin2,130,100,MAPA1,restart);
                coin_start(pcoin3,150,100,MAPA1,restart);
                coin_start(pcoin4,2895,52,MAPA1,restart);
                coin_start(pcoin5,1402,41,MAPA1,restart);
                coin_start(pcoin6,304,118,MAPA1,restart);
                coin_start(pcoin7,539,71,MAPA1,restart);
                coin_start(pcoin8,688,86,MAPA1,restart);
                coin_start(pcoin9,697,171,MAPA1,restart);
                coin_start(pcoin10,940,96,MAPA1,restart);
                coin_start(pcoin11,1087,182,MAPA1,restart);
                coin_start(pcoin12,1121,182,MAPA1,restart);
                coin_start(pcoin13,1272,78,MAPA1,restart);
                coin_start(pcoin14,1272,130,MAPA1,restart);
                coin_start(pcoin15,1530,179,MAPA1,restart);
                coin_start(pcoin16,1648,53,MAPA1,restart);
                coin_start(pcoin17,1768,179,MAPA1,restart);
                coin_start(pcoin18,1863,103,MAPA1,restart);
                coin_start(pcoin19,2135,34,MAPA1,restart);
                coin_start(pcoin20,2149,175,MAPA1,restart);
                coin_start(pcoin21,2204,175,MAPA1,restart);
                coin_start(pcoin22,2366,147,MAPA1,restart);
                coin_start(pcoin23,2550,142,MAPA1,restart);
                coin_start(pcoin24,2600,142,MAPA1,restart);
                coin_start(pcoin25,2825,117,MAPA1,restart);
                
                //Estado inicial de las monedas MAPA 2
                coin_start(pcoin26,193,108,MAPA2,restart);
                coin_start(pcoin27,224,108,MAPA2,restart);
                coin_start(pcoin28,254,108,MAPA2,restart);
                coin_start(pcoin29,639,119,MAPA2,restart);
                coin_start(pcoin30,1791,119,MAPA2,restart);
                coin_start(pcoin31,1023,119,MAPA2,restart);
                coin_start(pcoin32,1407,119,MAPA2,restart);
                coin_start(pcoin33,1607,179,MAPA2,restart);
                coin_start(pcoin34,1223,61,MAPA2,restart);
                coin_start(pcoin35,840,179,MAPA2,restart);
                
                //Carga del primer mapa
                
                clonarMatriz(mapainicio,mapa);
                background = al_load_bitmap("mapa-inicio.png");

                pausa=true;
            }
    
             
                //Muerte de Mario
                if((Mario.death == true)|| restart==true)
                {
                    if(restart==false)
                    {
                    Mario.live-=1;
                    Mario.death=false;
                    Mario.x=XINICIAL;
                    Mario.y=YINICIAL;
                    }
                    
                    //Estado inicial de los enemigos
                    
                    //MAPA 1
                    
                    enemy_start(F1p,false,FISH,MAPA1,219,122,false,0);
                    enemy_start(F2p,false,FISH,MAPA1,380,86,false,0);
                    enemy_start(F3p,false,FISH,MAPA1,615,71,false,0);
                    enemy_start(F4p,false,FISH,MAPA1,944,42,false,0);
                    enemy_start(F5p,false,FISH,MAPA1,1200,72,false,0);
                    enemy_start(F6p,false,FISH,MAPA1,1416,173,false,0);
                    enemy_start(F7p,false,FISH,MAPA1,1538,104,false,0);
                    enemy_start(F8p,false,FISH,MAPA1,1708,55,false,0);
                    enemy_start(F9p,false,FISH,MAPA1,2230,166,false,0);
                    enemy_start(F10p,false,FISH,MAPA1,2426,142,false,0);
                    enemy_start(F11p,false,FISH,MAPA1,2613,107,false,0);
                    enemy_start(F12p,false,FISH,MAPA1,2935,111,false,0);
                    
                    enemy_start(RF1p,false,REDFISH,MAPA1,268,87,false,0);
                    enemy_start(RF2p,false,REDFISH,MAPA1,756,172,false,0);
                    enemy_start(RF3p,false,REDFISH,MAPA1,1465,40,false,0);
                    enemy_start(RF4p,false,REDFISH,MAPA1,1820,158,false,0);
                    enemy_start(RF5p,false,REDFISH,MAPA1,1922,84,false,0);
                    enemy_start(RF6p,false,REDFISH,MAPA1,2322,84,false,0);
                    enemy_start(RF7p,false,REDFISH,MAPA1,2610,46,false,0);
                    enemy_start(RF8p,false,REDFISH,MAPA1,2787,112,false,0);
                    enemy_start(RF9p,false,REDFISH,MAPA1,2988,48,false,0);
                    
                    enemy_start(S1p,false,SQUID,MAPA1,459,173,false,0);
                    enemy_start(S2p,false,SQUID,MAPA1,944,168,false,0);
                    enemy_start(S3p,false,SQUID,MAPA1,1056,98,false,0);
                    enemy_start(S4p,false,SQUID,MAPA1,1258,131,false,0);
                    enemy_start(S5p,false,SQUID,MAPA1,1615,179,false,0);
                    enemy_start(S6p,false,SQUID,MAPA1,2076,107,false,0);
                    enemy_start(S7p,false,SQUID,MAPA1,2739,168,false,0);

                    //MAPA 3 - BOSS
                    
                    enemy_start(Bossp,false,BOSS,MAPA3,300,103,false,60*33);
                    
                    enemy_start(M1p,false,MISIL1,MAPA3,277,114,false,60*4);
                    enemy_start(M2p,false,MISIL2,MAPA3,277,114,false,60*6);
                    enemy_start(M3p,false,MISIL3,MAPA3,277,117,true,60*8);
                    enemy_start(M4p,false,MISIL4,MAPA3,260,157,false,60*10);
                    enemy_start(M5p,false,MISIL5,MAPA3,260,157,false,60*12);
                    enemy_start(M6p,false,MISIL6,MAPA3,277,114,false,60*14);
                    
                    restart=false;
                }
            
            mariosteady=true;//mintras que mario no se mueva esta variable permanecerá true
            
            if (pausa==false) //Las funciones de movimiento solo funcionaran cuando el juego no esté en pausa
            {          
               
                
                //Colision con las monedas
                
                fcoin(pMario,pcoin1);
                fcoin(pMario,pcoin2);
                fcoin(pMario,pcoin3);
                fcoin(pMario,pcoin4);
                fcoin(pMario,pcoin5);
                fcoin(pMario,pcoin6);
                fcoin(pMario,pcoin7);
                fcoin(pMario,pcoin8);
                fcoin(pMario,pcoin9);
                fcoin(pMario,pcoin10);
                fcoin(pMario,pcoin11);
                fcoin(pMario,pcoin12);
                fcoin(pMario,pcoin13);
                fcoin(pMario,pcoin14);
                fcoin(pMario,pcoin15);
                fcoin(pMario,pcoin16);
                fcoin(pMario,pcoin17);
                fcoin(pMario,pcoin18);
                fcoin(pMario,pcoin19);
                fcoin(pMario,pcoin20);
                fcoin(pMario,pcoin21);
                fcoin(pMario,pcoin22);
                fcoin(pMario,pcoin23);
                fcoin(pMario,pcoin24);
                fcoin(pMario,pcoin25);
                
                fcoin(pMario,pcoin26);
                fcoin(pMario,pcoin27);
                fcoin(pMario,pcoin28);
                fcoin(pMario,pcoin29);
                fcoin(pMario,pcoin30);
                fcoin(pMario,pcoin31);
                fcoin(pMario,pcoin32);
                fcoin(pMario,pcoin33);
                fcoin(pMario,pcoin34);
                fcoin(pMario,pcoin35);
                
                
                
                Mario.coin_obt=false;
                
                //Movimiento de enemigos MAPA 1
                
                enemy_mov(F1p, pMario);
                enemy_mov(F2p, pMario);
                enemy_mov(F3p, pMario);
                enemy_mov(F4p, pMario);
                enemy_mov(F5p, pMario);
                enemy_mov(F6p, pMario);
                enemy_mov(F7p, pMario);
                enemy_mov(F8p, pMario);
                enemy_mov(F9p, pMario);
                enemy_mov(F10p, pMario);
                enemy_mov(F11p, pMario);
                enemy_mov(F12p, pMario);
                
                enemy_mov(RF1p, pMario);
                enemy_mov(RF2p, pMario);
                enemy_mov(RF3p, pMario);
                enemy_mov(RF4p, pMario);
                enemy_mov(RF5p, pMario);
                enemy_mov(RF6p, pMario);
                enemy_mov(RF7p, pMario);
                enemy_mov(RF8p, pMario);
                enemy_mov(RF9p, pMario);
                
                enemy_mov(S1p, pMario);
                enemy_mov(S2p, pMario);
                enemy_mov(S3p, pMario);
                enemy_mov(S4p, pMario);
                enemy_mov(S5p, pMario);
                enemy_mov(S6p, pMario);
                enemy_mov(S7p, pMario);
                
                //Movimiento de enemigos MAPA 3 - BOSS
                
                enemy_mov(Bossp, pMario);
                enemy_mov(M1p, pMario);
                enemy_mov(M2p, pMario);
                enemy_mov(M3p, pMario);
                enemy_mov(M4p, pMario);
                enemy_mov(M5p, pMario);
                enemy_mov(M6p, pMario);

        
                //Timer de mario para sus animaciones
                timemarker++;
                if (timemarker==FPS)
                    {
                    Mario.timer--;
                    timemarker=0;
                    }
                


                        
                //Teclas de movimiento
 
                if (key_pressed[KEY_UP] && (Mario.y) >= MOVE_RATE && collidewborder(pMario ,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa,p_background ))
                    {
                    mariomove++;
                    mariosteady=false;
                    if ((Mario.salto_cooldown)==0 && (Mario.salto_lock)==false)
                        {
                        (Mario.salto_cooldown)= 30;
                        (Mario.salto) = SALTO_H;
                        (Mario.salto_lock)=true;
                        }                    
                    }
                    
                    if (!key_pressed[KEY_UP])
                        (Mario.salto_lock)=false;
                 
                        
                if (key_pressed[KEY_DOWN]  && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa,p_background))
                    {
                    (Mario.y) += MOVE_RATE;
                    mariomove++;
                    mariosteady=false;
                    }

                if (key_pressed[KEY_LEFT] && (Mario.x) >= MOVE_RATE && collidewborder(pMario,(Mario.x)-MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE-MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa,p_background))
                    {
                    (Mario.x) -= MOVE_RATE;
                    mariomove++;
                    marioright=false;
                    mariosteady=false;
                    }

                if (key_pressed[KEY_RIGHT] && collidewborder(pMario,(Mario.x)+MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE+MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa,p_background))
                    {
                    (Mario.x) += MOVE_RATE;
                    mariomove++;
                    marioright=true;
                    mariosteady=false;
                    }

                
                //Salto de Mario
                
                if ((Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE  && collidewborder(pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa,p_background)) //Mario cae siempre que no detecte nada abajo de él
                    {
                    (Mario.y) += MOVE_RATE/3; 
                    mariomove++;
                    }
                
                if((Mario.salto_cooldown)>0 ) //Se disminuye la variable (Mario.salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
                    (Mario.salto_cooldown)--;
                
                if ((Mario.y) >= MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa,p_background) && (Mario.salto>0) ) //Mario salta lo determinado por la variable saltito
                   {
                    (Mario.salto)-=1;
                    (Mario.y) -= MOVE_RATE*SALTO_SPEED;
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
            
                //Boton de reiniciar
                if(key_pressed[KEY_R])
                restart=true;
            
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
                        
                    case ALLEGRO_KEY_R:
                        key_pressed[KEY_R] = true;
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
                        
                    case ALLEGRO_KEY_R:
                        key_pressed[KEY_R] = false;
                        break;

                    case ALLEGRO_KEY_ESCAPE:
                        do_exit = true;
                        break;
                }
            }
        }
        
        //DIBUJO DE BITMAPS
        
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
            
            if ((!collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa,p_background))&& mariosteady==true)//Deteccion de si Mario está estático en el suelo
                {
                if (marioright==true)
                al_draw_bitmap(mario6, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario6, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            else if (mariomove < 20 && mariomove >= 0)
                {
                if (marioright==true)
                al_draw_bitmap(mario1, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario1, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            else if (mariomove < 40) 
                {
                if (marioright==true)
                al_draw_bitmap(mario2, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario2, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            else if (mariomove < 60) 
                {
                if (marioright==true)
                al_draw_bitmap(mario3, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario3, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            else if (mariomove < 80) 
                {
                if (marioright==true)
                al_draw_bitmap(mario4, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario4, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            else if (mariomove < 100) 
                {
                if (marioright==true)
                al_draw_bitmap(mario5, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario5, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            else 
                {
                mariomove=0;
                if (marioright==true)
                al_draw_bitmap(mario5, (Mario.x), (Mario.y), 0);
                else al_draw_bitmap(mario5, (Mario.x), (Mario.y), ALLEGRO_FLIP_HORIZONTAL);
                }
            
            
            //Dibujo de enemigos MAPA 1
            
            draw_enemy (F1p, pMario, p_bitmaps_t);
            draw_enemy (F2p, pMario, p_bitmaps_t);
            draw_enemy (F3p, pMario, p_bitmaps_t);
            draw_enemy (F4p, pMario, p_bitmaps_t);
            draw_enemy (F5p, pMario, p_bitmaps_t);
            draw_enemy (F6p, pMario, p_bitmaps_t);
            draw_enemy (F7p, pMario, p_bitmaps_t);
            draw_enemy (F8p, pMario, p_bitmaps_t);
            draw_enemy (F9p, pMario, p_bitmaps_t);
            draw_enemy (F10p, pMario, p_bitmaps_t);
            draw_enemy (F11p, pMario, p_bitmaps_t);
            draw_enemy (F12p, pMario, p_bitmaps_t);
            
            
            draw_enemy (RF1p, pMario, p_bitmaps_t);
            draw_enemy (RF2p, pMario, p_bitmaps_t);
            draw_enemy (RF3p, pMario, p_bitmaps_t);
            draw_enemy (RF4p, pMario, p_bitmaps_t);
            draw_enemy (RF5p, pMario, p_bitmaps_t);
            draw_enemy (RF6p, pMario, p_bitmaps_t);
            draw_enemy (RF7p, pMario, p_bitmaps_t);
            draw_enemy (RF8p, pMario, p_bitmaps_t);
            draw_enemy (RF9p, pMario, p_bitmaps_t);
            
            draw_enemy (S1p, pMario, p_bitmaps_t);
            draw_enemy (S2p, pMario, p_bitmaps_t);
            draw_enemy (S3p, pMario, p_bitmaps_t);
            draw_enemy (S4p, pMario, p_bitmaps_t);
            draw_enemy (S5p, pMario, p_bitmaps_t);
            draw_enemy (S6p, pMario, p_bitmaps_t);
            draw_enemy (S7p, pMario, p_bitmaps_t);

            //Dibujo de enemigos MAPA 3 - BOSS
            
            draw_enemy (Bossp, pMario, p_bitmaps_t);
            
            draw_enemy (M1p, pMario, p_bitmaps_t);
            draw_enemy (M2p, pMario, p_bitmaps_t);
            draw_enemy (M3p, pMario, p_bitmaps_t);
            draw_enemy (M4p, pMario, p_bitmaps_t);
            draw_enemy (M5p, pMario, p_bitmaps_t);
            draw_enemy (M6p, pMario, p_bitmaps_t);
            
            
            //Dibujo de monedas MAPA 1
            draw_coin(pMario,pcoin1,p_bitmaps_t);
            draw_coin(pMario,pcoin2,p_bitmaps_t);
            draw_coin(pMario,pcoin3,p_bitmaps_t);
            draw_coin(pMario,pcoin4,p_bitmaps_t);
            draw_coin(pMario,pcoin5,p_bitmaps_t);
            draw_coin(pMario,pcoin6,p_bitmaps_t);
            draw_coin(pMario,pcoin7,p_bitmaps_t);
            draw_coin(pMario,pcoin8,p_bitmaps_t);
            draw_coin(pMario,pcoin9,p_bitmaps_t);
            draw_coin(pMario,pcoin10,p_bitmaps_t);
            draw_coin(pMario,pcoin11,p_bitmaps_t);
            draw_coin(pMario,pcoin12,p_bitmaps_t);
            draw_coin(pMario,pcoin13,p_bitmaps_t);
            draw_coin(pMario,pcoin14,p_bitmaps_t);
            draw_coin(pMario,pcoin15,p_bitmaps_t);
            draw_coin(pMario,pcoin16,p_bitmaps_t);
            draw_coin(pMario,pcoin17,p_bitmaps_t);
            draw_coin(pMario,pcoin18,p_bitmaps_t);
            draw_coin(pMario,pcoin19,p_bitmaps_t);
            draw_coin(pMario,pcoin20,p_bitmaps_t);
            draw_coin(pMario,pcoin21,p_bitmaps_t);
            draw_coin(pMario,pcoin22,p_bitmaps_t);
            draw_coin(pMario,pcoin23,p_bitmaps_t);
            draw_coin(pMario,pcoin24,p_bitmaps_t);
            draw_coin(pMario,pcoin25,p_bitmaps_t);
            
            draw_coin(pMario,pcoin26,p_bitmaps_t);
            draw_coin(pMario,pcoin27,p_bitmaps_t);
            draw_coin(pMario,pcoin28,p_bitmaps_t);
            draw_coin(pMario,pcoin29,p_bitmaps_t);
            draw_coin(pMario,pcoin30,p_bitmaps_t);
            draw_coin(pMario,pcoin31,p_bitmaps_t);
            draw_coin(pMario,pcoin32,p_bitmaps_t);
            draw_coin(pMario,pcoin33,p_bitmaps_t);
            draw_coin(pMario,pcoin34,p_bitmaps_t);
            draw_coin(pMario,pcoin35,p_bitmaps_t);
            
            
            
            if ((Mario.live)==0) //Si se acabaron las vidas aparece el cartel de game over
            {
             al_draw_scaled_bitmap(game_over,0,0,240,210,0,0,BUFFER_H,BUFFER_H,0);
            } 

            disp_post_draw(display, buffer,menupausa ,game_over, pMario, font,pausa); 
        }
        
        
        
    }

    al_destroy_bitmap(mario1);
    al_destroy_bitmap(mario2);
    al_destroy_bitmap(mario3);
    al_destroy_bitmap(mario4);
    al_destroy_bitmap(mario5);
    al_destroy_bitmap(fish1);
    al_destroy_bitmap(fish2);
    al_destroy_bitmap(redfish1);
    al_destroy_bitmap(redfish2);
    al_destroy_bitmap(squid1);
    al_destroy_bitmap(squid2);
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