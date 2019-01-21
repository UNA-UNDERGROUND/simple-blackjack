#pragma once

#include <iostream>
#include <sstream>


#include "jugador.h"
#include "dealer.h"
#include "listaJugador.h"
#include "listaCarta.h"

#include "gestorGraficos.h"

using namespace std;

class juego {
private:
	listaJugador* listaJugadores;
	mazo* mazoCartas;
	gestorGraficos gestorPantalla;

	int jugadores = 6;
	int turnoJugador = 1;
	int pagina = 0;
	int paginaDealer = 0;
	int paginaJugadores = 0;

	void pantallaJuego();			//aqui se lleva la logica del juego, por lo tanto este metodo se encarga de la gestion de los juegos nuevo y los juegos cargados una vez inicializados
	void pantallaFinDelJuego();

public:
	juego();
	void jugar();

	~juego();
};