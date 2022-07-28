#pragma once
#include "Organizm.h"
#include "dziennikWydarzen.h"
#include <string>

class Swiat {
private:
	bool exit;
	int x, y, tura;
	Organizm* czlowiek;
	Organizm*** mapa;
	void znajdzPustePole(int& startX, int& startY);
	void obsluzAkcje();
	void inicjujZycie(int iloscTrawy, int iloscBarszczow, int iloscGuarany, int iloscMleczy, int iloscWilczychJagod, int iloscLisow,
		int iloscWilkow, int iloscOwiec, int iloscZolwi, int iloscAntylop);
	void obsluzKlawiature();
	bool zapiszStan();
	bool wczytajStan();
	void wyczyscSwiat();
	void generujPustaMape();
	void wczytajOrganizm(std::string gatunek, int orgX, int orgY, int orgSila, int orgWiek);
public:
	DziennikWydarzen dziennik;
	Swiat(int x, int y, int iloscTrawy, int iloscBarszczow, int iloscGuarany, int iloscMleczy, int iloscWilczychJagod, int iloscLisow,
		int iloscWilkow, int iloscOwiec, int iloscZolwi, int iloscAntylop);
	void rysujSwiat() const;
	bool getExit();
	int getX() const;
	int getY() const;
	int getTura() const;
	void wstawNaMape(Organizm* o, int x, int y);
	void czlowiekUmarl();
	void dodajWydarzenieDoDziennika(std::string);
	void dodajWydarzenieNaPoczatekDziennika(std::string);
	Organizm* getOrganizm(int x, int y) const;
	void usunOrganizm(int x, int y);
	void wykonajTure();
	~Swiat();
};
