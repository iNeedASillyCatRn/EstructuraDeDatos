#include <iostream>
#include <string>
using namespace std;

void XVI(){
    std::string asciiArt = R"(
 ____   _ .____  __    _ __    __ .____  __    _ _ .___     ___  
 /   \  | /      |\   |  |     |  /      |\   |  | /   `  .'   `.
 |,_-<  | |__.   | \  |   \    /  |__.   | \  |  | |    | |     |
 |    ` | |      |  \ |    \  /   |      |  \ |  | |    | |     |
 `----' / /----/ |   \|     \/    /----/ |   \|  / /---/   `.__.'                                                                 
    )";
    std::cout<<asciiArt<<std::endl<<std::endl;
    cout<<"ESTA ES UNA FUNCION SIMPLE!"<<endl;
    
}

int XVII(int XI, int XII){
    return XI+XII;
}
void XVIII(string Nombre, int Edad){
    cout<<"[NOMBRE]: "<<Nombre<<endl;
    cout<<"[EDAD]: "<<Edad<<endl;
}
double XIV(){
    return 3.14159;
}
int main(int argc, char const *argv[])
{
    XVI();
    int a = XVII(5,9);
    cout<<"El Resultado de la suma es: "<<a<<endl;
    XVIII("Edgar",6);
    double pi = XIV();
    cout<<"El valor de pi es: "<<pi<<endl;
    return 0;
}


