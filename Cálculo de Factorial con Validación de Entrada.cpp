#include <iostream>
using namespace std;

bool ErrorCheck(int a){
    if (a <= 0)
    {
        return true;
    }else {
        return false;
    }
    
}


int XI(int XII){
    if (XII <= 0) return 0;
    int XIII;
    XIII = XII;

    for (int i = 1; i < XII; i++)
    {
       // cout<<i;
        XIII = XIII*i;
    }
    return XIII;
}



int main(int argc, char const *argv[])
{   
    int a;
    bool err = false;

    do
    {
        cout<<"Selecciona un numero: ";
        cin>>a;
        if (ErrorCheck(a))
        {
            cout<<"Introduce un numero mayor a 0."<<endl;
            err = true;
            system("PAUSE");
            system("cls");
        }else{
            cout<<"Factorial es: "<<XI(a)<<endl;
            err = false;
        }
    } while (err == true);
    system("PAUSE");

    
    return 0;
}
