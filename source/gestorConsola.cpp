#include "gestorConsola.h"


gestorConsola::gestorConsola() {
	salidaConsola = GetStdHandle(STD_OUTPUT_HANDLE);
}


// cambia la posicion del cursor (consola) a la ubicacion indicada en coordenadas 2D 
void gestorConsola::gotoXY(int x, int y) {
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(salidaConsola, coordenadas);
}


//en esta funcion no ocupamos restaurar los colores a diferiencia de la original,tambien elige por defecto fondo negro
void gestorConsola::cambiarColor(color texto, color fondo) {
	SetConsoleTextAttribute(salidaConsola, texto | (fondo << 4));
}

//nos permite mostrar/ocultar el cursor, por defecto lo muestra
void gestorConsola::mostrarCursor(bool mostrarCursor) {

	CONSOLE_CURSOR_INFO     infoCursor;								//almacena la informacion del cursor
	GetConsoleCursorInfo(salidaConsola, &infoCursor);				//obtenemos la información del cursor
	infoCursor.bVisible = mostrarCursor;							//cambiamos el estado
	SetConsoleCursorInfo(salidaConsola, &infoCursor);				//guardamos los cambios
}

/* Standard error macro for reporting API errors */


void gestorConsola::limpiarPantalla() {
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
}


gestorConsola::~gestorConsola() {
}


