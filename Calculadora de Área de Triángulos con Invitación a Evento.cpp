#include <iostream>
#include <ctime>
using namespace std;


void InvitacionIniciar(string Evento, string Lugar, string Date){
    std::cout<<"[#] Ha sido invitado a el evento: "<<Evento<<"! [#]"<<std::endl;
    std::cout<<"[!] "<<"El evento se dara en la ubicacion de: "<<Lugar<<" [!]"<<std::endl;
    std::cout<<"[!] Nuestro evento sera presentado en la fecha: "<<Date;
    std::cout<<"[-] NO FALTES A NUESTRO EVENTO! [-]"<<std::endl; 
}
void Separador(){
    std::cout<<"\n"<<"[###########################################################################]"<<"\n"<<"\n";
}
void InicioArea(){
    std::cout<<"BIENVENIDO A CALCULADORA DE AREA DE TRIANGULOS"<<std::endl;
}

float A_Triangulo(float b, float h){
    return (b*h)/2;
}

int main(int argc, char const *argv[])
{
    float a;
    float b;
    time_t timestamp;
    time(&timestamp);
    InvitacionIniciar("Cumpleaños","Salon san pedro",ctime(&timestamp));
    Separador();
    InicioArea();
    std::cout<<"Intoduce la base de tu triangulo: ";
    cin>>b;
    std::cout<<"Intoduce la altura de tu triangulo: ";
    cin>>a;
    
    std::cout<<"El area de tu triangulo es: "<<A_Triangulo(b,a)<<".";

    return 0;
}
