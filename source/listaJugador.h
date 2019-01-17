#pragma once
#include "nodoJugador.h"
#include "jugador.h"		//necesario para crear una instancia vacia de jugadorGenerico


// nota: la listaJugador y su implementacion son similares a la listaCarta

class listaJugador {
private:
	nodoJugador *inicio;
public:
	listaJugador();
	listaJugador(listaJugador &ref);
	void insertarInicio(jugadorGenerico&);
	void insertarFin(jugadorGenerico&);
	void borrarInicio();
	void borrar(string nickname);				
	jugadorGenerico &obtenerJugador(int posicion);	
	int insertados();					
	bool listaVacia();					
	~listaJugador();						


};




