#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <list>
#include <fstream>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"

using namespace std;

void Swiat::znajdzPustePole(int& startX, int& startY) {
	while (mapa[startX][startY] != nullptr) {
		startX = rand() % x;
		startY = rand() % y;
	}
}

void Swiat::generujPustaMape() {
	mapa = new Organizm * *[x];

	for (int i = 0; i < x; i++) {
		mapa[i] = new Organizm * [y];
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			mapa[i][j] = nullptr;
		}
	}
}

void Swiat::inicjujZycie(int iloscTrawy, int iloscBarszczow, int iloscGuarany, int iloscMleczy, int iloscWilczychJagod, int iloscLisow,
	int iloscWilkow, int iloscOwiec, int iloscZolwi, int iloscAntylop) {
	czlowiek = new Czlowiek(*this);
	int startX, startY;
	startX = rand() % x;
	startY = rand() % y;
	for (int i = 0; i < iloscBarszczow; i++) {
		znajdzPustePole(startX, startY);
		new BarszczSosnowskiego(*this, startX, startY);
	}
	for (int i = 0; i < iloscTrawy; i++) {
		znajdzPustePole(startX, startY);
		new Trawa(*this, startX, startY);
	}
	for (int i = 0; i < iloscGuarany; i++) {
		znajdzPustePole(startX, startY);
		new Guarana(*this, startX, startY);
	}
	for (int i = 0; i < iloscMleczy; i++) {
		znajdzPustePole(startX, startY);
		new Mlecz(*this, startX, startY);
	}
	for (int i = 0; i < iloscWilczychJagod; i++) {
		znajdzPustePole(startX, startY);
		new WilczeJagody(*this, startX, startY);
	}
	for (int i = 0; i < iloscWilkow; i++) {
		znajdzPustePole(startX, startY);
		new Wilk(*this, startX, startY);
	}
	for (int i = 0; i < iloscLisow; i++) {
		znajdzPustePole(startX, startY);
		new Lis(*this, startX, startY);
	}
	for (int i = 0; i < iloscOwiec; i++) {
		znajdzPustePole(startX, startY);
		new Owca(*this, startX, startY);
	}
	for (int i = 0; i < iloscZolwi; i++) {
		znajdzPustePole(startX, startY);
		new Zolw(*this, startX, startY);
	}
	for (int i = 0; i < iloscAntylop; i++) {
		znajdzPustePole(startX, startY);
		new Antylopa(*this, startX, startY);
	}
}

Swiat::Swiat(int x, int y, int iloscTrawy, int iloscBarszczow, int iloscGuarany, int iloscMleczy, int iloscWilczychJagod, int iloscLisow,
	int iloscWilkow, int iloscOwiec, int iloscZolwi, int iloscAntylop) : x(x), y(y), tura(1), exit(0)
{
	if ((iloscTrawy + iloscBarszczow + iloscGuarany + iloscMleczy + iloscWilczychJagod + iloscLisow + iloscWilkow + iloscOwiec + iloscZolwi + iloscAntylop + 1) > (x * y)) {
		exit = 1;
	}
	srand(time(NULL));
	czlowiek = nullptr;
	mapa = nullptr;
	if (exit != 1) {
		generujPustaMape();

		inicjujZycie(iloscTrawy, iloscBarszczow, iloscGuarany, iloscMleczy, iloscWilczychJagod, iloscLisow,
			iloscWilkow, iloscOwiec, iloscZolwi, iloscAntylop);
	}
	else {
		printf("Liczba organizmow podana w konstruktorze swiata przekracza liczbe dostepnych pol\n");
	}
}

void Swiat::wyczyscSwiat() {
	if (mapa != nullptr) {
		czlowiek = nullptr;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (mapa[i][j] != nullptr) {
					delete mapa[i][j];
				}
			}
		}
		for (int i = 0; i < x; i++) {
			delete[] mapa[i];
		}
		delete[] mapa;
	}
}

