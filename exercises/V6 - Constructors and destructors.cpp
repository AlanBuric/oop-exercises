#include <iostream>

using namespace std;

class Pravokutnik {
	private:
		float *a, *b;
	public:
		Pravokutnik(): a(new float(0)), b(new float(0)) {
		}
		
		Pravokutnik(float aa, float bb): 
			a(new float(aa)), b(new float(bb)) {
		}
		
		Pravokutnik(const Pravokutnik& instanca): 
			a(new float(*(instanca.a))), b(new float(*(instanca.b))) {
		}
		
		~Pravokutnik() {
			delete a;
			delete b;
		}
		
		float get_a() {
			return *a;
		}
		
		float get_b() {
			return *b;
		}
		
		void set_a(float new_a) {
			*a = new_a;
		}
		
		void set_b(float new_b) {
			*b = new_b;
		}
		
		void print() {
			cout << get_a() * get_b() << endl;
		}
};

int main() {
	Pravokutnik prvi;
	
	cout << prvi.get_a() << endl << prvi.get_b() << endl;
	prvi.print();
	prvi.set_a(5.3);
	prvi.set_b(3.145);
	prvi.print();
	
	Pravokutnik drugi(prvi);
	
	drugi.print();
	cout << drugi.get_a() << endl;
	drugi.set_b(87.47825);
	drugi.print();
	
	// Namjerno double
	Pravokutnik treci(1 / (double) 3, 5 * 1.234);
	
	cout << treci.get_a() << endl << treci.get_b() << endl;
	treci.print();
	
	return 0;
}
