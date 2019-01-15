#include "jugadorGenerico.h"



jugadorGenerico::jugadorGenerico(string nickname) {
	this->nickname = nickname;
	manoJugador = new mano();
}
jugadorGenerico::jugadorGenerico(jugadorGenerico &ref) {
	this->nickname = ref.nickname;
	manoJugador = new mano(*ref.manoJugador);
}

void jugadorGenerico::pedirCarta(mazo *m) {
	manoJugador->agregarCarta(m);
}
string jugadorGenerico::getNickname() {
	return nickname;
}
bool jugadorGenerico::sePaso() {
	return manoJugador->getPuntos() > 21;
}
int jugadorGenerico::getPuntuacion() {
	return manoJugador->getPuntos();
}
mano *jugadorGenerico::getMano() {
	return manoJugador; // esto nos permite girar las cartas entre otros
}

jugadorGenerico::~jugadorGenerico() {

	if (manoJugador != nullptr){
		delete manoJugador;
		manoJugador = nullptr;
	}

}



