#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
private:
	void rozmnazaj(int x, int y) override;
	int czyWolne(int kierunek) const;
	bool czyGdziekolwiekWolne() const;
public:
	std::string toString() override;
	Lis(Swiat&, int x, int y);
	void akcja() override;
};
