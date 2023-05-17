//#include "klasy.h"


#ifndef objecth
#define objecth
//#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <vector>
#include <chrono>
#include <thread>

class Object : public sf::Sprite {
public:
    void ruszaj() {}
    bool gra();
    int punkt = 5;
};

class Platforma : public Object {
private:
    sf::Texture blat;
public:
    Platforma(int x, int y);
};

#endif