#include <iostream>
using namespace std;

// struktura liscia
struct Lisc
{
    int wartosc;
    Lisc* lewy;
    Lisc* prawy;
};

class drzewo
{
private:
    Lisc* korzen;

    // dodawanie do drzewa ktore pobiera wskaznik na poczatkowa drzewa oraz wartosc wpsana
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

    // wyswietlanie rosnaco ktoro pobiera wskaznik na pierwszy element
    void wyswietl(Lisc* korzen)
    {
        if (korzen == nullptr)
            return;

        // najpierw lewe
        wyswietl(korzen->lewy);

        // potem korzen
        cout << korzen->wartosc << " ";

        // na koncu prawe
        wyswietl(korzen->prawy);
    }

public:
    // konstruktor
    drzewo()
    {
        korzen = nullptr;
    }

    // dodawanie jako metoda klasy bioraca wartosc dodawana do drzewa
    void dodaj(int wartosc)
    {
        korzen = dodaj(korzen, wartosc);
    }

    // wyswietlanie jako metoda klasy
    void wyswietl()
    {
        wyswietl(korzen);
    }

    // destruktor
    ~drzewo()
    {
    }
};

int main()
{
    drzewo drzewo1;

    int ile;
    cout << "Ile liczb: ";
    cin >> ile;

    for (int i = 0; i < ile; i++)
    {
        int wartosc;
        cout << "Podaj liczbe: ";
        cin >> wartosc;

        drzewo1.dodaj(wartosc);
    }

    cout << endl;
    cout << "Drzewo rosnaco: ";
    drzewo1.wyswietl();

    return 0;
}
