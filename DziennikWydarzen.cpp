#pragma once
#include "DziennikWydarzen.h"
#include <list>
#include <iostream>

void DziennikWydarzen::dodajWydarzenie(std::string w) {
	l.push_back(w);
}

void DziennikWydarzen::dodajWydarzenieNaPoczatek(std::string w) {
	l.push_front(w);
}

void DziennikWydarzen::wypiszWydarzenia() {
	for (std::list<std::string>::iterator k = l.begin(); k != l.end(); k++) {
		std::cout << *k<<" ||| ";
	}
}

DziennikWydarzen::DziennikWydarzen() {

}

void DziennikWydarzen::wyczysc() {
	l.clear();
}