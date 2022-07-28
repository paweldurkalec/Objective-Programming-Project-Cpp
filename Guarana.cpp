#pragma once
#include <iostream>
#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(Swiat& swiat, int x, int y) : Roslina('g', 0, x, y, swiat) {

}

void Guarana::kolizja(int x, int y) {
	Organizm* oa = swiat.getOrganizm(x, y);
	oa->dajSile(3);
}

std::string Guarana::toString() {
	return "guarana";
}

bool Guarana::czyDajeSile(Organizm* oa) {
	kolizja(oa->getX(), oa->getY());
	return 1;
}

void Guarana::rozmnazaj(int a, int b) {
	new Guarana(swiat, a, b);
}
