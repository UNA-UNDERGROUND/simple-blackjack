#pragma once
#include "jugadorGenerico.h"

class jugador : public jugadorGenerico{
private:



public:
	jugador(std::string nickname);
	jugador(jugador &ref);

	~jugador();
};




