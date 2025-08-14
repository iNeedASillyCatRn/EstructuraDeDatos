#include <iostream>
using namespace std; 


int XVI(int XI){
    int a;
    for (int i = 0; i <= XI; i++)
    {
        a += i;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int a;
    cout<<"Introduce un numero positivo: ";
    cin>>a;
    if (a > 0)
    {
        cout<<"La sumatoria de "<<a<<" es "<<XVI(a)<<endl;
    }else{
        cout<<"[ERROR]: NUMERO NO POSITIVO.";
    }

    
    return 0;
}

