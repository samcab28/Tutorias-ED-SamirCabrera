#include <iostream>
#include "grafo.h"
#include "kruskal.h"
#include "prim.h"

int main() {
    std::cout << "=== IMPLEMENTACION DE ALGORITMOS MST ===" << std::endl;
    
    // Crear un grafo de ejemplo con 6 vértices
    Grafo grafo(6);
    
    // Agregar aristas (origen, destino, peso)
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 2);
    grafo.agregarArista(1, 2, 1);
    grafo.agregarArista(1, 3, 5);
    grafo.agregarArista(2, 3, 8);
    grafo.agregarArista(2, 4, 10);
    grafo.agregarArista(3, 4, 2);
    grafo.agregarArista(3, 5, 6);
    grafo.agregarArista(4, 5, 3);
    
    std::cout << "\nGrafo original:" << std::endl;
    grafo.mostrarGrafo();
    
    // Ejecutar algoritmo de Kruskal
    AlgoritmoKruskal kruskal(&grafo);
    kruskal.ejecutar();
    kruskal.mostrarMST();
    
    // Ejecutar algoritmo de Prim
    AlgoritmoPrim prim(&grafo);
    prim.ejecutar(0); // Comenzar desde el vértice 0
    prim.mostrarMST();
    
    // Verificar que ambos algoritmos dan el mismo peso total
    std::cout << "\n=== VERIFICACION ===" << std::endl;
    std::cout << "Peso total Kruskal: " << kruskal.getPesoTotal() << std::endl;
    std::cout << "Peso total Prim: " << prim.getPesoTotal() << std::endl;
    
    if (kruskal.getPesoTotal() == prim.getPesoTotal()) {
        std::cout << "✓ Ambos algoritmos encontraron el mismo peso mínimo!" << std::endl;
    } else {
        std::cout << "✗ Error: Los pesos no coinciden!" << std::endl;
    }
    
    std::cout << "\n=== PRUEBA CON GRAFO MAS PEQUEÑO ===" << std::endl;
    
    // Crear un grafo más pequeño para prueba adicional
    Grafo grafoSimple(4);
    grafoSimple.agregarArista(0, 1, 10);
    grafoSimple.agregarArista(0, 2, 6);
    grafoSimple.agregarArista(0, 3, 5);
    grafoSimple.agregarArista(1, 3, 15);
    grafoSimple.agregarArista(2, 3, 4);
    
    std::cout << "\nGrafo simple:" << std::endl;
    grafoSimple.mostrarGrafo();
    
    AlgoritmoKruskal kruskal2(&grafoSimple);
    kruskal2.ejecutar();
    kruskal2.mostrarMST();
    
    AlgoritmoPrim prim2(&grafoSimple);
    prim2.ejecutar(0);
    prim2.mostrarMST();
    
    std::cout << "\nPeso total Kruskal: " << kruskal2.getPesoTotal() << std::endl;
    std::cout << "Peso total Prim: " << prim2.getPesoTotal() << std::endl;
    
    return 0;
}