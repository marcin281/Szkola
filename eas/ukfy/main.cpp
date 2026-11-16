#include <iostream>

using namespace std;

string Cezar(int klucz, string tekst)
{
    char kod;
    int dl = tekst.length();
    string szyfrogram = "";

    for (int i=0; i<dl; i++)
    {
        if (tekst[i] == ' ') kod = ' ';
        else
        {
            kod = tekst[i] = klucz;
            if (kod>'Z') kod = kod - 26;
    }
    szyfrogram = szyfrogram + kod;
  }
  return szyfrogram;
}

int main()
{
    string jawny;
    int klucz;

    cout << "Podaj tekst: ";
    getline(cin,jawny);

     cout << "Podaj klucz: ";
     cin >> klucz;

     cout << "Szyfrogram: " << Cezar(klucz,jawny) << endl;

    return 0;
}
