#ifndef PRIM_H
#define PRIM_H

#include "grafo.h"
#include <vector>

class ColaPrioridad {
public:
    class NodoHeap {
    public:
        int vertice;
        int peso;
        
        NodoHeap(int v, int p) : vertice(v), peso(p) {}
    };
    
private:
    std::vector<NodoHeap> heap;
    
    void intercambiar(int i, int j);
    void heapifyArriba(int indice);
    void heapifyAbajo(int indice);
    int padre(int i);
    int hijoIzquierdo(int i);
    int hijoDerecho(int i);

public:
    void insertar(int vertice, int peso);
    NodoHeap extraerMinimo();
    bool estaVacia() const;
    void mostrar() const;
};

class AlgoritmoPrim {
private:
    Grafo* grafo;
    std::vector<Arista> mst;
    int pesoTotal;

public:
    AlgoritmoPrim(Grafo* g);
    void ejecutar(int verticeInicial = 0);
    void mostrarMST() const;
    int getPesoTotal() const;
};

#endif