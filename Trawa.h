#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
private:
	void rozmnazaj(int x, int y) override;
public:
	std::string toString() override;
	Trawa(Swiat&, int x, int y);
};