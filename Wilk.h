#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
private:
	void rozmnazaj(int x, int y) override;
public:
	std::string toString() override;
	Wilk(Swiat&, int x, int y);
};
