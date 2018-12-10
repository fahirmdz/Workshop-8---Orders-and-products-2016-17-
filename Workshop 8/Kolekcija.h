#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
class Kolekcija {
private:
	T1* _elementi1;
	T2* _elementi2;
	int _trenutno;
public:
	//------Constructors and destructors-----
	Kolekcija() :_elementi1(nullptr), _elementi2(nullptr), _trenutno(0) {}

	Kolekcija(const Kolekcija<T1, T2>& k) : _trenutno(k._trenutno) {
		if (_trenutno > 0) {
			_elementi1 = new T1[_trenutno];
			_elementi2 = new T2[_trenutno];
			for (int i = 0; i < _trenutno; i++) {
				_elementi1[i] = k._elementi1[i];
				_elementi2[i] = k._elementi2[i];
			}
		}
		else {
			_elementi1 = nullptr;
			_elementi2 = nullptr;
		}
	}
	~Kolekcija() {
		delete[] _elementi1; _elementi1 = nullptr;
		delete[] _elementi2; _elementi2 = nullptr;
	}


	//--------------Operators----------------------
	Kolekcija& operator()(T1& el1, T2& el2) {
		T1* temp1 = new T1[_trenutno + 1];   T2* temp2 = new T2[_trenutno + 1];

		for (int i = 0; i < _trenutno; i++) {
			temp1[i] = _elementi1[i];
			temp2[i] = _elementi2[i];
		}

		delete[] _elementi1;
		delete[] _elementi2;

		_elementi1 = temp1;
		_elementi2 = temp2;

		_elementi1[_trenutno] = el1;
		_elementi2[_trenutno] = el2;
		_trenutno++;
		return *this;
	}


	Kolekcija& operator=(const Kolekcija<T1, T2>& k) {
		if (&k == this)
			return *this;
		delete[] _elementi1;
		delete[] _elementi2;
		_trenutno = k._trenutno;
		if (_trenutno > 0) {
			_elementi1 = new T1[_trenutno];
			_elementi2 = new T2[_trenutno];
			for (int i = 0; i < _trenutno; i++) {
				_elementi1[i] = k._elementi1[i];
				_elementi2[i] = k._elementi2[i];
			}
		}
		else {
			_elementi1 = nullptr;
			_elementi2 = nullptr;
		}
		return *this;
	}

	T1* operator[](int index)const {
		if (index<0 || index>_trenutno - 1 || _trenutno <= 0 || _elementi1 == nullptr)
			return nullptr;
		return &_elementi1[index];
	}



	T2* operator()(int index)const {
		if (index<0 || index>_trenutno - 1 || _trenutno <= 0 || _elementi1 == nullptr)
			return nullptr;
		return &_elementi2[index];
	}

	int GetTrenutno() const { return _trenutno; }

	friend ostream& operator<< <>(ostream&, const Kolekcija&);
};
template<class T1, class T2>
ostream& operator<< <>(ostream& COUT, const Kolekcija<T1, T2>& k) {
	if (k._trenutno <= 0 || k._elementi1 == nullptr || k._elementi2 == nullptr)
		return COUT;
	cout << "Trenutno: " << k._trenutno << endl;
	for (int i = 0; i < k._trenutno; i++)
		cout << k._elementi2[i] << " - " << k._elementi1[i] << endl;

	return COUT;
}