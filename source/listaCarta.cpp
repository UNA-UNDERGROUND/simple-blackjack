#include "listaCarta.h"


listaCarta::listaCarta() {
	inicio = nullptr;

}
listaCarta::listaCarta(listaCarta &ref) {
	inicio = nullptr;
	nodoCarta* actualRef = ref.inicio;
	while (actualRef != nullptr){
		insertarInicio(*actualRef->getActual());
		actualRef = actualRef->getSiguiente();
	}


}
//-------------------------------------------

void listaCarta::insertarInicio(carta ref) {
	nodoCarta* temporal = new nodoCarta(&ref, inicio);
	inicio = temporal;

}




//---------------------------------------------//


//---------------------------------------------//
void listaCarta::borrarInicio() {
	if (inicio != nullptr)  {
		nodoCarta *actual = inicio->getSiguiente();
		delete inicio;
		inicio = actual;
		actual = nullptr;
	}
}


//---------------------------------------------//
bool listaCarta::listaVacia() {
	return  inicio == nullptr;
}


//---------------------------------------------//
int listaCarta::insertados() {
	nodoCarta *actual = inicio;
	int cantidad = 0;

	while (actual != nullptr) {
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}



listaCarta::~listaCarta() {
	while (!listaVacia()) { 
		borrarInicio();
	}
}


