#include "gra_gameplay.h"
#include "okno_gry.h"
#include <iostream>

c_gra_gameplay::c_gra_gameplay(
        std::string napis,
        sf::Vector2u rozmiar_okna):
            okno_gry_STAS(napis, rozmiar_okna)
{

}

c_gra_gameplay::~c_gra_gameplay()
{

}

void c_gra_gameplay::dodajSprite(std::string plik, int j)
{
        sf::Texture tempT;
        if(tempT.loadFromFile(plik))
            textureObrazek.push_back(tempT);
        else
            std::cout << "Blad przy wczytywaniu tekstury\n: ";

        sf::Sprite tempS;
        tempS.setTexture(textureObrazek.back());
        spriteStas.push_back(tempS);

        increment.push_back(sf::Vector2i(j,j));
}

void c_gra_gameplay::updateGry()
{
    okno_gry_STAS.czekajNaZdarzenia();
    std::list<sf::Texture>::iterator itTex = textureObrazek.begin();
    std::list<sf::Sprite>::iterator itSpr = spriteStas.begin();
    std::list <sf::Vector2i>::iterator itInc = increment.begin();
    while (itTex != textureObrazek.end())
    {
        ruszStasiem(*itTex, *itSpr, *itInc);
        itTex++;
        itSpr++;
        itInc++;
    }
}

void c_gra_gameplay::ruszStasiem(sf::Texture texture, sf::Sprite& sprite, sf::Vector2i &incr){
    sf::Vector2u rozmiar_okna = okno_gry_STAS.getRozmiarOkna_2u();
    sf::Vector2u rozmiar_obrazka = texture.getSize();

    if ((sprite.getPosition().x >
    rozmiar_okna.x - rozmiar_obrazka.x && incr.x > 0) ||
    (sprite.getPosition().x < 0 && incr.x< 0)){
    incr.x = -incr.x;
    }
    if((sprite.getPosition().y >
    rozmiar_okna.y - rozmiar_obrazka.y && incr.y > 0) ||
    (sprite.getPosition().y < 0 && incr.y< 0)){
    incr.y = -incr.y;
    }

    float czas = czas_ktory_minal.asSeconds();

    sprite.setPosition(
    sprite.getPosition().x + incr.x*czas,
    sprite.getPosition().y + incr.y*czas);
}

void c_gra_gameplay::odbierzInput()
{

}

void c_gra_gameplay::renderujGrafike()
{
    okno_gry_STAS.zacznijDraw();
    for (std::list<sf::Sprite>::iterator it = spriteStas.begin();
         it != spriteStas.end(); it++)
        okno_gry_STAS.narysuj_w_Oknie(*it);
    okno_gry_STAS.skonczDraw_i_Pokaz();
}

okno_gry* c_gra_gameplay::wskaznik_na_okno_gry_STAS()
{
    return &okno_gry_STAS;
}


sf::Time c_gra_gameplay::get_czas_ktory_minal()
{
    return czas_ktory_minal;
}
void c_gra_gameplay::zrestartujCzas()
{
    czas_ktory_minal = zegar.restart();
    //restart zatrzymuje zegar i przypisuje
    //czas do czas_ktory_minal
}

