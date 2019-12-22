#include "gestorConsola.h"

#ifndef WIN32
	struct COORD{
		int X=0;
		int Y=0;
	};
#endif


gestorConsola::gestorConsola() {
	#ifdef WIN32
	salidaConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	#endif
	/*
	wchar_t *screen = new wchar_t[120 * 30];
	salidaConsola = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(salidaConsola);
	*/

}


// cambia la posicion del cursor (consola) a la ubicacion indicada en coordenadas 2D 
void gestorConsola::gotoXY(int x, int y) {
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	#ifdef WIN32
	SetConsoleCursorPosition(salidaConsola, coordenadas);
	#endif
}

#ifdef WIN32
//en esta funcion no ocupamos restaurar los colores a diferiencia de la original,tambien elige por defecto fondo negro
void gestorConsola::cambiarColor(ccolor_t texto, ccolor_t fondo) {
	SetConsoleTextAttribute(salidaConsola, texto | (fondo << 4));
}


//nos permite mostrar/ocultar el cursor, por defecto lo muestra
void gestorConsola::mostrarCursor(bool mostrarCursor) {

	CONSOLE_CURSOR_INFO     infoCursor;								//almacena la informacion del cursor
	GetConsoleCursorInfo(salidaConsola, &infoCursor);				//obtenemos la informaci�n del cursor
	infoCursor.bVisible = mostrarCursor;							//cambiamos el estado
	SetConsoleCursorInfo(salidaConsola, &infoCursor);				//guardamos los cambios
}

#endif


void gestorConsola::limpiarPantalla() {
	#ifdef WIN32
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
										cursor */
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize;                 /* number of character cells in
										the current buffer */

										/* get the number of character cells in the current buffer */

	bSuccess = GetConsoleScreenBufferInfo(salidaConsola, &csbi);

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */

	bSuccess = FillConsoleOutputCharacter(salidaConsola, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);


	/* get the current text attribute */

	bSuccess = GetConsoleScreenBufferInfo(salidaConsola, &csbi);


	/* now set the buffer's attributes accordingly */

	bSuccess = FillConsoleOutputAttribute(salidaConsola, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);


	/* put the cursor at (0, 0) */

	bSuccess = SetConsoleCursorPosition(salidaConsola, coordScreen);
	return;
	#endif
}

#ifdef WIN32
void gestorConsola::setConsola(HANDLE consola) {
	salidaConsola = consola;
}
HANDLE gestorConsola::getConsola() {
	return salidaConsola;
}

#endif



gestorConsola::~gestorConsola() {
}


