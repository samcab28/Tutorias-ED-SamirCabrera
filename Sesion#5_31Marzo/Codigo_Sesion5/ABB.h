#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <string>
using namespace std;

// Clase para el nodo del árbol
class nodoArbol {
public:
    nodoArbol(int valor);
    nodoArbol(int valor, nodoArbol* izq, nodoArbol* der);
private:
    int valor;
    nodoArbol* izquierda;
    nodoArbol* derecha;
    friend class ArbolBinarioBusqueda;
};
typedef nodoArbol* pnodoArbol;

// Clase para el Árbol Binario de Búsqueda
class ArbolBinarioBusqueda {
public:
    ArbolBinarioBusqueda();
    ~ArbolBinarioBusqueda();

    // Operaciones básicas
    void insertar(int valor);
    bool buscar(int valor);
    void eliminar(int valor);

    // Métodos de visualización
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
    bool estaVacio();

    // Visualización interactiva
    void visualizarArbol();
    void visualizarArbolDetallado();

private:
    pnodoArbol raiz;

    // Métodos auxiliares privados
    pnodoArbol insertar(pnodoArbol nodo, int valor);
    pnodoArbol buscar(pnodoArbol nodo, int valor);
    void inOrden(pnodoArbol nodo);
    void preOrden(pnodoArbol nodo);
    void postOrden(pnodoArbol nodo);
    pnodoArbol eliminar(pnodoArbol nodo, int valor);
    pnodoArbol encontrarMinimo(pnodoArbol nodo);
    void destruir(pnodoArbol nodo);

    // Métodos para visualización
    int altura(pnodoArbol nodo);
    void imprimirNivel(pnodoArbol nodo, int nivel, int espacio);
};

#endif // ABB_H