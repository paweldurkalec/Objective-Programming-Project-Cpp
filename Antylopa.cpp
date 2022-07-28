#pragma once
#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(Swiat& swiat, int x, int y) : Zwierze(5, 'A', 4, 4, x, y, swiat) {

}

std::string Antylopa::toString() {
	return "antylopa";
}

bool Antylopa::czyGdziekolwiekWolne() const {
	if (y > 1) {
		if (swiat.getOrganizm(x, y - 2) == nullptr) {
			return 1;
		}
	}
	if (x < swiat.getX() - 2) {
		if (swiat.getOrganizm(x + 2, y) == nullptr) {
return 1;
		}
	}
	if (y < swiat.getY() - 2) {
		if (swiat.getOrganizm(x, y + 2) == nullptr) {
			return 1;
		}
	}
	if (x > 1) {
		if (swiat.getOrganizm(x - 2, y) == nullptr) {
			return 1;
		}
	}
	return 0;
}

int Antylopa::czyWolne(int kierunek) const {
	switch (kierunek) {
	case 0:
		if (y > 1) {
			if (swiat.getOrganizm(x, y - 2) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	case 1:
		if (x < swiat.getX() - 2) {
			if (swiat.getOrganizm(x + 2, y) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	case 2:
		if (y < swiat.getY() - 2) {
			if (swiat.getOrganizm(x, y + 2) == nullptr) {
				return 1;
			}
			else {
				return 2;
			}
		}
		break;
	default:
		if (x > 1) {
			if (swiat.getOrganizm(x - 2, y) == nullptr) {
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

bool Antylopa::czyUcieka() {
	if (((rand() % 2) == 0) && czyGdziekolwiekWolne()) {
		int kierunek;
		int nextX = x;
		int nextY = y;
		kierunek = rand() % 4;
		while (czyWolne(kierunek) != 1) {
			kierunek = rand() % 4;
		}
		switch (kierunek) {
		case 0:
			nextY -= 2;
			break;
		case 1:
			nextX += 2;
			break;
		case 2:
			nextY += 2;
			break;
		default:
			nextX -= 2;
			break;
		}
		swiat.usunOrganizm(x, y);
		x = nextX;
		y = nextY;
		swiat.dodajWydarzenieDoDziennika(toString() + " ucieka przed walka na pole (" + std::to_string(getX()) + "," + std::to_string(getY()) + ")");
		rysowanie();
		return 1;
	}
	return 0;
}

void Antylopa::rozmnazaj(int a, int b) {
	new Antylopa(swiat, a, b);
}

void Antylopa::kolizja(int x2, int y2) {
	Organizm* o = swiat.getOrganizm(x2, y2);
	if (o->getC() != getC() && (rand() % 2) == 0) {
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
				nextY -= 2;
				break;
			case 1:
				nextX += 2;
				break;
			case 2:
				nextY += 2;
				break;
			default:
				nextX -= 2;
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
		swiat.dodajWydarzenieDoDziennika(toString() + " ucieka przed walka na pole (" + std::to_string(getX()) + "," + std::to_string(getY()) + ")");
	}
	else {
		Zwierze::kolizja(x2, y2);
	}
}


void Antylopa::akcja() {
		int kierunek;
		int nextX = x;
		int nextY = y;
		kierunek = rand() % 4;
		switch (kierunek) {
		case 0:
			nextY -= 2;
			break;
		case 1:
			nextX += 2;
			break;
		case 2:
			nextY += 2;
			break;
		default:
			nextX -= 2;
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
			Antylopa::kolizja(nextX, nextY);
			wiek++;
			zwiekszCzasOdostatniegoRozmnazania();
			break;
		}
}