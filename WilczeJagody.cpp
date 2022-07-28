#pragma once
#include <iostream>
#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(Swiat& swiat, int x, int y) : Roslina('j', 99, x, y, swiat) {

}

void WilczeJagody::kolizja(int x2, int y2) {
	Organizm* oa = swiat.getOrganizm(x2, y2);
	swiat.usunOrganizm(oa->getX(), oa->getY());
	swiat.usunOrganizm(x, y);
}

bool WilczeJagody::czyTruje(Organizm* oa) {
	if (oa->czyZwierze()) {
		kolizja(oa->getX(), oa->getY());
		return 1;
	}
	else return 0;
}

std::string WilczeJagody::toString() {
	return "wilcze_jagody";
}

void WilczeJagody::rozmnazaj(int a, int b) {
	new WilczeJagody(swiat, a, b);
}
