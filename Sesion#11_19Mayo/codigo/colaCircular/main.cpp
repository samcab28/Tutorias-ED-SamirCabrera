#include "colaCircular.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Función para limpiar la pantalla según el sistema operativo
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para pausar la ejecución hasta que el usuario presione Enter
void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para mostrar el menú principal
void mostrarMenu() {
    limpiarPantalla();
    cout << "🖨️ === SISTEMA DE COLA CIRCULAR DE IMPRESIÓN === 🖨️" << endl;
    cout << "1. Agregar documento a la cola" << endl;
    cout << "2. Imprimir documento (siguiente en la cola)" << endl;
    cout << "3. Mostrar cola de impresión" << endl;
    cout << "4. Rotar cola (cambiar el orden de impresión)" << endl;
    cout << "5. Tamaño de la cola" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese su opción: ";
}

int main() {
    ImpresoraQueueCircular cola;
    int opcion;
    string documento;
    
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        
        switch (opcion) {
            case 1: // Agregar documento
                limpiarPantalla();
                cout << "=== AGREGAR DOCUMENTO ===" << endl;
                cout << "Ingrese el nombre del documento: ";
                getline(cin, documento);
                cola.AgregarDocumento(documento);
                pausar();
                break;
                
            case 2: // Imprimir documento
                limpiarPantalla();
                cout << "=== IMPRIMIR DOCUMENTO ===" << endl;
                cola.ImprimirDocumento();
                pausar();
                break;
                
            case 3: // Mostrar cola
                limpiarPantalla();
                cout << "=== MOSTRAR COLA DE IMPRESIÓN ===" << endl;
                cola.MostrarCola();
                pausar();
                break;
                
            case 4: // Rotar cola
                limpiarPantalla();
                cout << "=== ROTAR COLA ===" << endl;
                if (!cola.ColaVacia()) {
                    cout << "Rotando la cola..." << endl;
                    cola.RotarCola();
                    cout << "Cola rotada. Mostrando nuevo estado:" << endl;
                    cola.MostrarCola();
                } else {
                    cout << "No hay documentos en la cola para rotar." << endl;
                }
                pausar();
                break;
                
            case 5: // Tamaño de la cola
                limpiarPantalla();
                cout << "=== TAMAÑO DE LA COLA ===" << endl;
                cout << "La cola tiene " << cola.TamanioCola() << " documento(s)." << endl;
                pausar();
                break;
                
            case 0: // Salir
                limpiarPantalla();
                cout << "Saliendo del sistema de impresión. ¡Hasta pronto!" << endl;
                break;
                
            default:
                limpiarPantalla();
                cout << "⚠️ Opción inválida. Por favor, ingrese una opción válida." << endl;
                pausar();
                break;
        }
        
    } while (opcion != 0);
    
    return 0;
}