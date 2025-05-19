#include <iostream>
#include <string>
#include <limits>
#include "ABB.h"
using namespace std;

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Demostración con enteros
void demoEnteros() {
    ArbolBinarioBusqueda arbol;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n==== MENÚ ÁRBOL DE ENTEROS ====" << endl;
        cout << "1. Insertar número" << endl;
        cout << "2. Buscar número" << endl;
        cout << "3. Eliminar número" << endl;
        cout << "4. Visualizar árbol (simple)" << endl;
        cout << "5. Visualizar árbol (detallado)" << endl;
        cout << "6. Mostrar recorrido InOrden" << endl;
        cout << "7. Mostrar recorrido PreOrden" << endl;
        cout << "8. Mostrar recorrido PostOrden" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada inválida. Intente de nuevo." << endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {  // Insertar
                int valor;
                cout << "Ingrese el número a insertar: ";
                cin >> valor;

                if (cin.fail()) {
                    cout << "Valor inválido." << endl;
                    limpiarBuffer();
                } else {
                    arbol.insertar(valor);
                    cout << "Número " << valor << " insertado correctamente." << endl;
                }
                break;
            }

            case 2: {  // Buscar
                if (arbol.estaVacio()) {
                    cout << "El árbol está vacío." << endl;
                    break;
                }

                int valor;
                cout << "Ingrese el número a buscar: ";
                cin >> valor;

                if (cin.fail()) {
                    cout << "Valor inválido." << endl;
                    limpiarBuffer();
                } else {
                    if (arbol.buscar(valor)) {
                        cout << "El número " << valor << " se encuentra en el árbol." << endl;
                    } else {
                        cout << "El número " << valor << " NO se encuentra en el árbol." << endl;
                    }
                }
                break;
            }

            case 3: {  // Eliminar
                if (arbol.estaVacio()) {
                    cout << "El árbol está vacío." << endl;
                    break;
                }

                int valor;
                cout << "Ingrese el número a eliminar: ";
                cin >> valor;

                if (cin.fail()) {
                    cout << "Valor inválido." << endl;
                    limpiarBuffer();
                } else {
                    arbol.eliminar(valor);
                    cout << "Se ha eliminado el número " << valor << " del árbol (si existía)." << endl;
                }
                break;
            }

            case 4:  // Visualizar (simple)
                arbol.visualizarArbol();
                break;

            case 5:  // Visualizar (detallado)
                arbol.visualizarArbolDetallado();
                break;

            case 6:  // InOrden
                arbol.mostrarInOrden();
                break;

            case 7:  // PreOrden
                arbol.mostrarPreOrden();
                break;

            case 8:  // PostOrden
                arbol.mostrarPostOrden();
                break;

            case 0:  // Volver
                cout << "Volviendo al menú principal..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }
}


int main() {
    cout << "Programa de demostración de Árbol Binario de Búsqueda" << endl;
    demoEnteros();
    return 0;
}
