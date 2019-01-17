#pragma once


#include <string>
#include "mano.h"

using std::string;


class jugadorGenerico {
protected:

	mano * manoJugador;
	
public:
	jugadorGenerico();
	jugadorGenerico(jugadorGenerico &ref);

	virtual void pedirCarta(mazo *m) = 0;//las cartas del jugador se giran automaticamente,las del dealer no

	virtual string getNickname() = 0;
	bool sePaso();
	int getPuntuacion();
	mano* getMano();						//pasamos una copia para evitar modificaciones

	~jugadorGenerico();

	friend std::ostream& operator<<(std::ostream&, jugadorGenerico&);

};






