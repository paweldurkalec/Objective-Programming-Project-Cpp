/*
Sterowanie:
    q - nastepna tura
    strzalki - zmiana kierunku czlowieka
    w - aktywacja tarczy Alzura
    s - zapisanie rozgrywki
    r - wczytanie rozgrywki
    e - wyjscie
Organizmy:
    H - czlowiek
    W - wilk
    S - owca
    A - antylopa
    Z - zolw
    L - lis
    t - trawa
    g - guarana
    m - mlecz
    b - barszcz sosnowskiego
    j - wilcze jagody
Miejsce zapisu/odczytu:
    zapis.txt
*/

//organizmy rozmieszczane losowo(czlowiek(X/2,Y/2)), ilosc organizmow (wraz z czlowiekiem) na poczatku nie moze byc wieksza 
//niz ilosc dostepnych pol (X*Y), w innym wypadku symulacja sie nie uruchomi 
#define X 20
#define Y 20
#define ILOSCTRAWY 5
#define ILOSCBARSZCZOW 3
#define ILOSCGUARANY 10
#define ILOSCMLECZY 11
#define ILOSCWILCZYCHJAGOD 5
#define ILOSCLISOW 23
#define ILOSCWILKOW 11
#define ILOSCOWIEC 10
#define ILOSCZOLWI 5
#define ILOSCANTYLOP 3
#include <iostream>
#include "Swiat.h"

int main()
{
    Swiat swiat(X, Y, ILOSCTRAWY, ILOSCBARSZCZOW, ILOSCGUARANY, ILOSCMLECZY, ILOSCWILCZYCHJAGOD, ILOSCLISOW, ILOSCWILKOW, ILOSCOWIEC, ILOSCZOLWI, ILOSCANTYLOP);
    swiat.rysujSwiat();
    while (!swiat.getExit()) {
        swiat.wykonajTure();
    }
    return 0;
}
