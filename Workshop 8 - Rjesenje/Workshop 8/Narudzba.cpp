#include"pch.h"

//------Constructors and destructor------------
Narudzba::Narudzba() :_iznos(0) {}

Narudzba::Narudzba(const char* datum) : _iznos(0) {
	strncpy_s(_datum, datum, _TRUNCATE);
}
Narudzba::~Narudzba() {}
Narudzba::Narudzba(const Narudzba& n) : _iznos(n._iznos) {
	strncpy_s(_datum, n._datum, _TRUNCATE);
	_proizvodi = n._proizvodi;
}


//--------Operators----------
Narudzba& Narudzba::operator=(const Narudzba& n) {
	_iznos = n._iznos;
	strncpy_s(_datum, n._datum, _TRUNCATE);
	_proizvodi = n._proizvodi;
	return *this;
}
Narudzba& Narudzba::operator()(const Proizvod& p, int x) {
	Proizvod* temp = new Proizvod(p);
	_proizvodi(temp, x);
	_iznos += (p.getCijenu()*x);
	return *this;
}

//---------Get metode---------
Proizvod* Narudzba::getProizvod(int index)const {
	if (_proizvodi.GetTrenutno() <= 0 || index<0 || index>_proizvodi.GetTrenutno() - 1)
		return nullptr;
	return *_proizvodi[index];
}
double Narudzba::getKolicinu(int index)const {
	if (_proizvodi.GetTrenutno() <= 0 || index<0 || index>_proizvodi.GetTrenutno() - 1)
		return NULL;
	return *_proizvodi(index);
}
char* Narudzba::getDatum()const { return AlocirajNizKaraktera((char*)_datum); }
int Narudzba::getBrojProizvoda()const { return _proizvodi.GetTrenutno(); }

double Narudzba::getIznosNarudzbe()const { return _iznos; }

void Narudzba::obracunajPopust(double popust) {

	_iznos -= (_iznos * (popust / 100));
}


ostream& operator<<(ostream& COUT, const Narudzba& n) {
	cout << "Datum: " << n._datum << endl;
	cout << "Broj proizvoda: " << n._proizvodi.GetTrenutno() << endl;
	if (n._proizvodi.GetTrenutno() <= 0)
		cout << "--NEMA--\n";
	else {
		for (int i = 0; i < n._proizvodi.GetTrenutno(); i++)
			cout << **n._proizvodi[i] << " - " << *n._proizvodi(i) << endl;
	}

	return COUT;

}