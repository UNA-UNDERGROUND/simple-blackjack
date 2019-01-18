#include <iostream>
#include <string>



#include "utiles.h"



using std::cout;

using std::cin;
using std::string;

using std::endl;




int main(int argc, char const *argv[]) {


	setlocale(LC_ALL, "Spanish");				// localizacion al español para soportar tildes y caracteres españoles
	_setmode(_fileno(stdout), _O_U16TEXT);		// cambiamos a unicode en la consola para mostrar caracteres especiales



	mostrarCursor(false);
	gotoXY(8, 8);
	color Color = blanco;
	//cambiarColor(rojo, negro);
	
	carta c1(1, 3);
	carta c2(11, 1);
	carta c3(1, 1);

	c1.voltear();
	c2.voltear();

	imprimirCarta(c1,8,8);
	imprimirCarta(c2, 18, 8);
	imprimirCarta(c3, 28, 8);



	//cout << "color: " << "0x" << std::hex << Color << endl;
	//cout << "color(desplazado): " << "0x" << std::hex << (Color<<4) << endl;
	//cout << "color: " << "0x" << std::hex << (BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE) << endl;

	cin.ignore();
	return 0;
}

