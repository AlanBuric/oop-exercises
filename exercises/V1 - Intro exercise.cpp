#include <iostream>

using namespace std;

struct pravokutnik {
	int a, b;
};

int povrsina(const pravokutnik& p) {
	return p.a * p.b;
}

void povecaj_za(pravokutnik& p, int x) {
	p.a += x;
	p.b += x;
}

void smanji_za(pravokutnik& p, int x) {
	povecaj_za(p, -x);
}

void ispisi(const pravokutnik& p) {
	cout << p.a << " " << p.b << endl;
}

int main() {
	pravokutnik P = {2, 4};
	cout << povrsina(P) << endl;
	povecaj_za(P, 3);
	smanji_za(P, 2);
	ispisi(P);
	
	return 0;
}
