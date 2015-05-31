#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "game.h"



int main(){
	Game g;
	g.atualiza();
	g.draw();
	
	while(true){
		g.executar(0);
		g.atualiza();
		g.draw();
	}
	return 0;
}