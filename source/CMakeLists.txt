cmake_minimum_required (VERSION 3.8)

set(src_include
	include/carta.cpp
    include/dealer.cpp
	include/gestorArchivo.cpp
	include/gestorConsola.cpp
	include/gestorGraficos.cpp
	include/gestorMarcadores.cpp
	include/juego.cpp
    include/jugador.cpp
    include/jugadorGenerico.cpp
    include/listaCarta.cpp
    include/listaJugador.cpp
    include/mano.cpp
    include/mazo.cpp
    include/nodoCarta.cpp
    include/nodoJugador.cpp
    include/ui.cpp
	include/utiles.cpp

)
set(src  
	src/carta.cpp
    src/dealer.cpp
	src/gestorArchivo.cpp
	src/gestorConsola.cpp
	src/gestorGraficos.cpp
	src/gestorMarcadores.cpp
	src/juego.cpp
    src/jugador.cpp
    src/jugadorGenerico.cpp
    src/listaCarta.cpp
    src/listaJugador.cpp
    src/mano.cpp
    src/mazo.cpp
    src/nodoCarta.cpp
    src/nodoJugador.cpp
    src/ui.cpp
	src/utiles.cpp
)

target_include_directories(src_include)
add_executable(${PROJECT_NAME} ${src} ${src_include})