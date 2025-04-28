#ifndef ARBOL_AA_H
#define ARBOL_AA_H

#include <iostream>

// Clase que representa un árbol AA
class ArbolAA {
private:
    // Estructura del nodo
    struct Nodo {
        int valor;      // Valor almacenado en el nodo
        int nivel;      // Nivel del nodo (importante para mantener el balance)
        Nodo* izquierdo;  // Hijo izquierdo
        Nodo* derecho;    // Hijo derecho
        
        // Constructor
        Nodo(int val) : valor(val), nivel(1), izquierdo(nullptr), derecho(nullptr) {}
    };
    
    Nodo* raiz;  // Raíz del árbol
    
    // Métodos auxiliares privados
    Nodo* skew(Nodo* nodo);     // Rebalanceo horizontal (skew)
    Nodo* split(Nodo* nodo);    // Rebalanceo vertical (split)
    Nodo* insertar(Nodo* nodo, int valor);  // Inserción recursiva
    Nodo* eliminar(Nodo* nodo, int valor);  // Eliminación recursiva
    Nodo* encontrarMin(Nodo* nodo);         // Encontrar el nodo con valor mínimo
    Nodo* disminuirNivel(Nodo* nodo);       // Ajuste de nivel durante eliminación
    void destruir(Nodo* nodo);              // Liberación de memoria
    void imprimir(Nodo* nodo, int profundidad); // Impresión recursiva
    void preorden(Nodo* nodo);              // Recorrido en preorden
    void inorden(Nodo* nodo);               // Recorrido en inorden
    void postorden(Nodo* nodo);             // Recorrido en postorden
    
public:
    // Constructor y destructor
    ArbolAA();
    ~ArbolAA();
    
    // Operaciones del árbol
    void insertar(int valor);    // Insertar un valor
    void eliminar(int valor);    // Eliminar un valor
    bool buscar(int valor);      // Buscar un valor
    void imprimir();             // Imprimir árbol
    bool estaVacio() const;      // Verificar si está vacío
    
    // Recorridos
    void recorridoPreorden();    // Recorrido en preorden
    void recorridoInorden();     // Recorrido en inorden
    void recorridoPostorden();   // Recorrido en postorden
};

#endif // ARBOL_AA_H