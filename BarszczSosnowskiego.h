#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
private:
	void rozmnazaj(int x, int y) override;
	void eksterminujSasiedztwo();
public:
	std::string toString() override;
	BarszczSosnowskiego(Swiat&, int x, int y);
	bool czyTruje(Organizm* oa) override;
	void kolizja(int x, int y);
	void akcja() override;
};
