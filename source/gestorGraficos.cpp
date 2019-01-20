#include "gestorGraficos.h"

//120 ancho


gestorGraficos::gestorGraficos() {

	consolaUnicode();						//podremos acceder a mas caracteres,pero no podremos usar std::cout, a cambio se puede usar std::wcout
	consolaSalida.mostrarCursor(false);

}


void gestorGraficos::imprimirCarta(carta& ref, int x, int y,bool vacia) {
	consolaSalida.cambiarColor(blanco);

	//nos dirigimos a la posicion inicial
	consolaSalida.gotoXY(x, y);

	if (!vacia) {
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

			if (nombreCarta[ref.getcodigo()] == nombreCarta[10]) {
				consolaSalida.gotoXY(x + 6, y + 5);
			}
			else {
				consolaSalida.gotoXY(x + 7, y + 5);
			}
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
	}
	else {
		consolaSalida.cambiarColor(verde);

		wcout << L"▒▒▒▒▒▒▒▒▒";
		for (int i = 0; i < 5; i++) {
			consolaSalida.gotoXY(x, y + i + 1);

			wcout << L"▒▒▒▒▒▒▒▒▒";
		}
		consolaSalida.gotoXY(x, y + 6);

		wcout << L"▒▒▒▒▒▒▒▒▒";
	}


	consolaSalida.cambiarColor(blanco, negro);
}

void gestorGraficos::dibujarLogo(int xLogo, int yLogo) {

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

void gestorGraficos::limpiarSector(int x1, int y1, int x2, int y2) {

	//limpiamos los contenidos anteriores

	for (int y = y1; y <= y2; y++) {
		consolaSalida.gotoXY(x1, y);
		for (int x = x1; x <= x2; x++) {
			wprintf(L" ");					//queremos limpiar la pantalla lo mas rapido posible y wprintf es mas sencillo que wcout,pero es más rapido
		}

	}




}




void gestorGraficos::mostrarInfoUsuario(wstring nick, mano& manoJugador, bool esDealer){
	consolaSalida.cambiarColor(negro, grisOscuro);

	if (!esDealer) {

		limpiarSector(2, 1, 60, 1);		//limpiamos los datos anteriores

		consolaSalida.gotoXY(2, 1);
		wcout << "Jugador Actual: " << nick;

		consolaSalida.gotoXY(30, 1);
		wcout << "puntuacion: " << manoJugador.getPuntos();

		consolaSalida.gotoXY(46, 1);
		wcout << "cartas: " << manoJugador.getCartas();
	}
	else {

		consolaSalida.gotoXY(80, 0);
		wcout << "Dealer :        " << nick;

		consolaSalida.gotoXY(80, 1);
		wcout << "puntuacion:     ";
		if (manoJugador.getCarta(1).revelada()) {
			wcout << manoJugador.getPuntos();
		}
		else {
			wcout << "?";
		}

		consolaSalida.gotoXY(80, 2);
		wcout << "cartas:         " << manoJugador.getCartas();



	}


	

	consolaSalida.cambiarColor(negro);

}

void gestorGraficos::mostrarJugadorSecundario(wstring nick, listaJugador& jugadores, int ubicacion,int posicion) {


	int posicionY = (2 * (posicion + 1)) + 4 * posicion; //ubicacion de la esquina*(posicion deseada)+separacion entre jugadoresSecundarios

	//limpiamos los campos antes de usarlos
	limpiarSector(4, posicionY, 60, posicionY + 5);

	jugadorGenerico *Actual = &jugadores.obtenerJugador(ubicacion);


	if (Actual->getMano() != nullptr){
		consolaSalida.gotoXY(4, posicionY++);
		wcout << "jugador#" << ubicacion;
		consolaSalida.gotoXY(4, posicionY++);
		wcout << "nickname:         " << nick;
		consolaSalida.gotoXY(4, posicionY++);
		wcout << "Puntuacion:       " << Actual->getPuntuacion();
		consolaSalida.gotoXY(4, posicionY++);
		wcout << "Numero de Cartas: " << Actual->getMano()->getCartas();
		consolaSalida.gotoXY(4, posicionY);
		wcout << "cartas:           ";
		carta *cartaActual;
		int numeroCartas = Actual->getMano()->getCartas();
		for (int j = 0; j < numeroCartas; j++) {
				cartaActual = &Actual->getMano()->getCarta(j);
				wcout << nombreCarta[cartaActual->getcodigo()] << simboloPalo[cartaActual->getPalo()];
				wcout << ((j + 1) != numeroCartas? ", ":".");	
			}
	}


	

}
bool gestorGraficos::eleccion() {
	boton botonEntrada = Desconocido;
	do {
		botonEntrada = capturarEntrada();
	} while (botonEntrada != Boton1 && botonEntrada != Boton2);

	if (botonEntrada == Boton1) {
		return true;
	}
	else {
		return false;
	}
}

int gestorGraficos::menuPrincipal() {

	consolaSalida.limpiarPantalla();

	carta c1(1, 3);
	carta c2(11, 1);
	carta c3(1, 1);

	carta cartas[]{ carta(1,3),carta(11,1),carta(2, 2),carta(13, 4),carta(1, 1) };


	for (int i = 0; i < 4; i++) {
		cartas[i].voltear();
	}


	int puntoX[] = { 24,97,60,60 };
	int puntoY[] = { 15,8,15,8 };


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
	imprimirCarta(cartas[3], xCartas -= 5, yCartas -= 2);
	imprimirCarta(cartas[2], xCartas -= 5, yCartas -= 2);

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
				wcout << L"▓";

				if (puntoX[i] == 24) {
					consolaSalida.gotoXY(puntoX[i] - 1, puntoY[i]);
					wcout << L"▓";
				}
				else if (puntoX[i] == 97) {
					wcout << L"▓";
				}

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
			consolaSalida.limpiarPantalla();
			return eleccion;
			break;
		default:
		{

			break;
		}
		}



	}
}
void gestorGraficos::mostrarMesa() {

	consolaSalida.cambiarColor(grisOscuro);

	//primero dibujamos el fondo, asi evitamos que la pantalla se mueva
	for (int i = 27; i < 30; i++) {
		consolaSalida.gotoXY(0, i);
		for (int j = 0; j < 120; j++) {

			wcout << L"█";
		}
	}


	//dibujamos la parte de arriba
	for (int i = 0; i < 3; i++) {
		consolaSalida.gotoXY(0, i);
		for (int j = 0; j < 120; j++) {
			wcout << L"█";
		}
	}

	consolaSalida.cambiarColor(negro, grisOscuro);


	consolaSalida.gotoXY(0, 28);

	wcout << "		(z)Pedir carta - (x)Pasar - (c)Guardar Partida - (Esc)Salir";

	consolaSalida.cambiarColor(blanco);


}
void gestorGraficos::mostrarMano(mano &manoJugador, int pagina, bool esDealer) {
	carta cartaVacia;
	cartaVacia.voltear();


	if (!esDealer) {


		for (int i = 0; i < 4; i++) {

			carta *cartaJugador = &manoJugador.getCarta((pagina * 4) + i);

			if (cartaJugador->equivalente(cartaVacia)) {
				imprimirCarta(cartaVacia, (i * 5) + (i * 6) + 16, 20, true);
			}
			else {
				imprimirCarta(*cartaJugador, (i * 5) + (i * 6) + 16, 20);
			}


		}


		if (manoJugador.getCartas() > 4) {

			consolaSalida.gotoXY(0, 23);
			if (pagina != 0) {
				wcout << L"[ A / ← ] Atras";
			}
			else {
				wcout << "                ";
			}

			consolaSalida.gotoXY(60, 23);
			if (pagina != manoJugador.getCartas() / 4) {
				wcout << L"[ D / → ] Adelante";
			}
			else {
				wcout << "                  ";
			}



		}

	}
	else {
		for (int i = 0; i < 2; i++) {

			carta *cartaJugador = &manoJugador.getCarta((pagina * 2) + i);

			if (cartaJugador->equivalente(cartaVacia)) {
				imprimirCarta(cartaVacia, (i * 5) + (i * 6) + 96, 6, true);
			}
			else {
				imprimirCarta(*cartaJugador, (i * 5) + (i * 6) + 96, 6);
			}


		}


		if (manoJugador.getCartas() > 2) {

			consolaSalida.gotoXY(76, 8);
			if (pagina != 0) {
				wcout << "[ Q / <-] Atras";
			}
			else {
				wcout << "                ";
			}
			consolaSalida.gotoXY(76, 10);
			if (pagina != manoJugador.getCartas() / 2) {
				wcout << "[ E / ->] Adelante";
			}
			else {
				wcout << "                  ";
			}


		}

	}






}

