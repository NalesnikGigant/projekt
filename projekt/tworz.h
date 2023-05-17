#ifndef tworzh
#define tworzh
//#pragma once

//#include "bohater.h"
#include "smok.h"
//#include "object.h"

class Tworz : public Object {
public:
    friend class Bohater;
    friend class Smok;
    friend class Platforma;
    Tworz(sf::RenderWindow& okno, sf::Time czas, sf::Clock clock, Object f);
};
#endif // !1
