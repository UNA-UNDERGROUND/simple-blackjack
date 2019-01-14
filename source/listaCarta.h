#pragma once
#include "nodoCarta.h"
#include <iostream>




// en este caso el constructor de copia evita que en caso de crear una copia de este no se copien los mismos punteros,
// evitando un borrado inintencional posteriormente en el destructor de la copia



class listaCarta {
private:
	nodoCarta *inicio;
public:
	listaCarta();
	listaCarta(listaCarta &ref);
	void insertarInicio(carta);
	void insertarFin(carta);
	void borrarInicio();
	void borrar(carta ref);
	int insertados();// cuenta y retorna la cantidad de nodos
	bool listaVacia(); // retorna true si la lista esta vacia y false sino 
	~listaCarta();// destruye todos los nodos


	friend std::ostream& operator<<(std::ostream&, listaCarta);

};

