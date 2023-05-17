#include "tworz.h"
Tworz::Tworz(sf::RenderWindow &okno, sf::Time czas, sf::Clock clock, Object f) {
    czas = clock.getElapsedTime();
    std::vector<std::unique_ptr<sf::Drawable>> zagiel;
    zagiel.emplace_back(std::make_unique<Bohater>());
    for (int i = 0; i < 5; i++) {zagiel.emplace_back(std::make_unique<Smok>(i)); }
    for (int i = 0; i < 8; i++) {zagiel.emplace_back(std::make_unique<Platforma>(150 * i, 70 * i));}
    for (auto& x : zagiel) {
        okno.draw(*x);
        Bohater z = dynamic_cast<Bohater&>(*x);
        z.granice();
        for (auto &rec : zagiel) {
            Platforma kox = dynamic_cast<Platforma*>(*rec);
            z.skok(kox);
            z.ruszaj(czas, kox);
            z.zatrzymaj(kox);
            z.wygrana(f);
        }
        for (auto& rec : zagiel) {
            //okno.draw(*rec);
            Smok& obw = dynamic_cast<Smok&>(*rec);
            obw.telepotracja();
            obw.ruszaj(czas);
            for (auto& rec : zagiel) {
                Platforma& kox = dynamic_cast<Platforma&>(*rec);
                obw.spotkanie(kox);
            }
            obw.sp³oniêcie(z);
        }
        //for (auto& hok : zagiel) {
        //    //window.draw(*hok);
        //    Platforma& kox = dynamic_cast<Platforma&>(*hok);
        //}

        /*for (auto& rec : zagiel) {
            Platforma& kox = dynamic_cast<Platforma&>(*rec);
            Kosc.skok(kox);
            Kosc.ruszaj(czas, kox);
            Kosc.zatrzymaj(kox);
        }*/
        czas = clock.restart();
    }
}