#include "nodoJugador.h"



// el nodo jugador toma la memoria directamente, pero tambien la elimina como lo hace nodoCarta, 
// por lo que se debe considerar cualquier objeto concedido a un nodo o una lista
// reclamado por este y no eliminarlo manualmente ya que puede crear un comportamiento indefinido y detener abruptamente el programa
nodoJugador::nodoJugador(jugadorGenerico *ref, nodoJugador* siguiente) {
	actual = ref;							//las clases abtractas no se pueden copiar
	this->siguiente = siguiente;
}

void nodoJugador::setActual(jugadorGenerico *ref) {
	actual = ref;
}
jugadorGenerico* nodoJugador::getActual() {
	return actual;
}
void nodoJugador::setSiguiente(nodoJugador* siguiente) {
	this->siguiente = siguiente;
}
nodoJugador* nodoJugador::getSiguiente() {
	return siguiente;
}


nodoJugador::~nodoJugador() {
	if (actual != nullptr) {
		delete actual;
		actual = nullptr;
	}


}










