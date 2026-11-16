#include <iostream>

using namespace std;
unsigned long long sumaCyfr(unsigned long long n){
    if(n==0) return 0;
    return n%10+sumaCyfr(n/10);
}

int main(){
    unsigned long long n;
    cin>>n;
    cout<<sumaCyfr(n);
    return 0;
}
