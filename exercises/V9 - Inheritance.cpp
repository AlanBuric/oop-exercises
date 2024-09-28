#include <iostream>

using namespace std;

class Tijelo {
    private:
        float visina, sirina, dubina;
    public:
        Tijelo():
            visina(0), sirina(0), dubina(0) {
        };
        Tijelo(float _visina, float _sirina, float _dubina):
            visina(_visina), sirina(_sirina), dubina(_dubina) {
        };

        float getVisina() {
            return visina;
        }

        float getSirina() {
            return sirina;
        }

        float getDubina() {
            return dubina;
        }
};

class Kvadar : public Tijelo {
    public:
        Kvadar():
            Tijelo() {
        };
        Kvadar(float _visina, float _sirina, float _dubina):
            Tijelo(_visina, _sirina, _dubina) {
        };

        float getOplosje() {
            return 4 * getVisina() * getDubina()
                + 2 * getSirina() * getDubina();
        }

        float getVolumen() {
            return getVisina() * getDubina() * getSirina();
        }
};

class Kocka : private Kvadar {
    public:
        Kocka():
            Kvadar() {
        };
        Kocka(float stranica):
            Kvadar(stranica, stranica, stranica) {
        };

        float getStranica() {
            return getVisina();
        }

        float getOplosje() {
            return 6 * getStranica() * getStranica();
        }

        float getVolumen() {
            return getStranica() * getStranica() * getStranica();
        }
};

int main() {
    Kvadar kvadar(2, 3, 5);
    Kocka kocka(5);

    cout << kvadar.getOplosje() << " " << kvadar.getVolumen() << '\n'
        << kocka.getOplosje() << " " << kocka.getVolumen() << '\n';

    return 0;
}
