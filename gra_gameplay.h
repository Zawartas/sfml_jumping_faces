#ifndef GRA_GAMEPLAY_H
#define GRA_GAMEPLAY_H

#include "okno_gry.h"
#include <list>


class c_gra_gameplay{
private:
    okno_gry okno_gry_STAS;
    std::list<sf::Texture> textureObrazek;
    std::list<sf::Sprite> spriteStas;
    std::list <sf::Vector2i> increment;
    sf::Clock zegar;
    sf::Time czas_ktory_minal;
    void ruszStasiem(sf::Texture texture, sf::Sprite& sprite, sf::Vector2i &incr);

public:
    c_gra_gameplay(std::string, sf::Vector2u);
    ~c_gra_gameplay();

    void dodajSprite(std::string, int);
    void odbierzInput();//poki co nic
    void updateGry();
    void renderujGrafike();
    okno_gry* wskaznik_na_okno_gry_STAS();//

    sf::Time get_czas_ktory_minal();
    void zrestartujCzas();
};

#endif // GRA_GAMEPLAY_H
