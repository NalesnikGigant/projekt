//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <stdlib.h> 
//#include <time.h>
//#include <random>
//#include <vector>
//#include <chrono>
//#include <thread>

//#ifndef klasyh
//#define klasyh
#pragma once
//#include "tworz.h"
//#include "bohater.h"
//#include "smok.h"
#include "object.h"
//class Object : public sf::Sprite {
//public:
//    void ruszaj() {}
//    bool gra();
//    int punkt = 5;
//};
//class Platforma : public Object {
//private:
//    sf::Texture blat;
//public:
//    Platforma(int x, int y);
//};
//class bohater : public object {
//public:
//    sf::Texture boh;
//    bohater();
//    void ruszaj(sf::Time czas, platforma makaron);
//    void skok(platforma makaron);
//    void zatrzymaj(platforma makaron);
//    void granice();
//    void wygrana(object f);
//private:
//    int v_x = 25;
//};
//class sok : public object {
//public:
//    sf::Texture drake;
//    smok(int x);
//    void spotkanie(platforma makaron);
//    void telepotracja();
//    void ruszaj(sf::Time czas);
//    void sp³oniêcie(bohater& Kosc);
//    friend class lose;
//protected:
//    int v_x = 50;
//};
//class Tworz : public Bohater {
//public:
//    friend class Smok;
//    friend class Platforma;
//    Tworz(sf::RenderWindow &okno, sf::Time czas, sf::Clock clock, Object f);
//};
class Win : public Object {
public:
    sf::Texture ween;
    Win();
};
class Lose : public Object {
public:
    sf::Texture los;
    Lose();
};

//#endif