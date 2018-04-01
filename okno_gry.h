#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>

class okno_gry { //klasa okno gry
private:
    sf::RenderWindow oknoDoRysowania;
    bool oknoZamkniete_bool;
    bool pelnyEkran_bool;
    std::string tytulOkna_string;
    sf::Vector2u rozmiarOkna_2u;
    void setup_okna(const std::string&, const sf::Vector2u&);
    void zamknij_okno();
    void stworz_okno();

public:
    okno_gry();
    okno_gry(const std::string& tytulOkna_string, const sf::Vector2u&);
    ~okno_gry();
    void zacznijDraw();
    void skonczDraw_i_Pokaz();
    void czekajNaZdarzenia();
    bool getCzyOknoZamkniete();
    bool getIsFullscreen();
    sf::Vector2u getRozmiarOkna_2u();
    void FullscreenOnOff();
    void narysuj_w_Oknie(sf::Drawable&);
};

#endif // FUNCTIONS_H
