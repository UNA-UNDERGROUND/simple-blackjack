#include "listaCarta.h"

listaCarta::listaCarta() {
	inicio = nullptr;
}


nodoCarta* listaCarta::getInicio() {
	return inicio;
}


bool listaCarta::listaVacia() {
	return inicio == nullptr;
}

void listaCarta::insertar(nodoCarta &ref) {
	if (inicio == nullptr){
		inicio = &ref;
		return;
	}

	nodoCarta *nodoCuenta = inicio;
	while ( nodoCuenta != nullptr ) {


		if ( nodoCuenta->getSiguiente() == nullptr ) {
			nodoCuenta->setSiguiente(new nodoCarta(ref));
			return;
		}
		nodoCuenta = nodoCuenta->getSiguiente();

	}
	
}




listaCarta::~listaCarta() {



}

