#pragma once

#include <iostream>

//definiciones comunes de las cartas
const std::wstring nombreCarta[]{ L"?", L"A", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"10", L"J", L"Q", L"k" };
const std::wstring nombrePalo[]{ L"?", L"Espadas", L"Tréboles", L"Corazones", L"Diamantes" };
const std::wstring simboloPalo[]{ L"?", L"♠", L"♣", L"♥", L"♦" };


class carta{
private:
    int codigo=0;//0 es nulo
    int palo=0; //0 es nulo
    bool bocaAbajo=true;


public:
    carta() = default;
    carta(int codigo,int palo);
    
    void voltear();

    bool equivalente(carta &ref);

    int getcodigo();
    int getPalo();
	bool revelada();
    
};


