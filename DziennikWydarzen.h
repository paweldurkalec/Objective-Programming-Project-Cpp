#pragma once
#include <list>
#include <iostream>

class DziennikWydarzen {
private:
	std::list<std::string> l;
public:
	DziennikWydarzen();
	void dodajWydarzenie(std::string w);
	void dodajWydarzenieNaPoczatek(std::string w);
	void wypiszWydarzenia();
	void wyczysc();
};