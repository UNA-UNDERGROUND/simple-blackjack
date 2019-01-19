# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.3)
project (BlackJack CXX)



set(CMAKE_CXX_STANDARD 14)

set(src  
	source/carta.cpp
    source/dealer.cpp
	source/gestorArchivo.cpp
	source/juego.cpp
    source/jugador.cpp
    source/jugadorGenerico.cpp
    source/listaCarta.cpp
    source/listaJugador.cpp
    source/mano.cpp
    source/mazo.cpp
    source/nodoCarta.cpp
    source/nodoJugador.cpp
    source/source.cpp
)


set(src2  
	source/carta.cpp
    source/dealer.cpp
	source/gestorArchivo.cpp
	source/gestorConsola.cpp
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
add_executable(BlackJackUI ${src2})



