#include <iostream>
#include <string>
using namespace std;

class Pojazd {
private:
    string marka;
    int przebieg;

public:
    Pojazd(string m, int p) : marka(m), przebieg(p) {}

    // Deklaracja funkcji zaprzyjaünionej
    friend void wyswietlDane(const Pojazd& p);
};

// Definicja funkcji zaprzyjaünionej
void wyswietlDane(const Pojazd& p) {
    cout << "Marka: " << p.marka << endl;
    cout << "Przebieg: " << p.przebieg << " km" << endl;
}

// Dziedziczenie
class Samochod : public Pojazd {
private:
    int liczbaDrzwi;

public:
    Samochod(string m, int p, int d) : Pojazd(m, p), liczbaDrzwi(d) {}

    // Funkcja zaprzyjaüniona ma dostÍp takøe do pÛl prywatnych klasy pochodnej
    friend void pokazSzczegoly(const Samochod& s);
};

void pokazSzczegoly(const Samochod& s) {
    // Funkcja zaprzyjaüniona ma dostÍp do pÛl klasy Samochod
    cout << "SamochÛd: ";
    wyswietlDane(s); // uøycie zaprzyjaünionej funkcji z klasy bazowej
    cout << "Liczba drzwi: " << s.liczbaDrzwi << endl;
}

int main() {
    Samochod s("Toyota", 45000, 5);
    pokazSzczegoly(s);

    return 0;
}
