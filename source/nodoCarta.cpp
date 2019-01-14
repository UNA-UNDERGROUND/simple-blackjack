#include "nodoCarta.h"

nodoCarta::nodoCarta(carta *ref, nodoCarta* siguiente) {
	actual = new carta(*ref);
	this->siguiente = siguiente;
}

void nodoCarta::setActual(carta *ref) { 
	actual = ref; 
}
carta* nodoCarta::getActual() { 
	return actual; 
}
void nodoCarta::setSiguiente(nodoCarta* siguiente) { 
	this->siguiente = siguiente; 
}
nodoCarta* nodoCarta::getSiguiente() { 
	return siguiente; 
}


nodoCarta::~nodoCarta() {
	//es importante no borrar el siguiente puesto que aun puede ser usado
	if (actual != nullptr) {
		delete actual;
		actual = nullptr;
	}


}