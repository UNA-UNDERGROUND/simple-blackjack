#pragma once

#include "gestorConsola.h"
#include "jugador.h"


using std::endl;

class gestorGraficos {
private:

	gestorConsola consolaSalida;


	void gestorGraficos::imprimirCarta(carta& ref, int x, int y, bool vacia = false);
	void gestorGraficos::dibujarLogo(int xLogo, int yLogo);


public:
	gestorGraficos();


	int menuPrincipal();
	void mostrarMesa();
	void mostrarMano(mano &manoJugador, int pagina = 0);
	bool guardar();
	bool cargar();
	void mostrarMarcadores();


	~gestorGraficos();



};







