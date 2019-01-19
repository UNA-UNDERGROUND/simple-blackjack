#include <iostream>
#include <string>

#include "utiles.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main(int argc, char const *argv[]) {


	setlocale(LC_ALL, "es-CR.UTF-8"); // localizacion al español para soportar tildes y caracteres españoles
	mostrarCursor(false);
	gotoXY(8, 8);
	color Color = blanco;
	cambiarColor(negro, verde);
	cout << "hola mundo!!!";
	//cout << "color: " << "0x" << std::hex << Color << endl;
	//cout << "color(desplazado): " << "0x" << std::hex << (Color<<4) << endl;
	//cout << "color: " << "0x" << std::hex << (BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE) << endl;

	cin.ignore();
	return 0;
}

