#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_image.h>


#include "game.h"
#include "orientation.h"
#include "map.h"

bool Colisao (float x, float y, float ex, float ey, int larg, int alt){
        if(x + larg<ex || x> ex +larg || y+alt<ey || y>ey + alt){
            return false;
        }else{
            return true;

        }


}

int main(){
   ALLEGRO_DISPLAY *display;

	const float FPS = 60.0;
	//const float frameFPS = 15.0;
	const int largura = 800;
	const int altura = 600;
     Game *g = new Game();


	enum Direction { UP, DOWN, RIGHT, LEFT };

	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Não pode iniciar o Allegro", NULL, 0);

		return -1;
	}

	// Setando tipo de janela a ser criada
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	//al_set_new_display_flags(ALLEGRO_OPENGL);
	//al_set_new_display_flags(ALLEGRO_OPENGL);
	al_set_new_display_flags(ALLEGRO_WINDOWED);

	display = al_create_display(largura, altura);

	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();



	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_BITMAP *player = NULL;
	al_set_window_position(display,200,100);


	if (!display) {
		al_show_native_message_box(display, "Olá", "Opções do display", "Mensage,", NULL, 0);
	}


	// Mostra na tela o que está no buffer do display
	al_flip_display();

	// ***** RECEBENDO EVENTOS *****


	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	// registrando o teclado na fila de eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	// timer event
	ALLEGRO_TIMER *timer = al_create_timer( 1.0 / FPS );
	//ALLEGRO_TIMER *frametimer = al_create_timer( 1.0 / frameFPS );
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//al_register_event_source(event_queue, al_get_timer_event_source(frametimer));


	// Game loop
	bool finalizar = false;
	bool draw = false;
	bool comer = false;
	int x = 10, y = 10;
	float velocidade = 3;
	Direction direcao = DOWN;

	srand(time(NULL)*rand());

	x = rand() % largura;
	y = rand() % altura;

    int comida_x = rand() % largura;
    int comida_y = rand() % altura;
    int cont=0;




	al_start_timer(timer);
	//al_start_timer(frametimer);

	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);

	while (!finalizar) {


		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);


		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {
				case ALLEGRO_KEY_DOWN:
					direcao = DOWN;
					break;
				case ALLEGRO_KEY_UP:
					direcao = UP;
					break;
				case ALLEGRO_KEY_RIGHT:
					direcao = RIGHT;
					break;
				case ALLEGRO_KEY_LEFT:
					direcao = LEFT;
					break;
				case ALLEGRO_KEY_ESCAPE:
					finalizar = true;
					break;


			}
		}

		if (events.type == ALLEGRO_EVENT_TIMER) {
			switch (direcao) {
				case DOWN:
					y += velocidade;
					if(y>altura-20){
                        y =altura-20;
                        finalizar = true;
                    }

					break;
				case UP:
					y -= velocidade;
					if(y<0){
                        y=0;
                    finalizar = true;
                    }
					break;
				case RIGHT:
					x += velocidade;
					if(x > largura-20){
                        x=largura-20;
                        finalizar = true;
                    }
					break;
				case LEFT:
					x -= velocidade;
					if(x<0){
                        x=0;
                    finalizar = true;
                    }
					break;
			}

			draw = true;

		}if(Colisao(comida_x, comida_y, x, y, 20, 20)){
                    cont++;
                    if(direcao == DOWN)
                        comer = true;
                        //y -= velocidade;
                    else if(direcao == LEFT)
                        //x += velocidade;
                        comer = true;
                    else if(direcao == RIGHT)
                        //x -= velocidade;
                        comer = true;
                    else if(direcao ==UP)
                        //y +=velocidade;
                        comer = true;

                 }

		if (draw) {
            draw = false;
			// desenha retanguo 20x20 na posicao x,y nova
			//g->draw();



			if(comer){
			comer = false;
			al_draw_filled_rectangle(x, y, x+20, y+20, azul);
			al_draw_filled_circle(comida_x,comida_y, 5, vermelho);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));

            comida_x = rand() % largura;
            comida_y = rand() % altura;
			al_draw_filled_circle(comida_x,comida_y, 5, vermelho);
            al_clear_to_color(al_map_rgb(0,0,0));
            if(cont>=3){
                velocidade++;
                cont=0;
            }
			//al_flip_display();
			//al_clear_to_color(al_map_rgb(0,0,0));

            }else{
            al_draw_filled_circle(comida_x,comida_y, 5, vermelho);
            al_draw_filled_rectangle(x, y, x+20, y+20, azul);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
            }// Mostra na tela o que está no buffer do display

			// preenche o buffer com preto
			al_clear_to_color(al_map_rgb(0,0,0));
		}

	}


	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	return  0;
}
