# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.3)
project (BlackJack)


set(CMAKE_CXX_STANDARD 14)

set(src 
    source/source.cpp
    source/nodoCarta.cpp
    source/listaCarta.cpp
    source/nodoJugador.cpp
    source/listaJugador.cpp
    source/mano.cpp
    source/mazo.cpp
    source/carta.cpp
    source/jugador.cpp
    source/dealer.cpp
    source/jugadorGenerico.cpp
)

add_executable(${PROJECT_NAME} ${src})



