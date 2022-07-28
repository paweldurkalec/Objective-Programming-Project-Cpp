#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
private:
	int odOstatniegoRozmnazania;
	int minMiedzyRozmnazaniami;
protected:
	void rysowanie() override;
	void kolizja(int x, int y) override;
	virtual void rozmnazaj(int x, int y) = 0;
public:
	Zwierze(int minMiedzyRozmnazaniami, char c, int sila, int inicjatywa, int x, int y, Swiat& swiat);
	void szukajMiejscaDoRozrodu();
	int czyOdbilAtak(int x, int y) override;
	bool czyUcieka() override;
	bool czyDajeSile(Organizm* oa) override;
	bool czyTruje(Organizm* oa) override;
	bool czyZwierze() override;
	void zwiekszCzasOdostatniegoRozmnazania();
	void akcja() override;
};