bool Swiat::zapiszStan() {
	fstream plik;
	plik.open("zapis.txt", ios::out);

	if (plik.good() == false) {
		plik.close();
		return 0;
	}
	else {
		plik << x << endl;
		plik << y << endl;
		plik << tura << endl;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (mapa[i][j] != nullptr) {
					plik << mapa[i][j]->toString() << " " << mapa[i][j]->getX() << " " << mapa[i][j]->getY() << " " << mapa[i][j]->getSila()<< " " << mapa[i][j]->getWiek() << endl;
				}
			}
		}
	}
	plik.close();
	return 1;
}

void Swiat::wczytajOrganizm(string gatunek, int orgX, int orgY, int orgSila, int orgWiek) {
	Organizm* org=nullptr;
	if (gatunek == "czlowiek") {
		org = new Czlowiek(*this, orgX, orgY);
		czlowiek = org;
	}
	else if (gatunek == "owca") {
		org = new Owca(*this, orgX, orgY);
	}
	else if (gatunek == "antylopa") {
		org = new Antylopa(*this, orgX, orgY);
	}
	else if (gatunek == "lis") {
		org = new Lis(*this, orgX, orgY);
	}
	else if (gatunek == "zolw") {
		org = new Zolw(*this, orgX, orgY);
	}
	else if (gatunek == "wilk") {
		org = new Wilk(*this, orgX, orgY);
	}
	else if (gatunek == "trawa") {
		org = new Trawa(*this, orgX, orgY);
	}
	else if (gatunek == "mlecz") {
		org = new Mlecz(*this, orgX, orgY);
	}
	else if (gatunek == "guarana") {
		org = new Guarana(*this, orgX, orgY);
	}
	else if (gatunek == "wilcze_jagody") {
		org = new WilczeJagody(*this, orgX, orgY);
	}
	else if (gatunek == "barszcz_sosnowskiego") {
		org = new BarszczSosnowskiego(*this, orgX, orgY);
	}
	if (org != nullptr) {
		while (org->getSila() < orgSila) {
			org->dajSile(3);
		}
		org->setWiek(orgWiek);
	}
}

bool Swiat::wczytajStan() {
	fstream plik;
	string linia;
	int nrLinii = 1;
	string bufor, orgGatunek;
	int orgX, orgY, orgSila, orgWiek, k;
	plik.open("zapis.txt", ios::in);
	if (plik.good() == false) {
		plik.close();
		return 0;
	}
	else {
		wyczyscSwiat();
		for (int i = 0; i < 3; i++) {
			getline(plik, linia);
			switch (nrLinii) {
			case 1:
				x = atoi(linia.c_str());
				break;
			case 2:
				y = atoi(linia.c_str());
				break;
			case 3:
				tura = atoi(linia.c_str());
				break;
			}
			nrLinii++;
		}
		generujPustaMape();
		while (!plik.eof()) {
			getline(plik, linia);
			k = 0;
			bufor = "";
			for (auto x : linia)
			{
				if (x == ' ')
				{
					switch (k) {
					case 0:
						orgGatunek = bufor;
						break;
					case 1:
						orgX = atoi(bufor.c_str());
						break;
					case 2:
						orgY = atoi(bufor.c_str());
						break;
					case 3:
						orgSila = atoi(bufor.c_str());
						break;
					}
					bufor = "";
					k++;
				}
				else {
					bufor = bufor + x;
				}
			}
			orgWiek = atoi(bufor.c_str());
			wczytajOrganizm(orgGatunek, orgX, orgY, orgSila, orgWiek);
		}
	}
	plik.close();
	return 1;
}

int Swiat::getX() const {
	return x;
}

int Swiat::getY() const {
	return y;
}

int Swiat::getTura() const {
	return tura;
}

void Swiat::wstawNaMape(Organizm* o, int x, int y) {
	mapa[x][y] = o;
}

void Swiat::czlowiekUmarl() {
	czlowiek = nullptr;
}

void Swiat::usunOrganizm(int x, int y) {
	mapa[x][y] = nullptr;
}

Organizm* Swiat::getOrganizm(int x, int y) const{
	return mapa[x][y];
}

void Swiat::dodajWydarzenieDoDziennika(std::string w) {
	dziennik.dodajWydarzenie(w);
}

void Swiat::dodajWydarzenieNaPoczatekDziennika(std::string w) {
	dziennik.dodajWydarzenieNaPoczatek(w);
}

