#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>

class Heap {
public:
    Heap(int tamanio);
    ~Heap();
    
    // Métodos para el Heap
    void insertar(int nuevaLlave);
    void construirHeap(int arr[], int tamano);
    void heapSort();
    void imprimirArreglo();
    
private:
    int* llave;
    int capacidad;
    int tamanoActual;
};

#endif // HEAPSORT_H