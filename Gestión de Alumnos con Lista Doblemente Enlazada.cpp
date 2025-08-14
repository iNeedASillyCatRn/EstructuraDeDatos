#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
    int Matricula;
    std::string Nombre;
    float Promedio;
};

struct Nodo
{
    Alumno Datos;
    Nodo* sgt;
    Nodo* ant;

    Nodo(Alumno alumno){
        Datos = alumno;
        sgt = nullptr;
        ant =  nullptr;
    }
};

class ListaAlumnos
{
private:
    Nodo* Primero;
    Nodo* Ultimo;
public:
    ListaAlumnos(){
        Primero = nullptr;
        Ultimo =  nullptr;
    }
    ~ListaAlumnos(){
        Nodo* actual = Primero;
        while (actual != nullptr)
        {
            Nodo* sgt = actual->sgt;
            delete actual;
            actual = sgt;
        }
    }

    void AgregarAlumno(Alumno alumno){
        Nodo* nuevo = new Nodo(alumno);

        if (Primero ==  nullptr)
        {
            Primero =  nuevo;
            Ultimo =  nuevo;
        }else{
            Ultimo->sgt = nuevo;
            nuevo->ant = Ultimo;
            Ultimo =  nuevo;
        }
    }
    bool BuscarAlumno(int matricula, Alumno& resultado){
        Nodo* actual = Primero;

        while (actual != nullptr)
        {
            if (actual->Datos.Matricula ==  matricula)
            {
                resultado = actual->Datos;
                return true;
            }
            actual = actual->sgt;
        }
        return false;
    }
    bool EliminarAlumno(int matricula){
        if (Primero ==  nullptr)
        {
            return false;
        }

        if (Primero->Datos.Matricula ==  matricula)
        {
            Nodo* Temp = Primero;
            Primero = Primero->sgt;
            if (Primero != nullptr)
            {
                Primero->ant;
            }else{
                Ultimo = nullptr;
            }
            delete Temp;
            return true;
        }

        if (Ultimo->Datos.Matricula ==  matricula)
        {
            Nodo* temp = Ultimo;
            Ultimo =  Ultimo->ant;
            Ultimo->sgt = nullptr;
            delete temp;
            return true;
        }

         Nodo* actual = Primero->sgt;
         while (actual != nullptr && actual->Datos.Matricula != matricula)
         {
            actual = actual->sgt;
         }
         if (actual ==  nullptr)
         {
            return false;
         }
         actual->ant->sgt = actual->sgt;
         actual->sgt->ant = actual->ant;
         delete actual;
         return true;
    }

    void MostrarAlumnos(){
        Nodo* actual = Primero;
        if (actual ==  nullptr)
        {
            cout<<"No hay alumnos registrados."<<endl;
            return;
        }

        cout<<"\n====== LISTA DE ALUMNOS ======"<<endl;
        cout<<"Matricula | Nombre | Promedio"<<endl;
        cout<<"--------------------------------"<<endl;

        while (actual != nullptr)
        {
            cout<<actual->Datos.Matricula<<" | "
                <<actual->Datos.Nombre<<" | "
                <<actual->Datos.Promedio<<" | "<<endl;
            actual =  actual->sgt;
        }
        cout<<"================================="<<endl;    
    }

    void MostrarAlumnosInverso(){
        Nodo* actual = Ultimo;
        if (actual ==  nullptr)
        {
            cout<<"No hay alumnos registrados."<<endl;
            return;
        }

        cout<<"\n====== LISTA DE ALUMNOS(INVERSO) ======"<<endl;
        cout<<"Matricula | Nombre | Promedio"<<endl;
        cout<<"--------------------------------"<<endl;

        while (actual != nullptr)
        {
            cout<<actual->Datos.Matricula<<" | "
                <<actual->Datos.Nombre<<" | "
                <<actual->Datos.Promedio<<" | "<<endl;
            actual =  actual->ant;
        }
        cout<<"================================="<<endl; 
    }
};

int main(int argc, char const *argv[])
{
    ListaAlumnos lista;
    Alumno alumno, resultado;
    int opcion, matricula;
    do
    {
        cout<<"\n====== MENU DE SISTEMA DE ALUMNOS ======"<<endl;
        cout<<"1. Agregar Alumno"<<endl;
        cout<<"2. Buscar Alumno"<<endl;
        cout<<"3. Eliminar Alumno"<<endl;
        cout<<"4. Mostrar todos los alumnos"<<endl;
        cout<<"5. Mostrar alumnos en orden inverso"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cout<<"Matricula: ";
            cin>>alumno.Matricula;
            cin.ignore();
            cout<<"Nombre: ";
            getline(cin, alumno.Nombre);
            cout<<"Promedio: ";
            cin>>alumno.Promedio;

            lista.AgregarAlumno(alumno);
            cout<<"Alumno agregado correctamente!"<<endl;
            break;
        case 2:
            cout<<"Ingrese matricula a buscar: ";
            cin>>matricula;

            if (lista.BuscarAlumno(matricula,resultado))
            {
                cout<<"\nAlumno encontrado:"<<endl;
                cout<<"Matricula: "<<resultado.Matricula<<endl;
                cout<<"Nombre: "<<resultado.Nombre<<endl;
                cout<<"Promedio: "<<resultado.Promedio<<endl;
            }else{
                cout<<"Alumno no encontrado!"<<endl;
            }
            break;
        case 3:
            cout<<"Ingresa la matricula a eliminar: ";
            cin >>matricula;
            if (lista.EliminarAlumno(matricula))
            {
                cout<<"Alumno eliminado correctamente!"<<endl;
            }else{
                cout<<"Alumno no encontrado!"<<endl;
            }
            
            break;
        case 4:
            lista.MostrarAlumnos();
            break;
        case 5:
            lista.MostrarAlumnosInverso();
            break;
        case 0:
            cout<<"Saliendo del menu!"<<endl;
            break;
        
        default:
            cout<<"Opcion incorrecta!"<<endl;
            break;
        }
    } while (opcion != 0);
    
    return 0;
}




