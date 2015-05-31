#include <cstdlib>
#include <ctime>
#include <iostream>
#include "map.h"

using namespace std;

Map::Map(int _lar, int _alt) : largura(_lar), altura(_alt)
{
	currentFood = new Food;
	matrix = new int*[_alt];
	for(int i = 0; i < largura; i++){
		matrix[i] = new int[_lar];
	}	
}

int Map::getLargura(){
	return largura;
}

int Map::getAltura(){
	return altura;
}

Food Map::getCurrentFood(){
	return *currentFood;
}

void Map::addFood() {
	srand(time(NULL)*rand());
	
	currentFood->x = rand() % largura;
	currentFood->y = rand() % altura; 
}

void Map::imprime(){
	system("CLS");
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < largura; j++){
			if(currentFood->x == i && currentFood->y == j)
				cout << " O ";
			else
				cout << " . ";
		}
		cout << endl;
	}
}