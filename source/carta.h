#pragma once

#include <iostream>

//definiciones comunes de las cartas
const std::string nombreCarta[]{ "?", "A", "2", "3", "4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10", "J", "Q", "k" };
const std::string nombrePalo[]{ "?", "Espadas", "Tréboles", "Corazones", "Diamantes" };


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
	bool revelada();
    

    ~carta();
};


