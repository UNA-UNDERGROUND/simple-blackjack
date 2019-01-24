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
	gestorGraficos gestorPantalla;	//el gestor de graficos se no se deberia exponer

	int jugadores;
	int turnoJugador;

	//variables del gestor de la pantalla
	int pagina = 0;
	int paginaDealer = 0;
	int paginaJugadores = 0;

	void pantallaJuego();			//aqui se lleva la logica del juego, por lo tanto este metodo se encarga de la gestion de los juegos nuevo y los juegos cargados una vez inicializados
	void pantallaFinDelJuego();


	//fstream archivoMarcador;

public:
	juego();
	void jugar();


	//algunos getters en ese caso expondran los datos internos nescesarios para modificar una partida y por lo tanto guardarla y cargarla
	listaJugador& getJugadores();
	mazo& getMazoCartas();
	
	//void setJugadores();				//este metodo no es nescesario puesto que al cargar partida se registraran los usuarios insertados
	void setTurnoJugador(int turno);	// es nescesario un get, si se corrompe el archivo de la partida el turno sera del primer jugador
	int getTurnoJugador();


	~juego();
};