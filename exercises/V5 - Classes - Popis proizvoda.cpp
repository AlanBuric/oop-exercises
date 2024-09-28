#include <iostream>
#include <string>

using namespace std;

class Proizvod {
	private:
		string naziv;
		float cijena;
		int kolicina;
	public:
		void unos(string n, float c, int kol);
		
		string get_naziv() {
			return naziv;
		}
		
		float get_cijena() {
			return cijena;
		}
		
		int get_kolicina() {
			return kolicina;
		}
		
		float ukupno() {
			return get_kolicina() * get_cijena();
		}
};

void Proizvod::unos(string n, float c, int kol) {
	naziv = n;
	cijena = c;
	kolicina = kol;
}

int main() {
	Proizvod mlijeko, kruh, sok, salata, cokolada;
	
	mlijeko.unos("Mlijeko 2% 1L", 0.6, 3);
	kruh.unos("Bijeli kruh 500g", 0.5, 1);
	sok.unos("Sok od jabuke 1.5L", 1.2, 1);
	salata.unos("Salata iceberg", 0.3, 1);
	cokolada.unos("Cokolada s ljesnjacima", 0.7, 2);
	
	float ukupno = mlijeko.ukupno() + kruh.ukupno() + sok.ukupno() 
					+ salata.ukupno() + cokolada.ukupno();
	
	cout << "Ukupna cijena popisa proizvoda iznosi " << ukupno << "." << endl;
	
	return 0;
}
