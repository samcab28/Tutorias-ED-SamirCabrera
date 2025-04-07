#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

// Clase para el nodo del árbol AVL
class NodoAVL {
public:
    NodoAVL(int val);
    
private:
    int valor;
    int altura;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    
    friend class ArbolAVL;
};

typedef NodoAVL* pNodoAVL;

// Clase para el Árbol AVL
class ArbolAVL {
public:
    ArbolAVL();
    ~ArbolAVL();
    
    // Operaciones básicas
    void insertar(int valor);
    bool buscar(int valor);
    void eliminar(int valor);
    bool estaVacio();
    
    // Métodos de visualización
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
    void visualizarArbol();
    void visualizarArbolDetallado();
    
private:
    pNodoAVL raiz;
    
    // Métodos auxiliares para el balanceo
    int obtenerAltura(pNodoAVL nodo);
    int factorBalance(pNodoAVL nodo);
    pNodoAVL rotacionDerecha(pNodoAVL y);
    pNodoAVL rotacionIzquierda(pNodoAVL x);
    
    // Métodos auxiliares para operaciones
    pNodoAVL insertar(pNodoAVL nodo, int valor);
    pNodoAVL eliminar(pNodoAVL nodo, int valor);
    pNodoAVL buscarNodo(pNodoAVL nodo, int valor);
    pNodoAVL encontrarMinimo(pNodoAVL nodo);
    void destruir(pNodoAVL nodo);
    
    // Métodos para recorridos
    void inOrden(pNodoAVL nodo);
    void preOrden(pNodoAVL nodo);
    void postOrden(pNodoAVL nodo);
    
    // Métodos para visualización
    void imprimirNivel(pNodoAVL nodo, int nivel, int espacio);
};

#endif // AVL_H