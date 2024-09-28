#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const string SENTINEL = "kraj";

struct value_comparator {
    template<typename K, typename V>
    bool operator()(const pair<K, V> p1, const pair<K, V> p2) {
        return p1.second < p2.second;
    }
};

pair<map<string, int>, map<char, int>> unesi() {
    map<string, int> rijeci;
    map<char, int> slova;

    string unos;

    while (true) {
        cin >> unos;

        if (unos == SENTINEL) {
            break;
        }

        // Navodno je "::" bez icega prije jer je global namespace
        transform(unos.begin(), unos.end(), unos.begin(), ::tolower);

        rijeci[unos]++;

        for (char &slovo : unos) {
            slova[slovo]++;
        }
    }

    return {rijeci, slova};
}

int main() {
    map<string, int> rijeci;
    map<char, int> slova;

    // Odvajanje para u varijable
    tie(rijeci, slova) = unesi();

    auto najcesca_rijec = max_element(rijeci.begin(), rijeci.end(), value_comparator());
    auto najcesce_slovo = max_element(slova.begin(), slova.end(), value_comparator());

    cout << "Najcesa je rijec '" << najcesca_rijec->first
        << "' s " << najcesca_rijec->second << "pojavljivanja, a najcesce je slovo '"
        << najcesce_slovo->first << "' s " << najcesce_slovo->second << " pojavljivanja.\n";

    return 0;
}
