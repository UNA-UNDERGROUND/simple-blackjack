#pragma once

#include <iostream>

class carta{
private:
    int codigo;
    int palo;
    bool bocaAbajo;


public:
    carta();
    carta(int codigo,int palo);
    carta(carta & ref);
    
    void voltear();

    bool equivalente(carta &ref);

    int getcodigo();
    int getPalo();
    
    ~carta();
};


