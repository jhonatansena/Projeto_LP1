#include <cstdlib>
#include <ctime>
#include <iostream>
#include "snake.h"

using namespace std;

Snake::Snake() : size(1) {
	//Inicia a cabeça e a cauda
	srand(time(NULL));
	head = new Node;
	head->next = NULL;
	head->x = rand() % 10; //TODO: Receber posição máxima da classe game
	head->y = rand() % 10; //TODO: Receber posição máxima da classe game
	head->direction = (Orientation)(rand() % 4);
		
	tail = head;
	
	//Comer 2 vezes para criar o corpo com total de 3 blocos
	comer();
	comer();
};

Node* Snake::GetHead(){
	return head;
}

void Snake::comer(){
	//Adicionar um novo bloco ao fim
	Node *food = new Node;
	food->next = NULL;
	food->direction = tail->direction;
	//TODO: Definir posição do novo bloco de acordo com a posição e direção da cauda
	switch(tail->direction){
		case Up:
			food->x = tail->x;
			food->y = (tail->y + 1) % 10;
		break;
		case Right:
			food->y = tail->y;
			food->x = (tail->x + 1) % 10;
		break;
		case Down:
			food->x = tail->x;
			food->y = (tail->y - 1) % 10;
		break;
		case Left:
			food->y = tail->y;
			food->x = (tail->x - 1) % 10;
		break;
	}
	
	tail->next = food;
	tail = food;
	
	size++;
};

void Snake::moverUp(){
	head->direction = Up;
	cout << "Moveu para cima" << endl;
};

void Snake::moverRight(){
	head->direction = Right;
	scout << "Moveu para a direita" << endl;
};

void Snake::moverDown(){
	head->direction = Down;
	std::cout << "Moveu para baixo" << std::endl;
};

void Snake::moverLeft(){
	head->direction = Left;
	std::cout << "Moveu para a esquerda" << std::endl;
};

void Snake::avancar(){
	Node *temp = head;
	while(temp != NULL){
		switch(temp->Direction){
			case Up:
				temp->y--;
				if(temp->y < 0) 
					temp->y = 9;
			break;
			case Right:
				temp->x++;
				if(temp->x > 9) 
					temp->x = 0;
			break;
			case Down:
				temp->y++;
				if(temp->y > 9) 
					temp->y = 0;
			break;
			case Left:
				temp->x--;
				if(temp->x <0) 
					temp->x = 9;
			break;
		}
		if(temp != tail)
			temp->next->direction = temp->direction;
		temp = temp->next;
	}
	system("pause");
};

void Snake::imprime(){
	cout << "Tamanho: " << size << " -> ";
	Node *temp = head;
	while(temp != NULL){
		cout << "[" << temp->x << "," << temp->y << "(" << temp->direction << ")] ";
		temp = temp->next;
	}
};