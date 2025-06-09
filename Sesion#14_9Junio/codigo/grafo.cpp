#include "grafo.h"
#include <iostream>
#include <algorithm>

// Implementación de la clase Arista
Arista::Arista(int o, int d, int p) : origen(o), destino(d), peso(p) {}

int Arista::getOrigen() const {
    return origen;
}

int Arista::getDestino() const {
    return destino;
}

int Arista::getPeso() const {
    return peso;
}

bool Arista::operator<(const Arista& otra) const {
    return peso < otra.peso;
}

// Implementación de la clase ListaAdyacencia
ListaAdyacencia::ListaAdyacencia() : cabeza(nullptr) {}

ListaAdyacencia::~ListaAdyacencia() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaAdyacencia::agregar(int vertice, int peso) {
    Nodo* nuevoNodo = new Nodo(vertice, peso);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

ListaAdyacencia::Nodo* ListaAdyacencia::getCabeza() const {
    return cabeza;
}

// Implementación de la clase Grafo
Grafo::Grafo(int vertices) : numVertices(vertices) {
    listaAdyacencia = new ListaAdyacencia[vertices];
}

Grafo::~Grafo() {
    delete[] listaAdyacencia;
}

void Grafo::agregarArista(int origen, int destino, int peso) {
    listaAdyacencia[origen].agregar(destino, peso);
    listaAdyacencia[destino].agregar(origen, peso);
    aristas.push_back(Arista(origen, destino, peso));
}

int Grafo::getNumVertices() const {
    return numVertices;
}

ListaAdyacencia* Grafo::getListaAdyacencia() const {
    return listaAdyacencia;
}

const std::vector<Arista>& Grafo::getAristas() const {
    return aristas;
}

void Grafo::mostrarGrafo() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertice " << i << ": ";
        ListaAdyacencia::Nodo* temp = listaAdyacencia[i].getCabeza();
        while (temp != nullptr) {
            std::cout << "(" << temp->vertice << ", peso: " << temp->peso << ") ";
            temp = temp->siguiente;
        }
        std::cout << std::endl;
    }
}