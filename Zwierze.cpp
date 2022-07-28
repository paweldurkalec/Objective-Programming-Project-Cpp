#include <iostream>
#include <stdlib.h>
#include <time.h>       
#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(int minMiedzyRozmnazaniami, char c, int sila, int inicjatywa, int x, int y, Swiat& swiat) : Organizm(c, sila, inicjatywa, x, y, swiat), minMiedzyRozmnazaniami(minMiedzyRozmnazaniami){
	odOstatniegoRozmnazania = 0;
}

bool Zwierze::czyTruje(Organizm* oa) {
	return 0;
}

bool Zwierze::czyDajeSile(Organizm* oa) {
	return 0;
}

int Zwierze::czyOdbilAtak(int x2, int y2) {
	return 0;
}

bool Zwierze::czyUcieka() {
	return 0;
}

void Zwierze::rysowanie() {
	swiat.wstawNaMape(this, x, y);
}

bool Zwierze::czyZwierze() {
	return 1;
}

void Zwierze::zwiekszCzasOdostatniegoRozmnazania() {
	odOstatniegoRozmnazania++;
}

void Zwierze::szukajMiejscaDoRozrodu() {
	if (odOstatniegoRozmnazania >= minMiedzyRozmnazaniami) {
		if (Zwierze::czyGdziekolwiekWolne()) {
			odOstatniegoRozmnazania = 0;
			int kierunek = rand() % 4;
			int newX = x;
			int newY = y;
			while (!(Zwierze::czyWolne(kierunek) == 1)) {
				kierunek = rand() % 4;
			}
			switch (kierunek) {
			case 0:
				newY -= 1;
				break;
			case 1:
				newX += 1;
				break;
			case 2:
				newY += 1;
				break;
			default:
				newX -= 1;
				break;
			}
			swiat.dodajWydarzenieDoDziennika(toString()+" rozmnozyly sie na ("+std::to_string(getX())+","+ std::to_string(getY())+")");
			rozmnazaj(newX, newY);
		}
	}
}

void Zwierze::kolizja(int x2, int y2) {
	Organizm* drugiOrganizm = swiat.getOrganizm(x2, y2);
	int newX = drugiOrganizm->getX();
	int newY = drugiOrganizm->getY();
	if (drugiOrganizm->getC() == this->getC()) {
		if (odOstatniegoRozmnazania >= minMiedzyRozmnazaniami) {
			odOstatniegoRozmnazania = 0;
			Zwierze* zw = (Zwierze*)drugiOrganizm;
			zw->szukajMiejscaDoRozrodu();
		}
		return;
	}
	if (drugiOrganizm->czyOdbilAtak(x, y)==1) {
		swiat.dodajWydarzenieDoDziennika(drugiOrganizm->toString() + " odbil atak "+ toString() +" na (" + std::to_string(drugiOrganizm->getX()) + "," + std::to_string(drugiOrganizm->getY()) + ")");
		return;
	}
	else if (drugiOrganizm->czyOdbilAtak(x, y) == 2) {
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
			swiat.usunOrganizm(tempX, tempY);
			x = nextX;
			y = nextY;
			rysowanie();
		}
		else {
			x = tempX;
			y = tempY;
		}
		swiat.dodajWydarzenieDoDziennika(drugiOrganizm->toString() + " wykorzystal tarcze Alzura i odbil atak " + toString() + " na (" + std::to_string(drugiOrganizm->getX()) + "," + std::to_string(drugiOrganizm->getY()) + ")");
		return;
	}
	if (drugiOrganizm->czyTruje(this)) {
		swiat.dodajWydarzenieDoDziennika(toString() + " zjadl trujace " + drugiOrganizm->toString() + " na (" + std::to_string(drugiOrganizm->getX()) + "," + std::to_string(drugiOrganizm->getY()) + ")");
		return;
	}
	if(drugiOrganizm->czyDajeSile(this)) {
		swiat.dodajWydarzenieDoDziennika(toString() + " otrzymal sile, zjadajac " + drugiOrganizm->toString() + " na (" + std::to_string(drugiOrganizm->getX()) + "," + std::to_string(drugiOrganizm->getY()) + ")");
	}
	if (drugiOrganizm->czyUcieka()) {
		swiat.usunOrganizm(x, y);
		x = newX;
		y = newY;
		rysowanie();
		return;
	}
	if (drugiOrganizm->getSila() <= getSila()) {
		swiat.usunOrganizm(newX, newY);
		swiat.usunOrganizm(x, y);
		x = newX;
		y = newY;
		swiat.dodajWydarzenieDoDziennika(toString() + " pokonal " + drugiOrganizm->toString() + " na (" + std::to_string(drugiOrganizm->getX()) + "," + std::to_string(drugiOrganizm->getY()) + ")");
		rysowanie();
	}
	else {
		swiat.usunOrganizm(x, y);
		swiat.dodajWydarzenieDoDziennika(drugiOrganizm->toString() + " pokonal " + toString() + " na (" + std::to_string(drugiOrganizm->getX()) + "," + std::to_string(drugiOrganizm->getY()) + ")");
	}
	return;
}

void Zwierze::akcja() {
	int kierunek;
	int nextX = x;
	int nextY = y;
	kierunek = rand() % 4;
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
		this->akcja();
		break;
	case 1:
		swiat.usunOrganizm(x, y);
		x = nextX;
		y = nextY;
		wiek++;
		odOstatniegoRozmnazania++;
		rysowanie();
		break;
	default:
		kolizja(nextX, nextY);
		wiek++;
		odOstatniegoRozmnazania++;
		break;
	}
}

