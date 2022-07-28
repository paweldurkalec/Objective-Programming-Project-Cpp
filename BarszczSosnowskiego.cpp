#pragma once
#include <iostream>
#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#define ROZMNAZANIE 25

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, int x, int y) : Roslina('b', 10, x, y, swiat) {

}

std::string BarszczSosnowskiego::toString() {
	return "barszcz_sosnowskiego";
}

void BarszczSosnowskiego::kolizja(int x2, int y2) {
	Organizm* oa = swiat.getOrganizm(x2, y2);
	swiat.usunOrganizm(oa->getX(), oa->getY());
	swiat.usunOrganizm(x, y);
}

bool BarszczSosnowskiego::czyTruje(Organizm* oa) {
	if (oa->czyZwierze()) {
		if (oa->toString() != "cyber-owca") {
			kolizja(oa->getX(), oa->getY());
			return 1;
		}
		else return 0;
	}
	else return 0;
}

void BarszczSosnowskiego::rozmnazaj(int a, int b) {
	new BarszczSosnowskiego(swiat, a, b);
}

void BarszczSosnowskiego::eksterminujSasiedztwo() {
	if (y > 0) {
		if (swiat.getOrganizm(x, y - 1) != nullptr) {
			if (swiat.getOrganizm(x, y - 1)->czyZwierze()&&(swiat.getOrganizm(x, y - 1)->toString()!="cyber-owca")) {
				swiat.dodajWydarzenieDoDziennika(swiat.getOrganizm(x, y - 1)->toString() + " zostal spalony przez BS na (" + std::to_string(swiat.getOrganizm(x, y - 1)->getX()) + "," + std::to_string(swiat.getOrganizm(x, y - 1)->getY()) + ")");
				swiat.usunOrganizm(x, y - 1);
			}
		}
	}
	if (x < swiat.getX() - 1) {
		if (swiat.getOrganizm(x + 1, y) != nullptr) {
			if (swiat.getOrganizm(x + 1, y)->czyZwierze() && (swiat.getOrganizm(x + 1, y)->toString() != "cyber-owca")) {
				swiat.dodajWydarzenieDoDziennika(swiat.getOrganizm(x + 1, y)->toString() + " zostal spalony przez BS na (" + std::to_string(swiat.getOrganizm(x + 1, y)->getX()) + "," + std::to_string(swiat.getOrganizm(x + 1, y)->getY()) + ")");
				swiat.usunOrganizm(x + 1, y);
			}
		}
	}
	if (y < swiat.getY() - 1) {
		if (swiat.getOrganizm(x, y + 1) != nullptr) {
			if (swiat.getOrganizm(x, y + 1)->czyZwierze() && (swiat.getOrganizm(x, y + 1)->toString() != "cyber-owca")) {
				swiat.dodajWydarzenieDoDziennika(swiat.getOrganizm(x, y + 1)->toString() + " zostal spalony przez BS na (" + std::to_string(swiat.getOrganizm(x, y + 1)->getX()) + "," + std::to_string(swiat.getOrganizm(x, y + 1)->getY()) + ")");
				swiat.usunOrganizm(x, y + 1);
			}
		}
	}
	if (x > 0) {
		if (swiat.getOrganizm(x - 1, y) != nullptr) {
			if (swiat.getOrganizm(x - 1, y)->czyZwierze() && (swiat.getOrganizm(x - 1, y)->toString() != "cyber-owca")) {
				swiat.dodajWydarzenieDoDziennika(swiat.getOrganizm(x - 1, y)->toString() + " zostal spalony przez BS na (" + std::to_string(swiat.getOrganizm(x - 1, y)->getX()) + "," + std::to_string(swiat.getOrganizm(x - 1, y)->getY()) + ")");
				swiat.usunOrganizm(x - 1, y);
			}
		}
	}
}

void BarszczSosnowskiego::akcja() {
	eksterminujSasiedztwo();
	int czyRozmnazac = rand() % ROZMNAZANIE;
	if ((czyRozmnazac == 0) && czyGdziekolwiekWolne()) {
		int kierunek = rand() % 4;
		int newX = x;
		int newY = y;
		while (!(czyWolne(kierunek) == 1)) {
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
		rozmnazaj(newX, newY);
		swiat.dodajWydarzenieDoDziennika(toString() + " rozprzestrzenia sie na (" + std::to_string(newX) + "," + std::to_string(newY) + ")");
	}
	wiek++;
	rysowanie();
}
