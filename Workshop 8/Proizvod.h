#pragma once

class Proizvod {
	char* _naziv;
	char* _opis;
	double _cijena;
public:
	//----Constructors and destructor-------
	Proizvod();
	Proizvod(const char*, const char*, double);
	Proizvod(const Proizvod&);
	~Proizvod();

	//----Operators
	Proizvod& operator=(const Proizvod&);

	//-----Get methods------
	double getCijenu()const;
	char* getNaziv()const;
	char* getOpis()const;

	void obracunajPopust(double);
	friend ostream& operator<<(ostream&, const Proizvod&);
};
