#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(Swiat& swiat) : Zwierze(0, 'H', 5, 4, swiat.getX()/2, swiat.getY()/2, swiat) {
    kierunek = 0;
    tarczaAlzura = 0;
    licznikTarczy = 0;
    cooldownTarczy = 0;
}

Czlowiek::Czlowiek(Swiat& swiat, int x, int y) : Zwierze(0, 'H', 5, 4, x, y, swiat) {
    kierunek = 0;
    tarczaAlzura = 0;
    licznikTarczy = 0;
    cooldownTarczy = 0;
}

std::string Czlowiek::toString() {
    return "czlowiek";
}

int Czlowiek::czyOdbilAtak(int x2, int y2) {
    if (tarczaAlzura) {
        return 2;
    }
    else {
        return 0;
    }
}

void Czlowiek::rozmnazaj(int x, int y) {

}

void Czlowiek::setKierunek(int k) {
    kierunek = k;
}

void Czlowiek::setTarcza(bool t) {
    tarczaAlzura = t;
}

bool Czlowiek::getTarcza() const {
    return tarczaAlzura;
}

int Czlowiek::getCooldownTarczy() const {
    return cooldownTarczy;
}

void Czlowiek::resetLicznikTarczy() {
    licznikTarczy = 0;
}


int Czlowiek::getKierunek() const{
    return kierunek;
}

void Czlowiek::kolizja(int x2, int y2) {
    Organizm* o = swiat.getOrganizm(x2, y2);
    if (czyOdbilAtak(x2, y2)==2&&o->czyZwierze()) {
        int tempX = x;
        int tempY = y;
        x = x2;
        y = y2;
        if (czyGdziekolwiekWolne()) {
            int kierunek;
            int nextX = x;
            int nextY = y;
            kierunek = rand() % 4;
            while (czyWolne(kierunek) != 1) {
                kierunek = rand() % 4;
            }
            switch (kierunek) {
            case 0:
                nextY -= 1;
                break;
            case 1:
                nextX += 1;
                break;
            case 2:
                nextY += 1;
                break;
            default:
                nextX -= 1;
                break;
            }
            rysowanie();
            swiat.usunOrganizm(tempX, tempY);
            swiat.wstawNaMape(o, nextX, nextY);
            o->setX(nextX);
            o->setY(nextY);
        }
        else {
            x = tempX;
            y = tempY;
        }
        swiat.dodajWydarzenieDoDziennika(toString() + " wkracza na pole (" + std::to_string(getX()) + "," + std::to_string(getY()) + ") wypychajac "+o->toString()+" za pomoca tarczy Alzura");
    }
    else {
        Zwierze::kolizja(x2, y2);
    }
}

void Czlowiek::obsluzTarczaAlzura() {
    if (tarczaAlzura == 1) {
        licznikTarczy++;
        if (licznikTarczy == 5) {
            swiat.dodajWydarzenieNaPoczatekDziennika("Tarcza Alzura przestaje dzialac");
            tarczaAlzura = 0;
            cooldownTarczy = 5;
        }
        else {
            swiat.dodajWydarzenieNaPoczatekDziennika("Tarcza Alzura aktywna");
        }
    }
    else {
        if (cooldownTarczy > 0) {
            cooldownTarczy--;
        }
        if (!(cooldownTarczy > 0)) {
            swiat.dodajWydarzenieNaPoczatekDziennika("Tarcza Alzura gotowa do uzycia");
        }
    }
}

void Czlowiek::akcja() {
    int move;
    move = 1;
    int nextX = x;
    int nextY = y;
    switch (kierunek) {
    case 0:
        nextY -= 1;
        break;
    case 1:
        nextX += 1;
        break;
    case 2:
        nextY += 1;
        break;
    default:
        nextX -= 1;
        break;
    }
    switch (czyWolne(kierunek)) {
    case 0:        
        break;
    case 1:
        swiat.usunOrganizm(x, y);
        x = nextX;
        y = nextY;
        wiek++;
        rysowanie();
        break;
    default:
        kolizja(nextX, nextY);
        wiek++;
        break;
    }
    obsluzTarczaAlzura();
}

Czlowiek::~Czlowiek() {
    swiat.czlowiekUmarl();
}