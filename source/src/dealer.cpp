#include "dealer.h"



dealer::dealer() {

}

string dealer::getNickname() {
	return "dealer";
}

void dealer::pedirCarta(mazo *m) {
	manoJugador->agregarCarta(m);
	//se giraran por defecto las cartas que no sean la segunda
	if (manoJugador->getCartas() != 2) {
		manoJugador->getCarta(manoJugador->getCartas() - 1).voltear();
	}
}


void dealer::volteaSegunta() {
	this->manoJugador->getCarta(1).voltear();
}

bool dealer::equivalente(string nickname) {
	return getNickname() == nickname;						//puede que un futuro querramos cambiar el nickname del dealer por lo que se evitaran modificaciones innecesarias
}



dealer::~dealer() {


}




