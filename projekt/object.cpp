#include "object.h"

bool Object::gra() {
    int x = Object::punkt;

    if (x > 1) { return true; }
    else if (x < 1) { return false; }
}

Platforma::Platforma(int x, int y) {
    sf::Texture blat;
    if (!blat.loadFromFile("wall.png")) { std::cerr << "Could not load texture" << std::endl; }
    this->setTexture(blat);
    setScale(0.6f, 0.2f);
    setPosition(float((200 + x) % 1000), float(550 - y));
}