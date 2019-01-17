#pragma once
#include "jugadorGenerico.h"


//esta clase es exactamente igual a la de nodoCarta,la unica diferiencia es la clase que usa como actual

class nodoJugador {
private:
	jugador *actual;
	nodoJugador * siguiente;
public:

	nodoJugador(jugador *ref, nodoJugador* siguiente);
	void setActual(jugador *ref);
	jugador *getActual();
	void setSiguiente(nodoJugador* siguiente);
	nodoJugador* getSiguiente();
	~nodoJugador();

};