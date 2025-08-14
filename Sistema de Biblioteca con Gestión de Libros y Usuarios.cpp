#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct
{
    string Titulo;
    string Autor;
    string Date;
    int Stock;
    int ID;
} Libros;
typedef struct
{
    string Nombre;
    string Contraseña;
    int ID;
    int NumeroDeLibrosPrestados;
    vector<Libros> LibrosPrestados;
} Usuarios;
typedef struct
{
    int ProximoIdLibro;
    int ProximoIdUsuario;
    vector<Libros> Coleccion_Libros;
    vector<Usuarios> Usuarios_Registrados;
} Biblioteca;

void MostrarMenu(){
    cout<<"\n[!]BIENVENIDO A LA BIBLIOTECA[!]\n";
    cout<<"[##############################]\n";
    cout<<"[1]VER COLECCION DE LIBROS   [-]\n";
    cout<<"[2]AGREGAR LIBRO             [-]\n";
    cout<<"[3]AGREGAR USUARIO           [-]\n";
    cout<<"[4]MOSTRAR USUARIOS          [-]\n";
    cout<<"[5]PRESTAR LIBRO             [-]\n";
    cout<<"[6]SALIR                     [-]\n";
}

void MostrarLibro(const Libros& libro){
    cout<<"\n|Titulo: "<<libro.Titulo<<"|Autor: "<<libro.Autor<<"|Fecha de lanzamiento: "<<libro.Date<<"|Stock: "<<libro.Stock<<"|Id: "<<libro.ID;
}

void MostrarLibrosPrestados(const Usuarios& usuarios){
    cout<<"Total de Libros Prestados: "<<usuarios.NumeroDeLibrosPrestados<<": ";
    for (const auto& libro: usuarios.LibrosPrestados)
    {
        MostrarLibro(libro);
    }
    
}

void MostrarUsuarios(const Biblioteca& biblioteca){
    for (const auto& Usuario: biblioteca.Usuarios_Registrados)
    {
    cout<<"|Nombre: "<<Usuario.Nombre<<"|Contraseña: "<<Usuario.Contraseña<<"|ID: "<<Usuario.ID<<"|Total de libros prestados: \n";MostrarLibrosPrestados(Usuario);cout<<endl;        
    }
    
}

void MostrarColeccionLibros(const Biblioteca& biblioteca){
    for (const auto& Libro: biblioteca.Coleccion_Libros)
    {
        MostrarLibro(Libro);
    }
    
}

void AgregarNuevosLibros(Biblioteca& biblioteca){
    Libros ADLibro;

    cout << "Titulo del libro: ";
    cin.ignore(); 
    getline(cin, ADLibro.Titulo);

    cout << "Autor: ";
    getline(cin, ADLibro.Autor);

    cout << "Fecha de lanzamiento: ";
    getline(cin, ADLibro.Date);

    cout << "Stock: ";
    cin >> ADLibro.Stock;
    cin.ignore(); 
    ADLibro.ID = biblioteca.ProximoIdLibro++;
    biblioteca.Coleccion_Libros.push_back(ADLibro);
    cout<<"Libro añadido exitosamente!\n";
}

void RegistrarUsuarios(Biblioteca& biblioteca){
    Usuarios NuevoUser;
    cout<<"Introduce nombre de nuevo usuario: ";
    cin>>NuevoUser.Nombre;
    cout<<"Introduce nueva contraseña: ";
    cin>>NuevoUser.Contraseña;
    NuevoUser.LibrosPrestados = {};
    NuevoUser.NumeroDeLibrosPrestados = 0;
    NuevoUser.ID = biblioteca.ProximoIdUsuario++;
    biblioteca.Usuarios_Registrados.push_back(NuevoUser);
    cout<<"Usuario registrado exitosamente!\n";
}



void PrestarLibros(Biblioteca& biblioteca) {
    int IdUsuario;
    string Contraseña;
    int IdLibro;
    cout << "Introduce id del usuario: ";
    cin >> IdUsuario;


    
    for (auto& Usuario : biblioteca.Usuarios_Registrados) {
        if (Usuario.ID == IdUsuario) {
            cout << "Introduce contraseña del usuario: ";
            cin>>Contraseña;
         if (Usuario.Contraseña == Contraseña)
         {
             cout << "Introduce Id del libro: ";
            cin >> IdLibro;

            
            for (auto& Libro : biblioteca.Coleccion_Libros) {
                if (Libro.ID == IdLibro && Libro.Stock > 0) {
                    
                    Usuario.LibrosPrestados.push_back(Libro);  
                    Usuario.NumeroDeLibrosPrestados++;         
                    Libro.Stock--;                            
                    cout << "Libro prestado con éxito!" << endl;
                }
            }
            cout << "Libro no disponible o no encontrado!" << endl;
            return;
         }else{
            cout<<"Contraseña incorrecta!\n";
         }
           
        }else{
            cout<<"Usuario no encontrado!\n";
        }
    }
    cout << "Usuario o contraseña incorrectos!" << endl;
}




int main(int argc, char const *argv[])
{
    int Input1 ;
    Biblioteca Handle = {
        1,
        1,
        {},
        {},
    };

    do
    {
        MostrarMenu();
        cin>>Input1;
        
        
        
        switch (Input1)
        {
        case 1:
            MostrarColeccionLibros(Handle);
            break;
        case 2:
            AgregarNuevosLibros(Handle);
            break;
        case 3:
            RegistrarUsuarios(Handle);
            break;
        case 4:
            MostrarUsuarios(Handle);
            break;
        case 5:
            PrestarLibros(Handle);
            break;
        case 6:
            cout<<"Hasta luego!";
            break;
        default:
            break;
        }
    } while (Input1 != 6);
    
    return 0;
}