void gestorGraficos::mostrarJugadoresSecundarios(listaJugador& jugadores, int pagina, int jugadorActual) {

	consolaSalida.cambiarColor(blanco);

	consolaSalida.gotoXY(4, 4);
	wcout << "Pagina #" << pagina + 1 << "   ";

	int insertados = 0;
	int posicion = (pagina*2);
	int fin = jugadores.insertados();

	while (insertados < 2 && posicion != fin) {
		if (posicion != 0 && posicion != jugadorActual) {
			mostrarJugadorSecundario(s2ws(jugadores.obtenerJugador(posicion).getNickname()), jugadores, posicion, ++insertados);
		}
		posicion++;
	}


	for (int i = 0; i < 2; i++) {
		int numeroJugador = (pagina * 2) + i;
	}


	if (jugadores.insertados() > 2) {

		consolaSalida.gotoXY(40, 6);
		if (pagina != 0) {
			wcout << L"[ W / ↑ ] Arriba";
		}
		else {
			wcout << "                ";
		}

		consolaSalida.gotoXY(40, 8);
		if (pagina != jugadores.insertados() / 2) {
			wcout << L"[ S / ↓ ] Abajo";
		}
		else {
			wcout << "                  ";
		}
	}

}

bool gestorGraficos::dialogoSalida() {

	consolaSalida.gotoXY(15, 28);
	consolaSalida.cambiarColor(negro, grisOscuro);
	wcout << "¿ Desea salir del Juego ?		(Q)Si.		(E)No.";
	for (int i = 0; i < 40; i++) {
		wcout << " ";
	}
	consolaSalida.cambiarColor(blanco);

	return eleccion();
}
bool gestorGraficos::dialogoSalto() {

	consolaSalida.gotoXY(15, 28);
	consolaSalida.cambiarColor(negro, grisOscuro);
	wcout << "¿ Desea pasar su turno ?		(Q)Si.		(E)No.";
	for (int i = 0; i < 40; i++) {
		wcout << " ";
	}
	consolaSalida.cambiarColor(blanco);

	return eleccion();

}
int gestorGraficos::dialogoCantidadJugadores() {






}



gestorGraficos::~gestorGraficos() {

	//revertimos todo al estado original
	consolaUnicode(false);						
	consolaSalida.mostrarCursor();

}










