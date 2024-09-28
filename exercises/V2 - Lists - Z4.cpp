#include <iostream>
#include <list>

using namespace std;

bool IsSorted(list<char>& L) {
    list<char>::iterator iter = L.begin();
    
	for (auto prev = iter++; iter != L.end(); iter++, prev++) {
		if (*prev < *iter) return false;
	}
	
	return true;
}

int main() {
	return 0;
}