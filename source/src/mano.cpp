#include "mano.h"



void mano::agregarCarta(mazo& ref) {
	agregarCarta(ref.tomarCarta());
}
void mano::agregarCarta(carta& ref) {
	cartas.push_back(ref);
}
void mano::limpiar() {
	cartas.clear();
}


size_t mano::getCartas() {
	return cartas.size();// cartas->listaVacia() ? 0 : cartas->insertados();
}
carta& mano::getCarta(int posicion) {
	if (cartas.size()>posicion)
	{
		return cartas[posicion];//->obtenerCarta(posicion);
	}
	return carta();
}

//nota este metodo retorna los puntos de tal manera que sea el resultado que mas le convenga
int mano::getPuntos() {


	if (cartas.empty()){
		return 0;
	}
	size_t numeroCartas = getCartas();
	int puntaje = 0;
	int ases = 0;
	for (int i = 0; i < numeroCartas; i++) {
		carta c(cartas[i]);

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



