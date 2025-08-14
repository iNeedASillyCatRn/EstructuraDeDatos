#include <iostream>
using namespace std;

unsigned long long XVI(unsigned int  n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * XVI(n-1);
}

int main(int argc, char const *argv[])
{
    unsigned int XI;
    cout<<"Ingresa un numero: ";
    cin>>XI;
    cout<<"El factorial de: "<<XI<<" es: "<<XVI(XI)<<endl;
    
    return 0;
}
