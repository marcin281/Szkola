#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Struktura przechowuj¹ca dane pomiarowe
struct dane {
    string id;
    string data;
    float temperatura;
    float wiatr;
};

class pomiary {
public:

    // Wczytywanie danych z pliku
    void wczytaj(vector<dane>& Dane) {
        try {
            ifstream plik("a.txt");

            // Sprawdzenie, czy plik zosta³ otwarty
            if (!plik.is_open()) {
                throw runtime_error("Nie mozna otworzyc pliku a.txt");
            }

            string napis;

            while (getline(plik, napis)) {
                stringstream ss(napis);
                dane d;

                string temperatura, wiatr;

                // Pobieranie danych oddzielonych srednikami
                getline(ss, d.id, ';');
                getline(ss, d.data, ';');
                getline(ss, temperatura, ';');
                getline(ss, wiatr, ';');

                // Zamiana tekstu na liczby
                d.temperatura = stof(temperatura);
                d.wiatr = stof(wiatr);

                Dane.push_back(d);
            }

            plik.close();
        }
        catch (const exception& e) {
            cout << "Blad podczas wczytywania pliku: "
                 << e.what() << endl;
        }
    }

    // Wyszukiwanie pomiaru z najnizsza temperatura
    void min_temp(const vector<dane>& Dane) {

        // Sprawdzenie, czy wektor zawiera dane
        if (Dane.empty()) {
            cout << "Brak danych do analizy." << endl;
            return;
        }

        string min_i = Dane[0].id;
        string min_d = Dane[0].data;
        float min_t = Dane[0].temperatura;
        float min_w = Dane[0].wiatr;

        for (int i = 0; i < Dane.size(); i++) {

            if (Dane[i].temperatura < min_t) {

                min_i = Dane[i].id;
                min_d = Dane[i].data;
                min_t = Dane[i].temperatura;
                min_w = Dane[i].wiatr;
            }
        }

        cout << "najmniejsza temperatura: "
             << min_i << " "
             << min_d << " "
             << min_t << " "
             << min_w << endl;
    }

    // Wyszukiwanie pomiarow powyzej podanej temperatury
    void szukaj(const vector<dane>& Dane, float liczba) {

        for (int i = 0; i < Dane.size(); i++) {

            if (Dane[i].temperatura > liczba) {

                cout << Dane[i].id << " "
                     << Dane[i].data << " "
                     << Dane[i].temperatura << " "
                     << Dane[i].wiatr << endl;
            }
        }
    }
};

int main() {
    float liczba;
    vector<dane> Dane;
    pomiary Pomiary;

    // Wczytanie danych z pliku
    Pomiary.wczytaj(Dane);

    // Wyswietlenie najnizszej temperatury
    Pomiary.min_temp(Dane);

    // Pobranie temperatury od uzytkownika
    cout << "Podaj temperature: ";
    cin >> liczba;

    // Wyszukanie pomiarow powyzej podanej temperatury
    Pomiary.szukaj(Dane, liczba);

    return 0;
}
