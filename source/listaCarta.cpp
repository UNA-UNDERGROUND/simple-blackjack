#include "listaCarta.h"


listaCarta::listaCarta() {
	inicio = nullptr;

}
listaCarta::listaCarta(listaCarta &ref) {
	inicio = nullptr;
	nodoCarta* actualRef = ref.inicio;
	while (actualRef != nullptr){
		insertarFin(*actualRef->getActual());
		actualRef = actualRef->getSiguiente();
	}


}

void listaCarta::insertarInicio(carta ref) {
	nodoCarta* temporal = new nodoCarta(&ref, inicio);
	inicio = temporal;

}
void listaCarta::insertarFin(carta ref) {
	
	if (listaVacia()) {
		insertarInicio(ref);
		return; // de lo contrario en el constructor de copia el primer elemento se copiara 2 veces
	}
	

	nodoCarta* actual = inicio;
	
	while( actual != nullptr ){
		if (actual->getSiguiente() == nullptr){
			actual->setSiguiente(new nodoCarta(&ref,nullptr));
			return;
		}
		actual = actual->getSiguiente();
	}

	

}






void listaCarta::borrarInicio() {
	if (inicio != nullptr)  {
		nodoCarta *actual = inicio->getSiguiente();
		delete inicio;
		inicio = actual;
		actual = nullptr;
	}
}

void listaCarta::borrar(carta ref) {

	if ( inicio->getActual()->equivalente(ref) ) {
		borrarInicio();
	}

	nodoCarta *actual = inicio;


	while ( actual->getSiguiente() != nullptr )  {

		
		if ( actual->getSiguiente()->getActual()->equivalente(ref) ) {
				nodoCarta *siguiente=actual->getSiguiente()->getSiguiente();
				if(actual)

				delete actual->getSiguiente();
				actual->setSiguiente(siguiente);

			return;
		}
		actual = actual->getSiguiente();
	}


}



bool listaCarta::listaVacia() {
	return  inicio == nullptr;
}



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


