#pragma once
//Klasu Osoba deklarisati kao apstraktnu. 

class Osoba {
protected:
	char* _ime;
	char* _prezime;
	char* _adresa;
	char _telefon[15];

public:
	Osoba();
	Osoba(const char*, const char*, const char*, const char*);
	virtual ~Osoba() = 0;

	virtual void Info()const = 0;
	virtual char* getIme()const = 0;
	virtual char* getPrezime()const = 0;
	virtual char* getAdresu()const = 0;
	virtual char* getTelefon()const = 0;

	virtual void setIme(const char*) = 0;
	virtual void setPrezime(const char*) = 0;
	virtual void setAdresu(const char*) = 0;
	virtual void setTelefon(const char*) = 0;
};