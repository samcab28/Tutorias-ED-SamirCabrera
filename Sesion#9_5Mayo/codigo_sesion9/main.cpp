#include <iostream>
#include "BTree.h"
using namespace std;

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n=== MENÚ ÁRBOL B ===" << endl;
    cout << "1. Insertar clave" << endl;
    cout << "2. Eliminar clave" << endl;
    cout << "3. Buscar clave" << endl;
    cout << "4. Mostrar árbol" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";
}

int main() {
    int opcion, clave, grado;
    
    cout << "Ingrese el grado mínimo del árbol B (t >= 2): ";
    cin >> grado;
    
    // Validar el grado mínimo
    if (grado < 2) {
        cout << "El grado mínimo debe ser al menos 2. Usando t = 2." << endl;
        grado = 2;
    }
    
    // Crear el árbol B con el grado especificado
    BTree arbol(grado);
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: // Insertar
                cout << "Ingrese la clave a insertar: ";
                cin >> clave;
                arbol.insert(clave);
                cout << "Clave " << clave << " insertada correctamente." << endl;
                break;
                
            case 2: // Eliminar
                if (arbol.isEmpty()) {
                    cout << "El árbol está vacío." << endl;
                } else {
                    cout << "Ingrese la clave a eliminar: ";
                    cin >> clave;
                    arbol.remove(clave);
                    cout << "Operación de eliminación completada." << endl;
                }
                break;
                
            case 3: // Buscar
                if (arbol.isEmpty()) {
                    cout << "El árbol está vacío." << endl;
                } else {
                    cout << "Ingrese la clave a buscar: ";
                    cin >> clave;
                    if (arbol.search(clave)) {
                        cout << "La clave " << clave << " existe en el árbol." << endl;
                    } else {
                        cout << "La clave " << clave << " NO existe en el árbol." << endl;
                    }
                }
                break;
                
            case 4: // Mostrar
                if (arbol.isEmpty()) {
                    cout << "El árbol está vacío." << endl;
                } else {
                    cout << "Árbol B (recorrido inorden): ";
                    arbol.traverse();
                }
                break;
                
            case 5: // Salir
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
        
    } while (opcion != 5);
    
    return 0;
}