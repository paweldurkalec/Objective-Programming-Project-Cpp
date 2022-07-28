#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
private:
	void rozmnazaj(int x, int y) override;
public:
	int czyOdbilAtak(int x, int y) override;
	std::string toString() override;
	Zolw(Swiat&, int x, int y);
	void akcja() override;
};
