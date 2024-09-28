#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

const unordered_set<char> SENTINELI {'.', '?', '!'};

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

vector<pair<char, int>> unesi() {
    vector<pair<char, int>> rezultat;
    char unos;

    while (true) {
        cin >> unos;

        if (SENTINELI.find(unos) != SENTINELI.end()) {
            break;
        }

        auto iter = find_pair(rezultat, unos);

        if (iter == rezultat.end()) {
            rezultat.push_back({unos, 1});
        } else {
            *iter = {unos, iter->second + 1};
        }
    }

    return rezultat;
}

int main() {
    vector<pair<char, int>> slova = unesi();

    for (auto &par : slova) {
        cout << par.first << " " << par.second << '\n';
    }

    return 0;
}
