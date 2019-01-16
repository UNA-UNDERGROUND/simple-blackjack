#pragma once


#include <string>
#include "mano.h"

using std::string;


class jugadorGenerico {
protected:

	string nickname;
	mano * manoJugador;
	
public:
	jugadorGenerico();
	jugadorGenerico(jugadorGenerico &ref);

	void pedirCarta(mazo *m);

	string getNickname();
	bool sePaso();
	int getPuntuacion();
	mano* getMano();						//pasamos una copia para evitar modificaciones

	~jugadorGenerico();

	friend std::ostream& operator<<(std::ostream&, jugadorGenerico);

};






