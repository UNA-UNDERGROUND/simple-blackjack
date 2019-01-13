#pragma once
#include "carta.h"



class nodoCarta{
private:
    nodoCarta *siguiente;
    carta *actual;

public:
    nodoCarta(carta &ref);
    void setSiguiente(nodoCarta *ref);
    nodoCarta *getSiguiente();
	carta *getCarta();
    ~nodoCarta();
};


