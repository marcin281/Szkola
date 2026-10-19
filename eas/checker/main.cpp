
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class checker {
public:
    void wczytaj(vector<string>& jeden, vector<string>& dwa) {
        ifstream plik("a.txt");
        string napis;
        bool ktory = false;

        if (!plik.is_open()) {
            cout<<"Nie mozna otworzyc pliku a.txt!" << endl;
            return;
        }

        while (getline(plik, napis)) {
            if (napis == "drugi") {
                ktory = true;
                continue;
            }

            if (!ktory) {
                jeden.push_back(napis);
            } else {
                dwa.push_back(napis);
            }
        }

        plik.close();
    }

    void sprawdz(const vector<string>& jeden,
                 const vector<string>& dwa,
                 vector<string>& wspolne,
                 vector<string>& tylkoJeden,
                 vector<string>& tylkoDwa) {

        for (int i=0; i<jeden.size(); i++){
            bool znaleziono = false;

            for (int j = 0; j < dwa.size(); j++){
                if (jeden[i] == dwa[j]) {
                    znaleziono = true;
                    break;
                }
            }

            if (znaleziono) {
                wspolne.push_back(jeden[i]);
            } else {
                tylkoJeden.push_back(jeden[i]);
            }
        }

        for (int i=0; i<dwa.size(); i++){
            bool znaleziono=false;

            for (int j=0; j<jeden.size(); j++){
                if (dwa[i]==jeden[j]){
                    znaleziono = true;
                    break;
                }
            }

            if (!znaleziono){
                tylkoDwa.push_back(dwa[i]);
            }
        }
    }

    void wypisz(const vector<string>& wspolne,
                const vector<string>& tylkoJeden,
                const vector<string>& tylkoDwa) {

        ofstream plik("b.txt");

        if (!plik.is_open()){
            cout << "Nie mozna utworzyc pliku b.txt!" << endl;
            return;
        }

        plik<<"RAPORT:\n";

        plik<<"WSPOLNE:\n";
        for (int i=0; i<wspolne.size(); i++){
            plik<<wspolne[i]<<endl;
        }

        plik<<"TYLKO W PIERWSZYM:\n";
        for (int i=0; i<tylkoJeden.size(); i++){
            plik<<tylkoJeden[i]<<endl;
        }

        plik<<"TYLKO W DRUGIM:\n";
        for (int i=0; i<tylkoDwa.size(); i++){
            plik<<tylkoDwa[i]<<endl;
        }

        plik.close();
    }
};

int main() {
    vector<string> jeden;
    vector<string> dwa;
    vector<string> wspolne;
    vector<string> tylkoJeden;
    vector<string> tylkoDwa;

    checker check;

    check.wczytaj(jeden,dwa);
    check.sprawdz(jeden,dwa,wspolne,tylkoJeden,tylkoDwa);
    check.wypisz(wspolne,tylkoJeden,tylkoDwa);

    return 0;
}
