/*

SEMANA 8 - MINI PROYECTO: TIENDA DE ROPA 

AUTOR: Joustin Armas 
FECHA: 2026-10

*/


#include <iostream>
#include <string>
using namespace std;

void menuPrincipal(int &opcion);
void registrarProducto(string nombre[], double precio[], int stock[], int &cantidad);
void mostrarProductos(string nombre[], double precio[], int stock[], int cantidad);
void buscarProducto(string nombre[], double precio[], int stock[], int cantidad);
void generarReporte(string nombre[], double precio[], int stock[], int cantidad);
void controlStockBajo(string nombre[], int stock[], int cantidad);


int main() {

    int opcion;
    int cantidadProductos = 0;

    string nombre[20];
    double precio[20];
    int stock[20];

    menuPrincipal(opcion);

    return 0;
}

void menuPrincipal(int &opcion) {

    int cantidadProductos = 0;

    string nombre[20];
    double precio[20];
    int stock[20];

    do {

        cout << "===== VIPER TIENDA ONLINE =====" << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Reporte general" << endl;
        cout << "5. Alerta de stock bajo" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                registrarProducto(nombre, precio, stock, cantidadProductos);
                break;

            case 2:
                mostrarProductos(nombre, precio, stock, cantidadProductos);
                break;

            case 3:
                buscarProducto(nombre, precio, stock, cantidadProductos);
                break;

            case 4:
                generarReporte(nombre, precio, stock, cantidadProductos);
                break;

            case 5:
                controlStockBajo(nombre, stock, cantidadProductos);
                break;

            case 6:
                cout << "Gracias por visitar VIPER." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 6);
}

void registrarProducto(string nombre[], double precio[], int stock[], int &cantidad) {

    if (cantidad >= 20) {
        cout << "Inventario lleno. No puedes registrar mas productos." << endl;
        return;
    }

    cout << "=== REGISTRAR PRODUCTO ===" << endl;

    cout << "Nombre del producto: ";
    cin.ignore();
    getline(cin, nombre[cantidad]);

    cout << "Precio del producto: ";
    cin >> precio[cantidad];

    while (precio[cantidad] <= 0) {
        cout << "Precio invalido. Ingrese nuevamente: ";
        cin >> precio[cantidad];
    }

    cout << "Cantidad disponible: ";
    cin >> stock[cantidad];

    while (stock[cantidad] < 0) {
        cout << "Stock invalido. Ingrese nuevamente: ";
        cin >> stock[cantidad];
    }

    cantidad++;

    cout << "Producto registrado correctamente." << endl;
}

void mostrarProductos(string nombre[], double precio[], int stock[], int cantidad) {

    if (cantidad == 0) {
        cout << "Todavia no existen productos registrados." << endl;
        return;
    }

    cout << "=== INVENTARIO VIPER ===" << endl;

    for (int i = 0; i < cantidad; i++) {

        cout << "Producto: " << nombre[i] << endl;
        cout << "Precio: $" << precio[i] << endl;
        cout << "Stock: " << stock[i] << " unidades" << endl;
    }
}

void buscarProducto(string nombre[], double precio[], int stock[], int cantidad) {

    if (cantidad == 0) {
        cout << "No existen productos para buscar." << endl;
        return;
    }

    string productoBuscado;
    bool encontrado = false;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, productoBuscado);

    for (int i = 0; i < cantidad; i++) {

        if (nombre[i] == productoBuscado) {

            cout << "Producto encontrado." << endl;
            cout << "Nombre: " << nombre[i] << endl;
            cout << "Precio: $" << precio[i] << endl;
            cout << "Stock: " << stock[i] << endl;

            encontrado = true;
            break;
        }
    }

    if (encontrado == false) {
        cout << "El producto no existe en el inventario." << endl;
    }
}


void generarReporte(string nombre[], double precio[], int stock[], int cantidad) {

    if (cantidad == 0) {
        cout << "No existen datos para generar el reporte." << endl;
        return;
    }

    int totalUnidades = 0;
    double valorInventario = 0;

    for (int i = 0; i < cantidad; i++) {

        totalUnidades += stock[i];
        valorInventario += precio[i] * stock[i];
    }

    cout << "=== REPORTE GENERAL VIPER ===" << endl;
    cout << "Productos registrados: " << cantidad << endl;
    cout << "Total de unidades: " << totalUnidades << endl;
    cout << "Valor total del inventario: $" << valorInventario << endl;
}

void controlStockBajo(string nombre[], int stock[], int cantidad) {

    if (cantidad == 0) {
        cout << "No existen productos registrados." << endl;
        return;
    }

    bool stockBajo = false;

    cout << "=== ALERTA DE STOCK BAJO ===" << endl;

    for (int i = 0; i < cantidad; i++) {

        if (stock[i] <= 3) {

            cout << nombre[i] << ": "
                 << stock[i] << " unidades disponibles." << endl;

            stockBajo = true;
        }
    }

    if (stockBajo == false) {
        cout << "Todos los productos tienen stock suficiente." << endl;
    }
}
 