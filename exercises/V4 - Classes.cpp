#include <iostream>
#include <math.h>

using namespace std;

struct Vrijeme {
	int sat;
	int min;
	int sek;
	
	void postavi(int h, int m, int s) {
		sat = 0;
		min = 0;
		sek = 0;
		
		promjeni(h, m, s); // Radi odrzavanja tocnosti
	}
	
	void ispis() {
		cout << sat << ":" << min << ":" << sek << endl;
	}
	
	void promjeni(int a, int b, int c) {
		sat = (sat + a) % 24;
		min = (min + b) % 60;
		sek = (sek + c) % 60;
	}
	
	int sekunde() {
		return sek;
	}
	
	void ispis12() {
		if (sat == 0) {
			cout << 0 << ":" << min << ":" << sek << " AM" << endl;
		} else if (sat == 12) {
			cout << sat << ":" << min << ":" << sek << " PM" << endl;
		} else if (sat < 12) {
			cout << sat << ":" << min << ":" << sek << " AM" << endl;
		} else {
			cout << sat - 12 << ":" << min << ":" << sek << " PM" << endl;
		}
	}
};


int main() {
	Vrijeme v = {12, 23, 40};
	
	v.ispis();
	v.ispis12();
	
	v.promjeni(20, 30, 15);
	v.ispis12();
	
	Vrijeme v2 = {23, 40, 60};
	
	v.ispis12();
	v.promjeni(0, 0, 100);
	v.ispis12();
	
	return 0;
}
