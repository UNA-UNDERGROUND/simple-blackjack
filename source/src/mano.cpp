#include "mano.h"

mano::mano() {

	cartas = new listaCarta();

}

mano::mano(mano &ref) {
	cartas = new listaCarta(*ref.cartas);
}

void mano::agregarCarta(mazo* ref) {
	cartas->insertarFin(*ref->tomarCarta());
}
void mano::agregarCarta(carta ref) {
	cartas->insertarFin(ref);
}
void mano::limpiar() {

	if (cartas != nullptr) {
		delete cartas;
	}
	cartas = new listaCarta();

}


int mano::getCartas() {
	return cartas->listaVacia() ? 0 : cartas->insertados();
}
carta& mano::getCarta(int posicion) {
	return cartas->obtenerCarta(posicion);
}

//nota este metodo retorna los puntos de tal manera que sea el resultado que mas le convenga
int mano::getPuntos() {


	if (cartas->listaVacia()){
		return 0;
	}
	int numeroCartas = cartas->insertados();
	int puntaje = 0;
	int ases = 0;
	for (int i = 0; i < numeroCartas; i++) {
		carta c(cartas->obtenerCarta(i));

		if (c.getcodigo() == 0 || c.getPalo() == 0){
			//en caso de que la carta tenga un valor invalido
			continue;
		}

		if (c.getcodigo() == 1){
			ases++;
		}
		else if (c.getcodigo() > 10) {
			puntaje += 10;
		}
		else {
			puntaje += c.getcodigo();
		}
	}

	

	if (ases > 0) {
		if (puntaje > 21) {
			puntaje += ases;
		}
		else {

			int restante = puntaje - 21;
			if (restante < 11) {
				puntaje += ases;
			}
			else {
				while (ases > 0) {
					puntaje += (restante >= 11 + (ases - 1)) ? 11 : 1;
					ases--;
				}
			}
		}

	}

	return puntaje;
}



mano::~mano() {

	if (cartas != nullptr){
		delete cartas;
		cartas = nullptr;
	}
	
}
