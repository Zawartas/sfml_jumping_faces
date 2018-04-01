#include "okno_gry.h"

okno_gry::okno_gry()
{
    setup_okna("Okno", sf::Vector2u(800,600));
}

okno_gry::okno_gry(const std::string &tytulOkna_string, const sf::Vector2u &rozmiarOkna_2u)
{
    setup_okna(tytulOkna_string, rozmiarOkna_2u);
}

okno_gry::~okno_gry()
{
    zamknij_okno();
}

void okno_gry::setup_okna(const std::string& tytulOkna_string, const sf::Vector2u& rozmiarOkna_2u)
{
    this->tytulOkna_string = tytulOkna_string;
    this->rozmiarOkna_2u = rozmiarOkna_2u;
    this->pelnyEkran_bool = false;
    this->oknoZamkniete_bool = false;
    stworz_okno(); //uruchamia render okna
}

void okno_gry::stworz_okno()
{
    auto styl_okna = (pelnyEkran_bool? sf::Style::Fullscreen : sf::Style::Default);
    oknoDoRysowania.create({rozmiarOkna_2u.x, rozmiarOkna_2u.y, 32}, tytulOkna_string, styl_okna);
    oknoDoRysowania.setFramerateLimit(60);
}

void okno_gry::zamknij_okno(){
    oknoDoRysowania.close();
}

void okno_gry::czekajNaZdarzenia()
{
    sf::Event zdarzenie;
    while (oknoDoRysowania.pollEvent(zdarzenie))
    {
        if(zdarzenie.type == sf::Event::Closed)
            oknoZamkniete_bool = true;
        else if (zdarzenie.type == sf::Event::KeyPressed &&
                 zdarzenie.key.code == sf::Keyboard::F5)
        {
            FullscreenOnOff();
        }
    }
}

void okno_gry::FullscreenOnOff()
{
    pelnyEkran_bool = !pelnyEkran_bool;
    zamknij_okno();
    stworz_okno();
}

void okno_gry::zacznijDraw()
{
    oknoDoRysowania.clear(sf::Color::Black);
}

void okno_gry::skonczDraw_i_Pokaz()
{
    oknoDoRysowania.display();
}

bool okno_gry::getCzyOknoZamkniete()
{
    return oknoZamkniete_bool;
}

bool okno_gry::getIsFullscreen()
{
    return pelnyEkran_bool;
}

sf::Vector2u okno_gry::getRozmiarOkna_2u()
{
    return rozmiarOkna_2u;
}

void okno_gry::narysuj_w_Oknie(sf::Drawable &v_obiekt)
{
    oknoDoRysowania.draw(v_obiekt);
}
