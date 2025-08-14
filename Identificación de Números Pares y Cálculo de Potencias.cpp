#include <iostream>
#include <cmath>
using namespace std;

string XVV[4] = {"Introduce un numero: "," es un numero par."," al cuadrado es "," al cubo es "};

bool XVI(int XI){
    if (XI%2==0){
        return true;
    }else{
        return false;
    }
}
int XVII(int XI){
    return pow(XI,2);
}
int XVIII(int XI){
    return pow(XI,3);
}

int main(int argc, char const *argv[])
{
    int a;
    cout<<XVV[0];
    cin>>a;
    cout<<a<<" "<<(XVI(a) ? "si":"no")<<XVV[1]<<endl;
    cout<<a<<XVV[2]<<XVII(a)<<endl;
    cout<<a<<XVV[3]<<XVIII(a)<<endl;
    return 0;
}
