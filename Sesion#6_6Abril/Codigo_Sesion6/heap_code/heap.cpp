#include "heapsort.h"
#include <iostream>
using namespace std;

// Constructor
Heap::Heap(int tamanio) {
    // El índice 0 no se usa para facilitar los cálculos
    capacidad = tamanio + 1;
    llave = new int[capacidad];
    tamanoActual = 0;
}

// Destructor
Heap::~Heap() {
    delete[] llave;
}

// Insertar un elemento en el heap
void Heap::insertar(int nuevaLlave) {
    if (tamanoActual >= capacidad - 1) {
        cout << "Heap lleno, no se puede insertar más elementos." << endl;
        return;
    }
    
    // Insertar nuevo elemento al final del heap
    tamanoActual++;
    int siguiente = tamanoActual;
    int padre = siguiente / 2;
    
    llave[siguiente] = nuevaLlave;
    
    cout << "Insertando " << nuevaLlave << endl;
    
    // Restaurar la propiedad del heap (sift-up)
    while (siguiente != 1 && llave[padre] < llave[siguiente]) {
        cout << "Intercambio: " << llave[padre] << " <-> " << llave[siguiente] << endl;
        
        // Intercambiar padre e hijo
        int auxiliar = llave[padre];
        llave[padre] = llave[siguiente];
        llave[siguiente] = auxiliar;
        
        // Avanzar sobre el árbol
        siguiente = padre;
        padre = siguiente / 2;
    }
}

// Construir heap a partir de un arreglo
void Heap::construirHeap(int arr[], int tamano) {
    if (tamano >= capacidad) {
        cout << "Arreglo demasiado grande para el heap." << endl;
        return;
    }
    
    // Copiar arreglo a llave (empezando en índice 1)
    for (int i = 0; i < tamano; i++) {
        tamanoActual++;
        llave[tamanoActual] = arr[i];
    }
    
    cout << "Arreglo inicial: ";
    imprimirArreglo();
    
    // Convertir el arreglo en un heap
    for (int i = tamanoActual / 2; i >= 1; i--) {
        int padre = i;
        int hijo;
        
        // Determinar cuál hijo es mayor
        if (2*padre <= tamanoActual) {
            hijo = 2*padre;
            if (hijo + 1 <= tamanoActual && llave[hijo + 1] > llave[hijo]) {
                hijo = hijo + 1;
            }
            
            while (hijo <= tamanoActual && llave[hijo] > llave[padre]) {
                cout << "Intercambio (construir): " << llave[padre] << " <-> " << llave[hijo] << endl;
                
                // Intercambiar padre e hijo
                int auxiliar = llave[padre];
                llave[padre] = llave[hijo];
                llave[padre + hijo - padre] = auxiliar;
                
                padre = hijo;
                hijo = 2*padre;
                
                // Encontrar el hijo mayor
                if (hijo + 1 <= tamanoActual && llave[hijo + 1] > llave[hijo]) {
                    hijo = hijo + 1;
                }
            }
        }
    }
    
    cout << "Heap construido: ";
    imprimirArreglo();
}

// Realizar HeapSort
void Heap::heapSort() {
    cout << "\nEjecutando HeapSort:" << endl;
    
    for (int ultima = tamanoActual; ultima >= 2; ultima--) {
        // Mover la raíz al último lugar
        int llaveAnterior = llave[ultima];
        llave[ultima] = llave[1];
        
        cout << "Intercambio (sort): " << llave[1] << " <-> " << llaveAnterior << endl;
        
        // Ajustar el árbol al tamaño menos 1
        int padre = 1;
        
        // Buscar al mayor de los hijos de la raíz
        int hijo;
        if (ultima - 1 >= 3 && llave[3] > llave[2]) {
            hijo = 3;
        } else {
            hijo = 2;
        }
        
        // Mover las llaves hacia arriba hasta encontrar el lugar para llaveAnterior
        while (hijo <= ultima - 1 && llave[hijo] > llaveAnterior) {
            cout << "Reorganizando: " << llave[padre] << " <- " << llave[hijo] << endl;
            
            llave[padre] = llave[hijo];
            padre = hijo;
            hijo = padre * 2;
            
            // Encontrar al mayor de los hijos del padre
            if (hijo + 1 <= ultima - 1 && llave[hijo + 1] > llave[hijo]) {
                hijo = hijo + 1;
            }
        }
        
        llave[padre] = llaveAnterior;
        
        cout << "Estado actual: ";
        imprimirArreglo();
    }
    
    cout << "\nArreglo ordenado: ";
    imprimirArreglo();
}

// Imprimir el arreglo del heap
void Heap::imprimirArreglo() {
    for (int i = 1; i <= tamanoActual; i++) {
        cout << llave[i] << " ";
    }
    cout << endl;
}