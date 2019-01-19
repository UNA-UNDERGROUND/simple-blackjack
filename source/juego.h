#pragma once
using namespace std;
#include <iostream>
#include "carta.h"
#include "mano.h"
#include "jugador.h"
#include "dealer.h"
#include "listaJugador.h"
#include "mazo.h"

class juego {
private:
	mano *man;
	carta *cart;
	dealer *deal;
	jugador *juga;
	listaJugador listJuga;
	mazo *baraja;
public:
	juego();
	~juego();
	void jugar();
};