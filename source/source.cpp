#include <iostream>

#include "nodoCarta.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main(int argc, char const *argv[]){

    carta *c=new carta(2,2);
    nodoCarta c1(*c);      


    cin.ignore();
    return 0;
}

