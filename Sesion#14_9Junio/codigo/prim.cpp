#include "prim.h"
#include <iostream>
#include <limits>

// Implementación de la clase ColaPrioridad
void ColaPrioridad::intercambiar(int i, int j) {
    NodoHeap temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

int ColaPrioridad::padre(int i) {
    return (i - 1) / 2;
}

int ColaPrioridad::hijoIzquierdo(int i) {
    return 2 * i + 1;
}

int ColaPrioridad::hijoDerecho(int i) {
    return 2 * i + 2;
}

void ColaPrioridad::heapifyArriba(int indice) {
    while (indice > 0 && heap[padre(indice)].peso > heap[indice].peso) {
        intercambiar(indice, padre(indice));
        indice = padre(indice);
    }
}

void ColaPrioridad::heapifyAbajo(int indice) {
    int menor = indice;
    int izq = hijoIzquierdo(indice);
    int der = hijoDerecho(indice);
    
    if (izq < heap.size() && heap[izq].peso < heap[menor].peso) {
        menor = izq;
    }
    
    if (der < heap.size() && heap[der].peso < heap[menor].peso) {
        menor = der;
    }
    
    if (menor != indice) {
        intercambiar(indice, menor);
        heapifyAbajo(menor);
    }
}

void ColaPrioridad::insertar(int vertice, int peso) {
    heap.push_back(NodoHeap(vertice, peso));
    heapifyArriba(heap.size() - 1);
}

ColaPrioridad::NodoHeap ColaPrioridad::extraerMinimo() {
    if (heap.empty()) {
        return NodoHeap(-1, -1);
    }
    
    NodoHeap minimo = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    
    if (!heap.empty()) {
        heapifyAbajo(0);
    }
    
    return minimo;
}

bool ColaPrioridad::estaVacia() const {
    return heap.empty();
}

void ColaPrioridad::mostrar() const {
    for (size_t i = 0; i < heap.size(); i++) {
        std::cout << "(" << heap[i].vertice << ", " << heap[i].peso << ") ";
    }
    std::cout << std::endl;
}

// Implementación de la clase AlgoritmoPrim
AlgoritmoPrim::AlgoritmoPrim(Grafo* g) : grafo(g), pesoTotal(0) {}

void AlgoritmoPrim::ejecutar(int verticeInicial) {
    mst.clear();
    pesoTotal = 0;
    
    int numVertices = grafo->getNumVertices();
    bool* visitado = new bool[numVertices];
    int* padre = new int[numVertices];
    
    // Inicializar arrays
    for (int i = 0; i < numVertices; i++) {
        visitado[i] = false;
        padre[i] = -1;
    }
    
    ColaPrioridad colaPrioridad;
    visitado[verticeInicial] = true;
    
    // Agregar todas las aristas del vértice inicial a la cola de prioridad
    ListaAdyacencia* listaAdyacencia = grafo->getListaAdyacencia();
    ListaAdyacencia::Nodo* temp = listaAdyacencia[verticeInicial].getCabeza();
    while (temp != nullptr) {
        if (!visitado[temp->vertice]) {
            colaPrioridad.insertar(temp->vertice, temp->peso);
            if (padre[temp->vertice] == -1 || temp->peso < padre[temp->vertice]) {
                padre[temp->vertice] = verticeInicial;
            }
        }
        temp = temp->siguiente;
    }
    
    while (!colaPrioridad.estaVacia()) {
        ColaPrioridad::NodoHeap nodoMinimo = colaPrioridad.extraerMinimo();
        int vertice = nodoMinimo.vertice;
        int peso = nodoMinimo.peso;
        
        if (visitado[vertice]) {
            continue;
        }
        
        visitado[vertice] = true;
        
        if (padre[vertice] != -1) {
            mst.push_back(Arista(padre[vertice], vertice, peso));
            pesoTotal += peso;
        }
        
        // Agregar nuevas aristas a la cola de prioridad
        temp = listaAdyacencia[vertice].getCabeza();
        while (temp != nullptr) {
            if (!visitado[temp->vertice]) {
                colaPrioridad.insertar(temp->vertice, temp->peso);
                if (padre[temp->vertice] == -1 || temp->peso < padre[temp->vertice]) {
                    padre[temp->vertice] = vertice;
                }
            }
            temp = temp->siguiente;
        }
    }
    
    delete[] visitado;
    delete[] padre;
}

void AlgoritmoPrim::mostrarMST() const {
    std::cout << "\n--- Algoritmo de Prim ---" << std::endl;
    std::cout << "Aristas del MST:" << std::endl;
    for (const Arista& arista : mst) {
        std::cout << arista.getOrigen() << " - " << arista.getDestino() 
                  << " (peso: " << arista.getPeso() << ")" << std::endl;
    }
    std::cout << "Peso total del MST: " << pesoTotal << std::endl;
}

int AlgoritmoPrim::getPesoTotal() const {
    return pesoTotal;
}