#pragma once

#ifdef WIN32
	#include <Windows.h>			// la mayoria de estas funciones requieren la libreria de windows,pero tambien se pueder portear a linux o unix de ser necesario
	#include <io.h>					// nos permite cambiar el modo de la consola
	#include <conio.h>				// getch
#endif
#include <fcntl.h>				// nos permite cambiar a modo unicode

#include <iostream>
#include <chrono>
#include <future>
#include <string>

#include <codecvt>
#include <string>

using std::string;
using std::wstring;			//variante estandar de string
using std::wcout;			//variante estandar de cout

//utiles: aqui se encontraran fragmentos de codigo para la interfaz grafica
//
// las funciones fueron basadas en los siguientes recursos
//
// gotoxy extraido de:								https://www.aulavirtual.una.ac.cr/mod/resource/view.php?id=302651
// color  basado en:								https://stackoverflow.com/questions/9203362/c-color-text-in-terminal-applications-in-windows
// las definiciones de colores estan basadas en:	https://stackoverflow.com/questions/17125440/c-win32-console-color
// remover cursor basado de :						https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
// uso de _getch() obtenido de:						https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/getch-getwch?view=vs-2017
// getch con flechas :								https://stackoverflow.com/questions/10463201/getch-and-arrow-codes
// limpart pantalla extraido de :					https://support.microsoft.com/en-us/help/99261/how-to-performing-clear-screen-cls-in-a-console-application
// lectura en segundo plano extraido y badado de:	https://gist.github.com/vmrob/ff20420a20c59b5a98a1
//													http://www.cplusplus.com/reference/future/future/wait_for/
// s2ws basado en :									https://stackoverflow.com/questions/4804298/how-to-convert-wstring-into-string



enum entradas {
	arriba = 72,
	abajo = 80,
	izquierda = 75,
	derecha = 77,
	Q = 'q',
	E = 'e',
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd',
	Z = 'z',
	X = 'x', 
	C = 'c',
	escape = 27,
	intro = 32,
	esc = 13,
};
enum boton {
	Arriba,
	Abajo,
	Derecha,
	Izquierda,
	Boton1,		// q
	Boton2,		// e
	Boton3,		// z
	Boton4,		// x
	Boton5,		// c
	Atras,
	Adelante,
	Desconocido
};

// 
// definiciones de colores, notese que estan limitados a 8 colores,pero son 16 por la intentencidad,tambien al ser codigos hexadecimales pueden ser combinados con un o lógico
// o desplazarlos para cambiar entre fondo y texto,pero notese que son hexadecimales y no binarios por lo tanto deben de ser desplazados 4 bits y no uno

#ifdef WIN32
enum color {
	negro			= 0,
	azulOscuro		= FOREGROUND_BLUE,
	verdeOscuro		= FOREGROUND_GREEN,
	celesteOscuro	= FOREGROUND_GREEN | FOREGROUND_BLUE,
	rojoOscuro		= FOREGROUND_RED,
	fucsiaOscuro	= FOREGROUND_RED | FOREGROUND_BLUE,
	amarilloOscuro	= FOREGROUND_RED | FOREGROUND_GREEN,
	grisOscuro		= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	gris			= FOREGROUND_INTENSITY,
	azul			= FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	verde			= FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	celeste			= FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	rojo			= FOREGROUND_INTENSITY | FOREGROUND_RED,
	fucsia			= FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	amarillo		= FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	blanco			= FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};
#else
enum color{
	rojo
};
#endif

#ifdef WIN32
void consolaUnicode(bool activada = true);
#endif

boton capturarEntrada();


wstring s2ws(string ref);
string ws2s(wstring ref);

