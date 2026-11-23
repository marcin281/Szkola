
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    const int n = 10;
    int tab[n];

    // Losowanie 10 liczb od 1 do 50
    cout << "Tablica poczatkowa: ";

    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 50 + 1;
        cout << tab[i] << " ";
    }

    cout << endl << endl;

    // Sortowanie przez wstawianie
    for (int i = 1; i < n; i++) {
        int klucz = tab[i];
        int j = i - 1;

        while (j >= 0 && tab[j] > klucz) {
            tab[j + 1] = tab[j];
            j--;
        }

        tab[j + 1] = klucz;

        // Wyswietlanie kazdej proby
        cout << "Proba " << i << ": ";

        for (int k = 0; k < n; k++) {
            cout << tab[k] << " ";
        }

        cout << endl;
    }

    cout << endl << "Tablica posortowana!";

    return 0;
}


