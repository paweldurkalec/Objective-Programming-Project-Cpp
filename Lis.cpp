#pragma once
#include "Lis.h"
#include "Swiat.h"

Lis::Lis(Swiat& swiat, int x, int y) : Zwierze(5, 'L', 3, 7, x, y, swiat) {

}

bool Lis::czyGdziekolwiekWolne() const {
	if (y > 0) {
		if (swiat.getOrganizm(x, y - 1) == nullptr) {
			return 1;
		}
		else if (swiat.getOrganizm(x, y - 1)->getSila() <= getSila()) {
			return 1;
		}
	}
	if (x < swiat.getX() - 1) {
		if (swiat.getOrganizm(x+1, y) == nullptr) {
			return 1;
		}
		else if (swiat.getOrganizm(x+1, y)->getSila() <= getSila()) {
			return 1;
		}
	}
	if (y < swiat.getY() - 1) {
		if (swiat.getOrganizm(x, y + 1) == nullptr) {
			return 1;
		}
		else if (swiat.getOrganizm(x, y + 1)->getSila() <= getSila()) {
			return 1;
		}
	}
	if (x > 0) {
		if (swiat.getOrganizm(x-1, y) == nullptr) {
			return 1;
		}
		else if (swiat.getOrganizm(x-1, y)->getSila() <= getSila()) {
			return 1;
		}
	}
	return 0;
}

int Lis::czyWolne(int kierunek) const {
	switch (kierunek) {
	case 0:
		if (y > 0) {
			if (swiat.getOrganizm(x, y - 1) == nullptr) {
				return 1;
			}
			else if (swiat.getOrganizm(x, y - 1)->getSila() > getSila()) {
				return 0;
			}
			else return 2;
		}
		break;
	case 1:
		if (x < swiat.getX() - 1) {
			if (swiat.getOrganizm(x + 1, y) == nullptr) {
				return 1;
			}
			else if (swiat.getOrganizm(x + 1, y)->getSila() > getSila()) {
				return 0;
			}
			else return 2;
		}
		break;
	case 2:
		if (y < swiat.getY() - 1) {
			if (swiat.getOrganizm(x, y + 1) == nullptr) {
				return 1;
			}
			else if (swiat.getOrganizm(x, y + 1)->getSila() > getSila()) {
				return 0;
			}
			else return 2;
		}
		break;
	default:
		if (x > 0) {
			if (swiat.getOrganizm(x - 1, y) == nullptr) {
				return 1;
			}
			else if (swiat.getOrganizm(x - 1, y)->getSila() > getSila()) {
				return 0;
			}
			else return 2;
		}
		break;
	}
	return 0;
}

std::string Lis::toString() {
	return "lis";
}

void Lis::rozmnazaj(int a, int b) {
	new Lis(swiat, a, b);
}

void Lis::akcja() {
	if (Lis::czyGdziekolwiekWolne()) {
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
	else {
		wiek++;
		zwiekszCzasOdostatniegoRozmnazania();
	}
}