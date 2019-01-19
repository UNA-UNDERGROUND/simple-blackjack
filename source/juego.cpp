#include "juego.h"

juego::juego()
{
	baraja = new mazo();
}

juego::~juego()
{

}

void juego::jugar()
{
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
		listJuga.insertarInicio(jugador(nick2));
	}

	cout << "El juego se iniciara" << endl;
	system("cls");
	baraja->inicializar();//se inicializa el mazo
	baraja->barajar();//se baraja

	for (int i = 0; i < nick; i++)
	{
		juga->pedirCarta(baraja);
		juga->pedirCarta(baraja);
	}
	//puntuacion aqui debe de estar

	deal->pedirCarta(baraja);//aqui el dealer pide 2 cartas
	deal->pedirCarta(baraja);

	man = listJuga.obtenerJugador(nick).getMano();//para que las manos coincidan con jugador

	for (int i = 0; i < man->getCartas(); i++) {
		carta cart(man->getCarta(i));//carta actual
		cout << "" << i + 1 << endl;
		cout << "codigo:" << cart.getcodigo() << endl;
		cout << "palo" << cart.getPalo() << endl;
	}


	while (true)
	{
		system("cls");

		for (int i = 0; i < man->getCartas(); i++) {
			carta cart(man->getCarta(i));//carta actual
			cout << "" << i + 1 << endl;
			cout << "codigo:" << cart.getcodigo() << endl;
			cout << "palo" << cart.getPalo() << endl;
		}
		int puntuacion = man->getPuntos();
		cout << "Puntuacion" << puntuacion << endl;
		if (puntuacion < 21)
		{
			cout << "desea pedir mas cartas?" << endl;
			cin >> resp;
			if (resp == "si")
			{
				juga->pedirCarta(baraja);
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
			deal->volteaSegunta();
		}

		if (juga->getPuntuacion() > deal->getPuntuacion())
		{
			cout << "Has ganado" << endl;
		}

		if (juga->getPuntuacion() < deal->getPuntuacion())
		{
			cout << "Has perdido" << endl;
		}

		if (juga->getPuntuacion() == deal->getPuntuacion())
		{
			cout << "Has empatado" << endl;
		}

	}
}