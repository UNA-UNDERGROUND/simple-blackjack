#include <iostream>
#include <string>
#include <iostream>
#include "juego.h"
#include "jugador.h"
#include "dealer.h"
#include "mazo.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;



std::ostream &operator<<(std::ostream & o,jugadorGenerico& jugador) {

	o << "nickname: " << jugador.getNickname() << endl;
	o << (jugador.sePaso() ? "el jugador se paso" : "el jugador no se ha pasado") << endl;
	o << "puntos del jugador: " << jugador.getPuntuacion() << endl;
	o << "------------------------------------" << endl;

	if (jugador.getPuntuacion() < 0){
		o << "no hay cartas" << endl;
		o << "------------------------------------" << endl;
	}
	else {
		int numeroCartas = jugador.manoJugador->getCartas();
		int puntaje = 0;
		int ases = 0;
		for (int i = 0; i < numeroCartas; i++) {
			o << "carta #" << i + 1 << endl;
			carta c(jugador.manoJugador->getCarta(i));
			o << nombreCarta[c.getcodigo()] << " de " << nombrePalo[c.getPalo()] << endl;
			o << (c.revelada() ? "la carta esta revelada" : "la carta esta oculta") << endl;
			o << "------------------------------------" << endl;
		}
	}

	

	return o;
}


int main(int argc, char const *argv[]){


    setlocale(LC_ALL, "Spanish"); // localizacion al español para soportar tildes y caracteres españoles


	juego jueg;
	dealer *dealerEjemplo;
	jugador *jugadorEjemplo;
	mazo *mazoEjemplo;
	

	//mazoEjemplo.inicializar();
	//mazoEjemplo.barajar();
	jueg.jugar();
	

	/*for (int i = 0; i < 2; i++) {
		dealerEjemplo.pedirCarta(&mazoEjemplo);
		jugadorEjemplo.pedirCarta(&mazoEjemplo);
	}*/

	//dealerEjemplo.volteaSegunta();
	//cout << jugadorEjemplo << endl;
	//cout << dealerEjemplo << endl;



    cin.ignore();
    return 0;
}

