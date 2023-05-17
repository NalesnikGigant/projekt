
#ifndef smokh
#define smokh
//#pragma once
//#include "klasy.h"
//#include "object.h"
#include "bohater.h"

class Smok : public Object
{
    friend class Bohater;
public:
    sf::Texture drake;
    Smok(int x);
    void spotkanie(Platforma makaron);
    void telepotracja();
    void ruszaj(sf::Time czas);
    void sp³oniêcie(Bohater& Kosc);
    friend class lose;
protected:
    int v_x = 50;
}; 

#endif