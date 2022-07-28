#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
private:
	void rozmnazaj(int x, int y) override;
	void kolizja(int x, int y);
public:
	std::string toString() override;
	Guarana(Swiat&, int x, int y);
	bool czyDajeSile(Organizm* oa) override;
};
