#include "carta.h"

carta::carta(){
    valor = 0;
    palo = 0;
    bocaAbajo = true;
}

carta::carta(int valor,int palo,bool bocaAbajo){
    this->valor = valor;
    this->palo = palo;
    this->bocaAbajo = bocaAbajo;
}
carta::carta(carta &ref){
    this->valor = ref.valor;
    this->palo = ref.palo;
    this->bocaAbajo = ref.bocaAbajo;
}


int carta::getValor(){
    return valor;
}
int carta::getPalo(){
    return palo;
}
void carta::voltear(){
    bocaAbajo=false;
}


carta::~carta()
{
}
