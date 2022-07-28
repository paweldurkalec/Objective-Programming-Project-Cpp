#pragma once
#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw(Swiat& swiat, int x, int y) : Zwierze(5, 'Z', 2, 1, x, y, swiat) {

}

std::string Zolw::toString() {
	return "zolw";
}

int Zolw::czyOdbilAtak(int x, int y) {
	Organizm* oa = swiat.getOrganizm(x, y);
	if (oa->getSila() < 5) {
		return 1;
	}
	else {
		return 0;
	}
}

void Zolw::rozmnazaj(int a, int b) {
	new Zolw(swiat, a, b);
}

void Zolw::akcja() {
	if (rand() % 4 == 0) {
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
			zwiekszCzasOdostatniegoRozmnazania();
			rysowanie();
			break;
		default:
			kolizja(nextX, nextY);
			wiek++;
			zwiekszCzasOdostatniegoRozmnazania();
			break;
		}
	}
}