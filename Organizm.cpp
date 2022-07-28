#include <iostream>
#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(char c, int sila, int inicjatywa, int x, int y, Swiat& swiat) : c(c), sila(sila), inicjatywa(inicjatywa), x(x), y(y), wiek(0), swiat(swiat) {
	swiat.wstawNaMape(this, x, y);
}

Organizm::~Organizm() {

}

void Organizm::dajSile(int ile) {
	sila += ile;
}

char Organizm::getC() const {
	return c;
}

int Organizm::getSila() const {
	return sila;
}

int Organizm::getInit() const {
	return inicjatywa;
}

int Organizm::getWiek() const {
	return wiek;
}

void Organizm::setX(int newX) {
	x = newX;
}

void Organizm::setY(int newY) {
	y = newY;
}

void Organizm::setWiek(int newWiek) {
	wiek = newWiek;
}


int Organizm::getX() const {
	return x;
}

int Organizm::getY() const {
	return y;
}

bool Organizm::czyGdziekolwiekWolne() const {
	if (y > 0) {
		if (swiat.getOrganizm(x, y - 1) == nullptr) {
			return 1;
		}
	}
	if (x < swiat.getX() - 1) {
		if (swiat.getOrganizm(x + 1, y) == nullptr) {
			return 1;
		}
	}
	if (y < swiat.getY() - 1) {
		if (swiat.getOrganizm(x, y + 1) == nullptr) {
			return 1;
		}
	}
	if (x > 0) {
		if (swiat.getOrganizm(x - 1, y) == nullptr) {
			return 1;
		}
	}
	return 0;
}

int Organizm::czyWolne(int kierunek) const{
	switch (kierunek) {
	case 0:
		if (y > 0) {
			if (swiat.getOrganizm(x, y - 1) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	case 1:
		if (x < swiat.getX() - 1) {
			if (swiat.getOrganizm(x + 1, y) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	case 2:
		if (y < swiat.getY() - 1) {
			if (swiat.getOrganizm(x, y + 1) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	default:
		if (x > 0) {
			if (swiat.getOrganizm(x - 1, y) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	}
	return 0;
}

