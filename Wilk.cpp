#include "Wilk.h"
#include "Swiat.h"

Wilk::Wilk(Swiat& swiat, int x, int y) : Zwierze(5, 'W', 9, 5, x, y, swiat) {

}

std::string Wilk::toString() {
	return "wilk";
}

void Wilk::rozmnazaj(int a, int b) {
	new Wilk(swiat, a, b);
}