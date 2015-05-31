#ifndef _NODE_H_
#define _NODE_H_

#include "orientation.h"

//Cada bloco do corpo da cobra (nomeado como Node para facilitar a referência ao que foi dado em aula)
class Node {
	int x, y;
	Orientation direction;
	Node *next;
};


#endif