#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

class Arista {
private:
    int origen;
    int destino;
    int peso;

public:
    Arista(int o, int d, int p);
    int getOrigen() const;
    int getDestino() const;
    int getPeso() const;
    bool operator<(const Arista& otra) const;
};

class ListaAdyacencia {
public:
    class Nodo {
    public:
        int vertice;
        int peso;
        Nodo* siguiente;
        
        Nodo(int v, int p) : vertice(v), peso(p), siguiente(nullptr) {}
    };
    
private:
    Nodo* cabeza;

public:
    ListaAdyacencia();
    ~ListaAdyacencia();
    void agregar(int vertice, int peso);
    Nodo* getCabeza() const;
};

class Grafo {
private:
    int numVertices;
    ListaAdyacencia* listaAdyacencia;
    std::vector<Arista> aristas;

public:
    Grafo(int vertices);
    ~Grafo();
    void agregarArista(int origen, int destino, int peso);
    int getNumVertices() const;
    ListaAdyacencia* getListaAdyacencia() const;
    const std::vector<Arista>& getAristas() const;
    void mostrarGrafo() const;
};

#endif