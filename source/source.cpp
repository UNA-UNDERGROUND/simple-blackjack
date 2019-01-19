#include <iostream>
#include <string>
#include <iostream>
#include "juego.h"
#include "jugador.h"
#include "dealer.h"
#include "mazo.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;






int main(int argc, char const *argv[]){


    setlocale(LC_ALL, "Spanish"); // localizacion al español para soportar tildes y caracteres españoles


	juego jueg;
	dealer *dealerEjemplo;
	jugador *jugadorEjemplo;
	mazo *mazoEjemplo;
	

	jugador jugadorEjemplo("Perzival");
	dealer dealerEjemplo;

	mazo mazoEjemplo;
	mazoEjemplo.inicializar();
	mazoEjemplo.barajar();


	for (int i = 0; i < 2; i++) {
		dealerEjemplo.pedirCarta(&mazoEjemplo);
		jugadorEjemplo.pedirCarta(&mazoEjemplo);
	}

	//dealerEjemplo.volteaSegunta();
	//cout << jugadorEjemplo << endl;
	cout << dealerEjemplo << endl;



    cin.ignore();
    return 0;
}

