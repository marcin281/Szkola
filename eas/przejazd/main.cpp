
#include <iostream>
#include <chrono>
#include <conio.h>
using namespace std;

int stan = 0;
// 0 - zamkniety
// 1 - otwieranie
// 2 - otwarty
// 3 - zamykanie
// 4 - alarm

bool pojazd = false;

void otwieranie() {
    stan = 1;
    cout << "Szlaban otwiera sie...\n";

    auto start = chrono::steady_clock::now();

    while (chrono::steady_clock::now() - start < chrono::seconds(5)) {
        if (_kbhit()) {
            char klawisz = _getch();

            if (klawisz == '1' || klawisz == '3') {
                stan = 4;
                cout << "\nALARM! Szlaban zatrzymany!\n";
                return;
            }

            if (klawisz == '4') {
                pojazd = true;
                cout << "\nWykryto pojazd!\n";
                cout << "Wystawiono mandat!\n";
            }
        }
    }

    stan = 2;
    cout << "Szlaban otwarty!\n";
}

void zamykanie() {
    stan = 3;
    cout << "Szlaban zamyka sie...\n";

    auto start = chrono::steady_clock::now();

    while (chrono::steady_clock::now() - start < chrono::seconds(5)) {
        if (_kbhit()) {
            char klawisz = _getch();

            if (klawisz == '1' || klawisz == '3') {
                stan = 4;
                cout << "\nALARM! Szlaban zatrzymany!\n";
                return;
            }

            if (klawisz == '4') {
                pojazd = true;
                cout << "\nWykryto pojazd!\n";
                cout << "Wystawiono mandat!\n";
            }
        }
    }

    stan = 0;
    cout << "Szlaban zamkniety!\n";
}

int main() {
    int przycisk;

    while (true) {
        cout << "\n1 - Nacisnij przycisk";
        cout << "\n3 - Alarm";
        cout << "\n4 - Wykryto pojazd";
        cout << "\n5 - Reset alarmu";
        cout << "\n0 - Wyjscie\n";

        cin >> przycisk;
        pojazd=false;
        if (przycisk == 0) break;

        if (przycisk == 1) {
            if (stan == 0) otwieranie();
            else if (stan == 2) zamykanie();
            else cout << "Niepoprawny przycisk!\n";
        }
        else if (przycisk == 3) {
            if (stan == 1 || stan == 3)
                stan = 4;
            else
                cout << "Szlaban nie jest w ruchu!\n";
        }
        else if (przycisk == 4) {
            if (stan == 1 || stan == 3) {
                pojazd = true;
                cout << "Wykryto pojazd!\n";
            }
            else {
                cout << "Przejazd nie jest w trakcie ruchu!\n";
            }
        }
        else if (przycisk == 5) {
            if (stan == 4) {
                stan = 0;
                cout << "Alarm zresetowany!\n";
            }
        }
        cout<<"\n";
        cout<<"STAN SZLABANU: ";
        if (stan == 0) cout << "zamkniety\n";
        if (stan == 2) cout << "Szlaban otwarty\n";
        if (stan == 1) cout << "otwiera sie\n";
        if (stan == 3) cout << "Szlaban zamyka sie\n";
        cout<<"CZY ALARM: ";
        if (stan == 4) cout << "tak\n";
        else cout<< "nie\n";
        cout<<"CZY MANDAT:";
        if (pojazd) cout<<"tak";
        else cout<<"nie";
        cout<<"\n";
    }

    return 0;
}
