#pragma once

#include "carta.h"

class nodoCarta {
private:
	carta *actual;
	nodoCarta * siguiente;
public:

	nodoCarta(carta *ref, nodoCarta* siguiente);
	void setActual(carta *ref);
	carta *getActual();
	void setSiguiente(nodoCarta* siguiente);
	nodoCarta* getSiguiente();
	~nodoCarta();

};