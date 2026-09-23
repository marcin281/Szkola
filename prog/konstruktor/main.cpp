#include <iostream>

using namespace std;
//struktura linked listy z zmienna typu int
struct kolejka{
int liczba;
kolejka* next;
};
//klasa obslugujaca liste
class lista{
    //wzkaznik na poczatek listy
kolejka* poczatek;
public:
    //konstruktor ustawiajacy oczatek listy na pointer null
    lista(){
        poczatek=nullptr;
    }
    //zmmienna dodajaca element do listy, wczytuje int wartosc z main
    void dodaj(int wartosc){
        kolejka* nowa=new kolejka;
        nowa->liczba=wartosc;
        nowa->next=nullptr;
        if(poczatek==nullptr) poczatek=nowa;
        else{
            kolejka* temp= poczatek;
            while(temp->next!=nullptr) temp=temp->next;
                temp->next=nowa;
        }
    }
    //destruktor listy usuwajacy kazdy nastepny element listy od pocztku dopoki poczatek listy nie bedzie rowny null pointer
    ~lista(){
    kolejka* temp;
    while(poczatek!=nullptr){
        temp=poczatek;
        poczatek=poczatek->next;
        delete temp;
    }
    }
};
//funkcja main w ktorej jest tworzona lista i sa dodane 3 elementy
int main()
{
    lista kolejka;
    kolejka.dodaj(10);
    kolejka.dodaj(10);
    kolejka.dodaj(10);
    return 0;
}
