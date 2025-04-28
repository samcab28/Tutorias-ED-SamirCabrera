#include "arbol_aa.h"
#include <iostream>

int main() {
    // Crear un árbol AA
    ArbolAA arbol;
    
    std::cout << "=== DEMOSTRACIÓN DE ÁRBOL AA ===" << std::endl << std::endl;
    
    // Insertar algunos valores
    std::cout << "Insertando elementos: 10, 5, 15, 3, 7, 12, 18, 1, 6, 11, 20" << std::endl;
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(18);
    arbol.insertar(1);
    arbol.insertar(6);
    arbol.insertar(11);
    arbol.insertar(20);
    
    // Mostrar la estructura del árbol
    std::cout << std::endl << "Estructura del árbol después de insertar:" << std::endl;
    arbol.imprimir();
    
    // Realizar los recorridos
    std::cout << std::endl << "Recorridos del árbol:" << std::endl;
    arbol.recorridoPreorden();
    arbol.recorridoInorden();
    arbol.recorridoPostorden();
    
    // Buscar algunos valores
    std::cout << std::endl << "Operaciones de búsqueda:" << std::endl;
    std::cout << "Buscar 7: " << (arbol.buscar(7) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscar 22: " << (arbol.buscar(22) ? "Encontrado" : "No encontrado") << std::endl;
    
    // Eliminar algunos valores
    std::cout << std::endl << "Eliminando elementos:" << std::endl;
    
    std::cout << "Eliminar 5 (nodo con dos hijos)" << std::endl;
    arbol.eliminar(5);
    arbol.imprimir();
    
    std::cout << std::endl << "Eliminar 1 (nodo hoja)" << std::endl;
    arbol.eliminar(1);
    arbol.imprimir();
    
    std::cout << std::endl << "Eliminar 18 (nodo con un hijo)" << std::endl;
    arbol.eliminar(18);
    arbol.imprimir();
    
    // Mostrar recorridos finales
    std::cout << std::endl << "Recorridos finales:" << std::endl;
    arbol.recorridoPreorden();
    arbol.recorridoInorden();
    arbol.recorridoPostorden();
    
    return 0;
}