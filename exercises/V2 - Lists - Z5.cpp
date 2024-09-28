#include <iostream>
#include <list>

using namespace std;

int main() {
	list<string> lista;
	string unos;
	
	cin >> unos;
	
	// Nije specificirano koja je sentinel vrijednost ili nacin za unose	
	while (unos != "kraj") {
		for (char c : unos) lista.push_back({c});
		lista.push_back(unos);
		
		cin >> unos;
	}
	
	return 0;
}