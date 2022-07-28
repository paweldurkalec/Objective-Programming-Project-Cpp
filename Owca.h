#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
private:
	void rozmnazaj(int x, int y) override;
public:
	std::string toString() override;
	Owca(Swiat&, int x, int y);
};

