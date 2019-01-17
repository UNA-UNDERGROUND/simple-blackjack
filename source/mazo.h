#pragma once
// En el juego se utiliza una baraja inglesa de 52 cartas. 
// Las 52 cartas se dividen en 4 palos 
// 2 de color rojo y 2 de color negro
// la distribucion es:
// espadas (negro)
// corazones (rojo) 
// diamantes (rojo)
// tréboles (negro)
// el orden de las cartas por mazo es:
//                      ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦══════╦══════╦══════╦══════╦═════╗
// orden fisico:        ║  A  ║  2  ║  3  ║  4  ║  5  ║  6  ║  7  ║  8  ║  9  ║  10  ║  J   ║  Q   ║  K   ║  ?  ║
//                      ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬══════╬══════╬══════╬══════╬═════╣
// orden logico:        ║  1  ║  2  ║  3  ║  4  ║  5  ║  6  ║  7  ║  8  ║  9  ║  10  ║  11  ║  12  ║  13  ║ 0/? ║
//                      ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬══════╬══════╬══════╬══════╬═════╣ 
//  valor de la carta:  ║ 1-11║  2  ║  3  ║  4  ║  5  ║  6  ║  7  ║  8  ║  9  ║  10  ║  10  ║  10  ║  10  ║  0  ║
//                      ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩══════╩══════╩══════╩══════╩═════╝ 
//  notese que una carta con valor indefinido tiene un valor de 0,esto es en caso de un error critico al generar o procesar cartas,
//  aunque tambien puede ser vista como una medida extra ya que estas cartas no tienen valor alguno y se ignoran
//
// y el orden lógico de los palos es:
//                 ╔═══════════╦═══════════╦═══════════╦═══════════╦═══════════╗
//    palo:        ║  espadas  ║  tréboles ║ corazones ║ diamantes ║     ?     ║ 
//                 ╠═══════════╬═══════════╬═══════════╬═══════════╬═══════════╣  
//    numero:      ║     1     ║     2     ║     3     ║     4     ║    0/?    ║ 
//                 ╚═══════════╩═══════════╩═══════════╩═══════════╩═══════════╝ 
// esto permite identificar la primera mitad como negro y la otra como rojo, y cualquier otro valor como indefinido
//
//
// para barajar el mazo es necesario que sea aleatorio,pero que no sea tan predecible por lo que lo ideal es 
// tomar la secuencia de cartas y rotarlas,pero no puede ser rand() ya que suele ser muy predecible,
// y para no aumentar la complejidad del algoritmo se busca separarlo en una parte que reordena una lista 
// y otra que se encarga de reacomodarlos (o de ser posible todo en el mismo lugar)
// segun esos valores
// los ejemplos buscados para lograr el objetivo de una mejor aleatorizacion se encuentran en los siguientes enlaces
//
// std::random_shuffle:				 https://en.cppreference.com/w/cpp/algorithm/random_shuffle
// std::shufle						 http://www.cplusplus.com/reference/algorithm/shuffle/
// mezclar una secuencia:            https://stackoverflow.com/questions/18085633/c-generating-random-numbers-without-repetition-output-screen-is-just-blank-wi
// generador de numeros aleatorios:  https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
//
// 
#include "carta.h"
#include <algorithm>	//nos permite usar std::shuffle random
#include <random>		//nos permite una generacion aleatoria mas eficaz



class mazo{
private:
    carta **Carta;
public:
    mazo();
    mazo(mazo &ref);
    void inicializar();
    void barajar();
    carta *tomarCarta();
    ~mazo();
};








