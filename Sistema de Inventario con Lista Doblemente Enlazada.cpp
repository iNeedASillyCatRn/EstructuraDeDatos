#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto
{
    int barcode;
    string Nombre;
    string Descripcion;
    float Precio;
    int stock;
    Producto* siguiente;
    Producto* anterior;
};


class Inventario
{
private:
    Producto* prm;
    Producto* ult;
    int Stock;
public:
    Inventario() : prm(nullptr), ult(nullptr), Stock(0){}
    ~Inventario(){
        Producto* actual = prm;
        while (actual != nullptr)
        {
            Producto* temp = actual->siguiente;
            delete actual;
            actual = temp;
        }
    }
    void AgregarProducto(int codigo, string nombre, string descripcion, float precio, int Stock1){
        Producto*  nuevo =  new Producto;
        nuevo->barcode = codigo;
        nuevo->Nombre =  nombre;
        nuevo->Descripcion = descripcion;
        nuevo->Precio = precio;
        nuevo->stock =  Stock1;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;
        if (prm == nullptr) {
            prm = nuevo;
            ult = nuevo;
        } else {
            ult->siguiente = nuevo;
            nuevo->anterior = ult;
            ult = nuevo;
        }
        Stock++;
        cout << "Producto agregado al inventario.\n";      
    }
    Producto* buscarProducto(int Barcode){
        Producto* actual = prm;
        while (actual != nullptr) {
            if (actual->barcode == Barcode) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }
    void actualizarStock(int codigo, int cantidad) {
        Producto* producto = buscarProducto(codigo);
        if (producto != nullptr) {
            producto->stock += cantidad;
            cout << "Stock actualizado! Nuevo stock: " << producto->stock << "\n";
        } else {
            cout << "Producto no encontrado!\n";
        }
    }
    void mostrarInventario() {
        if (prm == nullptr) {
            cout << "El inventario está vacio.\n";
            return;
        }

        cout << "\n=== INVENTARIO DEL ALMACEN ===\n";
        cout << "Total de productos: " << Stock << "\n\n";
        
        Producto* actual = prm;
        while (actual != nullptr) {
            cout << "Codigo de barras: " << actual->barcode << "\n";
            cout << "Nombre: " << actual->Nombre << "\n";
            cout << "Descripción: " << actual->Descripcion << "\n";
            cout << "Precio: $" << actual->Precio << "\n";
            cout << "Stock: " << actual->stock << "\n";
            cout << "===========================\n";
            actual = actual->siguiente;
        }
    }
    void mostrarStockBajo() {
        bool hayStockBajo = false;
        Producto* actual = prm;

        cout << "\n=== PRODUCTOS CON STOCK BAJO ===\n";
        while (actual != nullptr) {
            if (actual->stock < 5) {
                hayStockBajo = true;
                cout << "Código de barras: "<<actual->barcode<<"|"<< actual->Nombre<<"|Stock: "<<actual->stock<<endl;
            }
            actual = actual->siguiente;
        }

        if (!hayStockBajo) {
            cout << "No hay productos con stock bajo.\n";
        }
    }
    void eliminarProducto(int codigo) {
        Producto* producto = buscarProducto(codigo);
        if (producto == nullptr) {
            cout << "Producto no encontrado.\n";
            return;
        }

        if (producto->anterior != nullptr) {
            producto->anterior->siguiente = producto->siguiente;
        } else {
            prm = producto->siguiente;
        }

        if (producto->siguiente != nullptr) {
            producto->siguiente->anterior = producto->anterior;
        } else {
            ult = producto->anterior;
        }

        delete producto;
        Stock--;
        cout << "Producto eliminado del inventario.\n";
    }
};

void MostraMenu(){
    cout<<"========[MENU INVENTRIO]========"<<endl;
    cout<<"1.- Aregar producto."<<endl;
    cout<<"2.- Buscar producto."<<endl;
    cout<<"3.- Actualizar stock."<<endl;
    cout<<"4.- Ver todo el inventario."<<endl;
    cout<<"5.- Ver stocks bajos."<<endl;
    cout<<"6.- Eliminar producto."<<endl;
    cout<<"7.- Salir."<<endl;
}

int main(int argc, char const *argv[])
{
    Inventario inventario;
    int op;

    do
    {
        MostraMenu();
        cin>>op;
        cin.ignore();

        switch (op)
        {
        case 1:
            {
                int codigo, stock;
                string nombre, descripcion;
                double precio;

                cout << "Ingrese codigo de barras del producto: ";
                cin >> codigo;
                cin.ignore();
                cout << "Ingrese nombre del producto: ";
                getline(cin, nombre);
                cout << "Ingrese descripcion: ";
                getline(cin, descripcion);
                cout << "Ingrese precio: ";
                cin >> precio;
                cout << "Ingrese stock inicial: ";
                cin >> stock;

                inventario.AgregarProducto(codigo,nombre,descripcion,precio,stock);
                break;
            }
            
        case 2:
            {
                int codigo;
                cout << "Ingrese codigo del producto a buscar: ";
                cin >> codigo;

                Producto* producto = inventario.buscarProducto(codigo);
                if (producto != nullptr) {
                    cout << "\nProducto encontrado:\n";
                    cout << "Codigo de barras: " << producto->barcode << "\n";
                    cout << "Nombre: " << producto->Nombre << "\n";
                    cout << "Descripcion: " << producto->Descripcion << "\n";
                    cout << "Precio: $" << producto->Precio << "\n";
                    cout << "Stock: " << producto->stock << "\n";
                } else {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
        case 3:
            {
                int codigo, cantidad;
                cout << "Ingrese codigo de barras del producto: ";
                cin >> codigo;
                cout << "Ingrese cantidad a añadir/restar: ";
                cin >> cantidad;

                inventario.actualizarStock(codigo, cantidad);
                break;
            }
        case 4:
            inventario.mostrarInventario();
            break;
        case 5:
            inventario.mostrarStockBajo();
            break;
        case 6:{
                int codigo;
                cout << "Ingrese codigo de barras del producto a eliminar: ";
                cin >> codigo;
                inventario.eliminarProducto(codigo);
                break;
            }
        case 7:
            cout<<"Hasta pronto!"<<endl;
            break;
        default:
            cout<<"Opcion invalida, intenta nuevamente."<<endl;
            break;
        }
    } while (op != 7);
    
    return 0;
}
