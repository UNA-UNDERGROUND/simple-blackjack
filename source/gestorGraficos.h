#pragma once

#include "gestorConsola.h"
#include "listaJugador.h"
#include "dealer.h"


using std::endl;

class gestorGraficos {
private:

	gestorConsola consolaSalida;


	void imprimirCarta(carta& ref, int x, int y, bool vacia = false);
	void dibujarLogo(int xLogo, int yLogo);
	void limpiarSector(int x1, int y1, int x2, int y2);
	void mostrarJugadorSecundario(wstring nick, listaJugador& jugadores, int ubicacion, int posicion);
	bool eleccion();																							//para reutilizar el codigo de eleccion si/no

public:
	gestorGraficos();


	int menuPrincipal();
	void mostrarMesa();
	void mostrarMano(mano &manoJugador, int pagina = 0, bool esDealer = false);
	void mostrarInfoUsuario(wstring nick, mano& manoJugador, bool esDealer = false);
	void mostrarJugadoresSecundarios(listaJugador& jugadores, int pagina,int actual);
	bool dialogoSalida();
	bool dialogoSalto();
	int dialogoCantidadJugadores();
	bool guardar();
	bool cargar();
	void mostrarMarcadores();



	~gestorGraficos();



};







