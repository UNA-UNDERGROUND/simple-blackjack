#include <iostream>
#include <string>


#include "listaCarta.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


//definiciones comunes de las cartas
const std::string nombreCarta[]{ "?", "A", "1", "3", "4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10", "J", "Q", "k" };
const std::string nombrePalo[]{ "?", "Espadas", "Tréboles", "Corazones", "Diamantes" };



std::ostream& operator<<(std::ostream& o, listaCarta lc) {

	//o << (lc.listaVacia() ? "la lista esta vacia" : "la lista no esta vacia") << endl;
	nodoCarta* actual = lc.inicio;
	//o << "------------------------" << endl;
	while (actual != nullptr){
		string ncarta = nombreCarta[actual->getActual()->getcodigo()];
		string npalo = nombrePalo[actual->getActual()->getPalo()];
		//o << "carta: " << (ncarta.empty() ? "?" : ncarta) << endl;
		//o << "palo: " << (npalo.empty() ? "?" : npalo) << endl;
		//o << "------------------------" << endl;
		actual = actual->getSiguiente();
	}


	return o;

}

int main(int argc, char const *argv[]){

	setlocale(LC_ALL, "spanish"); // localizacion al español para soportar tildes y caracteres españoles



	listaCarta lc;

	


    



    cin.ignore();
    return 0;
}

