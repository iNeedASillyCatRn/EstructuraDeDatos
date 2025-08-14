#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Nodo{
    public:
    int dato;
    Nodo*Siguiente;
    Nodo(int val) : dato(val), Siguiente(nullptr) {}
};

class ListaEnlazada{
    private:
    Nodo*Cabeza;

    public:
    ListaEnlazada() : Cabeza(nullptr) {}

    void InsertarAlFinal(int val){
        Nodo*NuevoNodo = new Nodo(val);
        if (!Cabeza)
        {
            Cabeza = NuevoNodo;
            return;
        }
        Nodo*temp = Cabeza;
        while (temp -> Siguiente)
        {
            temp = temp->Siguiente;
        };
        temp -> Siguiente =  NuevoNodo;
    };

    void M(){
        Nodo*temp = Cabeza;
        while (temp)
        {
            cout<<temp->dato<<" ";
            temp = temp->Siguiente;
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    ListaEnlazada lista;
    lista.InsertarAlFinal(1);
    lista.InsertarAlFinal(2);
    lista.InsertarAlFinal(3);
    cout<<"Lista: ";
    lista.M();
    return 0;
}
