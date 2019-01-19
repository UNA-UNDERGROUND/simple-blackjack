#include <iostream>
#include <string>




#include "gestorConsola.h"
#include "carta.h"


#include "utiles.h"


using std::cout;

using std::cin;
using std::string;

using std::endl;

gestorConsola consolaSalida;
bool animarLogo = true;

void imprimirCarta(carta& ref, int x, int y) {
	std::wstring simbolo;


	//nos dirigimos a la posicion inicial
	consolaSalida.gotoXY(x, y);


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




	consolaSalida.cambiarColor(blanco, negro);
}

void dibujarLogo(int xLogo, int yLogo) {

	consolaSalida.gotoXY(xLogo, yLogo++);

	//primera linea
	consolaSalida.cambiarColor(rojo);
	wcout << L"██████╗";
	consolaSalida.cambiarColor(blanco);
	wcout << L" ██╗      █████╗  ██████╗██╗  ██╗";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"     ██╗ ";
	consolaSalida.cambiarColor(blanco);
	wcout << L"█████╗  ██████╗██╗  ██╗";


	//segunda linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██╔══██╗";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║     ██╔══██╗██╔════╝██║ ██╔╝";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"     ██║";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██╔══██╗██╔════╝██║ ██╔╝" << endl;


	//tercera linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██████╔╝";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║     ███████║██║     █████╔╝ ";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"     ██║";
	consolaSalida.cambiarColor(blanco);
	wcout << L"███████║██║     █████╔╝" << endl;

	//cuarta linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██╔══██╗";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║     ██╔══██║██║     ██╔═██╗ ";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"██   ██║";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██╔══██║██║     ██╔═██╗" << endl;

	//quinta linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"██████╔╝";
	consolaSalida.cambiarColor(blanco);
	wcout << L"███████╗██║  ██║╚██████╗██║  ██╗";
	consolaSalida.cambiarColor(amarillo);
	wcout << L"╚█████╔╝";
	consolaSalida.cambiarColor(blanco);
	wcout << L"██║  ██║╚██████╗██║  ██╗" << endl;

	//sexta linea
	consolaSalida.gotoXY(xLogo, yLogo++);
	consolaSalida.cambiarColor(rojo);
	wcout << L"╚═════╝ ";
	consolaSalida.cambiarColor(blanco);
	wcout << L"╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝";
	consolaSalida.cambiarColor(amarillo);
	wcout << L" ╚════╝ ";
	consolaSalida.cambiarColor(blanco);
	wcout << L"╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝" << endl;


	
}

int menuPrincipal() {

	consolaUnicode();						//podremos acceder a mas caracteres,pero no podremos usar std::cout, a cambio se puede usar std::wcout
	consolaSalida.mostrarCursor(false);

	carta c1(1, 3);
	carta c2(11, 1);
	carta c3(1, 1);

	carta cartas[]{carta(1,3),carta(11,1),carta(2, 2),carta(13, 4),carta(1, 1)};


	for (int i = 0; i < 4; i++) {
		cartas[i].voltear();
	}


	int puntoX[] = {24,97,60,60};
	int puntoY[] = {15,8,15,8};


	color colorLuz = rojo;
	int puntosRestantes = 3; //detemina la longitud de una luz especifica

	int xCartas = 0;
	int yCartas = 0;


	imprimirCarta(cartas[0], xCartas, yCartas);
	imprimirCarta(cartas[1], xCartas += 8, yCartas);
	imprimirCarta(cartas[4], xCartas += 8, yCartas);

	xCartas = 110;
	yCartas = 23;
	imprimirCarta(cartas[4], xCartas, yCartas);
	imprimirCarta(cartas[3], xCartas -= 5, yCartas-=2);
	imprimirCarta(cartas[2], xCartas -= 5, yCartas-=2);

	dibujarLogo(25, 9);



	int eleccion = 0;


	consolaSalida.gotoXY(0, 26);
	wcout << "controles:" << endl;
	wcout << "espacio:              seleccionar." << endl;
	wcout << "flecha arriba/w:      moverse arriba." << endl;
	wcout << "flecha abajo/s:       moverse abajo.";
	

	while (true) {


		{
			consolaSalida.gotoXY(55, 18);
			if (eleccion == 0) {
				consolaSalida.cambiarColor(negro, gris);
			}
			wcout << "nueva  partida ";
			consolaSalida.cambiarColor(blanco);
			consolaSalida.gotoXY(55, 19);


			if (eleccion == 1) {
				consolaSalida.cambiarColor(negro, gris);
			}
			wcout << "cargar partida ";
			consolaSalida.cambiarColor(blanco);
			consolaSalida.gotoXY(55, 20);


			if (eleccion == 2) {
				consolaSalida.cambiarColor(negro, gris);
			}
			wcout << "  Marcadores   ";
			consolaSalida.cambiarColor(blanco);


			if (eleccion == 3) {
				consolaSalida.cambiarColor(negro, gris);
			}
			consolaSalida.gotoXY(55, 21);

			wcout << "     Salir     ";
			consolaSalida.cambiarColor(blanco);

		}





		consolaSalida.gotoXY(0, 8);
		

		//int entrada = capturarEntrada();
		int entrada = 0;

		auto future = std::async(std::launch::async, capturarEntrada);
		while (future.wait_for(std::chrono::milliseconds(75)) == std::future_status::timeout) {
			
			//durante este tiempo podemos realizar algo rapido como animar el titulo
			
			consolaSalida.cambiarColor(colorLuz);
			for (int i = 0; i < 4; i++) {
				consolaSalida.gotoXY(puntoX[i], puntoY[i]);
				wcout << "*";
				if (puntoX[i] == 24 && puntoY[i] != 15) {
					puntoY[i]++;
				}
				else if (puntoX[i] != 97 && puntoY[i] == 15) {
					puntoX[i]++;
				}
				else if (puntoX[i] == 97 && puntoY[i] != 8) {
					puntoY[i]--;
				}
				else {
					puntoX[i]--;
				}
			}
			consolaSalida.cambiarColor(blanco);

			if (puntosRestantes == 0) {
				if (colorLuz == rojo) {
					colorLuz = celeste;
				}
				else if (colorLuz == celeste) {
					colorLuz = verde;
				}
				else if (colorLuz == verde) {
					colorLuz = amarillo;
				}
				else {
					colorLuz = rojo;
				}

				//cambiar la luz en cada inicio
				if (puntoX[0] == 24 && puntoY[0] == 8) {
					if (colorLuz == rojo) {
						colorLuz = celeste;
					}
					else if (colorLuz == celeste) {
						colorLuz = verde;
					}
					else if (colorLuz == verde) {
						colorLuz = amarillo;
					}
					else {
						colorLuz = rojo;
					}
				}

				puntosRestantes = 3;
			}
			else {
				puntosRestantes--;
			}


		}

			entrada = future.get();

			switch (entrada) {
			case Arriba:
				if (eleccion != 0) {
					eleccion--;
				}
				else {
					eleccion = 3;
				}

				break;
			case Abajo:
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
			default:{

				break;
			}
			}

		

	}
}

int main(int argc, char const *argv[]) {



	//setlocale(LC_ALL, "Spanish");				// localizacion al español para soportar tildes y caracteres españoles





	int eleccion = 0;
	do {
		animarLogo = true;
		eleccion = menuPrincipal();
		animarLogo = false;

	} while (eleccion != 3);



	return 0;
}

