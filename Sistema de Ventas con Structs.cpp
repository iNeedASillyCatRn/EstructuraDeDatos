#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

typedef struct
{
    int ID;
    string Nombre;
    float Precio;
} Producto;
typedef struct 
{
    int IDVenta;
    vector<Producto> productos;
    float Total;
} Venta;

void MostrarProducto(const Producto& producto){
    cout<<"|ID: "<<producto.ID<<", Nombre: "<<producto.Nombre<<", Precio: "<<producto.Precio<<"|"<<endl;
}
void MostrarVenta(const Venta& venta){
    cout<<"ID de venta: "<<venta.IDVenta<<endl;
    for (const auto& producto: venta.productos)
    
    {
        MostrarProducto(producto);
    }
    cout<<"|Total: "<<venta.Total<<"                                 |"<<endl;
    cout<<"------------------------------------------------\n";
}

int main(int argc, char const *argv[])
{
    vector<Producto> productos = {
        {1, "RVVZ Xploit    ", 199.99},
        {2, "KRNL Executor    ", 2.99},
        {3, "Synapse X       ", 15.99},
        {4, "RVVZ Spoofer    ", 20.99},
    };
    Venta venta1;
    venta1.IDVenta = 1;
    venta1.productos.push_back(productos[0]);
    venta1.Total = productos[0].Precio;
    
    Venta venta2;
    venta2.IDVenta = 2;
    venta2.productos.push_back(productos[0]);
    venta2.productos.push_back(productos[3]);
    venta2.Total = productos[0].Precio + productos[3].Precio;
   // cout<<"ventas realizadas\n";
    MostrarVenta(venta1);MostrarVenta(venta2);

    return 0;
}

