#include "utiles.h"



// cambia la posicion del cursor (consola) a la ubicacion indicada en coordenadas 2D 
void gotoXY(HANDLE salidaConsola, int x, int y) {
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(salidaConsola, coordenadas);
}


//en esta funcion no ocupamos restaurar los colores a diferiencia de la original,tambien elige por defecto fondo negro
void cambiarColor(HANDLE salidaConsola, color texto, color fondo = negro) {
	SetConsoleTextAttribute(salidaConsola, texto | (fondo << 4));
}

//nos permite mostrar/ocultar el cursor, por defecto lo muestra
void mostrarCursor(HANDLE salidaConsola, bool mostrarCursor = true) {

	CONSOLE_CURSOR_INFO     infoCursor;								//almacena la informacion del cursor
	GetConsoleCursorInfo(salidaConsola, &infoCursor);				//obtenemos la información del cursor
	infoCursor.bVisible = mostrarCursor;							//cambiamos el estado
	SetConsoleCursorInfo(salidaConsola, &infoCursor);				//guardamos los cambios
}


void imprimirCarta(carta& ref, int x, int y) {
	std::wstring simbolo;

	//nos dirigimos a la posicion inicial
	gotoXY(x, y);

	//cambiamos a modo unicode
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"╔═══════╗";
	for (int i = 0; i < 5; i++) {
		gotoXY(x, y + i + 1);
		wcout << L"║       ║";
	}
	gotoXY(x, y + 6);
	wcout << L"╚═══════╝";


	if (ref.revelada()) {
		//nos dirigimos al centro
		gotoXY(x + 4, y + 3);
		//verificar el rango y escoger el color del simbolo
		int palo = ref.getPalo();
		if (palo < 1 || palo > 4) {
			cambiarColor(amarillo, negro);
		}
		else {
			if (palo > 2) {
				cambiarColor(rojo, negro);
			}
			else {
				cambiarColor(gris, negro);
			}
		}

		wcout << simboloPalo[ref.getPalo()];


		cambiarColor(celeste, negro);
		gotoXY(x + 7, y + 5);
		wcout << nombreCarta[ref.getcodigo()];
		gotoXY(x + 1, y + 1);
		wcout << nombreCarta[ref.getcodigo()];
	}
	else {
		for (int i = 1; i < 6; i++) {
			gotoXY(x + 1, y + i);
			cambiarColor(verde);

			wcout << L"░░░░░░░";


		}

		gotoXY(x + 1, y + 1);
	}




	_setmode(_fileno(stdout), _O_TEXT);

	cambiarColor(blanco, negro);
}
