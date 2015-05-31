#ifndef _MAP_H_
#define _MAP_H_

#include "food.h"

//Classe que representa o mapa (matriz de pontos)
class Map {
	private:
		int largura, altura	;
		int **matrix;
		Food *currentFood; //Comida atual
	public:
		Map(int _lar, int _alt);
		int getLargura();
		int getAltura();
		Food getCurrentFood();
		void addFood(); //Adiciona uma comida em posição aleatória
		void imprime(); //Imprime o mapa no console (para testes)
};

#endif