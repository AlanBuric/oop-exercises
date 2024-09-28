#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct nijeDvoznamenkast {
	bool operator()(int broj) {
		return broj <= -100 || broj >= 100;
	}
};

struct paran {
	bool operator()(int &broj) {
		return (broj & 1) == 0;
	}
};

int zbrojZnamenki(int broj) {
	int zbroj = 0;
	
	while (broj) {
		zbroj += broj % 10;
		broj /= 10;
	}
	
	return zbroj;
}

struct manjiZbrojZnamenki {
	int operator()(int a, int b) {
		return zbrojZnamenki(a) < zbrojZnamenki(b) ? 1 : -1;
	}
};

class jeLiPotencija {
	private:
		double baza;
	public:
		jeLiPotencija(const int baza_): baza(log(baza_)) {
		}
		
		bool operator()(int broj) {
			return (log(broj) / baza) == broj;
		}
};

template<typename T>
class ispisi {
	private:
		string delimiter;
	public:
		ispisi(const string delimiter_ = " "): delimiter(delimiter_) {
		}
		
		void operator()(T &vrijednost) {
			cout << vrijednost << delimiter;
		}
};

const int N = 10;

int main() {
	// Velicina liste je predodredna i ne mijenja se tijekom programa,
	// stoga koristim array strukturu.
	array<int, N> brojevi;
	
	for (int i = 0; i < N; i++) {
		cout << i + 1 << '/' << N << ':';
		cin >> brojevi[i];
	}
	
	int unos;
	
	do {
		cout << "Odaberite operaciju: " << '\n'
			<< "1. Najveci element u nizu" << '\n'
			<< "2. Broj ponavljanja najmanjeg elementa u nizu" << '\n'
			<< "3. Broj parnih brojeva u nizu" << '\n'
			<< "4. Broj potencija broja 2" << '\n'
			<< "5. Element sa najmanjim zbrojem znamenki" << '\n'
			<< "6. Ispis elemenata koji nisu dvoznamenkasti" << '\n'
			<< "0. Izlaz iz programa" << '\n';
		
		cin >> unos;
		
		switch (unos) {
			case 1:
				cout << *max_element(brojevi.begin(), brojevi.end()) << '\n';
				break;
			case 2: {
				int minimum = *min_element(brojevi.begin(), brojevi.end());
				int broj = count(brojevi.begin(), brojevi.end(), minimum);
				
				cout << "Najmanji broj " << minimum << "pojavljuje se " << broj << " puta u nizu.\n";
				break;
			}
			case 3: {
				int broj = count_if(brojevi.begin(), brojevi.end(), paran());
				cout << broj << " je parnih brojeva.\n";
				break;
			}
			case 4: {
				int broj = count_if(brojevi.begin(), brojevi.end(), jeLiPotencija(2));
				cout << broj << " je potencija broja 2.\n";
				break;
			}
			case 5: {
				int minimum = *min_element(brojevi.begin(), brojevi.end(), manjiZbrojZnamenki());
				cout << "Broj " << minimum << "ima najmanji zbroj znamenki.\n";
				break;
			}
			case 6: {
				// Program se rusi
				array<int, N> rezultat;
				copy_if(brojevi.begin(), brojevi.end(), rezultat.begin(), nijeDvoznamenkast());
				for_each(rezultat.begin(), rezultat.end(), ispisi<int>(", "));
				cout << '\n';
				break;
			}
			case 0: break;
			default:
				cout << "Nepoznata vrijednost.\n";
				break;
		}
	} while (unos != 0);
}
