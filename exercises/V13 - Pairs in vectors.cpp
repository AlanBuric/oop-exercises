#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const string SENTINEL = "kraj";

template <typename K>
class key_filter {
    private:
        K value;
    public:
        key_filter(K vrijednost): value(vrijednost) {
        }

        template <typename V>
        bool operator()(pair<K, V> &par) {
            return par.first == this->value;
        }
};

template <typename K, typename V>
typename vector<pair<K, V>>::iterator find_pair(vector<pair<K, V>> &vektor, K &key) {
    return find_if(vektor.begin(), vektor.end(), key_filter<K>(key));
}

vector<pair<string, vector<int>>> unesi() {
    vector<pair<string, vector<int>>> rezultat;
    string unos;

    for (int i = 1; i < INT_MAX; i++) {
        cin >> unos;

        if (unos == SENTINEL) {
            break;
        }

        auto iter = find_pair(rezultat, unos);

        if (iter == rezultat.end()) {
            rezultat.push_back({unos, {i}});
        } else {
            iter->second.push_back(i);
        }
    }

    return rezultat;
}

template <typename E>
string join(vector<E> &elementi, const string &delimiter = ", ") {
    string rezultat = "";

    for (auto &element : elementi) {
        rezultat += to_string(element) + delimiter;
    }

    return rezultat.substr(0, rezultat.size() - delimiter.size());
}

int main() {
    vector<pair<string, vector<int>>> rijeci = unesi();

    for (auto &par : rijeci) {
        cout << "Rijec: " << par.first << '\n'
            << "Redni brojevi: " << join(par.second, " ") << '\n'
            << "Ucestalost: " << par.second.size() << '\n';
    }

    return 0;
}
