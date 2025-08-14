/*
__| |___________________________________| |__
__   ___________________________________   __
  | |                                   | |  
  | |███╗   ██╗ █████╗ ████████╗███████╗| |  
  | |████╗  ██║██╔══██╗╚══██╔══╝╚══███╔╝| |  
  | |██╔██╗ ██║███████║   ██║     ███╔╝ | |  
  | |██║╚██╗██║██╔══██║   ██║    ███╔╝  | |  
  | |██║ ╚████║██║  ██║   ██║   ███████╗| |  
  | |╚═╝  ╚═══╝╚═╝  ╚═╝   ╚═╝   ╚══════╝| |  
__| |___________________________________| |__
__   ___________________________________   __
  | |                                   | |  
*/

// Librerias escensiales

#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

// Estructuras de la tienda

typedef struct
{
  int IdShop;
  string Name;  
} ClaseVideoJuegos;
typedef struct 
{
    int SKU;
    int Stock;
    string Name;
    int IdShop;
    float Precio;
} VideoJuego;
typedef struct 
{

    float Total;
} Carrito;

void MostrarClaseDeVid(const vector<ClaseVideoJuegos>& Class){
    for (const auto& Clases: Class)
    {
        cout<<"|ID: "<<Clases.IdShop<<"| CLASE: "<<Clases.Name<<endl;
    }
}

std::vector<VideoJuego> Filtrar(const vector<VideoJuego>& VideoJuegos, const vector<ClaseVideoJuegos>& ClasesDeVid, string CClass){
    int IDWGAME = -1;
    vector<VideoJuego> Resultados;
    
    for (const auto&clase: ClasesDeVid)
    {
        if (clase.Name == CClass)
        {
            IDWGAME == clase.IdShop;
        }
    }

    if (IDWGAME == -1)
    {
        return Resultados;
    }
    for (const auto& juego: VideoJuegos)
    {
        if (juego.IdShop == IDWGAME)
        {
            Resultados.push_back(juego);
        }
        
    }
    return {};
}

void MostrarJuegos(const vector<VideoJuego>& Juegoss){
    cout<<"AE";
    for (const auto& Juegos: Juegoss)
    {
        
        cout<<"|SKU: "<<Juegos.SKU<<"|NOMBRE: "<<Juegos.Name<<"|STOCK: "<<Juegos.Stock<<"|PRECIO: "<<Juegos.Precio<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
    int Op;
    vector<ClaseVideoJuegos> Clases = {
        {001,"Terror"},
        {002,"FPS"},
        {003,"RPG"},
        {004,"Estrategia"},
        {005,"Deportes"},
    };
    vector<VideoJuego> VideoJ = {
        {320001873,67,"FIFA 25",005,59.99},
    };
    vector<VideoJuego> resultados;
    string ClaseB;
    do
    {
        cout<<"Bienvenido a la tienda de videojuegos\n";
        cout<<"[1] VER CATALOGO.\n";
        cout<<"[2] VER COMPRAR.\n";
        cout<<"[3] VER VER CARRITO.\n";
        cout<<"[4] SALIR.\n";
        cin>>Op;
        switch (Op)
        {
        case 1:
            MostrarClaseDeVid(Clases);
            cin>>ClaseB;
            
            resultados = Filtrar(VideoJ,Clases,ClaseB);
            MostrarJuegos(resultados);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        default:
            break;
        }

    } while (Op != 4);
    


    return 0;
}
