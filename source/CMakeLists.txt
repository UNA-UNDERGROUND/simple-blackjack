cmake_minimum_required (VERSION 3.8)

set(src_include
	include/carta.h
    include/dealer.h
	include/gestorConsola.h
	include/gestorGraficos.h
	include/juego.h
    include/jugador.h
    include/jugadorGenerico.h
    include/listaCarta.h
    include/listaJugador.h
    include/mano.h
    include/mazo.h
    include/nodoCarta.h
    include/nodoJugador.h
	include/utiles.h
)
set(src  
	src/carta.cpp
    src/dealer.cpp
	src/gestorConsola.cpp
	src/gestorGraficos.cpp
	src/juego.cpp
    src/jugador.cpp
    src/jugadorGenerico.cpp
    src/listaCarta.cpp
    src/listaJugador.cpp
    src/mano.cpp
    src/mazo.cpp
    src/nodoCarta.cpp
    src/nodoJugador.cpp
	src/utiles.cpp
)


add_executable(${PROJECT_NAME} ${src} ${src_include})
target_include_directories(${PROJECT_NAME} PRIVATE include())
