#pragma once
#include "Owca.h"
#include "Swiat.h"

Owca::Owca(Swiat& swiat, int x, int y) : Zwierze(3, 'S', 4, 4, x, y, swiat) {
	
}

std::string Owca::toString() {
	return "owca";
}

void Owca::rozmnazaj(int a, int b) {
	new Owca(swiat, a, b);
}