#include <iostream>
#include <string>

using namespace std;

template <class T> void obrniniz(T a[], const int n) {
    T temp;

    for (int i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

template <class T> void ispisiNiz(T a[], const int n, const string separator = " ") {
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << separator;
    }

    cout << a[n - 1];
}

int main() {
    int primjer1[] = {5, 4, 7, 39, 2, -10, 1, 3};
    char primjer2[] = {'b', 'z', '5', '-', '!', 'a', 'd'};
    string primjer3[] = {"abc", "test", "ex", "12"};

    int n1 = sizeof(primjer1) / sizeof(*primjer1),
        n2 = sizeof(primjer2) / sizeof(*primjer2),
        n3 = sizeof(primjer3) / sizeof(*primjer3);

    cout << "Duljine nizova:\n"
        << n1 << ", " << n2 << ", " << n3
        << "\nOriginalni nizovi:\n";
    ispisiNiz(primjer1, n1, ", ");
    cout << '\n';
    ispisiNiz(primjer2, n2);
    cout << '\n';
    ispisiNiz(primjer3, n3);
    cout << '\n';

    obrniniz(primjer1, n1);
    obrniniz(primjer2, n2);
    obrniniz(primjer3, n3);

    cout << "Obrnuti nizovi:\n";
    ispisiNiz(primjer1, n1, ", ");
    cout << '\n';
    ispisiNiz(primjer2, n2);
    cout << '\n';
    ispisiNiz(primjer3, n3);
    cout << '\n';

    return 0;
}
