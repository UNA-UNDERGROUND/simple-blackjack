#include "jugadorGenerico.h"



jugadorGenerico::jugadorGenerico() {
	manoJugador = new mano();
}
jugadorGenerico::jugadorGenerico(jugadorGenerico &ref) {
	manoJugador = new mano(*ref.manoJugador);
}



bool jugadorGenerico::sePaso() {
	return manoJugador->getPuntos() > 21;
}
int jugadorGenerico::getPuntuacion() {
	return manoJugador->getPuntos();
}
mano *jugadorGenerico::getMano() {
	return manoJugador; // esto nos permite girar las cartas entre otros,ademas poder acceder a los datos para cargarlos/guardarlos
}

jugadorGenerico::~jugadorGenerico() {

	if (manoJugador != nullptr){
		delete manoJugador;
		manoJugador = nullptr;
	}

}



