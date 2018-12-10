#include"pch.h"


//----------Constructors and destructor----------
Klijent::Klijent() :_email(nullptr) {}
Klijent::Klijent(const char* ime, const char* prezime, const char* adresa, const char* telefon, const char* email, int id) :
	Osoba(ime, prezime, adresa, telefon), _email(AlocirajNizKaraktera(email)), _id(id) {}
Klijent::Klijent(const Klijent& k) : Osoba(k), _email(AlocirajNizKaraktera(k._email)), _id(k._id) {
	_narudzbe = k._narudzbe;
}
Klijent::~Klijent() {
	delete[] _email; _email = nullptr;
}

//----------------------Base functions------------------------------------
Osoba::Osoba() {}
Osoba::Osoba(const char* ime, const char* prezime, const char* adresa, const char* telefon) {
	_ime = AlocirajNizKaraktera(ime);
	_prezime = AlocirajNizKaraktera(prezime);
	_adresa = AlocirajNizKaraktera(adresa);
	strncpy_s(_telefon, telefon, _TRUNCATE);
}
Osoba::~Osoba() {
	delete[] _ime;
	delete[] _prezime;
	delete[] _adresa;
	_adresa = _ime = _prezime = nullptr;
}

char* Klijent::getIme()const { return AlocirajNizKaraktera(_ime); }
char* Klijent::getPrezime()const { return AlocirajNizKaraktera(_prezime); }
char* Klijent::getTelefon()const { return AlocirajNizKaraktera((char*)_telefon); }
char* Klijent::getAdresu()const { return AlocirajNizKaraktera(_adresa); }

void Klijent::setIme(const char* ime) { delete[] _ime; _ime = AlocirajNizKaraktera(ime); }
void Klijent::setPrezime(const char* prezime) { delete[] _prezime; _prezime = AlocirajNizKaraktera(prezime); }
void Klijent::setTelefon(const char* telefon) { strncpy_s(_telefon, telefon, _TRUNCATE); }
void Klijent::setAdresu(const char* adresa) { delete[] _adresa; _adresa = AlocirajNizKaraktera(adresa); }

void Klijent::Info()const {
	cout << "Ime i prezime: " << _ime << " " << _prezime << endl;
	cout << "Adresa: " << _adresa << endl;   cout << "Telefon: " << _telefon << endl;
}
//-----------------------------------------------------------------------


//----------Get methods---------------------
Narudzba* Klijent::getNarudzbu(int index) {
	if (_narudzbe.GetTrenutno() > 0)
		if (_narudzbe.GetTrenutno() - 1 < index || index < 0)
			return nullptr;
	return _narudzbe[index];
}

double Klijent::getUtroseno(int index) {
	if (_narudzbe.GetTrenutno() > 0)
		if (_narudzbe.GetTrenutno() - 1 < index || index < 0)
			return NULL;
	return *_narudzbe(index);
}

int getMjesec(const char* datum) {
	if (strlen(datum) < 6)
		return 0;
	int m = 0;
	char* temp = strstr((char*)datum, "/");
	if (temp[1] != '0')
		m = 10;
	m += atoi(&temp[2]);
	return m;
}
int Klijent::getBrojNarudzbi()const { return _narudzbe.GetTrenutno(); }

int Klijent::getID()const { return _id; }

char* Klijent::getEmail()const { return AlocirajNizKaraktera(_email); }
//--------------------------------

bool Klijent::IsPotrosnjaVeca(int mjesec, double potrosnja) {
	if (_narudzbe.GetTrenutno() <= 0)
		return false;
	double ukupno = 0;
	for (int i = 0; i < _narudzbe.GetTrenutno(); i++)
		if (getMjesec(_narudzbe[i]->getDatum()) == mjesec)
			ukupno += _narudzbe[i]->getIznosNarudzbe();
	return potrosnja < ukupno;
}
//---------------Set methods---------------
void Klijent::setEmail(const char* mail) {
	delete[] _email;
	_email = AlocirajNizKaraktera(mail);
}

//-------------Operators---------------
Klijent& Klijent::operator()(Narudzba& n, double x) {
	_narudzbe(n, x);
	return *this;
}


ostream& operator<<(ostream& COUT, const Klijent& k) {
	if (k._email == nullptr || k._id == 0)
		return COUT;
	k.Info();
	cout << "E-mail: " << k._email;
	cout << "\nID klijenta: " << k._id;
	cout << "\n--NARUDZBE--\n";
	if (k._narudzbe.GetTrenutno() <= 0)
		cout << "--NEMA TRENUTNO NARUDZBI--\n";
	else {
		for (int i = 0; i < k._narudzbe.GetTrenutno(); i++)
			cout << k._narudzbe[i] << " - " << k._narudzbe(i) << endl;
	}
	return COUT;
}
