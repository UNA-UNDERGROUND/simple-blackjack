
#include <Windows.h> //la mayoria de estas funciones requieren la libreria de windows,pero tambien se pueder portear a linux o unix de ser necesario


//utiles: aqui se encontraran fragmentos de codigo para la interfaz grafica
//
// las funciones fueron basadas en ls
//
// https://www.aulavirtual.una.ac.cr/mod/resource/view.php?id=302651



void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	//GetStdHandle(STD_OUTPUT_HANDLE)metodo de la windows que me permite ubicar a la consola en un lugar y coord es el objeto con los valores
}




