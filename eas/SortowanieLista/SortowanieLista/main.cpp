#include <iostream>
#include <fstream>

using namespace std;

// Struktura elementu listy
struct kolejka {
    int liczba;
    kolejka* next;
};

// Klasa obs³uguj¹ca listê
class lista {
    kolejka* poczatek;

public:

    // Konstruktor
    lista() {
        poczatek = nullptr;
    }

    // Dodawanie elementu na koniec listy
    void dodaj(int wartosc) {
        kolejka* nowa = new kolejka;
        nowa->liczba = wartosc;
        nowa->next = nullptr;

        if (poczatek == nullptr) {
            poczatek = nowa;
        }
        else {
            kolejka* temp = poczatek;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = nowa;
        }
    }

    // Zapisywanie listy do pliku
    void zapisz() {
        ofstream plik("b.txt");

        if (!plik) {
            cout << "Nie udalo sie otworzyc pliku!\n";
            return;
        }

        kolejka* temp = poczatek;

        while (temp != nullptr) {
            plik << temp->liczba << endl;
            temp = temp->next;
        }

        plik.close();

        cout << "Dane zostaly zapisane do pliku.\n";
    }

    // Wczytywanie listy z pliku
    void wczytaj() {
        ifstream plik("a.txt");

        if (!plik) {
            cout << "Nie udalo sie otworzyc pliku!\n";
            return;
        }

        int wartosc;

        while (plik >> wartosc) {
            dodaj(wartosc);
        }

        plik.close();

        cout << "Dane zostaly wczytane z pliku.\n";
    }

    // Wyœwietlanie listy
    void wyswietl() {
        kolejka* temp = poczatek;

        while (temp != nullptr) {
            cout << temp->liczba << " ";
            temp = temp->next;
        }

        cout << endl;
    }
    //sortowanie babelkowe
    void bubble() {
        bool zamiana;

        do {
            zamiana = false;

            kolejka* temp = poczatek;

            while (temp != nullptr && temp->next != nullptr) {

                if (temp->liczba > temp->next->liczba) {

                    int pom = temp->liczba;
                    temp->liczba = temp->next->liczba;
                    temp->next->liczba = pom;

                    zamiana = true;
                }

                temp = temp->next;
            }

        } while (zamiana);
    }

    // Destruktor
    ~lista() {
        kolejka* temp;

        while (poczatek != nullptr) {
            temp = poczatek;
            poczatek = poczatek->next;
            delete temp;
        }
    }
};

int main()
{
    lista kolejka;

    int choice;

    do {
        cout << "\nCo chcesz zrobic?\n";
        cout << "1 - wczytaj z pliku\n";
        cout << "2 - wyswietl liste\n";
        cout << "3 - posortuj liste\n";
        cout << "4 - zapisz do pliku\n";
        cout << "0 - zamknij program\n";
        cout << "Wybor: ";

        cin >> choice;

        switch (choice) {

        case 1:
            kolejka.wczytaj();
            break;

        case 2:
            kolejka.wyswietl();
            break;
        case 3:
            kolejka.bubble();
            break;
        case 4:
            kolejka.zapisz();
            break;

        case 0:
            cout << "Koniec programu.\n";
            break;

        default:
            cout << "Nieprawidlowy wybor!\n";
        }

    } while (choice != 0);

    return 0;
}
