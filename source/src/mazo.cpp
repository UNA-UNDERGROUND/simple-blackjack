#include "mazo.h"

mazo::mazo(){
    this->Carta = new carta*[52];

    
    for(int i = 0; i < 52; i++){
        Carta[i] = nullptr;
    }
    

}
mazo::mazo(mazo &ref){
    this->Carta = new carta*[52];
    for(int i = 0; i < 52; i++){
        Carta[i] = ref.Carta[i] != nullptr ? new carta(*ref.Carta[i]) : nullptr;
    }
}

void mazo::inicializar(){

    //eliminamos las cartas anteriores
    for(int i = 0; i < 52; i++){
        //pueden existir cartas previamente eliminadas
        if ( this->Carta[i] != nullptr ) {
            delete Carta[i];
            Carta[i] = nullptr;
        } 
    }
    for(int i = 0; i < 52; i++){
        int codigo = ( i % 13 ) + 1;			//del 1 al 13
        int palo = ( ( i % 52 ) / 13 ) + 1;		//del 1 al 4
        Carta[i] = new carta(codigo,palo);
    }


}
void mazo::barajar(){    
	std::random_device dispositivoAleatorio;
	std::mt19937 generadorAleatorio(dispositivoAleatorio());
    std::shuffle( Carta, Carta + 52, generadorAleatorio);
}
carta* mazo::tomarCarta(){

    
    for(int i = 51; i >= 0; i--){
        
        if ( Carta[i] != nullptr ) {
            carta * c = new carta( *Carta[i] );   //creamos una carta nueva a partir de la que encontramos
            delete Carta[i];                      //eliminamos nuestra carta
            Carta[i] = nullptr;                   //asignamos un puntero nulo para su posterior reutilizacion
            return c;                             //retornamos el puntero de la copia de nuestra carta, nota: importante eliminar la instancia posteriormente
        }
        
    }
    return nullptr;                               // no hay mas cartas disponibles
}
void mazo::insertarCarta(carta ref) {

	for (int i = 0; i < 52; i++) {
		if (Carta[i] != nullptr) {
			Carta[i] = new carta(ref);
		}
	}

}


mazo::~mazo(){
    
    
    for(int i = 0; i < 52; i++){
        
        //pueden existir cartas previamente eliminadas
        if ( this->Carta[i] != nullptr ) {
            delete Carta[i];
            Carta[i] = nullptr;
        } 
    }
    delete [] Carta;

}

