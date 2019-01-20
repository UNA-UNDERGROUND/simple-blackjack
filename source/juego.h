#pragma once
using namespace std;
#include <iostream>

#include "jugador.h"
#include "dealer.h"
#include "listaJugador.h"
#include "listaCarta.h"

#include "gestorGraficos.h"

class juego {
private:
	dealer *dealer;
	listaJugador *listaJugadores;
	mazo *baraja;
public:
	juego();
	void jugar();

	~juego();
};