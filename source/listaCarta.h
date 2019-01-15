#pragma once
#include "nodoCarta.h"



// en este caso el constructor de copia evita que en caso de crear una copia de este no se copien los mismos punteros,
// evitando un borrado inintencional posteriormente en el destructor de la copia

// importante:	la clase no esta diseñada para que se modifiquen sus nodos por lo tanto en el metodo obtener
//				retorna una copia de este objeto,pero esta copia no es un puntero por lo que se eliminara automaticamente 

class listaCarta {
private:
	nodoCarta *inicio;
public:
	listaCarta();
	listaCarta(listaCarta &ref);
	void insertarInicio(carta);
	void insertarFin(carta);
	void borrarInicio();
	void borrar(carta ref);				// borra la primera coincidencia con la carta
	carta &obtenerCarta(int posicion);	// al ser puntero puede ser girada
	int insertados();					// cuenta y retorna la cantidad de nodos
	bool listaVacia();					// retorna true si la lista esta vacia y false sino 
	~listaCarta();						// destruye todos los nodos


};

