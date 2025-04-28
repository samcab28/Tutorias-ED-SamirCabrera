#ifndef ARBOL_ROJINEGRO_H
#define ARBOL_ROJINEGRO_H

#include <iostream>

// Enumeración para representar los colores de los nodos
enum Color { ROJO, NEGRO };

// Clase para los nodos del árbol
class Nodo {
public:
    int valor;
    Color color;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo* padre;

    // Constructor
    Nodo(int val);
};

// Clase para el árbol rojinegro
class ArbolRojiNegro {
private:
    Nodo* raiz;
    Nodo* nil; // Nodo nulo (centinela)

    // Métodos auxiliares privados
    void rotacionIzquierda(Nodo* x);
    void rotacionDerecha(Nodo* y);
    void arreglarInsercion(Nodo* k);
    void arreglarEliminacion(Nodo* x);
    void transplante(Nodo* u, Nodo* v);
    Nodo* minimo(Nodo* nodo);
    void inordenRecursivo(Nodo* nodo);
    void imprimirArbolRecursivo(Nodo* nodo, int nivel, int indentacion);
    void liberarMemoria(Nodo* nodo);

public:
    // Constructor y destructor
    ArbolRojiNegro();
    ~ArbolRojiNegro();

    // Operaciones básicas del árbol
    void insertar(int valor);
    void eliminar(int valor);
    bool buscar(int valor);
    void inorden(); // Recorrido en orden
    void imprimirArbol(); // Imprime estructura del árbol
    bool estaVacio();
};

#endif // ARBOL_ROJINEGRO_H