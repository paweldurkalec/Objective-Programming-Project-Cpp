#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	void rozmnazaj(int x, int y) override;
	int czyWolne(int kierunek) const;
	bool czyGdziekolwiekWolne() const;
	void kolizja(int x, int y) override;
public:
	std::string toString() override;
	bool czyUcieka();
	Antylopa(Swiat&, int x, int y);
	void akcja() override;
};
