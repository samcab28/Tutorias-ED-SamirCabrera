#include "kruskal.h"
#include <iostream>
#include <algorithm>

// Implementación de la clase UnionFind
UnionFind::UnionFind(int n) : tamaño(n) {
    padre = new int[n];
    rango = new int[n];
    for (int i = 0; i < n; i++) {
        padre[i] = i;
        rango[i] = 0;
    }
}

UnionFind::~UnionFind() {
    delete[] padre;
    delete[] rango;
}

int UnionFind::encontrar(int x) {
    if (padre[x] != x) {
        padre[x] = encontrar(padre[x]); // Compresión de camino
    }
    return padre[x];
}

bool UnionFind::unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    
    if (raizX == raizY) {
        return false; // Ya están en el mismo conjunto
    }
    
    // Unión por rango
    if (rango[raizX] < rango[raizY]) {
        padre[raizX] = raizY;
    } else if (rango[raizX] > rango[raizY]) {
        padre[raizY] = raizX;
    } else {
        padre[raizY] = raizX;
        rango[raizX]++;
    }
    
    return true;
}

// Implementación de la clase AlgoritmoKruskal
AlgoritmoKruskal::AlgoritmoKruskal(Grafo* g) : grafo(g), pesoTotal(0) {}

void AlgoritmoKruskal::ejecutar() {
    mst.clear();
    pesoTotal = 0;
    
    // Obtener todas las aristas y ordenarlas
    std::vector<Arista> aristas = grafo->getAristas();
    std::sort(aristas.begin(), aristas.end());
    
    UnionFind uf(grafo->getNumVertices());
    
    for (const Arista& arista : aristas) {
        if (uf.unir(arista.getOrigen(), arista.getDestino())) {
            mst.push_back(arista);
            pesoTotal += arista.getPeso();
            
            // Si ya tenemos V-1 aristas, terminamos
            if (mst.size() == grafo->getNumVertices() - 1) {
                break;
            }
        }
    }
}

void AlgoritmoKruskal::mostrarMST() const {
    std::cout << "\n--- Algoritmo de Kruskal ---" << std::endl;
    std::cout << "Aristas del MST:" << std::endl;
    for (const Arista& arista : mst) {
        std::cout << arista.getOrigen() << " - " << arista.getDestino() 
                  << " (peso: " << arista.getPeso() << ")" << std::endl;
    }
    std::cout << "Peso total del MST: " << pesoTotal << std::endl;
}

int AlgoritmoKruskal::getPesoTotal() const {
    return pesoTotal;
}