

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

#define BORDER 4

void disp_pre_draw(ALLEGRO_BITMAP* buffer);

void disp_post_draw(ALLEGRO_DISPLAY* disp,ALLEGRO_BITMAP* buffer,float x,float y);

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento);

bool collidewborder(int ax1, int ay1, int ax2, int ay2,const char mapa [BUFFER_H][BUFFER_W]);

enum MYKEYS 
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT //arrow keys
};

char mapa2[BUFFER_H][BUFFER_W]={0};




int main(void) 
{
    //INICIALIZACION 
    // init_display();
    // init_buffer();
    //
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *buffer = NULL;
    ALLEGRO_BITMAP *Mario = NULL;
    ALLEGRO_BITMAP *background = NULL;

    float Mario_x = 0;//SCREEN_W / 2.0 - MARIO_SIZE / 2.0;
    float Mario_y =0;// SCREEN_H / 2.0 - MARIO_SIZE / 2.0;

    bool key_pressed[4] = {false, false, false, false}; //Estado de teclas, true cuando esta apretada
    bool redraw = false;
    bool do_exit = false;
    float saltito=0;
    float saltito2=0;

   //Zona de creacion de barrera
   putbarrier (0 , 200, 3101, 223, mapa2, 4);
   putbarrier (175, 152, 190, 199, mapa2, 4);
   putbarrier (288, 136, 335, 151, mapa2, 4);
   putbarrier (544, 120, 559, 199, mapa2, 4);
   putbarrier (688, 104, 703, 135, mapa2, 4);
   putbarrier (688, 136, 719, 151, mapa2, 4);
   putbarrier (816, 136, 831, 199, mapa2, 4);
   putbarrier (1040, 152, 1055, 199, mapa2, 4);
   putbarrier (1056, 120, 1071, 199, mapa2, 4);
   putbarrier (1152, 120, 1167, 199, mapa2, 4);
   putbarrier (1168, 152, 1183, 199, mapa2, 4);
   putbarrier (1264, 152, 1295, 199, mapa2, 4);
   putbarrier (1264, 24, 1295, 71, mapa2, 4);
   putbarrier (1328, 72, 1375, 87, mapa2, 4);
   putbarrier (1344, 40, 1359, 71, mapa2, 4);
   putbarrier (1440, 152, 1455, 199, mapa2, 4);
   putbarrier (1648, 72, 1663, 135, mapa2, 4);
   putbarrier (1648, 136, 1679, 151, mapa2, 4);
   putbarrier (1855, 120, 1886, 135, mapa2, 4);
   putbarrier (1935, 136, 1950, 199, mapa2, 4);
   putbarrier (2079, 136, 2094, 199, mapa2, 4);
   putbarrier (2095, 168, 2110, 199, mapa2, 4);
   
   putbarrier (2111, 24, 2126, 55, mapa2, 4);
   putbarrier (2111, 56, 2254, 71, mapa2, 4);
   putbarrier (2255, 168, 2286, 199, mapa2, 4);
   putbarrier (2271, 136, 2286, 168, mapa2, 4);
   putbarrier (2364, 186, 2382, 199, mapa2, 4);
   putbarrier (2399, 152, 2414, 199, mapa2, 4);
   putbarrier (2511, 72, 2525, 199, mapa2, 4);
   putbarrier (2527, 72, 2558, 87, mapa2, 4);
   putbarrier (2607, 72, 2654, 87, mapa2, 4);
   putbarrier (2639, 88, 2654, 199, mapa2, 4);
   putbarrier (2767, 72, 2845, 87, mapa2, 4);
   putbarrier (2783, 40, 2798, 71, mapa2, 4);
   putbarrier (2894, 72, 2956, 87, mapa2, 4);
   putbarrier (2767, 136, 2845, 151, mapa2, 4);
   putbarrier (2894, 136, 2956, 151, mapa2, 4);
   
   putbarrier (3022, 24, 3101, 87, mapa2, 4);
   putbarrier (3054, 88, 3101, 223, mapa2, 4);
   putbarrier (3022, 136, 3070, 223, mapa2, 4);
   putbarrier (3006, 152, 3037, 199, mapa2, 4);
   putbarrier (2990, 168, 3021, 199, mapa2, 4);
   putbarrier (2974, 184, 2989, 199, mapa2, 4);
   
    
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
        al_destroy_bitmap(Mario);
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
    
    Mario = al_load_bitmap("Mario.png");//al_create_bitmap(MARIO_SIZE, MARIO_SIZE);
    if (!Mario) {
        fprintf(stderr, "failed to create Mario bitmap!\n");
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
   
    event_queue = al_create_event_queue();
    if (!event_queue) 
    {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_bitmap(Mario);
        al_destroy_timer(timer);
        return -1;
    }


    
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
                
                if (key_pressed[KEY_UP] && Mario_y >= MOVE_RATE && collidewborder(Mario_x, Mario_y-MOVE_RATE, Mario_x+MARIO_SIZE , Mario_y-MOVE_RATE+MARIO_SIZE, mapa2) )
                    {
                    if (saltito2==0 )
                        {
                        saltito2= 60;
                        saltito = 8;
                        }                    
                    }
                else if(key_pressed[KEY_UP] && Mario_y >= MOVE_RATE && collidewborder(Mario_x, Mario_y-1, Mario_x+MARIO_SIZE , Mario_y-1+MARIO_SIZE, mapa2))
                    Mario_y -= 1;
                else if (Mario_y <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder(Mario_x, Mario_y+MOVE_RATE, Mario_x+MARIO_SIZE , Mario_y+MOVE_RATE+MARIO_SIZE, mapa2))
                    Mario_y += MOVE_RATE/3;
                
                if (key_pressed[KEY_DOWN] && Mario_y <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder(Mario_x, Mario_y+MOVE_RATE, Mario_x+MARIO_SIZE , Mario_y+MOVE_RATE+MARIO_SIZE, mapa2))
                    Mario_y += MOVE_RATE;
                else if(key_pressed[KEY_DOWN] && Mario_y <= SCREEN_H - MARIO_SIZE - MOVE_RATE && collidewborder(Mario_x, Mario_y+1, Mario_x+MARIO_SIZE , Mario_y+1+MARIO_SIZE, mapa2))
                    Mario_y += 1;

                if (key_pressed[KEY_LEFT] && Mario_x >= MOVE_RATE && collidewborder(Mario_x-MOVE_RATE, Mario_y, Mario_x+MARIO_SIZE-MOVE_RATE , Mario_y+MARIO_SIZE, mapa2))
                    Mario_x -= MOVE_RATE;
                else if (key_pressed[KEY_LEFT] && Mario_x >= MOVE_RATE && collidewborder(Mario_x-1, Mario_y, Mario_x+MARIO_SIZE-1 , Mario_y+MARIO_SIZE, mapa2))
                    Mario_x -= 1;
                    
                if (key_pressed[KEY_RIGHT]&& collidewborder(Mario_x+MOVE_RATE, Mario_y, Mario_x+MARIO_SIZE+MOVE_RATE , Mario_y+MARIO_SIZE, mapa2))
                    Mario_x += MOVE_RATE;
                else if (key_pressed[KEY_RIGHT]&& collidewborder(Mario_x+1, Mario_y, Mario_x+MARIO_SIZE+1 , Mario_y+MARIO_SIZE, mapa2))
                    Mario_x += 1;
                
                if(saltito2>0)
                    saltito2--;
                
                if (Mario_y >= MOVE_RATE && collidewborder(Mario_x, Mario_y-MOVE_RATE, Mario_x+MARIO_SIZE , Mario_y-MOVE_RATE+MARIO_SIZE, mapa2) && (saltito>0) )
                   {
                    saltito-=1;
                    Mario_y -= MOVE_RATE;
                   }
                
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

                    case ALLEGRO_KEY_ESCAPE:
                        do_exit = true;
                        break;
                }
            }
        }

        
        
        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            disp_pre_draw(buffer);
            
            al_draw_bitmap(background,0,0,0);
            

            
            al_draw_bitmap(Mario, Mario_x, Mario_y, 0);

            
            disp_post_draw(display, buffer, Mario_x, Mario_y);

            
        }
    }

    al_destroy_bitmap(Mario);
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

void putbarrier (int ax, int ay, int bx, int by, char mapa[BUFFER_H][BUFFER_W] , char elemento)
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


bool collidewborder(int ax1, int ay1, int ax2, int ay2, const char mapa [BUFFER_H][BUFFER_W])
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
        }
    }

    return true;
}