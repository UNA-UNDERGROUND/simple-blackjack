#pragma once
#include "nodoCarta.h"
#include <iostream>

class listaCarta {
private:
	nodoCarta *inicio;
public:
	listaCarta();
	
	
	
	nodoCarta* getInicio();

	bool listaVacia();

	void insertar(nodoCarta&);

	
	friend std::ostream& operator<<(std::ostream&, listaCarta);

	~listaCarta();
};








