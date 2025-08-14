#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Estudiante
{
private:
    std::string nombre;
    std::string apellido;
    double promedio;
public:
    Estudiante(std::string nom, std::string apc, double prom)
    : nombre(nom), apellido(apc), promedio(prom) {}
    void MostrarInfo() const{
        std::cout << std::left
        <<std::setw(15) << nombre
        <<std::setw(15) << apellido
        << "Promedio: " << std::fixed << std::setprecision(2) << promedio << std::endl;
    }

    double ObtenerPromedio() const{
        return promedio;
    }
};

void OrdenarEstudiantesPorPromedio(std::vector<Estudiante>& estudiantes){
    int n = estudiantes.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (estudiantes[j].ObtenerPromedio() < estudiantes[j+1].ObtenerPromedio())
            {
                std::swap(estudiantes[j],estudiantes[j+1]);
            }
        }
        
    }
    
}





int main(int argc, char const *argv[])
{
    std::vector<Estudiante> estudiantes = {
        Estudiante("Juan","Perez",8.5),
        Estudiante("Jose", "Segundo", 10),
        Estudiante("Antonio","Rivera", 5.1),
        Estudiante("Example","3", 6.1),
        Estudiante("Example","2", 3.1),
        Estudiante("Example","1", 9.1),
    };
    cout<<"Estudiantes sin ordenar por promedio: "<<endl;
    for (auto const& estudiante: estudiantes)
    {
        estudiante.MostrarInfo();
    }

    OrdenarEstudiantesPorPromedio(estudiantes);
    cout<<"Estudiantes ordenados por promedio: "<<endl;
    for (auto const& estudiante: estudiantes)
    {
        estudiante.MostrarInfo();
    }
    
    return 0;
}
