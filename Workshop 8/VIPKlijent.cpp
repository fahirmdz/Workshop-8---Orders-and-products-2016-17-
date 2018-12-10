#pragma once
#include "pch.h"

//--------------Constructors and destructor-----------------------

VIPKlijent::VIPKlijent() :_parkingOznaka(nullptr), _popust(0) {}
VIPKlijent::VIPKlijent(const char* ime, const char* prezime, const char* adresa, const char* telefon, const char* email, int id, const char* parkingOz, double popust) :
	Klijent(ime, prezime, adresa, telefon, email, id), _parkingOznaka(AlocirajNizKaraktera(parkingOz)), _popust(popust) {}
VIPKlijent::VIPKlijent(const VIPKlijent& vk) : Klijent(vk), _parkingOznaka(AlocirajNizKaraktera(vk._parkingOznaka)), _popust(vk._popust) {}
VIPKlijent::~VIPKlijent() {
	delete[]  _parkingOznaka; _parkingOznaka = nullptr;
}

//---------Operators------------------------

VIPKlijent& VIPKlijent::operator()(Narudzba& n, double x) {
	n.obracunajPopust(_popust);
	x = n.getIznosNarudzbe();
	Klijent::operator()(n, x);
	return *this;
}

VIPKlijent& VIPKlijent::operator()(const Proizvod& p) {
	if (_narudzbe.GetTrenutno() <= 0)
		return *this;
	_narudzbe[_narudzbe.GetTrenutno() - 1]->operator()(p, 1);
	return *this;
}

//-------------Get methods------------------
char* VIPKlijent::getParkingOznaka()const { return AlocirajNizKaraktera(_parkingOznaka); }
double VIPKlijent::getPopust()const { return _popust; }

//-----------Set methods--------------------
void VIPKlijent::setParkingOznaka(const char* oznaka) {
	delete[] _parkingOznaka;
	_parkingOznaka = AlocirajNizKaraktera(oznaka);
}
void VIPKlijent::setPopust(double popust) { _popust = popust; }


ostream& operator<<(ostream& COUT, const VIPKlijent& vip) {
	if (vip._parkingOznaka == nullptr)
		return COUT;
	vip.Info();
	cout << "Parking oznaka: " << vip._parkingOznaka;
	cout << "\nPopust na sve proizvode: " << vip._popust << "%\n";
	cout << "E-mail: " << vip._email;
	cout << "\nID klijenta: " << vip._id;
	cout << "\n\n--NARUDZBE--\n";
	if (vip._narudzbe.GetTrenutno() <= 0)
		cout << "--NEMA TRENUTNO NARUDZBI--\n";
	else {
		for (int i = 0; i < vip._narudzbe.GetTrenutno(); i++)
			cout << *vip._narudzbe[i] << "\n\nIznos narudzbe: " << *vip._narudzbe(i) << endl;
	}
	return COUT;
}