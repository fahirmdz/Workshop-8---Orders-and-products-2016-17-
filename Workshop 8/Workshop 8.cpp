//fahirmdz GitHub

#include"pch.h"
#include<type_traits>
//U programu implementirati nasljeđivanje između odgovarajućih klasa 

//Funkcija treba da pronađe sve one klijente koji su za odabrani mjesec ostvarili potrošnju veću
//od zadate. Ispisati njihove podatke i vratiti ukupan broj pronađenih klijenata. 

void print(Osoba* o) {
	if (dynamic_cast<VIPKlijent*>(o) != nullptr)
		cout << *dynamic_cast<VIPKlijent*>(o) << endl;
	else
		cout << *dynamic_cast<Klijent*>(o) << endl;
}

int PronadjiKlijentePoPotrosnji(Osoba* niz[], int max, double potrosnja) {
	if (max <= 0)
		return 0;
	int uk = 0;

	Klijent** temp = new Klijent*[max];
	for (int i = 0; i < max; i++)
		temp[i] = static_cast<Klijent*>(niz[i]);

	int mjesec;
	do {
		cout << "Unesite mjesec za koji zelite provjeriti potrosnju(1 do 12, 0 - EXIT): ";
		cin >> mjesec;
		if (mjesec < 0 || mjesec>12)
			cout << "Greska!Unijeli ste neispravan format mjeseca..\n";
	} while ((mjesec < 0 || mjesec>12) && mjesec != 0);

	cout << "-----Podaci klijenata koji su imali potrosnju vecu od zadate---\n==================================================\n";
	for (int i = 0; i < max; i++)
		if (temp[i]->IsPotrosnjaVeca(mjesec, potrosnja)) {
			print(temp[i]);
			uk++;
		}
	if (uk == 0)
		cout << "---LISTA PRAZNA--\n\n";

	return uk;
}

//Pronaći sve VIP klijente, te im dodati gratis proizvod proslijeđen kao parametar. 
void UkljuciGratisProizvodVIPKlijentima(Osoba* niz[], int max, const Proizvod& p) {
	if (max <= 0)
		return;
	for (int i = 0; i < max; i++)
		if (dynamic_cast<VIPKlijent*>(niz[i]) != nullptr)
			if (dynamic_cast<VIPKlijent*>(niz[i])->getBrojNarudzbi() > 0)
				dynamic_cast<VIPKlijent*>(niz[i])->operator()(p);
}

//Svim klijentima postaviti mail adresu u formatu: ime.prezime@firma.ba.
void GenerisiMailAdreseKlijentima(Osoba* niz[], int max) {
	if (max <= 0)
		return;
	int uk = 0;

	Klijent** temp = new Klijent*[max];
	for (int i = 0; i < max; i++) {
		temp[i] = static_cast<Klijent*>(niz[i]);
		char *newMail = new char[80];
		strcpy_s(newMail, 80, temp[i]->getIme());
		strcat_s(newMail, 80, ".");
		strcat_s(newMail, 80, temp[i]->getPrezime());
		strcat_s(newMail, 80, "@firma.ba");
		temp[i]->setEmail(newMail);
	}
}

//Omogućiti pretragu klijenata po imenu ili prezimenu (ispisati informacije
//o svim klijentima koji sadrže uneseni tekst u dijelu imena ili prezimena.
void PronadjiKlijentePoImenuPrezimenu(Osoba* niz[], int max) {
	if (max <= 0)
		return;
	int izbor;
	Klijent** temp = new Klijent*[max];
	for (int i = 0; i < max; i++)
		temp[i] = static_cast<Klijent*>(niz[i]);
	do {
		cout << "Pretragu zelite po imenu ili prezimenu?(1-IME,2-PREZIME,0-EXIT): ";
		cin >> izbor;
		if (izbor < 0 || izbor>2)
			cout << "Greska! Ponovite unos..\n";
	} while ((izbor < 0 || izbor>2) && izbor != 0);
	cin.ignore();
	if (izbor == 1) {
		char *ime = new char[50];
		cout << "Unesite ime: ";
		cin.getline(ime, 50);
		for (int i = 0; i < max; i++) {
			if (strcmp(ime, temp[i]->getIme()) == 0) {
				cout << "\nKlijent pronadjen..\n";
				print(temp[i]);
				return;
			}
		}
		cout << "\nKlijent nije pronadjen..\n";
	}
	if (izbor == 2) {
		char *pr = new char[50];
		cout << "Unesite prezime: ";
		cin.getline(pr, 50);
		for (int i = 0; i < max; i++) {
			if (strcmp(pr, temp[i]->getPrezime()) == 0) {
				cout << "\nKlijent pronadjen..\n";
				print(temp[i]);
				return;
			}
		}
		cout << "\nKlijent nije pronadjen..\n";
	}
}

int main() {
	//Testirati sve dostupne funkcionalnosti uz obaveznu provjeru globalnih funkcija. 
	//VIP klijentima sve narudžbe kreirati uz zaračunati popust pozivom odgovarajuće funkcije. 
	Osoba** Klijenti = new Osoba*[10];
	Klijenti[0] = new VIPKlijent("Jo", "Newman", "Rossenberg 1", "09857588", "joros@live.com", 262, "ID122", 10.00);
	Klijenti[1] = new Klijent("Mo", "Salah", "Gad 1", "0638759823", "iko@live.com", 125);
	Klijenti[2] = new Klijent("John", "Sterling", "Simons 2", "04431233", "joh@live.com", 100);
	Klijenti[3] = new VIPKlijent("Efes", "Cok", "Grimmons 3", "058584323", "efes@live.com", 122, "ID132", 20.00);

	GenerisiMailAdreseKlijentima(Klijenti, 2);
	for (int i = 0; i < 4; i++)
		print(Klijenti[i]);
	cin.get();
	system("cls");

	Narudzba n("01/01/2019");
	n(Proizvod("Smoki", "Slano", 4.5), 3);
	n(Proizvod("Jaffa", "Slatko", 5.3), 5);

	Narudzba n1("01/02/2019");
	n1(Proizvod("Marshmallow", "Slatko", 4.5), 3);
	n1(Proizvod("Orbit", "Zvake", 7.3), 2);
	n1(Proizvod("Chips", "Marble", 2.3), 1);

	Narudzba n2("01/03/2019");
	n2(Proizvod("Cheesese", "Slano", 1.4), 3);
	n2(Proizvod("Joghurt", "Slano", 2.7), 5);
	n2(Proizvod("Napolitanke", "Slatko", 9.7), 2);
	n2(Proizvod("Jaffa", "Slatko", 1), 1);

	if (dynamic_cast<VIPKlijent*>(Klijenti[0]) != nullptr)
		dynamic_cast<VIPKlijent*>(Klijenti[0])->operator()(n, n.getIznosNarudzbe());
	else
		dynamic_cast<Klijent*>(Klijenti[0])->operator()(n, n.getIznosNarudzbe());



	UkljuciGratisProizvodVIPKlijentima(Klijenti, 4, Proizvod("King Sladoled", "Frikom", 4));
	print(Klijenti[0]);
	cin.get();
	system("cls");
	//PronadjiKlijentePoImenuPrezimenu(Klijenti, 4);

	cout << "Ukupno je " << PronadjiKlijentePoPotrosnji(Klijenti, 4, 30) << " klijenata koji su imali potrosnju vecu od 30 BAM..\n";

	system("PAUSE");
	system("cls");

	cout << "Ukupno je " << PronadjiKlijentePoPotrosnji(Klijenti, 4, 40) << " klijenata koji su imali potrosnju vecu od 40 BAM..\n";

	return 0;
}