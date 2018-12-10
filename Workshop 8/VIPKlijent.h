#pragma once
#include"Klijent.h"

class VIPKlijent :public Klijent {

	char* _parkingOznaka;
	double _popust;

public:
	//-----------Constructors and destructors-------------------- 
	VIPKlijent();
	VIPKlijent(const char*, const char*, const char*, const char*, const char*, int, const char*, double);
	VIPKlijent(const VIPKlijent&);
	~VIPKlijent();
	//--------------Operators-------------------------
	VIPKlijent& operator()(Narudzba&, double);
	VIPKlijent& operator()(const Proizvod&);

	//--------------Get methonds--------------------
	char* getParkingOznaka()const;
	double getPopust()const;

	//------------Set methods-------------------
	void setParkingOznaka(const char*);
	void setPopust(double);

	friend ostream& operator<<(ostream&, const VIPKlijent&);
};