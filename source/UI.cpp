#include <iostream>
#include <string>


#include "juego.h"













int main(int argc, char const *argv[]) {




	gestorGraficos g;

	carta cartas[] = { carta(1, 1), carta(1, 2), carta(1, 3), carta(1, 4), carta(11, 1), carta(13, 3) };


	mano manoJugador; 

	for (int i = 0; i < 6; i++) {
		cartas[i].voltear();
	}

	for (int i = 0; i <6; i++) {
		manoJugador.agregarCarta(cartas[i]);
	}


	g.mostrarMesa();
	g.mostrarMano(manoJugador);
	_getch();

	int eleccion = 0;
	do {
		eleccion = g.menuPrincipal();

		switch (eleccion) {
		
		//nueva partida
		case 0:{

			break;
		}

		default:
			
			break;
		}

	} while (eleccion != 3);



	return 0;
}

