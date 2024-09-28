#include <iostream>

using namespace std;

class Racun {
	private:
		int stanje = 0;
	public:
		void uplati(int iznos) {
			if (iznos <= 0) {
				cout << "Iznos uplate ne smije biti 0 ili negativan.\n";
				return;
			}
			
			stanje += iznos;
		}
		
		int getStanje() {
			return stanje;
		}
		
		void ispis_stanja() {
			cout << "Stanje racuna: " << getStanje() << '\n';
		}
		
		virtual void isplati(int) = 0;
	protected:
		void _isplati(int iznos) {
			stanje -= iznos;
		}
};

class Tekuci : public Racun {
	private:
		int dozvoljeni_minus = 1000;
	public:
		Tekuci() {
		};
		Tekuci(int _dozvoljeni_minus): 
			dozvoljeni_minus(_dozvoljeni_minus) {
		}
		
		void isplati(int iznos) {
			if (getStanje() - iznos < -getDozvoljeniMinus()) {
				cout << "Isplata nije moguca jer prekoracuje dozvoljeni minus.\n";
				return;
			}
			
			_isplati(iznos);
			cout << "Uspjesno je isplaceno " << iznos << "." << '\n';
		}
		
		int getDozvoljeniMinus() {
			return dozvoljeni_minus;
		}
};

class Stednja : public Racun {
	public:
		void isplati(int iznos) {
			if (iznos > getStanje()) {
				cout << "Nemate dovoljno novca na racunu za isplatiti " << iznos << ".\n";
				return;
			}
			
			_isplati(iznos);
			cout << "Uspjesno je isplaceno " << iznos << ".\n";
		}
};

int main() {
	Tekuci tekuci1, tekuci2(500);
	Stednja stednja;
	
	tekuci1.isplati(2000);
	tekuci1.uplati(500);
	tekuci1.isplati(1500);
	
	tekuci2.isplati(501);
	tekuci2.uplati(100);
	
	stednja.isplati(1);
	stednja.uplati(50);
	
	cout << "Stanja:\n" 
		<< tekuci1.getStanje() << "\n" 
		<< tekuci2.getStanje() << "\n"
		<< stednja.getStanje() << "\n"
		<< "Dozvoljeni minusi:\n"
		<< tekuci1.getDozvoljeniMinus() << "\n"
		<< tekuci2.getDozvoljeniMinus() << ".\n";
	
	return 0;
}
