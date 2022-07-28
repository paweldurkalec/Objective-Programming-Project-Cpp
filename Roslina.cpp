#include <iostream>
#include "Roslina.h"
#include "Swiat.h"
#define ROZMNAZANIE 10

Roslina::Roslina(char c, int sila, int x, int y, Swiat& swiat) : Organizm(c, sila, 0, x, y, swiat) {
	
}

bool Roslina::czyTruje(Organizm* oa) {
	return 0;
}

bool Roslina::czyDajeSile(Organizm* oa) {
	return 0;
}

int Roslina::czyOdbilAtak(int x2, int y2) {
	return 0;
}

bool Roslina::czyUcieka() {
	return 0;
}

void Roslina::rysowanie() {
	swiat.wstawNaMape(this, x, y);
}

void Roslina::kolizja(int x, int y) {

}

bool Roslina::czyZwierze() {
	return 0;
}

void Roslina::akcja() {
	int czyRozmnazac = rand() % ROZMNAZANIE;
	if ((czyRozmnazac==0)&&czyGdziekolwiekWolne()) {
		int kierunek = rand() % 4;
		int newX = x;
		int newY = y;
		while (!(czyWolne(kierunek)==1)) {
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