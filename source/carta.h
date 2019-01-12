class carta{
private:
    int codigo;
    int palo;
    bool bocaAbajo;


public:
    carta();
    carta(int codigo,int palo,bool bocaAbajo);
    carta(carta & ref);
    
    void voltear();

    int getcodigo();
    int getPalo();
    
    ~carta();
};