void Swiat::rysujSwiat() const{
	if (exit != 1) {
		system("CLS");
		printf("Pawel Durkalec, 184773\n");
		for (int i = -1; i <= y; i++) {
			for (int j = -1; j <= x; j++) {
				if ((j == -1 && i == -1) || (j == -1 && i == y) || (j == x && i == -1) || (j == x && i == y)) {
					printf("#");
				}
				else if (i == -1 || i == y) {
					printf("###");
				}
				else if (j == -1 || j == x) {
					printf("#");
				}
				else {
					if (mapa[j][i] != nullptr) {
						printf(" %c ", mapa[j][i]->getC());
					}
					else {
						printf("   ");
					}
				}
			}
			printf("\n");
		}
		printf("Tura:%d\n", getTura());
	}
}

void Swiat::obsluzAkcje() {
	list<Organizm*> l;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mapa[i][j] != nullptr) {
				if (l.size() != 0) {
					for (list<Organizm*>::iterator k = l.begin(); k != l.end(); k++) {
						if (mapa[i][j]->getInit() > (*k)->getInit()) {						
							l.insert(k, mapa[i][j]);
							break;
						}
						else if (mapa[i][j]->getInit() == (*k)->getInit()) {
							if (mapa[i][j]->getWiek() >= (*k)->getWiek()) {
								l.insert(k, mapa[i][j]);
								break;
							}
						}
						if (*k == l.back()) {
							l.push_back(mapa[i][j]);
							break;
						}
					}
				}
				else {
					l.push_back(mapa[i][j]);
				}
			}
		}
	}
	for (Organizm* o : l) {
		if (mapa[o->getX()][o->getY()] == o) {
			o->akcja();
		}
	}
	for (Organizm* o : l) {
		if (mapa[o->getX()][o->getY()] != o) {
			delete o;
		}
	}
}

void Swiat::obsluzKlawiature() {
	int nextRound = 0;
	int ch;
	bool czyToDrugieR = 0;
	Czlowiek* cz=nullptr;
	if (czlowiek != nullptr) {
		cz = (Czlowiek*)czlowiek;
	}
	while (!nextRound) {
		while (_kbhit())
		{
			ch = _getch();
			if (ch == 224) {
				if (cz != nullptr) {
					switch (_getch()) {
					case 72: cz->setKierunek(0); break;
					case 80: cz->setKierunek(2); break;
					case 77: cz->setKierunek(1); break;
					case 75: cz->setKierunek(3);; break;
					}
				}
			}
			else if (ch == 'w') {
				if (cz != nullptr) {
					if (cz->getTarcza() == 0 && cz->getCooldownTarczy() == 0) {
						cz->setTarcza(1);
						cz->resetLicznikTarczy();
					}
				}
				czyToDrugieR = 0;
			}
			else if (ch == 'q') {
				nextRound = 1;
			}
			else if (ch == 'e') {
				exit = 1;
				nextRound = 1;
			}
			else if (ch == 's') {
				rysujSwiat();
				if (zapiszStan()) {
					printf("Stan rozgrywki zostal zapisany\n");
				}
				else {
					printf("Blad zapisu\n");
					exit = 1;
					nextRound = 1;
				}
				czyToDrugieR = 0;
			}
			else if (ch == 'r') {
				if (!czyToDrugieR) {
					rysujSwiat();
					printf("Czy na pewno chcesz wczytac stan? Utracisz aktualny swiat (nacisnij ponownie 'r')\n");
					czyToDrugieR = 1;
				}
				else {
					if (wczytajStan()) {
						rysujSwiat();
						printf("Stan rozgrywki zostal wczytany poprawnie\n");
					}
					else {
						rysujSwiat();
						printf("Blad odczytu, pozostajesz na aktualnym swiecie\n");
						czyToDrugieR = 0;
					}
				}
			}
		}
	}
}

bool Swiat::getExit() {
	return exit;
}

void Swiat::wykonajTure() {
	obsluzKlawiature();
	if (exit == 0) {
		obsluzAkcje();
		rysujSwiat();
		dziennik.wypiszWydarzenia();
		dziennik.wyczysc();
		tura++;
	}
}

Swiat::~Swiat() {
	wyczyscSwiat();
}