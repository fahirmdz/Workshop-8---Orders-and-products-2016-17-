#pragma once
#include"Kolekcija.h"
#include"Proizvod.h"

class Narudzba {
	char _datum[12]; //Format: dd.MM.yyyy. 
	Kolekcija<Proizvod*, int> _proizvodi; //Podaci o naručenim proizvodima i količinama
	double _iznos;

public:
	//-----Constructors and destructor
	Narudzba();
	Narudzba(const char*);
	Narudzba(const Narudzba&);
	~Narudzba();

	//----Operators-------
	Narudzba& operator=(const Narudzba&);
	Narudzba& operator()(const Proizvod&, int);

	//----Get methods--------
	char* getDatum()const;
	Proizvod* getProizvod(int)const;
	double getKolicinu(int)const;
	int getBrojProizvoda()const;
	double getIznosNarudzbe()const;

	void obracunajPopust(double);

	friend ostream& operator<<(ostream&, const Narudzba&);

};