#include <iostream>
#include <fstream>
#include <list>

using namespace std;

struct Vino {
    int sifra;
    char naziv[16];
    float cijena;
};

bool izmijeni_cijenu(list<Vino> & podaci, int sifra, float nova_cijena) {
    for (list<Vino>::iterator iter = podaci.begin(); iter != podaci.end(); iter++) {
        if (iter->sifra == sifra) {
            iter->cijena = nova_cijena;
            return true;
        }
    }

    return false;
}

bool izbrisi_vino(list<Vino> & podaci, int sifra) {
    for (list<Vino>::iterator iter = podaci.begin(); iter != podaci.end(); iter++) {
        if (iter->sifra == sifra) {
            podaci.erase(iter);
            return true;
        }
    }

    return false;
}

void zamijeni_dva_vina(list<Vino> & podaci, int sifra1, int sifra2) {
    list<Vino>::iterator vino1, vino2;

    // Umjesto dvije boolean varijable kodiram jedan bajt gdje zadnja 2 LSB
    // kodiraju stanje pronadenosti dvaju vina.
    char found = 0;

    for (list<Vino>::iterator iter = podaci.begin(); iter != podaci.end(); iter++) {
        if (iter->sifra == sifra1) {
            vino1 = iter;
            found |= 1;
        } else if (iter->sifra == sifra2) {
            vino2 = iter;
            found |= 2;
        }

        // 1 × 2^0 + 1 × 2^1 = 3 kada su oba pronadena.
        if (found == 3) {
            break;
        }
    }

    switch (found) {
        case 0:
            cout << "Nijedno vino nije pronadeno s tim siframa." << endl;
            break;
        case 1:
            cout << "Drugo vino nije pronadeno s tom sifrom." << endl;
            break;
        case 2:
            cout << "Prvo vino nije pronadeno s tom sifrom." << endl;
            break;
        case 3:
            {
                // std::swap(vino1, vino2); // Ne radi
                Vino temp = *vino1;
                *vino1 = *vino2;
                *vino2 = temp;
            }
            cout << "Poredak trazenih vina je uspjesno zamijenjen." << endl;
            break;
//        default:
//            cout << "Doslo je do nepoznate pogreske." << endl;
//            break;
    }
}

bool usporedi_sifre(Vino & v1, Vino & v2) {
    return v1.sifra < v2.sifra;
}

void save_file(fstream & datoteka, list<Vino> & podaci) {
    datoteka.seekg(0, ios::beg);

    for (list<Vino>::iterator iter = podaci.begin(); iter != podaci.end(); iter++) {
        datoteka.write((char * ) & * iter, sizeof(Vino));
    }
}

list<Vino> read_file(fstream & datoteka) {
    list<Vino> vina;
    Vino temp;

    datoteka.seekg(0, ios::beg);
    datoteka.read((char * ) & temp, sizeof(Vino));

    while (!datoteka.eof()) {
        vina.push_back(temp);
        datoteka.read((char * ) & temp, sizeof(Vino));
    }

    return vina;
}

// Nacin funkcioniranja: u listu ucitavam datoteku, promjene radim samo u listi, pa tek
// na kraju rada s programom overwriteam datoteku vrijednostima iz liste.
int main() {
    fstream datoteka("listavina.dat", ios::in | ios::out | ios::binary);

    if (!datoteka) {
        cout << "Datoteka nije pronadena. Kraj rada." << endl;
        return 0;
    }

    list<Vino> podaci = read_file(datoteka);

    datoteka.close();
    int izbor;

    do {
        cout << "============F U N K C I J E===========" << endl <<
            "1. Ispis liste vina" << endl //ispo?etka u?ita sadr?aj datoteke u listu i ispi?e ga na zaslon
            << "2. Dodavanje novog vina na listu" << endl //dodaje novo vino u listu i datoteku
            << "3. Izmjena cijene vina" << endl //za jedno od vina na listi i u datoteci se mijenja ?ifra
            << "4. Brisanje vina sa liste" << endl //vino sa upisanom sifrom se bri?e iz liste i datoteke
            << "5. Sortiranje liste vina po sifri" << endl //sortiraju se podaci o vinima u listi i datoteci po sifri
            << "6. Zamjena redoslijeda dva vina u listi" << endl //mijenja redoslijed dva vina u listi i datoteci
            << "0. Izlaz" << endl << endl
            << "Izbor: ";

        cin >> izbor;

        switch (izbor) {
        case 1:
            for (list<Vino>::iterator iter = podaci.begin(); iter != podaci.end(); iter++) {
                cout << iter->sifra << ": " << iter->naziv << ", " << iter->cijena << endl;
            }
            break;
        case 2: {
            Vino novo_vino;
            bool nastavi = false;

            do {
                nastavi = false;

                cout << "Unesite sifru novog vina: ";
                cin >> novo_vino.sifra;

                for (list<Vino>::iterator iter = podaci.begin(); iter != podaci.end(); iter++) {
                    if (iter->sifra == novo_vino.sifra) {
                        cout << "Vino s tom sifrom vec postoji." << endl;
                        nastavi = true;
                        break;
                    }
                }
            } while (nastavi);

            cout << "Unesite naziv novog vina: ";
            cin >> novo_vino.naziv;

            cout << "Unesite cijenu novog vina: ";
            cin >> novo_vino.cijena;

            podaci.push_back(novo_vino);

            cout << "Novo je vino dodano." << endl;
        }
        break;
        case 3: {
            int sifra;
            float nova_cijena;

            cout << "Unesite sifru vina za izmjenu cijene: ";
            cin >> sifra;

            cout << "Unesite novu cijenu: ";
            cin >> nova_cijena;

            if (izmijeni_cijenu(podaci, sifra, nova_cijena)) {
                cout << "Cijena je uspjesno izmijenjena." << endl;
            } else {
                cout << "Ne postoji vino s tom sifrom." << endl;
            }
        }
        break;
        case 4: {
            int sifra;

            cout << "Unesite sifru vina za brisanje: ";
            cin >> sifra;

            if (izbrisi_vino(podaci, sifra)) {
                cout << "Vino je uspjesno izbrisano." << endl;
            } else {
                cout << "Vino s tom sifrom ne postoji." << endl;
            }
        }
        break;
        case 5:
            podaci.sort(usporedi_sifre);
            cout << "Sortirano!" << endl;
            break;
        case 6:
            int sifra1, sifra2;

            cout << "Sifra prvog vina: ";
            cin >> sifra1;

            cout << "Sifra drugog vina: ";
            cin >> sifra2;

            zamijeni_dva_vina(podaci, sifra1, sifra2);
            break;
        }
    } while (izbor != 0);

    cout << "Spremam..." << endl;

    datoteka.open("listavina.dat", ios::out | ios::binary);
    save_file(datoteka, podaci);

    cout << "Spremljeno!" << endl;

    return 0;
}
