#include "carta.h"



carta::carta(){
    codigo = 0;		//0 es nulo
    palo = 0;		//0 es nulo
    bocaAbajo = true;
}

// nota: los codigos y palos se manejan internamente iniciando por el 1,esto permite una mejor administracion,ademas el valor de 0 es para caso de error  

carta::carta(int codigo,int palo){
	this->codigo = codigo < 1 || codigo > 13 ? 0 : codigo;
	this->palo = palo < 1 || palo > 4 ? 0 : palo;
    this->bocaAbajo = true;
}
carta::carta(carta &ref){
    this->codigo = ref.codigo;
    this->palo = ref.palo;
    this->bocaAbajo = ref.bocaAbajo;
}


int carta::getcodigo(){
    return codigo;
}
int carta::getPalo(){
    return palo;
}
bool carta::revelada() {
	return !bocaAbajo;
}

void carta::voltear(){
    bocaAbajo=false;
}

//este metodo no verifica si esta boca abajo,solo verifica si coincide
bool carta::equivalente(carta &ref){
    return this->codigo == ref.codigo && this->palo == ref.palo;
}



carta::~carta(){
}
