#include <iostream>
#include <list>

using namespace std;

int main() {
	list<string> lista;
	string unos;
	
	cin >> unos;
	
	while (unos != "kraj") {
		lista.push_back(unos);
		cin >> unos;	
	}
	
	return 0;
}