#pragma once

#include "gestorConsola.h"
#include "listaJugador.h"
#include "dealer.h"


using std::endl;



class gestorGraficos {
private:

	int puntoX[4] = { 24,97,60,60 };
	int puntoY[4] = { 15,8,15,8 };


	color colorLuz = rojo;
	int puntosRestantes = 3; //detemina la longitud de una luz especifica


	gestorConsola consolaSalida;


	void imprimirCarta(carta& ref, int x, int y, bool vacia = false);

	void dibujarLogo(int xLogo, int yLogo);
	void animarLogo();																													//mueve una imagen la animacion del logo
	void limpiarSector(int x1, int y1, int x2, int y2);
	void mostrarJugadorSecundario(wstring nick, listaJugador& jugadores, int ubicacion, int posicion);
	bool eleccion();		
	bool animacionLogo(int& eleccion,int limite);																						//nos permite animar el logo y tambien obtener un resultado cuando este listo//para reutilizar el codigo de eleccion si/no

public:
	gestorGraficos();


	int menuPrincipal();
	void mostrarMesa();
	void mostrarMano(mano &manoJugador, int pagina = 0, bool esDealer = false);
	void mostrarInfoJugador(jugadorGenerico& jugadorActual, bool esDealer = false);
	void mostrarJugadoresSecundarios(listaJugador& jugadores, int pagina,int actual);
	void mostrarFinDelJuego(listaJugador& jugadores, int posicionGanador, bool empate);
	bool dialogoSalida();
	bool dialogoSalto();
	int dialogoCantidadJugadores();
	bool guardar();
	bool cargar();
	void mostrarMarcadores();



	~gestorGraficos();



};







