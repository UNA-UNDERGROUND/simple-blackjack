#include "juego.h"


juego::juego(){
	baraja = nullptr;
	listaJugadores = nullptr;
	dealer = nullptr;
}

void juego::jugar() {




	return;
	/*
	jugador Jugador("abc");

	string resp, nick2;
	int nick;

	cout << "Bienvenido al juego Blackjack" << endl;
	cout << "Cuantas personas van a jugar" << endl;
	cin >> nick;
	if (nick > 7) {
		cout << "no se pueden mas de 7 jugadores" << endl;
	}
	for (int i = 0; i <= nick; i++)
	{
		cout << "registrese un nickname" << endl;
		cin >> nick2;
		listJugadores.insertarInicio(jugador(nick2));
	}

	cout << "El juego se iniciara" << endl;
	system("cls");
	baraja->inicializar();//se inicializa el mazo
	baraja->barajar();//se baraja

	for (int i = 0; i < nick; i++)
	{
		//Jugador->pedirCarta(baraja);
		//Jugador->pedirCarta(baraja);
	}
	//puntuacion aqui debe de estar

	dealer->pedirCarta(baraja);//aqui el dealer pide 2 cartas
	dealer->pedirCarta(baraja);

	mano = listJugadores.obtenerJugador(nick).getMano();//para que las manos coincidan con jugador

	for (int i = 0; i < mano->getCartas(); i++) {
		carta cart(mano->getCarta(i));//carta actual
		cout << "" << i + 1 << endl;
		cout << "codigo:" << cart.getcodigo() << endl;
		cout << "palo" << cart.getPalo() << endl;
	}


	while (true)
	{
		system("cls");

		for (int i = 0; i < mano->getCartas(); i++) {
			carta cart(mano->getCarta(i));//carta actual
			cout << "" << i + 1 << endl;
			cout << "codigo:" << cart.getcodigo() << endl;
			cout << "palo" << cart.getPalo() << endl;
		}
		int puntuacion = mano->getPuntos();
		cout << "Puntuacion" << puntuacion << endl;
		if (puntuacion < 21)
		{
			cout << "desea pedir mas cartas?" << endl;
			cin >> resp;
			if (resp == "si")
			{
				//Jugador->pedirCarta(baraja);
			}
			else {
				break;

			}
		}
		else
		{
			cout << "el jugador se paso" << endl;
			system("pause");
			break;
		}

		if (resp == "no")//si todos responden que no pues el dealer le dara vuelta
		{
			dealer->volteaSegunta();
		}

		if (Jugador.getPuntuacion() > dealer->getPuntuacion())
		{
			cout << "Has ganado" << endl;
		}

		if (Jugador.getPuntuacion() < dealer->getPuntuacion())
		{
			cout << "Has perdido" << endl;
		}

		if (Jugador.getPuntuacion() == dealer->getPuntuacion())
		{
			cout << "Has empatado" << endl;
		}

	}

	*/

}

juego::~juego(){
	if (baraja!=nullptr) {
		delete baraja;
	}
	if (listaJugadores != nullptr) {
		delete listaJugadores;
	}
	if (dealer != nullptr) {
		delete dealer;
	}
}

