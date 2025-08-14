#include <iostream>
#include <cmath>
using namespace std;



float Suma(float a, float b){
    float x = a+b;
    return x;
}

float Resta(float a, float b){
    float x = a-b;
    return x;
}

float Mult(float a, float b){
    float x = a*b;
    return x;
}

float Div(float a,float b){
    if (a == 0 || b == 0)
    {
        cout<<"No puedes divir entre 0"<<endl;
        return 0;
    }else{
        float x = a/b;
        return x;
    }
}

int main(int argc, char const *argv[])
{
    double a,b;
    char OPERATORS[4] = {'+','-','*','/'};
    cout<<"TIPO DE OPERACION: "<<endl<<"SUMA [+]"<<endl<<"RESTA [-]"<<endl<<"MULTIPLICACION [*]"<<endl<<"DIVISION [/]"<<endl;
    char x;
    cin>>x;

    cout<<"Introduce numero 1"<<endl;
    cin>>a;
    cout<<"Introduce numero 2"<<endl;
    cin>>b;

    
    switch (x)
    {
    case '+':
        cout<<"Tu resultado es: "<<Suma(a,b)<<endl;
        break;
    case '-':
        cout<<"Tu resultado es: "<<Resta(a,b)<<endl;
        break;
    case '*':
        cout<<"Tu resultado es: "<<Mult(a,b)<<endl;
        break;
    case '/':
        if (Div(a,b) == 0){
            return 0;
        }
        cout<<"Tu resultado es: "<<Div(a,b)<<endl;
        break;
    default:
        cout<<"OPERACION NO VALIDA"<<endl;
        return 0;
        break;
    }
    system("PAUSE");
    return 0;
}


