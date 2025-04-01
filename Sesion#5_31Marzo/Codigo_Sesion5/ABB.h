#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

// Estructura del nodo del árbol
template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;

    Nodo(const T& valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

// Clase del Árbol Binario de Búsqueda
template <typename T>
class ABB {
private:
    Nodo<T>* raiz;

    // Métodos auxiliares privados
    Nodo<T>* insertar(Nodo<T>* nodo, const T& valor);
    Nodo<T>* buscar(Nodo<T>* nodo, const T& valor);
    void inOrden(Nodo<T>* nodo);
    void preOrden(Nodo<T>* nodo);
    void postOrden(Nodo<T>* nodo);
    Nodo<T>* eliminar(Nodo<T>* nodo, const T& valor);
    Nodo<T>* encontrarMinimo(Nodo<T>* nodo);
    void destruir(Nodo<T>* nodo);

    // Métodos para visualización
    int altura(Nodo<T>* nodo);
    void imprimirNivel(Nodo<T>* nodo, int nivel, int espacio);

public:
    ABB();
    ~ABB();

    // Operaciones básicas
    void insertar(const T& valor);
    bool buscar(const T& valor);
    void eliminar(const T& valor);

    // Métodos de visualización
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
    bool estaVacio();

    // Visualización interactiva
    void visualizarArbol();
    void visualizarArbolDetallado();
};

// Incluimos la implementación aquí porque es una plantilla
#include "ABB.cpp"

#endif // ABB_H