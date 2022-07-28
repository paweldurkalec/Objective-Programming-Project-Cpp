#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
private:
	void rozmnazaj(int x, int y) override;
	void kolizja(int x, int y);
public:
	std::string toString() override;
	WilczeJagody(Swiat&, int x, int y);
	bool czyTruje(Organizm* oa) override;
};
