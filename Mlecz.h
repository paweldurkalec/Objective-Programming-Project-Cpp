#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
private:
	void rozmnazaj(int x, int y) override;
public:
	std::string toString() override;
	void akcja() override;
	Mlecz(Swiat&, int x, int y);
};