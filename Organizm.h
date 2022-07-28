#pragma once
#include <iostream>
class Swiat;

class Organizm {
private: 
	int sila, inicjatywa;
	char c;
protected:
	int czyWolne(int kierunek) const;
	bool czyGdziekolwiekWolne() const;
	int x, y, wiek;
	Swiat& swiat;
	virtual void kolizja(int x, int y) = 0;
public:
	Organizm(char c, int sila, int inicjatywa, int x, int y, Swiat& swiat);
	virtual int czyOdbilAtak(int x, int y) = 0;
	virtual bool czyZwierze() = 0;
	virtual bool czyUcieka() = 0;
	virtual bool czyDajeSile(Organizm* oa) = 0;
	virtual bool czyTruje(Organizm* oa) = 0;
	virtual std::string toString() = 0;
	virtual void akcja() = 0;
	virtual void rysowanie() = 0;
	void dajSile(int ile);
	char getC() const;
	int getInit() const;
	int getSila() const;
	int getWiek() const;
	int getX() const;
	int getY() const;
	void setX(int);
	void setY(int);
	void setWiek(int);
	virtual ~Organizm();
};