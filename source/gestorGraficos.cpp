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

	/*
	wcout << L"╔═══════╗";
	for (int i = 0; i < 5; i++) {
		consolaSalida.gotoXY(x, y + i + 1);
		wcout << L"║       ║";
	}
	consolaSalida.gotoXY(x, y + 6);
	wcout << L"╚═══════╝";
	*/
	

	dibujarRectangulo(x, y, x + 8, y + 6);


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
void gestorGraficos::dibujarRectangulo(int x1, int y1, int x2, int y2,bool rellenar) {

	//primero dibujamos los bordes

	consolaSalida.gotoXY(x1, y1);
	wcout << L"╔";
	consolaSalida.gotoXY(x2,y1);
	wcout << L"╗";
	consolaSalida.gotoXY(x1, y2);
	wcout << L"╚";
	consolaSalida.gotoXY(x2, y2);
	wcout << L"╝";

	//dibujamos los bordes superiores e inferiores
	for (int x = x1+1; x < x2; x++) {
		consolaSalida.gotoXY(x, y1);
		wcout << L"═";
		consolaSalida.gotoXY(x, y2);
		wcout << L"═";
	}
	//dibujamos los bordes laterales
	for (int y = y1 + 1; y < y2; y++) {
		consolaSalida.gotoXY(x1, y);
		wcout << L"║";
		consolaSalida.gotoXY(x2, y);
		wcout << L"║";
	}

	if (rellenar) {

		//es mas rapido dibujar caracteres contiguos
		for (int y = y1 + 1; y < y2; y++) {
			consolaSalida.gotoXY(x1 + 1, y);
			for (int x = x1 + 1; x < x2; x++) {
				wcout << " ";
			}
		}

	}


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
void gestorGraficos::animarLogo() {
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

void gestorGraficos::limpiarSector(int x1, int y1, int x2, int y2) {

	//limpiamos los contenidos anteriores

	for (int y = y1; y <= y2; y++) {
		consolaSalida.gotoXY(x1, y);
		for (int x = x1; x <= x2; x++) {
			wprintf(L" ");					//queremos limpiar la pantalla lo mas rapido posible y wprintf es mas sencillo que wcout,pero es más rapido
		}

	}




}
void gestorGraficos::limpiarPantalla() {
	consolaSalida.limpiarPantalla();
}



void gestorGraficos::mostrarInfoJugador(jugadorGenerico &jugadorActual, bool esDealer){
	consolaSalida.cambiarColor(negro, grisOscuro);

	if (!esDealer) {

		limpiarSector(2, 1, 60, 1);		//limpiamos los datos anteriores

		consolaSalida.gotoXY(2, 1);
		wcout << "Jugador Actual: " << s2ws(jugadorActual.getNickname());

		consolaSalida.gotoXY(30, 1);
		wcout << "puntuacion: " << jugadorActual.getMano()->getPuntos();

		consolaSalida.gotoXY(46, 1);
		wcout << "cartas: " << jugadorActual.getMano()->getCartas();
	}
	else {

		consolaSalida.gotoXY(80, 0);
		wcout << "Dealer :        " << s2ws(jugadorActual.getNickname());

		consolaSalida.gotoXY(80, 1);
		wcout << "puntuacion:     ";
		if (jugadorActual.getMano()->getCarta(1).revelada()) {
			wcout << jugadorActual.getMano()->getPuntos();
		}
		else {
			wcout << "?";
		}

		consolaSalida.gotoXY(80, 2);
		wcout << "cartas:         " << jugadorActual.getMano()->getCartas();



	}


	

	consolaSalida.cambiarColor(negro);

}

void gestorGraficos::mostrarJugadorSecundario(wstring nick, listaJugador& jugadores, int ubicacion,int posicion) {


	int posicionY = (2 * (posicion + 1)) + 4 * posicion; //ubicacion de la esquina*(posicion deseada)+separacion entre jugadoresSecundarios

	//limpiamos los campos antes de usarlos
	limpiarSector(4, posicionY, 60, posicionY + 5);
	//limpiarSector(4, 6, 60, 18);

	jugadorGenerico *Actual = jugadores.obtenerJugador(ubicacion);


	if (Actual != nullptr){
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


	int eleccion = 0;


	consolaSalida.gotoXY(0, 26);
	wcout << "controles:" << endl;
	wcout << "espacio:              seleccionar." << endl;
	wcout << "flecha arriba/w:      moverse arriba." << endl;
	wcout << "flecha abajo/s:       moverse abajo.";

	dibujarLogo(25, 9);

	do {
		consolaSalida.gotoXY(55, 18);
		if (eleccion == 0) {
			consolaSalida.cambiarColor(negro, gris);
		}
		wcout << " nueva  partida  ";
		consolaSalida.cambiarColor(blanco);
		consolaSalida.gotoXY(55, 19);


		if (eleccion == 1) {
			consolaSalida.cambiarColor(negro, gris);
		}
		wcout << "reanudar partida ";
		consolaSalida.cambiarColor(blanco);
		consolaSalida.gotoXY(55, 20);


		if (eleccion == 2) {
			consolaSalida.cambiarColor(negro, gris);
		}
		wcout << "   Marcadores    ";
		consolaSalida.cambiarColor(blanco);


		if (eleccion == 3) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, 21);

		wcout << "      Salir      ";
		consolaSalida.cambiarColor(blanco);

	} while (!animacionLogo(eleccion, 3));

	return eleccion;
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

	wcout << "		(z)Pedir carta - (x)Pasar - (c)Guardar Marcador - (Esc)Salir";

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

void gestorGraficos::mostrarJugadoresSecundarios(listaJugador& jugadores, int pagina) {

	int insertados = 0;
	int posicion = (pagina * 2);
	int fin = jugadores.insertados();

	consolaSalida.gotoXY(2, 3);
	consolaSalida.cambiarColor(blanco);

	wcout << "numero de jugadores: " << fin - 1;

	limpiarSector(4, 4, 60, 18);

	consolaSalida.gotoXY(4, 4);

	if (fin - 1 > 2) {
		wcout << "Pagina #" << pagina + 1 << "   ";
	}

	while (insertados < 2 && posicion != fin) {
		if (posicion != 0) {
			mostrarJugadorSecundario(s2ws(jugadores.obtenerJugador(posicion)->getNickname()), jugadores, posicion, ++insertados);
		}
		posicion++;
	}


	for (int i = 0; i < 2; i++) {
		int numeroJugador = (pagina * 2) + i;
	}


	if (jugadores.insertados() > 3) {

		consolaSalida.gotoXY(40, 6);
		if (pagina != 0) {
			wcout << L"[ W / ↑ ] Arriba";
		}
		else {
			wcout << "                ";
		}

		consolaSalida.gotoXY(40, 8);
		if (pagina < jugadores.insertados() / 2 && (jugadores.insertados() / 2 - pagina > 1)) { // la segunda comparacion determina si es una media pagina,(en caso de numeros impares como 3,5 7)
			wcout << L"[ S / ↓ ] Abajo";
		}
		else {
			wcout << "                  ";
		}
	}

	if (insertados < 2) {
		limpiarSector(4, 14, 60, 18);
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
void gestorGraficos::dialogoPasado() {

	consolaSalida.gotoXY(15, 28);
	consolaSalida.cambiarColor(negro, grisOscuro);
	wcout << "el Jugador se paso de 21 ó llego a 21, presione cualquier tecla para cambiar de turno";
	consolaSalida.cambiarColor(blanco);
	_getch();

}

int gestorGraficos::dialogoCantidadJugadores() {

	limpiarSector(55, 18, 80, 23);

	int eleccion = 0;

	do {

		int posicionInicial = 18;

		consolaSalida.gotoXY(55, posicionInicial++);
		if (eleccion == 0) {
			consolaSalida.cambiarColor(negro, gris);
		}
		wcout << "Atras        ";
		consolaSalida.cambiarColor(blanco);
		consolaSalida.gotoXY(55, posicionInicial++);


		if (eleccion == 1) {
			consolaSalida.cambiarColor(negro, gris);
		}
		wcout << "1 Jugador.   ";
		consolaSalida.cambiarColor(blanco);
		consolaSalida.gotoXY(55, posicionInicial++);


		if (eleccion == 2) {
			consolaSalida.cambiarColor(negro, gris);
		}
		wcout << "2 Jugadores. ";
		consolaSalida.cambiarColor(blanco);


		if (eleccion == 3) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, posicionInicial++);

		wcout << "3 Jugadores. ";
		consolaSalida.cambiarColor(blanco);

		if (eleccion == 4) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, posicionInicial++);

		wcout << "4 Jugadores. ";
		consolaSalida.cambiarColor(blanco);

		if (eleccion == 5) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, posicionInicial++);

		wcout << "5 Jugadores. ";
		consolaSalida.cambiarColor(blanco);

		if (eleccion == 6) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, posicionInicial++);

		wcout << "6 Jugadores. ";
		consolaSalida.cambiarColor(blanco);

		if (eleccion == 7) {
			consolaSalida.cambiarColor(negro, gris);
		}
		consolaSalida.gotoXY(55, posicionInicial);

		wcout << "7 Jugadores. ";




	} while (!animacionLogo(eleccion, 7));


	if (eleccion != 0) {
		//limpiarSector(0, 3, 120, 27);
		consolaSalida.limpiarPantalla();		//es mas rapido que limpiar un sector cuando el sector es bastante grande

	}

	return eleccion;
}

void gestorGraficos::mostrarFinDelJuego(listaJugador& jugadores, int posicionGanador, bool empate) {


	consolaSalida.limpiarPantalla();


	int cantidadJugadores = jugadores.insertados();

	jugadorGenerico *jugadorActual;
	for (int i = 0; i < cantidadJugadores; i++) {
		consolaSalida.gotoXY(2, 2 + i);
		jugadorActual = jugadores.obtenerJugador(i);
		wcout << s2ws(jugadorActual->getNickname()) << ", puntuación: " << jugadorActual->getPuntuacion();
	}
	consolaSalida.gotoXY(40, 2);


	if (empate) {
		wcout << "ocurrio un empate";
	}
	else {
		if (posicionGanador != 0) {
			wcout << "gano el jugador #" << posicionGanador;
		}
		else {
			wcout << "Gana la casa.";
		}

	}
	consolaSalida.gotoXY(40, 3);
	wcout << "con una puntuacion de: " << jugadores.obtenerJugador(posicionGanador)->getPuntuacion();
	




	dibujarRectangulo(1, 1, 30, cantidadJugadores + 2, false);
	dibujarRectangulo(38, 1, 70, 4, false);
	dibujarRectangulo(28, 26, 84, 28, false);
	dibujarRectangulo(74, 4, 118, 14, false);


	consolaSalida.gotoXY(30, 27);
	wcout << "   presione espacio para volver al menu de inicio";

	int pagina = 0;
	boton botonEleccion = boton::Desconocido;

	mostrarMano(*jugadores.obtenerJugador(0)->getMano(), pagina, true);

	do {

		//solo actualizamos la pagina del dealer cuando sea nescesario

		botonEleccion = capturarEntrada();
		switch (botonEleccion) {
		case Boton1:{	// Q
			if (pagina!= 0) {
				pagina--;
				mostrarMano(*jugadores.obtenerJugador(0)->getMano(), pagina, true);
			}
			break;
		}
		case Boton2:{	// E
			if (pagina != jugadores.obtenerJugador(0)->getMano()->getCartas() / 2) {
				pagina++;
				mostrarMano(*jugadores.obtenerJugador(0)->getMano(), pagina, true);
			}
			break;
		}

		default:
			break;
		}


	} while (botonEleccion != boton::Adelante);

}

bool gestorGraficos::animacionLogo(int& eleccion,int limite) {

	while (true) {

		int entrada = 0;

		auto future = std::async(std::launch::async, capturarEntrada);
		while (future.wait_for(std::chrono::milliseconds(75)) == std::future_status::timeout) {

			//durante este tiempo podemos realizar algo rapido como animar el titulo o cualquier otra tarea mientras no se realize una accion del usuario
			animarLogo();
		}

		entrada = future.get();

		switch (entrada) {
		case Arriba:
			if (eleccion != 0) {
				eleccion--;
			}
			else {
				eleccion = limite;
			}
			return false;
			break;
		case Abajo:
			if (eleccion != limite) {
				eleccion++;
			}
			else {
				eleccion = 0;
			}
			return false;
			break;

		case Adelante:
			//consolaSalida.limpiarPantalla();
			return true;
			break;
		default:
		{

			break;
		}
		}



	}


}


void gestorGraficos::mostrarMarcadores() {


	std::wfstream archivoMarcador("marcadores.txt", std::fstream::in);

	consolaSalida.cambiarColor(blanco);

	consolaSalida.limpiarPantalla();

	
	if (!archivoMarcador.is_open()) {
		wcout << "no se pudieron abrir los marcadores" << endl;
		_getch();
		return;
	}


	wstring linea;														//algunos caracteres son unicode, así que usaremos wstring,pero se puede usar string si no se usan signos 								
	while (!archivoMarcador.eof()) {
		std::getline(archivoMarcador, linea);
		wcout << linea << endl;
	}
	wcout << "fin de los marcadores guardados" << endl;
	_getch();


}

bool gestorGraficos::guardarMarcador(listaJugador& jugadores) {
	//creamos el archivo
	std::ofstream("marcadores.txt", std::fstream::app);
	//no tenemos que cerrarlo puesto que el se cierra solo al dejar de ser usado
	//sin embargo cuando escribamos en el es recomendable guardar inmediatamente  
	//ya que usualmente se realizan hasta que dejemos de usarlo
	//esto se puede hacer cerrandolo manualmente o usando std::flush

	//abrimos el archivo en entrada,salida y agregamos los contenidos, puesto que queremos agregar, no sobreescribir 
	std::fstream archivoMarcador("marcadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	if (!archivoMarcador.is_open()) {
		archivoMarcador.close();

		consolaSalida.gotoXY(15, 28);
		consolaSalida.cambiarColor(negro, grisOscuro);
		wcout << "                      no se pudo guardar el marcador                        ";
		consolaSalida.cambiarColor(blanco);

		_getch();
		return false;
	}

	jugadorGenerico* jugadorActual;
	int jugadoresActuales = jugadores.insertados();

	archivoMarcador << "---------------------------------------------------" << std::endl;
	archivoMarcador << "jugadores : " << jugadores.insertados() << std::endl;


	for (int i = 0; i < jugadoresActuales; i++) {
		archivoMarcador << "---------------------------------------------------" << std::endl;
		jugadorActual = jugadores.obtenerJugador(i);
		archivoMarcador << "nickname:   " << jugadorActual->getNickname() << std::endl;
		archivoMarcador << "puntuacion: " << jugadorActual->getPuntuacion() << std::endl;
		archivoMarcador << "cartas del jugador" << std::endl;
		archivoMarcador << "---------------------------------------------------" << std::endl;

		carta * cartaActual;
		mano * manoActual=jugadorActual->getMano();
		int cartas=jugadorActual->getMano()->getCartas();

		for (int posicionCarta = 0; posicionCarta < cartas; posicionCarta++) {
			cartaActual = &manoActual->getCarta(posicionCarta);
			string carta= ws2s(nombreCarta[cartaActual->getcodigo()]) + " de " + ws2s(nombrePalo[cartaActual->getPalo()]) + ",";
			archivoMarcador << carta;
		}
		archivoMarcador << endl;
		archivoMarcador << "---------------------------------------------------" << std::endl;
	}



	archivoMarcador.close();


	consolaSalida.gotoXY(15, 28);
	consolaSalida.cambiarColor(negro, grisOscuro);
	wcout << "                          marcador guardado exitosamente                ";
	consolaSalida.cambiarColor(blanco);

	_getch();
	return true;
}



gestorGraficos::~gestorGraficos() {

	//revertimos todo al estado original
	consolaUnicode(false);						
	consolaSalida.mostrarCursor();

}



