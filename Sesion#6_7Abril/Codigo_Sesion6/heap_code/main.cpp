#include <iostream>
#include "ABB.h"
#include "heapsort.h"
using namespace std;

int main() {
    cout << "===== IMPLEMENTACIÓN DE HEAP Y HEAPSORT =====" << endl;
    
    // Crear un arreglo de 10 elementos
    int arr[10] = {45, 36, 54, 27, 63, 18, 72, 9, 81, 90};
    
    // Mostrar el arreglo original
    cout << "Arreglo original: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // Crear y construir el heap
    cout << "IMPLEMENTACIÓN DE HEAP:" << endl;
    Heap miHeap(10);
    miHeap.construirHeap(arr, 10);
    
    // Realizar HeapSort
    cout << "\nIMPLEMENTACIÓN DE HEAPSORT:" << endl;
    miHeap.heapSort();
    
    // Demostración de ABB con los mismos datos
    cout << "\n\n===== IMPLEMENTACIÓN DE ÁRBOL BINARIO DE BÚSQUEDA =====" << endl;
    ArbolBinarioBusqueda miArbol;
    
    // Insertar los elementos originales
    for (int i = 0; i < 10; i++) {
        miArbol.insertar(arr[i]);
    }
    
    // Mostrar visualización del árbol
    cout << "\nVisualización del ABB:" << endl;
    miArbol.visualizarArbol();
    
    // Mostrar recorridos
    cout << "\nRecorridos del ABB:" << endl;
    miArbol.mostrarInOrden();
    miArbol.mostrarPreOrden();
    miArbol.mostrarPostOrden();
    
    cout << "\n\nFin del programa." << endl;
    
    return 0;
}