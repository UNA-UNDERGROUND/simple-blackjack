#include "dealer.h"



dealer::dealer() {
	nickname = "Dealer";
}
void dealer::volteaSegunta() {
	this->manoJugador->getCarta(1).voltear();
}
dealer::~dealer() {


}




