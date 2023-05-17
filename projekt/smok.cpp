#include "smok.h"
Smok::Smok(int x) {
    if (!drake.loadFromFile("szcz.png")) { std::cerr << "Could not load texture" << std::endl; }
    this->setTexture(drake);
    setScale(0.4f, 0.4f);
    setPosition(100 * (1 + x), 100 * x);
}
// zawracaj przy kolizji z platform¹
void Smok::spotkanie(Platforma makaron) {
    sf::FloatRect spagetti = makaron.getGlobalBounds();
    if (this->getGlobalBounds().contains(makaron.getPosition().x, makaron.getPosition().y))
    {
        v_x = -v_x; setPosition(getPosition().x - 1, getPosition().y);
    }
    if (this->getGlobalBounds().contains(makaron.getPosition().x + spagetti.width, makaron.getPosition().y))
    {
        v_x = -v_x; setPosition(getPosition().x + 1, getPosition().y);
    }
}
//teleportuj smoka na drug¹ stronê planszy przy kolizji z krañcem planszy
void Smok::telepotracja() {
    sf::FloatRect dziobak = this->getGlobalBounds();
    if (dziobak.left > 1000) { this->setPosition(0 - dziobak.width + 10, this->getPosition().y); }
    else if (dziobak.left + dziobak.width < 0) { this->setPosition(1000 - 10 /*- dziobak.width*/, this->getPosition().y); }
}
//poruszaj na osi X
void Smok::ruszaj(sf::Time czas) { move((v_x)*czas.asSeconds(), 0); }
//jesli Koœciuszko- boahter- spotka smoka, ustaw go na pocz¹tku
void Smok::sp³oniêcie(Bohater& Kosc) {
    sf::FloatRect nightfury = getGlobalBounds();
    sf::FloatRect swistoklik = Kosc.getGlobalBounds();
    if (swistoklik.top <= nightfury.top + nightfury.height && swistoklik.top + swistoklik.height >= nightfury.top &&
        swistoklik.left <= nightfury.left + nightfury.height && swistoklik.left + swistoklik.height >= nightfury.left)
    {
        Object::punkt--;
        std::cout << "nie dzia³am";  Kosc.setPosition(10, 600 - Kosc.getGlobalBounds().height);
    }
}