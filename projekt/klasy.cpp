#include "klasy.h"
//tworz platformê
//Platforma::Platforma(int x, int y) {
//    sf::Texture blat;
//    if (!blat.loadFromFile("wall.png")) { std::cerr << "Could not load texture" << std::endl; }
//    this->setTexture(blat);
//    setScale(0.6f, 0.2f);
//    setPosition((200 + x) % 1000, 550 - y);
//}
//twórz bohatera
//bohater::bohater() {
//    if (!boh.loadFromFile("bohater1.png")) { std::cerr << "Could not load texture" << std::endl; }
//    this->setTexture(boh);
//    setPosition(10, 600 - getGlobalBounds().height);
//
//}
////poruszaj bohatera: W-skok; grawitacja do do³u okna; D-w prawo; A - w lewo;
//void bohater::ruszaj(sf::Time czas, Platforma makaron) {
//    sf::FloatRect swistoklik = this->getGlobalBounds();
//    sf::FloatRect spagetti = makaron.getGlobalBounds();
//    //while (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//    //    switch ( {
//    //        move(0, -50 * czas.asSeconds());
//    //        case (getPosition().y >= spagetti.top + swistoklik.height * 2) {
//    //            return 0;
//    //        }
//    //    }
//    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ((swistoklik.top + 2 * swistoklik.height) >= 600 ||
//    //        (swistoklik.top + 2 * swistoklik.height) >= spagetti.top)) {
//    //        /*setPosition(getPosition().x, getPosition().y - swistoklik.height );*/
//    //        move(0, -50 * czas.asSeconds());
//    //    }
//    //}
//    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ setScale(1,0.5); }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { setScale(1, 1); setPosition(getPosition().x, getPosition().y + swistoklik.height / 2.f); }*/
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (swistoklik.top > spagetti.top + 2 * swistoklik.height && swistoklik.top >spagetti.top &&
//        (swistoklik.left - swistoklik.width > spagetti.left) || (swistoklik.left + swistoklik.width > spagetti.left + spagetti.width)
//            || (swistoklik.top+swistoklik.height > 0))) {
//        move(0, -50 * czas.asSeconds());
//    }
//    if ((swistoklik.top + swistoklik.height) <= 600)
//        this->move(0, 10 * czas.asSeconds());
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//        move({ v_x * czas.asSeconds(), 0.f });
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//        move({ -v_x * czas.asSeconds(), 0.f });
//    }
//}
////zatrzymuj siê na górze platformy; nie przechodŸ przez dó³ platformy
//void bohater::skok(Platforma makaron) {
//    sf::FloatRect swistoklik = getGlobalBounds();
//    sf::FloatRect spagetti = makaron.getGlobalBounds();
//    if (swistoklik.top + swistoklik.height >= spagetti.top && swistoklik.left + swistoklik.width >= spagetti.left &&
//        swistoklik.top + swistoklik.height <= spagetti.top + 5 && swistoklik.left <= spagetti.left + spagetti.width)
//    {
//        setPosition(getPosition().x, makaron.getPosition().y - swistoklik.height);
//    }
//}
////nie przechodŸ przez boczne granice platformy
//void bohater::zatrzymaj(Platforma makaron) {
//    sf::FloatRect swistoklik = getGlobalBounds();
//    sf::FloatRect spagetti = makaron.getGlobalBounds();
//    if (swistoklik.top + swistoklik.height >= spagetti.top - 10 && spagetti.top > swistoklik.top &&
//        swistoklik.left + swistoklik.width >= spagetti.left && swistoklik.left + swistoklik.width <= spagetti.left + 10)
//    {
//        setPosition(spagetti.left - swistoklik.width, getPosition().y);
//    }
//    if (swistoklik.top + swistoklik.height >= spagetti.top - 10 && spagetti.top > swistoklik.top &&
//        swistoklik.left <= spagetti.left + spagetti.width && swistoklik.left + 10 >= spagetti.left + spagetti.width)
//    {
//        setPosition(spagetti.left + spagetti.width, getPosition().y);
//    }
//}
////teleportuj siê przez boczne granice na drug¹ stronê
//void bohater::granice() {
//    sf::FloatRect swistoklik = this->getGlobalBounds();
//    if (swistoklik.left < 0) { this->setPosition(1000 - swistoklik.width, this->getPosition().y); }
//    else if (swistoklik.width + swistoklik.left > 1000) { this->setPosition(0, this->getPosition().y); }
//}
////jeœli wyskoczysz poza górn¹ granicê: wygrywasz; tworzy siê kolejne okno z napise, "You win";
//void bohater::wygrana(Object f) {
//    if (f.gra() == 0) {
//        sf::RenderWindow okno(sf::VideoMode(600, 600), "PSiO wymiata", sf::Style::Titlebar | sf::Style::Close);
//        while (okno.isOpen()) {
//            sf::Event event;
//            while (okno.pollEvent(event)) {
//                if (event.type == sf::Event::Closed)
//                    okno.close();
//            }
//            okno.clear(sf::Color::Black);
//            lose cos;
//            okno.draw(cos);
//        }
//    }
//    sf::FloatRect swistoklik = getGlobalBounds();
//    if (swistoklik.top + swistoklik.height <= 0) {
//        sf::RenderWindow okno(sf::VideoMode(600, 600), "PSiO wymiata", sf::Style::Titlebar | sf::Style::Close);
//        while (okno.isOpen()) {
//            sf::Event event;
//            while (okno.pollEvent(event)) {
//                if (event.type == sf::Event::Closed)
//                    okno.close();
//            }
//            sf::Texture X;
//            if (!X.loadFromFile("youwin.png")) { std::cerr << "Could not load texture" << std::endl; }
//            Sprite Y;
//            Y.setTexture(X);
//            Y.setScale(okno.getSize().x / X.getSize().x, okno.getSize().y / X.getSize().y);
//            okno.draw(Y);
//            okno.display();
//        }
//        std::cout << "You win";
//    }
//
//}
//tworzy smoka
//smok::smok(int x) {
//    if (!drake.loadFromFile("szcz.png")) { std::cerr << "Could not load texture" << std::endl; }
//    this->setTexture(drake);
//    setScale(0.4f, 0.4f);
//    setPosition(100 * (1 + x), 100 * x);
//}
//// zawracaj przy kolizji z platform¹
//void smok::spotkanie( Platforma makaron) {
//    sf::FloatRect spagetti = makaron.getGlobalBounds();
//    if (this->getGlobalBounds().contains(makaron.getPosition().x, makaron.getPosition().y)) 
//    { v_x = -v_x; setPosition(getPosition().x - 1, getPosition().y); }
//    if (this->getGlobalBounds().contains(makaron.getPosition().x + spagetti.width, makaron.getPosition().y))
//    {
//        v_x = -v_x; setPosition(getPosition().x + 1, getPosition().y);
//    }
//}
////teleportuj smoka na drug¹ stronê planszy przy kolizji z krañcem planszy
//void smok::telepotracja() {
//    sf::FloatRect dziobak = this->getGlobalBounds();
//    if (dziobak.left  > 1000) { this->setPosition(0 - dziobak.width+10, this->getPosition().y); }
//    else if (dziobak.left + dziobak.width < 0) { this->setPosition(1000-10 /*- dziobak.width*/, this->getPosition().y); }
//}
////poruszaj na osi X
//void smok::ruszaj(sf::Time czas) { move((v_x)*czas.asSeconds(), 0); }
////jesli Koœciuszko- boahter- spotka smoka, ustaw go na pocz¹tku
//void smok::sp³oniêcie(bohater& Kosc) {
//    sf::FloatRect nightfury = getGlobalBounds();
//    sf::FloatRect swistoklik = Kosc.getGlobalBounds();
//    if (swistoklik.top <= nightfury.top + nightfury.height && swistoklik.top + swistoklik.height >= nightfury.top &&
//        swistoklik.left <= nightfury.left + nightfury.height && swistoklik.left + swistoklik.height >= nightfury.left)
//    {
//        Object::punkt--;
//        std::cout << "nie dzia³am";  Kosc.setPosition(10, 600 - Kosc.getGlobalBounds().height);
//    }
//}
//bool Object::gra() {
//    int x = Object::punkt;
//
//    if (x > 1) { return true; }
//    else if (x < 1) { return false; }
//}

//Tworz::Tworz(sf::RenderWindow &okno, sf::Time czas, sf::Clock clock, Object f) {
//    czas = clock.getElapsedTime();
//    std::vector<std::unique_ptr<sf::Drawable>> zagiel;
//    zagiel.emplace_back(std::make_unique<Bohater>());
//    for (int i = 0; i < 5; i++) {zagiel.emplace_back(std::make_unique<Smok>(i)); }
//    for (int i = 0; i < 8; i++) {zagiel.emplace_back(std::make_unique<Platforma>(150 * i, 70 * i));}
//    for (auto& x : zagiel) {
//        okno.draw(*x);
//        Bohater& z = dynamic_cast<Bohater&>(*x);
//        z.granice();
//        for (auto& rec : zagiel) {
//            Platforma& kox = dynamic_cast<Platforma&>(*rec);
//            z.skok(kox);
//            z.ruszaj(czas, kox);
//            z.zatrzymaj(kox);
//            z.wygrana(f);
//        }
//        for (auto& rec : zagiel) {
//            //okno.draw(*rec);
//            Smok& obw = dynamic_cast<Smok&>(*rec);
//            obw.telepotracja();
//            obw.ruszaj(czas);
//            for (auto& rec : zagiel) {
//                Platforma& kox = dynamic_cast<Platforma&>(*rec);
//                obw.spotkanie(kox);
//            }
//            obw.sp³oniêcie(z);
//        }
//        //for (auto& hok : zagiel) {
//        //    //window.draw(*hok);
//        //    Platforma& kox = dynamic_cast<Platforma&>(*hok);
//        //}
//
//        /*for (auto& rec : zagiel) {
//            Platforma& kox = dynamic_cast<Platforma&>(*rec);
//            Kosc.skok(kox);
//            Kosc.ruszaj(czas, kox);
//            Kosc.zatrzymaj(kox);
//        }*/
//        czas = clock.restart();
//    }
//}
Win::Win() {
    if (!ween.loadFromFile("youwin.png")) { std::cerr << "Could not load texture" << std::endl; }
    this->setTexture(ween);
    setPosition(10, 600 - getGlobalBounds().height);
}
Lose::Lose() {
    if (!los.loadFromFile("youwin.png")) { std::cerr << "Could not load texture" << std::endl; }
    this->setTexture(los);
    setPosition(10, 600 - getGlobalBounds().height);
}
