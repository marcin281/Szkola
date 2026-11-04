#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct dane {
    string id;
    string data;
    float temperatura;
    float wiatr;
};

class pomiary {
public:
    void wczytaj(vector<dane>& Dane){

    ifstream plik("a.txt");
    string napis;

    if (plik.good()) {
        while (getline(plik, napis)) {
            stringstream ss(napis);
            dane d;

            string temperatura, wiatr;

            getline(ss, d.id, ';');
            getline(ss, d.data, ';');
            getline(ss, temperatura, ';');
            getline(ss, wiatr, ';');

            d.temperatura = stof(temperatura);
            d.wiatr = stof(wiatr);

            Dane.push_back(d);
        }

        plik.close();
    }
    }
void min_temp(const vector<dane>& Dane) {
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
void szukaj(const vector<dane>& Dane, float liczba){
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
int main()
{
    float liczba;
    vector<dane> Dane;
    pomiary Pomiary;
    Pomiary.wczytaj(Dane);
    Pomiary.min_temp(Dane);
    cin>>liczba;
    Pomiary.szukaj(Dane, liczba);
    return 0;
}
