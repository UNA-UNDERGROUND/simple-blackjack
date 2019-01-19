#include <iostream>
#include <string>



#include "gestorConsola.h"
#include "carta.h"


using std::cout;

using std::cin;
using std::string;

using std::endl;

gestorConsola consolaSalida;

void imprimirCarta(carta& ref, int x, int y) {
	std::wstring simbolo;

	//nos dirigimos a la posicion inicial
	consolaSalida.gotoXY(x, y);

	//cambiamos a modo unicode
	consolaUnicode();
	wcout << L"╔═══════╗";
	for (int i = 0; i < 5; i++) {
		consolaSalida.gotoXY(x, y + i + 1);
		wcout << L"║       ║";
	}
	consolaSalida.gotoXY(x, y + 6);
	wcout << L"╚═══════╝";


	if (ref.revelada()) {
		//nos dirigimos al centro
		consolaSalida.gotoXY(x + 4, y + 3);
		//verificar el rango y escoger el color del simbolo
		int palo = ref.getPalo();
		if (palo < 1 || palo > 4) {
			consolaSalida.cambiarColor(amarillo, negro);
		}
		else {
			if (palo > 2) {
				consolaSalida.cambiarColor(rojo, negro);
			}
			else {
				consolaSalida.cambiarColor(gris, negro);
			}
		}

		wcout << simboloPalo[ref.getPalo()];


		consolaSalida.cambiarColor(celeste, negro);
		consolaSalida.gotoXY(x + 7, y + 5);
		wcout << nombreCarta[ref.getcodigo()];
		consolaSalida.gotoXY(x + 1, y + 1);
		wcout << nombreCarta[ref.getcodigo()];
	}
	else {
		for (int i = 1; i < 6; i++) {
			consolaSalida.gotoXY(x + 1, y + i);
			consolaSalida.cambiarColor(verde);

			wcout << L"░░░░░░░";

		}

		consolaSalida.gotoXY(x + 1, y + 1);
	}


	consolaUnicode(false);

	consolaSalida.cambiarColor(blanco, negro);
}

void dibujarLogo(int xLogo, int yLogo) {

	consolaUnicode();


	consolaSalida.gotoXY(xLogo, yLogo++);

	//primera linea
	consolaSalida.cambiarColor(rojo);
	wcout << L"██████╗";
	consolaSalida.cambiarColor(blanco);
	wcout << L" ██╗      █████╗  ██████╗██╗  ██╗";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"     ██╗ ";
	consolaSalida.cambiarColor(blanco);
	wcout << L"█████╗  ██████╗██╗  ██╗ ";


	//segunda linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██╔══██╗";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║     ██╔══██╗██╔════╝██║ ██╔╝";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"     ██║";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██╔══██╗██╔════╝██║ ██╔╝ " << endl;


	//tercera linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██████╔╝";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║     ███████║██║     █████╔╝ ";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"     ██║";
	consolaSalida.cambiarColor(blanco);
	wcout << L"███████║██║     █████╔╝  " << endl;

	//cuarta linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██╔══██╗";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║     ██╔══██║██║     ██╔═██╗ ";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"██   ██║";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██╔══██║██║     ██╔═██╗  " << endl;

	//quinta linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██████╔╝";
	consolaSalida.cambiarColor(blanco);
	wcout << L"███████╗██║  ██║╚██████╗██║  ██╗";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"╚█████╔╝";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║  ██║╚██████╗██║  ██╗ " << endl;

	//sexta linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"╚═════╝ ";
	consolaSalida.cambiarColor(blanco);
	wcout << L"╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝";
	consolaSalida.cambiarColor(amarillo);
	wcout << L" ╚════╝ ";
	consolaSalida.cambiarColor(blanco);
	wcout << L"╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ " << endl;


	consolaUnicode(false);
}

int menuPrincipal() {
	consolaSalida.mostrarCursor(false);

	carta c1(1, 3);
	carta c2(11, 1);
	carta c3(1, 1);

	c1.voltear();
	c2.voltear();





	int xLogo = 0;
	int yLogo = 0;

	int yCartas = 0;
	int xCartas = 0;

	imprimirCarta(c1, xCartas, yCartas);
	imprimirCarta(c2, xCartas += 8, yCartas);
	imprimirCarta(c3, xCartas += 8, yCartas);


	dibujarLogo(25, 9);

	int eleccion = 0;

	while (true) {


		consolaSalida.gotoXY(55, 18);
		if (eleccion == 0) {
			consolaSalida.cambiarColor(negro, gris);
		}
		cout << "nueva partida  ";
		consolaSalida.cambiarColor(blanco);
		consolaSalida.gotoXY(55, 19);


		if (eleccion == 1) {
			consolaSalida.cambiarColor(negro, gris);
		}
		cout << "cargar partida ";
		consolaSalida.cambiarColor(blanco);
		consolaSalida.gotoXY(55, 20);


		if (eleccion == 2) {
			consolaSalida.cambiarColor(negro, gris);
		}
		cout << "Marcadores     ";
		consolaSalida.cambiarColor(blanco);


		if (eleccion == 3) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, 21);

		cout << "Salir          ";
		consolaSalida.cambiarColor(blanco);


		consolaSalida.gotoXY(55, 22);
		cout << "eleccion: " << eleccion;

		consolaSalida.gotoXY(0, 8);


		int entrada = capturarEntrada();



		switch (entrada) {
		case Arriba:
			cout << "arriba    " << endl;
			if (eleccion != 0) {
				eleccion--;
			}
			else {
				eleccion = 3;
			}
			break;
		case Abajo:
			cout << "abajo    " << endl;
			if (eleccion != 3) {
				eleccion++;
			}
			else {
				eleccion = 0;
			}
			break;

		case Adelante:
			return eleccion;
			break;


		default:
		{
			break;
		}
		}




	}
}

int main(int argc, char const *argv[]) {


	setlocale(LC_ALL, "Spanish");				// localizacion al español para soportar tildes y caracteres españoles
	

	int eleccion;
	do {
		eleccion = menuPrincipal();
	} while (eleccion!=3);



	cout << "fin del programa(main)" << endl;
	return 0;
}

