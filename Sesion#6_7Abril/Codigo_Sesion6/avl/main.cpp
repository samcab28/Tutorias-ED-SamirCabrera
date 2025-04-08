#include <iostream>
#include "AVL.h"
using namespace std;

int main() {
    cout << "===== IMPLEMENTACIÓN DE ÁRBOL AVL =====" << endl;
    
    ArbolAVL miArbolAVL;
    
    // Insertar elementos para demostrar las rotaciones
    cout << "\nInsertando elementos en el árbol AVL:" << endl;
    
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45, 5, 1};
    int numValores = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < numValores; i++) {
        cout << "\nInsertando " << valores[i] << ":" << endl;
        miArbolAVL.insertar(valores[i]);
        cout << "Estado del árbol después de insertar " << valores[i] << ":" << endl;
        miArbolAVL.visualizarArbol();
    }
    
    // Mostrar recorridos
    cout << "\nRecorridos del árbol AVL:" << endl;
    miArbolAVL.mostrarInOrden();
    miArbolAVL.mostrarPreOrden();
    miArbolAVL.mostrarPostOrden();
    
    // Visualización detallada
    //cout << "\nVisualización detallada del árbol AVL:" << endl;
    //miArbolAVL.visualizarArbolDetallado();
    
    // Demostrar búsqueda
    int valorBuscar = 40;
    cout << "\nBuscando el valor " << valorBuscar << ": ";
    if (miArbolAVL.buscar(valorBuscar)) {
        cout << "Encontrado." << endl;
    } else {
        cout << "No encontrado." << endl;
    }
    
    // Demostrar eliminación
    int valorEliminar = 30;
    cout << "\nEliminando el valor " << valorEliminar << ":" << endl;
    miArbolAVL.eliminar(valorEliminar);
    
    cout << "\nEstado del árbol después de eliminar " << valorEliminar << ":" << endl;
    miArbolAVL.visualizarArbol();
    
    // Mostrar recorridos actualizados
    cout << "\nRecorridos del árbol AVL después de eliminar " << valorEliminar << ":" << endl;
    miArbolAVL.mostrarInOrden();
    
    cout << "\n\nFin del programa." << endl;
    
    return 0;
}