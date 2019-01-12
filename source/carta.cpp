#include "carta.h"



carta::carta(){
    codigo = 0;
    palo = 0;
    bocaAbajo = true;
}

carta::carta(int codigo,int palo,bool bocaAbajo){
    this->codigo = codigo;
    this->palo = palo;
    this->bocaAbajo = bocaAbajo;
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
void carta::voltear(){
    bocaAbajo=false;
}


carta::~carta(){
}
