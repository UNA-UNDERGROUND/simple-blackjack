#include "jugador.h"



jugador::jugador(std::string nickname) {
	this->nickname = nickname;
}
jugador::jugador(jugador &ref) {
	nickname = ref.nickname;
}

string jugador::getNickname() {
	return nickname;
}


void jugador::pedirCarta(mazo *m) {
	manoJugador->agregarCarta(m);
	manoJugador->getCarta(manoJugador->getCartas() - 1).voltear(); // las cartas de los jugadores siempre se giran
}


jugador::~jugador() {
}




