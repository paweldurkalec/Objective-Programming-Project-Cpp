#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	virtual void rozmnazaj(int x, int y) = 0;
	void kolizja(int, int) override;
public:
	int czyOdbilAtak(int x, int y) override;
	bool czyUcieka() override;
	bool czyDajeSile(Organizm* oa) override;
	bool czyTruje(Organizm* oa) override;
	bool czyZwierze();
	Roslina(char c, int sila, int x, int y, Swiat& swiat);
	void akcja() override;
	void rysowanie() override;
};
