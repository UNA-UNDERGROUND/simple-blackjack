#include "nodoCarta.h"


nodoCarta::nodoCarta(carta &ref){
    //copiaremos la carta
    actual=new carta(ref);
    siguiente=nullptr;
}
void nodoCarta::setSiguiente(nodoCarta *siguiente){
    this->siguiente = siguiente;
}
nodoCarta* nodoCarta::getSiguiente(){
    return siguiente;
}


nodoCarta::~nodoCarta(){
    
    if ( actual != nullptr ) {
        delete actual;
        actual = nullptr;
    }
    siguiente = nullptr;
    
}


