#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "grafo.h"
#include <vector>

class UnionFind {
private:
    int* padre;
    int* rango;
    int tamaño;

public:
    UnionFind(int n);
    ~UnionFind();
    int encontrar(int x);
    bool unir(int x, int y);
};

class AlgoritmoKruskal {
private:
    Grafo* grafo;
    std::vector<Arista> mst;
    int pesoTotal;

public:
    AlgoritmoKruskal(Grafo* g);
    void ejecutar();
    void mostrarMST() const;
    int getPesoTotal() const;
};

#endif