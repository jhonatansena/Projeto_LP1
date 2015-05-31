#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "snake.h"

//Classe que encapsula os elementos do jogo
class Game{
	private:
		int **matrix;
		Map *map;
		Snake *snake;		
	public:
		Game();
		void atualiza(); 
		void draw();
		void executar(int acao);
};

#endif