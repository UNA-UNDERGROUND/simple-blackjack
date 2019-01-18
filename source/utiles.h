
#include <Windows.h> //la mayoria de estas funciones requieren la libreria de windows,pero tambien se pueder portear a linux o unix de ser necesario
#include "carta.h"

//utiles: aqui se encontraran fragmentos de codigo para la interfaz grafica
//
// las funciones fueron basadas en los siguientes recursos
//
// gotoxy extraido de:								https://www.aulavirtual.una.ac.cr/mod/resource/view.php?id=302651
// color  basado en:								https://stackoverflow.com/questions/9203362/c-color-text-in-terminal-applications-in-windows
// las definiciones de colores estan basadas en:	https://stackoverflow.com/questions/17125440/c-win32-console-color
// : https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt


// 
// definiciones de colores, notese que estan limitados a 8 colores,pero son 16 por la intentencidad,tambien al ser codigos hexadecimales pueden ser combinados con un o lógico
// o desplazarlos para cambiar entre fondo y texto,pero notese que son hexadecimales y no binarios por lo tanto deben de ser desplazados 4 bits y no uno
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


// cambia la posicion del cursor (consola) a la ubicacion indicada en coordenadas 2D 
void gotoXY(int x, int y) {
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadas);
}


//en esta funcion no ocupamos restaurar los colores a diferiencia de la original
void cambiarColor(color texto, color fondo){

	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);							//a diferiencia de gotoxy aqui usaremos el puntero de la consola mas veces
											
	SetConsoleTextAttribute(consola, texto | (fondo << 4));

}

//nos permite mostrar/ocultar el cursor, por defecto lo muestra
void mostrarCursor(bool mostrarCursor = true){
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     infoCursor;						//almacena la informacion del cursor

	GetConsoleCursorInfo(consola, &infoCursor);				//obtenemos la información del cursor
	infoCursor.bVisible = mostrarCursor;							//cambiamos el estado
	SetConsoleCursorInfo(consola, &infoCursor);				//guardamos los cambios
}

