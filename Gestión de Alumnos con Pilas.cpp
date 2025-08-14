#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Alumno
{
public:
    std::string Nombre;
    int edad;
    float promedio;
    Alumno(std::string n, int e, float p) : Nombre(n), edad(e), promedio(p) {}

    void mostrar() const{
        std::cout<<"Nombre: "<<Nombre<<"|Edad: "<<edad<<"|Promedio: "<<promedio<<std::endl;
    }
};

void AgregarAlumno(std::stack<Alumno>& pila, const Alumno& alumno){
    pila.push(alumno);
    std::cout<<"Alumno agregado: "<<alumno.Nombre<<std::endl;
}

void mostrarUltAlumno(const std::stack<Alumno>& pila){
    if (!pila.empty())
    {
        cout<<"Ultimo alumno agregado: "<<endl;
        pila.top().mostrar();
    }else
    {
        cout<<"La pila esta vacia!"<<endl;
    }     
}

void EliminarAlumno(std::stack<Alumno>& pila){
    if (!pila.empty())
    {
        cout<<"Eliminando alumno: "<<pila.top().Nombre<<endl;
        pila.pop();
    }else{
        cout<<"La pila esta vacia no se puede eliminar!"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    std::stack<Alumno> pilaAlumnos;
    int op;
    do{
        cout<<"========SELECCIONA UNA OPCION=========="<<"\n 1.-Mostrando ultimo alumno agregado"<<"\n 2.-Eliminar alumno"<<"\n 3.-Agregar Alumno"<<"\n 4.- Salir"<<endl;
        cin>>op;
        switch (op)
        {
        case 1:
            mostrarUltAlumno(pilaAlumnos);
            break;
        case 2:
            EliminarAlumno(pilaAlumnos);
            break;
      case 3:{
            std::string nom;
            int Edad;
            float Promedio;
            cout<<"\nNombre: ";
            cin>>nom;
            cin.ignore();
            cout<<"\nEdad: ";
            cin>>Edad;
            cin.ignore();
            cout<<"\nPromedio: ";
            cin>>Promedio;
            cin.ignore();
            AgregarAlumno(pilaAlumnos, Alumno(nom,Edad,Promedio));
            cout<<"\nAgregado correctamente!"<<endl;

            break;}
        case 4:
            cout<<"ReturnExit"<<endl;
            break;
        default:
            cout<<"idk";
            break;
        }
    } while (op != 4);
    return 0;
}

