//#ifndef bohaterh
//#define bohaterh
#pragma once
#include "klasy.h"
//#include "object.h"

class Bohater : public Object{
private:
    int v_x = 25;
    int v_y = 0;
public:
    friend class Platforma;
    sf::Texture boh;
    Bohater();
    void ruszaj(sf::Time czas, Platforma makaron);
    void skok(Platforma makaron);
    void zatrzymaj(Platforma makaron);
    void granice();
    void wygrana(Object& f);
    //void x() { move(v_x, v_y); }

};

//#endif