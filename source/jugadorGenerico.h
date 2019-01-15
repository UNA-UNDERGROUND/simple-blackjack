#pragma once


#include <string>
#include "mano.h"

using std::string;


class jugadorGenerico {
private:

	string nickname;
	mano * manoJugador;
	
public:
	jugadorGenerico(string nickname);
	jugadorGenerico(jugadorGenerico &ref);

	void pedirCarta(mazo *m);

	string getNickname();
	bool sePaso();
	int getPuntuacion();
	mano* getMano();				//pasamos una copia para evitar modificaciones

	~jugadorGenerico();

	friend std::ostream& operator<<(std::ostream&, jugadorGenerico);

};






