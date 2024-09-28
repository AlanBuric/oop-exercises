#include <iostream>
#include <list>

using namespace std;

void zbroji(list<double> L, double pribrojnik) {
	for (list<double>::iterator iter = L.begin(); iter != L.end(); iter++){
		*iter += pribrojnik;
	}
}

int main() {
	return 0;
}