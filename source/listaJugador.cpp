#include "listaJugador.h"


listaJugador::listaJugador() {
	inicio = nullptr;

}
listaJugador::listaJugador(listaJugador &ref) {
	inicio = nullptr;
	nodoJugador* actualRef = ref.inicio;
	while (actualRef != nullptr) {
		insertarFin(*actualRef->getActual());
		actualRef = actualRef->getSiguiente();
	}


}

void listaJugador::insertarInicio(jugadorGenerico& ref) {
	nodoJugador* temporal = new nodoJugador(&ref, inicio);
	inicio = temporal;
}
void listaJugador::insertarFin(jugadorGenerico& ref) {

	if (listaVacia()) {
		insertarInicio(ref);
		return; // de lo contrario en el constructor de copia el primer elemento se copiara 2 veces
	}


	nodoJugador* actual = inicio;

	while (actual != nullptr) {
		if (actual->getSiguiente() == nullptr) {
			actual->setSiguiente(new nodoJugador(&ref, nullptr));
			return;
		}
		actual = actual->getSiguiente();
	}



}






void listaJugador::borrarInicio() {
	if (inicio != nullptr) {
		nodoJugador *actual = inicio->getSiguiente();
		delete inicio;
		inicio = actual;
		actual = nullptr;
	}
}

void listaJugador::borrar(string nickname) {

	if (inicio->getActual()->equivalente(nickname)) {
		borrarInicio();
	}

	nodoJugador *actual = inicio;


	while (actual->getSiguiente() != nullptr) {


		if (actual->getSiguiente()->getActual()->equivalente(nickname)) {
			nodoJugador *siguiente = actual->getSiguiente()->getSiguiente();
			if (actual)

				delete actual->getSiguiente();
			actual->setSiguiente(siguiente);

			return;
		}
		actual = actual->getSiguiente();
	}


}


jugadorGenerico* listaJugador::obtenerJugador(int posicion) {


	if (listaVacia()) {
		return nullptr;
	}
	if (posicion + 1 < 0 || posicion + 1 > insertados()){
		return nullptr;
	}
	nodoJugador * actual = inicio;
	for (int i = 0; i < posicion; i++) {
		actual = actual->getSiguiente();
	}

	//en caso de que exista un error en los nodos podemos verificar si es nulo
	return actual != nullptr ? actual->getActual() : nullptr;
}



int listaJugador::insertados() {
	nodoJugador *actual = inicio;
	int cantidad = 0;

	while (actual != nullptr) {
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}



bool listaJugador::listaVacia() {
	return  inicio == nullptr;
}




listaJugador::~listaJugador() {
	while (!listaVacia()) {
		borrarInicio();
	}
}


