#include <iostream>
#include <chrono>
#include <thread>

#include "nodoCarta.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main(int argc, char const *argv[]){

    carta *c;
    carta *C;

    
    c=new carta(2,2);
    C=new carta(4,4);
    nodoCarta c1(*c);   
    nodoCarta c2(*C); 
    c1.setSiguiente(&c2);  
    delete c;
    delete C;
    

    



    cin.ignore();
    return 0;
}

