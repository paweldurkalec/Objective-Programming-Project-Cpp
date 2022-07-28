#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int kierunek;
	int licznikTarczy;
	int cooldownTarczy;
	void obsluzTarczaAlzura();
	void rozmnazaj(int x, int y) override;
	bool tarczaAlzura;
protected:
	void kolizja(int x, int y) override;
public:
	Czlowiek(Swiat&);
	Czlowiek(Swiat&, int x, int y);
	std::string toString() override;
	int czyOdbilAtak(int x, int y);
	void setKierunek(int);
	void setTarcza(bool);
	bool getTarcza() const;
	int getCooldownTarczy() const;
	void resetLicznikTarczy();
	int getKierunek() const;
	void akcja() override;
	~Czlowiek();
};