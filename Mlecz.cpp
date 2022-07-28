#pragma once
#include <iostream>
#include "Mlecz.h"
#include "Swiat.h"
#define ROZMNAZANIE 10

Mlecz::Mlecz(Swiat& swiat, int x, int y) : Roslina('m', 0, x, y, swiat) {

}

std::string Mlecz::toString() {
	return "mlecz";
}

void Mlecz::rozmnazaj(int a, int b) {
	new Mlecz(swiat, a, b);
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
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
	}
	wiek++;
	rysowanie();
}