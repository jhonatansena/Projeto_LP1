#include <iostream>
#include <cstdlib>
#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "game.h"
#include "node.h"

using namespace std;

Game::Game(){
	map = new Map(10,10);
	snake = new Snake;
	map->addFood();//Inicia com uma comida

	matrix = new int*[map->getAltura()];
	for(int i = 0; i < map->getAltura(); i++){
		matrix[i] = new int[map->getLargura()];
	}
}

void Game::atualiza(){
	int largura = map->getLargura();
	int altura = map->getAltura();//Redimensiona
	int pos_x=100;
    int pos_y=100;

	for(int i = 0; i < largura; i++){
		for(int j = 0; j < altura; j++){
			matrix[i][j] = 0; //preenche o mapa
		}
	}

	matrix[map->getCurrentFood().x][map->getCurrentFood().y] = 1;//Geração da nova comida | chama

	Node *temp = snake->GetHead();

	while(temp != NULL){
		matrix[temp->x][temp->y] = 2;

		temp = temp->next;
	}
}

void Game::draw(){

srand(time(NULL)*rand());
	int largura = map->getLargura();
	int altura = map->getAltura();
	int tam = 30;

	//system("cls");
	system("clear");


	for(int i = 0; i < largura; i++){
		for(int j = 0; j < altura; j++){

            //int pos_x = 5 + rand()%(largura-10);
            //int pos_y = 5 + rand()%(altura - 10);
            // ****** DEFINIÇÃO DAS CORES ******
	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR verde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);

			switch(matrix[i][j]){
				case 0:
					//cout << " . ";//Desenhar os pixels
//					 //  al_draw_filled_rectangle(pos_x, pos_y, pos_x+tam, pos_y+tam, al_map_rgb(255,255,255));
              //al_draw_pixel(pos_x, pos_y, al_map_rgb(255,255,255));
					break;
                case 1:
					//cout << " O ";//Desenhar a comida
            al_draw_filled_circle(snake->head->x, snake->head->y, 10, vermelho);

					break;
				case 2:
					//cout << " X ";//Denhar o corpo da cobra
    al_draw_filled_rectangle(snake->head->x, snake->head->y, snake->head->x+20, snake->head->y+20, azul);
					break;




			}
		}
		cout << endl;
	}
}

void Game::executar(int acao){
	switch(acao){
		case 0:
			snake->avancar();
			break;
		case 1:
			snake->moverUp();
			break;
		case 2:
			snake->moverRight();
			break;
		case 3:
			snake->moverDown();
			break;
		case 4:
			snake->moverLeft();
			break;
	}
}
