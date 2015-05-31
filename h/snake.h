#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "node.h"

//Classe que representa a cobra (lista encadeada)
class Snake {
	private:
		Node *head, *tail;
		int size;
	public:
		Snake(); //Construtor padrão (inicia a cobra com 3 blocos)
		Node* GetHead();
		void comer(); //Come um novo bloco
		void moverUp(); //Move a cobra para cima
		void moverRight(); //Move a cobra para a direita
		void moverDown(); //Move a cobra para baixo
		void moverLeft(); //Move a cobra para a esquerda
		void avancar(); //Anda na direção atual (avança um passo)
		void imprime(); //Imprime o corpo da cobra (para testes)	
};

#endif