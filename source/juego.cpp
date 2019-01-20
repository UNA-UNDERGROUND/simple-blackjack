#include "juego.h"


juego::juego(){
	mazoCartas = nullptr;
	listaJugadores = nullptr;
}

void juego::pantallaJuego() {

	bool continuar = true;						//nos permite saber si queremos saltar el turno o salir del juego

	jugadorGenerico* jugadorActual;				//puntero hacia el jugador que posee el turno actual
	jugadorGenerico* Dealer;


	Dealer = &listaJugadores->obtenerJugador(0);

	//primera capa de la interfaz grafica
	gestorPantalla.mostrarMesa();

	//mostramos la mano del dealer
	gestorPantalla.mostrarMano(*Dealer->getMano(), paginaDealer, true);
	gestorPantalla.mostrarInfoUsuario(s2ws(Dealer->getNickname()), *Dealer->getMano(), true);


	//el dealer es el primero en la lista, por lo tanto se inicia desde el turno de los datos guardados (#1 si es un juego nuevo)
	for (int turnoActual = turnoJugador; (turnoActual <= jugadores) && (continuar); turnoActual++) {

		jugadorActual = &listaJugadores->obtenerJugador(turnoActual);

		gestorPantalla.mostrarInfoUsuario(s2ws(jugadorActual->getNickname()), *jugadorActual->getMano());
		gestorPantalla.mostrarMano(*jugadorActual->getMano(), pagina);


		gestorPantalla.mostrarJugadoresSecundarios(*listaJugadores, paginaJugadores, turnoActual);


		boton botonEleccion = boton::Desconocido;
		do {


			botonEleccion = capturarEntrada();
			switch (botonEleccion) {
			case Izquierda:
				if (pagina != 0) {
					pagina--;
					gestorPantalla.mostrarMano(*jugadorActual->getMano(), pagina);
				}
				break;
			case Derecha:
				if (pagina != jugadorActual->getMano()->getCartas() / 4) {
					pagina++;
					gestorPantalla.mostrarMano(*jugadorActual->getMano(), pagina);
				}
				break;
			case Arriba:
				if (paginaJugadores != 0) {
					paginaJugadores--;
					gestorPantalla.mostrarJugadoresSecundarios(*listaJugadores, paginaJugadores, turnoActual);
				}
				break;
			case Abajo:
				if (paginaJugadores != jugadores / 2) {
					paginaJugadores++;
					gestorPantalla.mostrarJugadoresSecundarios(*listaJugadores, paginaJugadores, turnoActual);
				}
				break;
			case Boton1:	// Q
				if (paginaDealer != 0) {
					paginaDealer--;
					gestorPantalla.mostrarInfoUsuario(s2ws(Dealer->getNickname()), *Dealer->getMano(), true);
				}
				break;
			case Boton2:	// E
				if (paginaDealer != jugadorActual->getMano()->getCartas() / 4) {
					paginaDealer++;
					gestorPantalla.mostrarInfoUsuario(s2ws(Dealer->getNickname()), *Dealer->getMano(), true);
				}
				break;

			case Boton3:	// Z
				break;

			case Boton4:
			{	// X - saltar partida

				if (!gestorPantalla.dialogoSalto()) {
					botonEleccion = boton::Desconocido;

				}
				else {
					botonEleccion = boton::Atras; // cambiar de turno
				}

				gestorPantalla.mostrarMesa();
				gestorPantalla.mostrarInfoUsuario(s2ws(jugadorActual->getNickname()), *jugadorActual->getMano());
				gestorPantalla.mostrarInfoUsuario(s2ws(Dealer->getNickname()), *Dealer->getMano(), true);


				break;
			}
			case Boton5:	// C
				break;
			case Atras:

				if (!gestorPantalla.dialogoSalida()) {
					botonEleccion = boton::Desconocido; // esto evitara que salgamos del programa
					gestorPantalla.mostrarMesa();
					gestorPantalla.mostrarInfoUsuario(s2ws(jugadorActual->getNickname()), *jugadorActual->getMano());
					gestorPantalla.mostrarInfoUsuario(s2ws(Dealer->getNickname()), *Dealer->getMano(), true);
				}
				else {
					continuar = false;
				}


				break;
			default:
				break;
			}

		} while (botonEleccion != boton::Atras);


	}


	//verificamos si se deseaba salir, o simplemente es el turno del dealer
	if (continuar) {





	}

}


void juego::jugar() {

	int eleccion = 0;
	do {
		eleccion = gestorPantalla.menuPrincipal();

		switch (eleccion) {

			//nueva partida
		case 0:{

			//inicializaremos todos los datos y luego llamamos a la pantalla del juego

			//eliminamos los datos previos y creamos nuevos datos limpios
			if (mazoCartas != nullptr) {
				delete mazoCartas;
			}
			if (listaJugadores != nullptr) {
				delete listaJugadores;
			}

			mazoCartas = new mazo();
			listaJugadores = new listaJugador();


			// agregamos nuevas cartas y las barajamos el mazo
			mazoCartas->inicializar();
			mazoCartas->barajar();

			//insertamos siempre al dealer de primero 
			listaJugadores->insertarFin(*(new dealer()));


			listaJugadores->insertarFin(*(new jugador("The only one")));

			for (int i = 0; i < jugadores; i++) {

				stringstream s;
				s << "Persival#" << i;
				listaJugadores->insertarFin(*(new jugador(s.str())));
			}





			//le damos 2 cartas a cada jugador, el primer jugador(#0) es el dealer y el oculta su segunda carta
			for (int i = 0; i <= jugadores; i++) {
				listaJugadores->obtenerJugador(i).pedirCarta(mazoCartas);
				listaJugadores->obtenerJugador(i).pedirCarta(mazoCartas);
			}

			turnoJugador = 1;//el primer jugador es el #1 ya que el dealer es el #0


			//ahora podemos mostrar la pantalla del juego puesto que todos los datos ya estan preparados
			pantallaJuego();

			break;
		}

		

		default:

			break;
		}

	} while (eleccion != 3);


	return;
}

juego::~juego(){
	if (mazoCartas!=nullptr) {
		delete mazoCartas;
	}
	if (listaJugadores != nullptr) {
		delete listaJugadores;
	}
}

