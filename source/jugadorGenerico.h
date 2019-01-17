#pragma once


#include <string>
#include "mano.h"

using std::string;

//nota: como usaremos posteriormente poliformismo y punteros tenemos 2 opciones
//
// 1. evitar adquirir memoria dinamica en las clases hijas
// 2. usar destructores virtuales
//
// lo mas recomendado es evitar usar memoria dinamica, puesto que jugadorGenerico ya almacena la memoria escencial de las cartas y sus métodos, además no hay un dato especial que lo requiera
// pero si fuera nescesario se pueden usar destructores virtuales para liberar destructores de las clases hijas




class jugadorGenerico {
protected:

	mano * manoJugador;
	
public:
	jugadorGenerico();
	jugadorGenerico(jugadorGenerico &ref);

	virtual void pedirCarta(mazo *m) = 0;//las cartas del jugador se giran automaticamente,las del dealer no

	virtual string getNickname() = 0;
	bool sePaso();
	virtual bool equivalente(string nickname) = 0;
	int getPuntuacion();
	mano* getMano();						//pasamos una copia para evitar modificaciones


	~jugadorGenerico();

	friend std::ostream& operator<<(std::ostream&, jugadorGenerico&);

};






