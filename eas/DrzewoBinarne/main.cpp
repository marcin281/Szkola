#include <iostream>
using namespace std;

// struktura liscia
struct Lisc
{
    int wartosc;
    Lisc* lewy;
    Lisc* prawy;
};

// dodawanie do drzewa
Lisc* dodaj(Lisc* korzen, int wartosc)
{
    // jesli drzewo jest puste
    if (korzen == nullptr)
    {
        Lisc* nowy = new Lisc;
        nowy->wartosc = wartosc;
        nowy->lewy = nullptr;
        nowy->prawy = nullptr;

        return nowy;
    }

    // jesli liczba jest mniejsza od poprzedniej liczby
    if (wartosc < korzen->wartosc)
    {
        korzen->lewy = dodaj(korzen->lewy, wartosc);
    }
    // jesli liczba jest wieksza od poprzedniej liczby
    else
    {
        korzen->prawy = dodaj(korzen->prawy, wartosc);
    }

    return korzen;
}
// wyswietlanie drzewa
void wyswietl(Lisc* korzen)
{
    if (korzen == nullptr)
        return;

    cout << korzen->wartosc << " ";

    wyswietl(korzen->lewy);
    wyswietl(korzen->prawy);
}
int main()
{
    Lisc* korzen = nullptr;

    int ile;
    cout << "Ile liczb: ";
    cin >> ile;

    for (int i = 0; i < ile; i++)
    {
        int wartosc;
        cout << "Podaj liczbe: ";
        cin >> wartosc;
        korzen = dodaj(korzen, wartosc);
    }
    // wyswietlanie drzewa
    cout << endl;
    cout << "Drzewo: ";
    wyswietl(korzen);

    return 0;
}
