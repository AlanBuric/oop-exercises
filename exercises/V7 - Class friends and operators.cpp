#include <iostream>

using namespace std;

class Vrijeme{
	private:
		int sat, minute, sekunde;
		
		void fix_negative_overflow() {
			while (sekunde < 0) {
				sekunde += 60;
				minute -= 1;
			}
			
			while (minute < 0) {
				minute += 60;
				sat -= 1;
			}
			
			while (sat < 0) {
				sat += 24;
			}
		}
		
		void fix_positive_overflow() {
			minute += sekunde / 60;
			sekunde %= 60;
			
			sat += minute / 60;
			minute %= 60;
			
			sat %= 24;
		}
	public:
		Vrijeme() : sat(0), minute(0), sekunde(0) {}
		Vrijeme(int hour, int min, int sec = 1) : sat(hour), minute(min), sekunde(sec) {
			fix_negative_overflow();
			fix_positive_overflow();
		}
		
		Vrijeme operator+(const Vrijeme& drugo) {
			return Vrijeme(sat + drugo.sat, minute + drugo.minute, sekunde + drugo.sekunde);
		}
		
		void operator-=(const Vrijeme&);
		
		friend ostream& operator<<(ostream&, const Vrijeme&);
		
		Vrijeme operator++(int) { // v++
			Vrijeme temp = *this;
			
			sekunde++;
			fix_positive_overflow();
			
			return temp;
		}
		
		Vrijeme operator++() { // ++v
			++sekunde;
			
			fix_positive_overflow();
			
			return *this;
		}
		
		bool operator<(const Vrijeme& drugo) {
//			if (sat < drugo.sat) {
//				return true;
//			} else if (sat == drugo.sat) {
//				if (minute < drugo.minute) {
//					return true;
//				} else if (minute == drugo.minute) {
//					if (sekunde < drugo.sekunde) {
//						return true;
//					}
//				}
//			}
			
			//return false;
			// Optimizacija: A || (B && (C || D && E))
			return sat < drugo.sat || 
				(sat == drugo.sat && 
					(minute < drugo.minute || 
						minute == drugo.minute && sekunde < drugo.sekunde));
		}
};

void Vrijeme::operator-=(const Vrijeme& drugo) {
	sat -= drugo.sat;
	minute -= drugo.minute;
	sekunde -= drugo.sekunde;
	
	fix_negative_overflow();
}

ostream& operator<<(ostream& tok, const Vrijeme& drugo) {
	tok << drugo.sat << ":" << drugo.minute << ":" << drugo.sekunde;
}

int main() {
	Vrijeme sada(18, 7, 20);
	Vrijeme za10min(18, 17, 20);
	
	cout << sada << endl;
	cout << sada << " " << za10min << endl;
	
	sada++;
	
	cout << sada << endl;
	sada -= za10min;
	cout << sada << endl;
	
	cout << "Je li 'sada' vece od 'za10min'?" << endl;
	cout << ((sada < za10min) ? "Manje je!" : "Vece je!") << endl;
	
	Vrijeme novo(25, 894, 3);
	
	cout << novo << endl;
	cout << (novo + sada) << endl;
	
	Vrijeme usporedba(25, 894, 3);
	cout << (usporedba < novo) << endl;
	cout << (novo < usporedba) << endl;
	usporedba++;
	
	cout << (novo < usporedba) << endl;
	
	return 0;
}
