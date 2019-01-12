#include <iostream>
#include "mazo.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main(int argc, char const *argv[]){

    mazo m;

    m.inicializar();
    m.barajar();


    cin.ignore();
    return 0;
}

