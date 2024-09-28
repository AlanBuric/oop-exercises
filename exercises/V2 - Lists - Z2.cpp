#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> lista;
	int unos;
	
	cin >> unos;
	
	while (unos) {
		if (unos & 1) lista.push_back(unos);
		else lista.push_front(unos);
		
		cin >> unos;	
	}
	
	return 0;
}