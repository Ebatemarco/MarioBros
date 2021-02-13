
#ifdef ALLEGRO
#include "dibujo allegro.h"
#endif /*ALLEGRO*/
#include "enemigos y monedas.h"
#include "mapas.h"


#ifdef RPI
#include "raspberry.h"
#endif

extern char mapa[BUFFER_H][BUFFER_W]; 
extern char mapainicio[BUFFER_H][BUFFER_W]; 

int main(void) 
{
    //INICIALIZACION 
#ifdef RPI
    //Inicializacion Display RPi
    joy_init();		//inicializa el joystick
    disp_init();        //inicializa el display
    disp_clear();	//limpia todo el display
    
    jcoord_t coord = {0,0};
    
#endif    
    
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
    enemy F13;
    enemy * F13p = &F13;
    enemy F14;
    enemy * F14p = &F14;
    enemy F15;
    enemy * F15p = &F15;
    enemy F16;
    enemy * F16p = &F16;
    enemy F17;
    enemy * F17p = &F17;
    enemy F18;
    enemy * F18p = &F18;
    enemy F19;
    enemy * F19p = &F19;
    enemy F20;
    enemy * F20p = &F20;
    enemy F21;
    enemy * F21p = &F21;
    enemy F22;
    enemy * F22p = &F22;
    enemy F23;
    enemy * F23p = &F23;
    enemy F24;
    enemy * F24p = &F24;
    enemy F25;
    enemy * F25p = &F25;
    enemy F26;
    enemy * F26p = &F26;
    enemy F27;
    enemy * F27p = &F27;
    
    
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
    enemy RF10;
    enemy * RF10p = &RF10;
    enemy RF11;
    enemy * RF11p = &RF11;
    enemy RF12;
    enemy * RF12p = &RF12;
    enemy RF13;
    enemy * RF13p = &RF13;
    
    
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
    enemy S8;
    enemy * S8p = &S8;
    enemy S9;
    enemy * S9p = &S9;
    enemy S10;
    enemy * S10p = &S10;
    enemy S11;
    enemy * S11p = &S11;
    enemy S12;
    enemy * S12p = &S12;
    enemy S13;
    enemy * S13p = &S13;
    enemy S14;
    enemy * S14p = &S14;
    
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
    
   #ifdef ALLEGRO
    
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
    
    background = al_load_bitmap("mapa-inicio.png");

    

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    
   
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
    
    #endif /*ALLEGRO*/
//putbarrier (0, 14, 30, 15, mapainicio, BORDER);
    barriers();/*
    Mario.x=XPANTALLA;
    Mario.y=YPANTALLA;
    printmario(pMario);
    disp_update();	//Actualiza el display con el contenido del buffer
*/
#ifdef RPI
    unsigned int times=TIEMPO;

#endif   

    while (!do_exit) 
    {    
#ifdef ALLEGRO
        ALLEGRO_EVENT ev;
        if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if (ev.type == ALLEGRO_EVENT_TIMER) {
#endif /*ALLEGRO*/

    #ifdef RPI
             if(usleep(times))
                 printf("ERROR KPO");  
    #endif /* RPI*/ 

            if (restart==true)
            {
                //Estado inicial de Mario
                Mario.live=MARIO_LIVES;
                Mario.death=false;
                Mario.x=XPANTALLA;
                Mario.y=YPANTALLA;
                Mario.n_mapa_actual=MAPAINICIO;
                Mario.salto=0;
                Mario.salto_cooldown=0;
                Mario.salto_lock=false;
                Mario.coins=0;
                Mario.coin_obt=false;
                Mario.timer=LEVEL_TIME;
                Mario.score=0;
                Mario.exit_pass=false;

#ifdef ALLEGRO                
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

#endif /*ALLEGRO */ 
                
                //Carga del primer mapa
                
                clonarMatriz(mapainicio,mapa); //clonarMatriz(mapainicio,mapa);
               
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
                   
#ifdef ALLEGRO                    
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
                    
                    //MAPA 2
                    
                    enemy_start(F13p,false,FISH,MAPA2,293,98,false,0);
                    enemy_start(F14p,false,FISH,MAPA2,371,182,false,0);
                    enemy_start(F15p,false,FISH,MAPA2,484,73,false,0);
                    enemy_start(F16p,false,FISH,MAPA2,528,142,false,0);
                    enemy_start(F17p,false,FISH,MAPA2,696,144,false,0);
                    enemy_start(F18p,false,FISH,MAPA2,751,98,false,0);
                    enemy_start(F19p,false,FISH,MAPA2,808,180,false,0);
                    enemy_start(F20p,false,FISH,MAPA2,963,99,false,0);
                    enemy_start(F21p,false,FISH,MAPA2,1083,97,false,0);
                    enemy_start(F22p,false,FISH,MAPA2,1173,178,false,0);
                    enemy_start(F23p,false,FISH,MAPA2,1230,74,false,0);
                    enemy_start(F24p,false,FISH,MAPA2,1389,141,false,0);
                    enemy_start(F25p,false,FISH,MAPA2,1511,98,false,0);
                    enemy_start(F26p,false,FISH,MAPA2,1590,165,false,0);
                    enemy_start(F27p,false,FISH,MAPA2,1760,102,false,0);
                    
                    enemy_start(RF10p,false,REDFISH,MAPA2,1147,49,false,0);
                    enemy_start(RF11p,false,REDFISH,MAPA2,1337,148,false,0);
                    enemy_start(RF12p,false,REDFISH,MAPA2,1633,53,false,0);
                    enemy_start(RF13p,false,REDFISH,MAPA2,2061,76,false,0);
                    
                    enemy_start(S8p,false,SQUID,MAPA2,892,148,false,0);
                    enemy_start(S9p,false,SQUID,MAPA2,1193,138,false,0);
                    enemy_start(S10p,false,SQUID,MAPA2,1340,104,false,0);
                    enemy_start(S11p,false,SQUID,MAPA2,1530,179,false,0);
                    enemy_start(S12p,false,SQUID,MAPA2,1168,107,false,0);
                    enemy_start(S13p,false,SQUID,MAPA2,1872,139,false,0);
                    enemy_start(S14p,false,SQUID,MAPA2,2070,185,false,0);

                    //MAPA 3 - BOSS
                    
                    enemy_start(Bossp,false,BOSS,MAPA3,300,103,false,60*33);
                    
                    enemy_start(M1p,false,MISIL1,MAPA3,277,114,false,60*4);
                    enemy_start(M2p,false,MISIL2,MAPA3,277,114,false,60*6);
                    enemy_start(M3p,false,MISIL3,MAPA3,277,117,true,60*8);
                    enemy_start(M4p,false,MISIL4,MAPA3,260,157,false,60*10);
                    enemy_start(M5p,false,MISIL5,MAPA3,260,157,false,60*12);
                    enemy_start(M6p,false,MISIL6,MAPA3,277,114,false,60*14);
#endif /* ALLEGRO */                    
                    restart=false;
                }
            
  /*          mariosteady=true;//mintras que mario no se mueva esta variable permanecerá true
            
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
                
                //Movimiento de enemigos MAPA 2
                
                enemy_mov(F12p, pMario);
                enemy_mov(F13p, pMario);
                enemy_mov(F14p, pMario);
                enemy_mov(F15p, pMario);
                enemy_mov(F16p, pMario);
                enemy_mov(F17p, pMario);
                enemy_mov(F18p, pMario);
                enemy_mov(F19p, pMario);
                enemy_mov(F20p, pMario);
                enemy_mov(F21p, pMario);
                enemy_mov(F22p, pMario);
                enemy_mov(F23p, pMario);
                enemy_mov(F24p, pMario);
                enemy_mov(F25p, pMario);
                enemy_mov(F26p, pMario);
                enemy_mov(F27p, pMario);
                
                enemy_mov(RF10p, pMario);
                enemy_mov(RF11p, pMario);
                enemy_mov(RF12p, pMario);
                enemy_mov(RF13p, pMario);
                
                enemy_mov(S8p, pMario);
                enemy_mov(S9p, pMario);
                enemy_mov(S10p, pMario);
                enemy_mov(S11p, pMario);
                enemy_mov(S12p, pMario);
                enemy_mov(S13p, pMario);
                enemy_mov(S14p, pMario);
                
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
                
*/
                //Teclas de movimiento
#ifdef RPI

            if ( (coord.y > MINY && coord.y <= MAXY) && (Mario.y) >= MOVE_RATE && collidewborder(pMario ,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa ))
                    {
                    mariomove++;
                    mariosteady=false;
                    if ((Mario.salto_cooldown)==0 && (Mario.salto_lock)==false)
                        {
                        (Mario.salto_cooldown)= SALTO_COOLDOWN;
                        (Mario.salto) = SALTO_H;
                        (Mario.salto_lock)=true;
                        }                    
                    }
                    
                    if (!(coord.y > MINY && coord.y <= MAXY))
                        (Mario.salto_lock)=false;
                 
                        
                if ((coord.y > -MINY && coord.y <= -MAXY) && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa))
                    {
                    (Mario.y) += MOVE_RATE;
                    mariomove++;
                    mariosteady=false;
                    }

                if ((coord.x < -MINX && coord.x >= -MAXX) && collidewborder(pMario,(Mario.x)-MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE-MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa))
                    {
                    (Mario.x) -= MOVE_RATE;
                    mariomove++;
                    marioright=false;
                    mariosteady=false;
                    }

                if ((coord.x > MINX && coord.x <= MAXX) && collidewborder(pMario,(Mario.x)+MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE+MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa))
                    {
                    (Mario.x) += MOVE_RATE;
                    mariomove++;
                    marioright=true;
                    mariosteady=false;
                    }

                
                //Salto de Mario
                
                if ((Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE  && collidewborder(pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa)) //Mario cae siempre que no detecte nada abajo de él
                    {
                    (Mario.y) += MOVE_RATE/3; 
                    mariomove++;
                    }
                
                if((Mario.salto_cooldown)>0 ) //Se disminuye la variable (Mario.salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
                    (Mario.salto_cooldown)--;
                
                if ((Mario.y) >= MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa) && (Mario.salto>0) ) //Mario salta lo determinado por la variable saltito
                   {
                    (Mario.salto)-=1;
                    (Mario.y) -= MOVE_RATE*SALTO_SPEED;
                   }
                
                
                printmatrp (mapa,pMario);
                printmario(pMario);
                disp_update();	//Actualiza el display con el contenido del buffer
		joy_update();	//Mide las coordenadas del joystick
                coord = joy_get_coord();//Guarda las coordenadas medidas
                //}
            }
                
                
#endif                 
                
                
#ifdef ALLEGRO      
                
 
                if (key_pressed[KEY_UP] && (Mario.y) >= MOVE_RATE && collidewborder(pMario ,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa ))
                    {
                    mariomove++;
                    mariosteady=false;
                    if ((Mario.salto_cooldown)==0 && (Mario.salto_lock)==false)
                        {
                        (Mario.salto_cooldown)= SALTO_COOLDOWN;
                        (Mario.salto) = SALTO_H;
                        (Mario.salto_lock)=true;
                        }                    
                    }
                    
                    if (!key_pressed[KEY_UP])
                        (Mario.salto_lock)=false;
                 
                        
                if (key_pressed[KEY_DOWN]  && (Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa))
                    {
                    (Mario.y) += MOVE_RATE;
                    mariomove++;
                    mariosteady=false;
                    }

                if (key_pressed[KEY_LEFT] && (Mario.x) >= MOVE_RATE && collidewborder(pMario,(Mario.x)-MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE-MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa))
                    {
                    (Mario.x) -= MOVE_RATE;
                    mariomove++;
                    marioright=false;
                    mariosteady=false;
                    }

                if (key_pressed[KEY_RIGHT] && collidewborder(pMario,(Mario.x)+MOVE_RATE, (Mario.y), (Mario.x)+MARIO_SIZE+MOVE_RATE , (Mario.y)+MARIO_SIZE, mapa))
                    {
                    (Mario.x) += MOVE_RATE;
                    mariomove++;
                    marioright=true;
                    mariosteady=false;
                    }

                
                //Salto de Mario
                
                if ((Mario.y) <= SCREEN_H - MARIO_SIZE - MOVE_RATE  && collidewborder(pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa)) //Mario cae siempre que no detecte nada abajo de él
                    {
                    (Mario.y) += MOVE_RATE/3; 
                    mariomove++;
                    }
                
                if((Mario.salto_cooldown)>0 ) //Se disminuye la variable (Mario.salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
                    (Mario.salto_cooldown)--;
                
                if ((Mario.y) >= MOVE_RATE && collidewborder(pMario,(Mario.x), (Mario.y)-MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)-MOVE_RATE+MARIO_SIZE, mapa) && (Mario.salto>0) ) //Mario salta lo determinado por la variable saltito
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
            disp_pre_draw(buffer,pMario,p_background);
            
            //Dibujo del mapa
            al_draw_bitmap(background,0,0,0);

            if ((Mario.live)==0)//Si se acabaron las vidas Mario se bloquea en una posicion y se pausa el juego
            {
             Mario.x= BUFFER_H/2; 
             pausa=true;
            }
            
            //Dibujo de Mario
            
            if ((!collidewborder( pMario,(Mario.x), (Mario.y)+MOVE_RATE, (Mario.x)+MARIO_SIZE , (Mario.y)+MOVE_RATE+MARIO_SIZE, mapa))&& mariosteady==true)//Deteccion de si Mario está estático en el suelo
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
            
            //Dibujo de enemigos MAPA 2
            draw_enemy (F13p, pMario, p_bitmaps_t);
            draw_enemy (F14p, pMario, p_bitmaps_t);
            draw_enemy (F15p, pMario, p_bitmaps_t);
            draw_enemy (F16p, pMario, p_bitmaps_t);
            draw_enemy (F17p, pMario, p_bitmaps_t);
            draw_enemy (F18p, pMario, p_bitmaps_t);
            draw_enemy (F19p, pMario, p_bitmaps_t);
            draw_enemy (F20p, pMario, p_bitmaps_t);
            draw_enemy (F21p, pMario, p_bitmaps_t);
            draw_enemy (F22p, pMario, p_bitmaps_t);
            draw_enemy (F23p, pMario, p_bitmaps_t);
            draw_enemy (F24p, pMario, p_bitmaps_t);
            draw_enemy (F25p, pMario, p_bitmaps_t);
            draw_enemy (F26p, pMario, p_bitmaps_t);
            draw_enemy (F27p, pMario, p_bitmaps_t);
            
            draw_enemy (RF10p, pMario, p_bitmaps_t);
            draw_enemy (RF11p, pMario, p_bitmaps_t);
            draw_enemy (RF12p, pMario, p_bitmaps_t);
            draw_enemy (RF13p, pMario, p_bitmaps_t);
            
            draw_enemy (S8p, pMario, p_bitmaps_t);
            draw_enemy (S9p, pMario, p_bitmaps_t);
            draw_enemy (S10p, pMario, p_bitmaps_t);
            draw_enemy (S11p, pMario, p_bitmaps_t);
            draw_enemy (S12p, pMario, p_bitmaps_t);
            draw_enemy (S13p, pMario, p_bitmaps_t);
            draw_enemy (S14p, pMario, p_bitmaps_t);
            

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
    
    al_destroy_display(display);
    

    al_destroy_timer(timer);
    
    #endif   /*ALLEGRO*/ 
    //#endif 
    return 0;
}

