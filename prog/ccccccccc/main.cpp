#include <iostream>

using namespace std;

int NWD ( int a,int b)

{
    while (b=0)
    {
        int reszta = a%b;
        a=b;
        b=reszta;
    }
    return a;
    }
 int main ()
 {
     int a,b ;
    cout << " podaj dwie liczby:";
cin >> a>>b;
if (NWD(a,b) == 1)
        cout << "liczby sa wzglednie pierwsze.";
else
    cout << "liczby nie sa wzglednie pierwsze.";

    return 0;
}
