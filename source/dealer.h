#pragma once
#include "jugadorGenerico.h"

class dealer : public jugadorGenerico{
private:

public:
	dealer();


	string getNickname();
	void pedirCarta(mazo *m);
	void volteaSegunta();


	~dealer();

};







