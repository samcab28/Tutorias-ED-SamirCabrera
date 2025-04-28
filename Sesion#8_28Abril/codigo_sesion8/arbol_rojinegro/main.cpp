#include "arbol_rojinegro.h"
#include <iostream>

int main() {
    // Crear un árbol rojo-negro
    ArbolRojiNegro arbol;
    
    std::cout << "== DEMOSTRACIÓN DE ÁRBOL ROJO-NEGRO ==" << std::endl << std::endl;
    
    // Insertar elementos
    std::cout << "Insertando valores: 10, 20, 30, 15, 25, 5, 35, 40" << std::endl;
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(30);
    arbol.insertar(15);
    arbol.insertar(25);
    arbol.insertar(5);
    arbol.insertar(35);
    arbol.insertar(40);
    
    // Mostrar el árbol en recorrido inorden
    std::cout << "\nRecorrido inorden (valor(color)): ";
    arbol.inorden();
    
    // Mostrar la estructura del árbol
    std::cout << "\nEstructura del árbol (vista vertical):" << std::endl;
    arbol.imprimirArbol();
    
    // Buscar elementos
    std::cout << "\nBuscar elementos:" << std::endl;
    int valorBuscar = 25;
    std::cout << "¿El valor " << valorBuscar << " existe en el árbol? " 
              << (arbol.buscar(valorBuscar) ? "Sí" : "No") << std::endl;
    
    valorBuscar = 100;
    std::cout << "¿El valor " << valorBuscar << " existe en el árbol? " 
              << (arbol.buscar(valorBuscar) ? "Sí" : "No") << std::endl;
    
    // Eliminar elementos
    std::cout << "\nEliminando valores:" << std::endl;
    int valorEliminar = 20;
    std::cout << "Eliminando " << valorEliminar << std::endl;
    arbol.eliminar(valorEliminar);
    
    // Mostrar el árbol después de eliminar
    std::cout << "\nRecorrido inorden después de eliminar " << valorEliminar << ": ";
    arbol.inorden();
    
    std::cout << "\nEstructura del árbol después de eliminar " << valorEliminar << ":" << std::endl;
    arbol.imprimirArbol();
    
    // Eliminar otro elemento
    valorEliminar = 10;
    std::cout << "\nEliminando " << valorEliminar << std::endl;
    arbol.eliminar(valorEliminar);
    
    // Mostrar el árbol después de eliminar
    std::cout << "\nRecorrido inorden después de eliminar " << valorEliminar << ": ";
    arbol.inorden();
    
    std::cout << "\nEstructura del árbol después de eliminar " << valorEliminar << ":" << std::endl;
    arbol.imprimirArbol();
    
    // Intentar eliminar un valor que no existe
    valorEliminar = 100;
    std::cout << "\nEliminando " << valorEliminar << std::endl;
    arbol.eliminar(valorEliminar);
    
    return 0;
}