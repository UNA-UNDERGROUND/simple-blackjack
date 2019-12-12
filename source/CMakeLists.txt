cmake_minimum_required (VERSION 3.8)

set(src  
	source/carta.cpp
    source/dealer.cpp
	source/gestorArchivo.cpp
	source/gestorConsola.cpp
	source/gestorGraficos.cpp
	source/gestorMarcadores.cpp
	source/juego.cpp
    source/jugador.cpp
    source/jugadorGenerico.cpp
    source/listaCarta.cpp
    source/listaJugador.cpp
    source/mano.cpp
    source/mazo.cpp
    source/nodoCarta.cpp
    source/nodoJugador.cpp
    source/ui.cpp
	source/utiles.cpp
)


add_executable(${PROJECT_NAME} ${src})