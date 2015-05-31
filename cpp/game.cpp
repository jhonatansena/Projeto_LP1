#include <iostream>
#include <cstdlib>

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
	int altura = map->getAltura();
	
	for(int i = 0; i < largura; i++){
		for(int j = 0; j < altura; j++){
			matrix[i][j] = 0;
		}
	}
	
	matrix[map->getCurrentFood().x][map->getCurrentFood().y] = 1;
	
	Node *temp = snake->GetHead();

	while(temp != NULL){
		matrix[temp->x][temp->Yy] = 2;
		temp = temp->next;
	}
}

void Game::draw(){
	int largura = map->getLargura();
	int altura = map->getAltura();
	
	system("cls");
	
	for(int i = 0; i < largura; i++){
		for(int j = 0; j < altura; j++){
			switch(matrix[i][j]){
				case 0:
					cout << " . ";
					break;
				case 1:
					cout << " O ";
					break;
				case 2:
					cout << " X ";
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