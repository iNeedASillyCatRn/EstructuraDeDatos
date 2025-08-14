#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
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

class GestorDeAlumnos
{
private:
    std::stack<Alumno> PIlaAlumnos;
public:
    void AgregarAlumno(std::stack<Alumno>& pila, const Alumno& alumno){
        pila.push(alumno);
        std::cout<<"Alumno agregado: "<<alumno.Nombre<<std::endl;
    }
    void EliminarAlumno(std::stack<Alumno>& pila){
        if (!pila.empty()){
            cout<<"Eliminando alumno: "<<pila.top().Nombre<<endl;
            pila.pop();
        }else{
            cout<<"La pila esta vacia no se puede eliminar!"<<endl;
        }
    }
    void mostrarUltAlumno(const std::stack<Alumno>& pila){
        if (!pila.empty()){
            cout<<"Ultimo alumno agregado: "<<endl;
            pila.top().mostrar();
        }else{
            cout<<"La pila esta vacia!"<<endl;
        }     
    }
    void MostrarTodosAlumnos() const{
        if (PIlaAlumnos.empty())
        {
            cout<<"La pila de alumnos esta vacia!"<<endl;
            return;
        }else{
            
        }
        
    }
};







int main(int argc, char const *argv[])
{
    
    return 0;
}

