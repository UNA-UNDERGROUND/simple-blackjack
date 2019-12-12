#pragma once
#include "jugadorGenerico.h"


// esta clase es exactamente igual a la de nodoCarta,la unica diferiencia es la clase que usa como actual(jugador especificamente),
// tambien este reclama la memoria del objeto actual, en vez de crear una copia

class nodoJugador {
private:
	jugadorGenerico *actual;
	nodoJugador * siguiente;
public:

	nodoJugador(jugadorGenerico *ref, nodoJugador* siguiente);
	void setActual(jugadorGenerico *ref);
	jugadorGenerico *getActual();
	void setSiguiente(nodoJugador* siguiente);
	nodoJugador* getSiguiente();
	~nodoJugador();

};