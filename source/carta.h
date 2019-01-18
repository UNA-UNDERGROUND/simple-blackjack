#pragma once

#include <iostream>

//definiciones comunes de las cartas
const std::wstring nombreCarta[]{ L"?", L"A", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"10", L"J", L"Q", L"k" };
const std::wstring nombrePalo[]{ L"?", L"Espadas", L"Tréboles", L"Corazones", L"Diamantes" };
const std::wstring simboloPalo[]{ L"?", L"♠", L"♣", L"♥", L"♦" };


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


