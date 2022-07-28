#include <iostream>
#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(Swiat& swiat, int x, int y) : Roslina('t', 0, x, y, swiat) {
   
}

std::string Trawa::toString() {
	return "trawa";
}

void Trawa::rozmnazaj(int a, int b) {
	new Trawa(swiat, a, b);
}