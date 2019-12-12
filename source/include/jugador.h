#pragma once
#include "jugadorGenerico.h"

class jugador : public jugadorGenerico{
private:

	std::string nickname;

public:
	jugador(std::string nickname);
	jugador(jugador &ref);
	string getNickname();
	void pedirCarta(mazo *m);
	bool equivalente(string ref);							//metodo necesario para comparar jugadores en la lista

	~jugador();
};




