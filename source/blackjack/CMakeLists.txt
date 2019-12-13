cmake_minimum_required (VERSION 3.8)


set(src_include_graficos
    include/gestorConsola.h
    include/gestorGraficos.h
)
set(src_graficos
    src/gestorConsola.cpp
    src/gestorGraficos.cpp
)

set(src_include
    ${src_include_graficos}
	include/carta.h
    include/dealer.h
	include/juego.h
    include/jugador.h
    include/jugadorGenerico.h
    include/mano.h
    include/mazo.h
    include/utiles.h

)
set(src
    ${src_graficos}
	src/carta.cpp
    src/dealer.cpp
	src/juego.cpp
    src/jugador.cpp
    src/jugadorGenerico.cpp
    src/mano.cpp
    src/mazo.cpp
    src/utiles.cpp
    
    src/source.cpp
)


add_executable(${PROJECT_NAME} ${src} ${src_include})
target_include_directories(${PROJECT_NAME} PRIVATE include())

if (UNIX)
    find_package (Threads)
    target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

endif()

