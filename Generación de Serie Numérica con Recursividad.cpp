#include <iostream>
using namespace std;

int XVI(int n){
    if (n==0)
    {
        return 0;
    }else if (n==1)
    {
        return 1;
    }else{
        return XVI(n-1)+XVI(n-1);
    }
}

int main(int argc, char const *argv[])
{
    int Numero;
    cout<<"Introduce un numero: ";
    cin>>Numero;
    cout<<"Serie: ";

    
    for (int i = 0; i < Numero; i++)
    {
        cout<<XVI(i)<<" ";
    }
    
    return 0;
}
