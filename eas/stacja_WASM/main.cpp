#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <emscripten.h>

using namespace std;

// Struktura przechowująca dane pomiarowe
struct dane {
    string id;
    string data;
    float temperatura;
    float wiatr;
};

class pomiary {
public:

    // Wczytywanie danych z pliku pobierajaca adres pamieci Dane
    void wczytaj(vector<dane>& Dane) {
        try {
            ifstream plik("a.txt");

            // Sprawdzenie, czy plik został otwarty
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

    // Wyszukiwanie pomiaru z najnizsza temperatura pobierajaca const adres pamieci Dane
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

    // Wyszukiwanie pomiarow powyzej podanej temperatury pobierajaca const adres pamieci Dane
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

// Obiekt klasy
pomiary Pomiary;

// Wektor przechowujacy dane
vector<dane> Dane;

// Funkcje do komunikacji z JavaScriptem
extern "C" {

    // Wczytywanie danych i wyswietlanie minimum
    EMSCRIPTEN_KEEPALIVE
    const char* wczytaj() {

        static string wynik;

        Dane.clear();

        Pomiary.wczytaj(Dane);

        if (Dane.empty()) {
            wynik = "Brak danych do analizy.";
            return wynik.c_str();
        }

        // Przechwycenie wyniku min_temp
        stringstream ss;
        streambuf* stare = cout.rdbuf(ss.rdbuf());

        Pomiary.min_temp(Dane);

        cout.rdbuf(stare);

        wynik = ss.str();

        return wynik.c_str();
    }

    // Wyszukiwanie pomiarow powyzej podanej temperatury
    EMSCRIPTEN_KEEPALIVE
    const char* szukaj(float liczba) {

        static string wynik;

        // Przechwycenie wyniku szukaj
        stringstream ss;
        streambuf* stare = cout.rdbuf(ss.rdbuf());

        Pomiary.szukaj(Dane, liczba);

        cout.rdbuf(stare);

        wynik = ss.str();

        if (wynik.empty()) {
            wynik = "Brak pomiarow powyzej podanej temperatury.";
        }

        return wynik.c_str();
    }
}
