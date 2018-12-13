#include"pch.h"


//------Constructors and destructor
Proizvod::Proizvod() :_naziv(nullptr), _opis(nullptr), _cijena(0) {}
Proizvod::Proizvod(const char* naziv, const char* opis, double cijena) : _naziv(AlocirajNizKaraktera(naziv)),
_opis(AlocirajNizKaraktera(opis)) {
	_cijena = cijena;
}
Proizvod::Proizvod(const Proizvod& p) : _naziv(AlocirajNizKaraktera(p._naziv)), _opis(AlocirajNizKaraktera(p._opis)), _cijena(p._cijena) {}
Proizvod::~Proizvod() {
	delete[] _naziv;   _naziv = nullptr;

	delete[] _opis;   _opis = nullptr;
}

//-------Operators-------
Proizvod& Proizvod::operator=(const Proizvod& p) {
	if (&p == this)
		return *this;
	delete[] _naziv;
	delete[] _opis;
	_naziv = AlocirajNizKaraktera(p._naziv);
	_opis = AlocirajNizKaraktera(p._opis);
	_cijena = p._cijena;
	return *this;
}

//--------Get methods-----
char* Proizvod::getNaziv()const { return AlocirajNizKaraktera(_naziv); }
char* Proizvod::getOpis()const { return AlocirajNizKaraktera(_opis); }
double Proizvod::getCijenu()const { return _cijena; }

void Proizvod::obracunajPopust(double p) { _cijena -= (_cijena*(p / 100)); }
//-----Operators---------
ostream& operator<<(ostream& COUT, const Proizvod& p) {
	if (p._naziv == nullptr)
		return COUT;
	cout << "Naziv: " << p._naziv << endl;
	cout << "Cijena: " << p._cijena << endl;
	cout << "Opis: ";
	if (p._opis == nullptr)
		cout << "--NEMA--\n";
	else
		cout << p._opis << endl;
	return COUT;
}
