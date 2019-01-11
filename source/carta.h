


class carta{
protected:
int valor;
int palo;
bool bocaAbajo;


public:
    carta();
    carta(int valor,int palo,bool bocaAbajo);
    carta(carta & ref);
    
    void voltear();

    int getValor();
    int getPalo();
    
    ~carta();
};


