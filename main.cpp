#include "okno_gry.h"
#include "gra_gameplay.h"
#include <iostream>

int main(){

    c_gra_gameplay GRA("Gra", sf::Vector2u(800, 600));

    GRA.dodajSprite("DS_1.png", 300);
    GRA.dodajSprite("Slavko_1.png", 200);
    GRA.dodajSprite("Simon.png", 50);
    GRA.dodajSprite("Mysza.png", 90);


    while (!GRA.wskaznik_na_okno_gry_STAS()->getCzyOknoZamkniete())
    {
        GRA.odbierzInput();//nic nie robi
        GRA.updateGry();
        GRA.renderujGrafike();
        GRA.zrestartujCzas();
    }

return 0;
}
