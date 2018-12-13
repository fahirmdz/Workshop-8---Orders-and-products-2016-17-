#pragma once
#include"Osoba.h"
#include"Kolekcija.h"
#include"Narudzba.h"
#include<iostream>

class Klijent :public Osoba {
protected:
	int _id;
	char* _email;
	Kolekcija<Narudzba, double> _narudzbe;
	//Podaci o narudžbama sa ukupnim utrošenim iznosom u KM 

public:
	//----------Constructors and destructor-------------------
	Klijent();
	Klijent(const char*, const char*, const char*, const char*, const char*, int);
	Klijent(const Klijent&);
	~Klijent();

	void Info()const;
	char* getIme()const;
	char* getPrezime()const;
	char* getAdresu()const;
	char* getTelefon()const;

	void setIme(const char*);
	void setPrezime(const char*);
	void setAdresu(const char*);
	void setTelefon(const char*);
	bool IsPotrosnjaVeca(int, double);

	//-------Set methods------------
	void setEmail(const char*);

	//------Get methods-------
	Narudzba* getNarudzbu(int);
	double getUtroseno(int);
	int getID()const;
	char* getEmail()const;
	int getBrojNarudzbi()const;
	//------Operators--------
	Klijent& operator()(Narudzba&, double);

	friend ostream& operator<<(ostream&, const Klijent&);

};