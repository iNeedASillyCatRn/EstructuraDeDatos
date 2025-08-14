#include <iostream>
#include <cmath>
using namespace std;

string XVI[4] = {"La suma es: ","La resta es: ","La multiplicacion es: ","La division es: "};


float XVII(float XI,float XII){
    return XI+XII;
}
float XVIII(float XI,float XII){
    return XI-XII;
}
float XVIV(float XI,float XII){
    return XI*XII;
}
float XVV(float XI,float XII){
    if (XI == 0 || XII == 0){
        return 0;
    }else{
        return XI/XII;     
    }
}

int main(int argc, char const *argv[])
{
    double a,b;
    cout<<"Introduce 2 numeros: "<<endl;
    cin>>a;
    cin>>b;
    cout<<XVI[0]<<XVII(a,b)<<endl;
    cout<<XVI[1]<<XVIII(a,b)<<endl;
    cout<<XVI[2]<<XVIV(a,b)<<endl;
    if (XVV(a,b) == 0){
        return 0;
    }else{
        cout<<XVI[3]<<XVV(a,b)<<endl;
    }
    return 0;
}
