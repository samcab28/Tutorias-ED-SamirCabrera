#include "ABB.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

// Implementación de la clase nodoArbol
nodoArbol::nodoArbol(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}

nodoArbol::nodoArbol(int val, nodoArbol* izq, nodoArbol* der) : valor(val), izquierda(izq), derecha(der) {}

// Constructor
ArbolBinarioBusqueda::ArbolBinarioBusqueda() : raiz(nullptr) {}

// Destructor
ArbolBinarioBusqueda::~ArbolBinarioBusqueda() {
    destruir(raiz);
}

// Destruir el árbol
void ArbolBinarioBusqueda::destruir(pnodoArbol nodo) {
    if (nodo) {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}

// Verificar si el árbol está vacío
bool ArbolBinarioBusqueda::estaVacio() {
    return raiz == nullptr;
}

// Insertar un valor en el árbol
void ArbolBinarioBusqueda::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

// Método auxiliar para insertar un valor
pnodoArbol ArbolBinarioBusqueda::insertar(pnodoArbol nodo, int valor) {
    if (nodo == nullptr) {
        return new nodoArbol(valor);
    }

    if (valor < nodo->valor) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->valor) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }

    return nodo;
}

// Buscar un valor en el árbol
bool ArbolBinarioBusqueda::buscar(int valor) {
    return buscar(raiz, valor) != nullptr;
}

// Método auxiliar para buscar un valor
pnodoArbol ArbolBinarioBusqueda::buscar(pnodoArbol nodo, int valor) {
    if (nodo == nullptr || nodo->valor == valor) {
        return nodo;
    }

    if (valor < nodo->valor) {
        return buscar(nodo->izquierda, valor);
    } else {
        return buscar(nodo->derecha, valor);
    }
}

// Eliminar un valor del árbol
void ArbolBinarioBusqueda::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}

// Método auxiliar para eliminar un valor
pnodoArbol ArbolBinarioBusqueda::eliminar(pnodoArbol nodo, int valor) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (valor < nodo->valor) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    } else if (valor > nodo->valor) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    } else {
        // Caso 1: Nodo hoja (sin hijos)
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
            delete nodo;
            return nullptr;
        }
        // Caso 2: Nodo con un hijo
        else if (nodo->izquierda == nullptr) {
            pnodoArbol temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            pnodoArbol temp = nodo->izquierda;
            delete nodo;
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            pnodoArbol temp = encontrarMinimo(nodo->derecha);
            nodo->valor = temp->valor;
            nodo->derecha = eliminar(nodo->derecha, temp->valor);
        }
    }

    return nodo;
}

// Encontrar el nodo con el valor mínimo
pnodoArbol ArbolBinarioBusqueda::encontrarMinimo(pnodoArbol nodo) {
    pnodoArbol actual = nodo;

    while (actual && actual->izquierda != nullptr) {
        actual = actual->izquierda;
    }

    return actual;
}

// Mostrar el árbol en orden (inorden)
void ArbolBinarioBusqueda::mostrarInOrden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    cout << "Recorrido InOrden: ";
    inOrden(raiz);
    cout << endl;
}

// Método auxiliar para recorrido inorden
void ArbolBinarioBusqueda::inOrden(pnodoArbol nodo) {
    if (nodo) {
        inOrden(nodo->izquierda);
        cout << nodo->valor << " ";
        inOrden(nodo->derecha);
    }
}

// Mostrar el árbol en preorden
void ArbolBinarioBusqueda::mostrarPreOrden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    cout << "Recorrido PreOrden: ";
    preOrden(raiz);
    cout << endl;
}

// Método auxiliar para recorrido preorden
void ArbolBinarioBusqueda::preOrden(pnodoArbol nodo) {
    if (nodo) {
        cout << nodo->valor << " ";
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

// Mostrar el árbol en postorden
void ArbolBinarioBusqueda::mostrarPostOrden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    cout << "Recorrido PostOrden: ";
    postOrden(raiz);
    cout << endl;
}

// Método auxiliar para recorrido postorden
void ArbolBinarioBusqueda::postOrden(pnodoArbol nodo) {
    if (nodo) {
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        cout << nodo->valor << " ";
    }
}

// Calcular la altura del árbol
int ArbolBinarioBusqueda::altura(pnodoArbol nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int alturaIzq = altura(nodo->izquierda);
    int alturaDer = altura(nodo->derecha);

    return (alturaIzq > alturaDer ? alturaIzq : alturaDer) + 1;
}

// Imprimir un nivel específico del árbol
void ArbolBinarioBusqueda::imprimirNivel(pnodoArbol nodo, int nivel, int espacio) {
    if (nodo == nullptr) {
        if (nivel == 1) {
            cout << setw(espacio) << " ";
        }
        return;
    }

    if (nivel == 1) {
        cout << setw(espacio) << nodo->valor;
    } else if (nivel > 1) {
        imprimirNivel(nodo->izquierda, nivel - 1, espacio);
        imprimirNivel(nodo->derecha, nivel - 1, espacio);
    }
}

// Visualización básica del árbol
void ArbolBinarioBusqueda::visualizarArbol() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    int h = altura(raiz);
    int espacio = 4;

    cout << "Visualización del árbol:" << endl;
    cout << "------------------------" << endl;

    for (int i = 1; i <= h; i++) {
        imprimirNivel(raiz, i, (1 << (h - i)) * espacio);
        cout << endl;
    }
}

// Visualización detallada del árbol (más interactiva)
void ArbolBinarioBusqueda::visualizarArbolDetallado() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    cout << "\nVisualización Detallada del Árbol" << endl;
    cout << "=================================" << endl;

    queue<pair<pnodoArbol, string>> cola;
    cola.push({raiz, "Raíz"});

    while (!cola.empty()) {
        int nivelSize = cola.size();

        for (int i = 0; i < nivelSize; i++) {
            pnodoArbol nodo = cola.front().first;
            string posicion = cola.front().second;
            cola.pop();

            cout << posicion << ": " << nodo->valor;

            // Mostrar información de hijos
            if (nodo->izquierda || nodo->derecha) {
                cout << " (";

                if (nodo->izquierda) {
                    cout << "Izq=" << nodo->izquierda->valor;
                    cola.push({nodo->izquierda, posicion + " -> Izq"});
                } else {
                    cout << "Izq=NULL";
                }

                cout << ", ";

                if (nodo->derecha) {
                    cout << "Der=" << nodo->derecha->valor;
                    cola.push({nodo->derecha, posicion + " -> Der"});
                } else {
                    cout << "Der=NULL";
                }

                cout << ")";
            }

            cout << endl;
        }

        cout << endl;  // Separación entre niveles
    }
}