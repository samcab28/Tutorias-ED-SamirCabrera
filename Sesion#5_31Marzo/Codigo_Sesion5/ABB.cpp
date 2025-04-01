#ifndef ABB_CPP
#define ABB_CPP

#include "ABB.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <vector>

// Constructor
template <typename T>
ABB<T>::ABB() : raiz(nullptr) {}

// Destructor
template <typename T>
ABB<T>::~ABB() {
    destruir(raiz);
}

// Destruir el árbol
template <typename T>
void ABB<T>::destruir(Nodo<T>* nodo) {
    if (nodo) {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}

// Verificar si el árbol está vacío
template <typename T>
bool ABB<T>::estaVacio() {
    return raiz == nullptr;
}

// Insertar un valor en el árbol
template <typename T>
void ABB<T>::insertar(const T& valor) {
    raiz = insertar(raiz, valor);
}

// Método auxiliar para insertar un valor
template <typename T>
Nodo<T>* ABB<T>::insertar(Nodo<T>* nodo, const T& valor) {
    if (nodo == nullptr) {
        return new Nodo<T>(valor);
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }

    return nodo;
}

// Buscar un valor en el árbol
template <typename T>
bool ABB<T>::buscar(const T& valor) {
    return buscar(raiz, valor) != nullptr;
}

// Método auxiliar para buscar un valor
template <typename T>
Nodo<T>* ABB<T>::buscar(Nodo<T>* nodo, const T& valor) {
    if (nodo == nullptr || nodo->dato == valor) {
        return nodo;
    }

    if (valor < nodo->dato) {
        return buscar(nodo->izquierda, valor);
    } else {
        return buscar(nodo->derecha, valor);
    }
}

// Eliminar un valor del árbol
template <typename T>
void ABB<T>::eliminar(const T& valor) {
    raiz = eliminar(raiz, valor);
}

// Método auxiliar para eliminar un valor
template <typename T>
Nodo<T>* ABB<T>::eliminar(Nodo<T>* nodo, const T& valor) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (valor < nodo->dato) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    } else {
        // Caso 1: Nodo hoja (sin hijos)
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
            delete nodo;
            return nullptr;
        }
        // Caso 2: Nodo con un hijo
        else if (nodo->izquierda == nullptr) {
            Nodo<T>* temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            Nodo<T>* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            Nodo<T>* temp = encontrarMinimo(nodo->derecha);
            nodo->dato = temp->dato;
            nodo->derecha = eliminar(nodo->derecha, temp->dato);
        }
    }

    return nodo;
}

// Encontrar el nodo con el valor mínimo
template <typename T>
Nodo<T>* ABB<T>::encontrarMinimo(Nodo<T>* nodo) {
    Nodo<T>* actual = nodo;

    while (actual && actual->izquierda != nullptr) {
        actual = actual->izquierda;
    }

    return actual;
}

// Mostrar el árbol en orden (inorden)
template <typename T>
void ABB<T>::mostrarInOrden() {
    if (estaVacio()) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    std::cout << "Recorrido InOrden: ";
    inOrden(raiz);
    std::cout << std::endl;
}

// Método auxiliar para recorrido inorden
template <typename T>
void ABB<T>::inOrden(Nodo<T>* nodo) {
    if (nodo) {
        inOrden(nodo->izquierda);
        std::cout << nodo->dato << " ";
        inOrden(nodo->derecha);
    }
}

// Mostrar el árbol en preorden
template <typename T>
void ABB<T>::mostrarPreOrden() {
    if (estaVacio()) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    std::cout << "Recorrido PreOrden: ";
    preOrden(raiz);
    std::cout << std::endl;
}

// Método auxiliar para recorrido preorden
template <typename T>
void ABB<T>::preOrden(Nodo<T>* nodo) {
    if (nodo) {
        std::cout << nodo->dato << " ";
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

// Mostrar el árbol en postorden
template <typename T>
void ABB<T>::mostrarPostOrden() {
    if (estaVacio()) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    std::cout << "Recorrido PostOrden: ";
    postOrden(raiz);
    std::cout << std::endl;
}

// Método auxiliar para recorrido postorden
template <typename T>
void ABB<T>::postOrden(Nodo<T>* nodo) {
    if (nodo) {
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        std::cout << nodo->dato << " ";
    }
}

// Calcular la altura del árbol
template <typename T>
int ABB<T>::altura(Nodo<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int alturaIzq = altura(nodo->izquierda);
    int alturaDer = altura(nodo->derecha);

    return (alturaIzq > alturaDer ? alturaIzq : alturaDer) + 1;
}

// Imprimir un nivel específico del árbol
template <typename T>
void ABB<T>::imprimirNivel(Nodo<T>* nodo, int nivel, int espacio) {
    if (nodo == nullptr) {
        if (nivel == 1) {
            std::cout << std::setw(espacio) << " ";
        }
        return;
    }

    if (nivel == 1) {
        std::cout << std::setw(espacio) << nodo->dato;
    } else if (nivel > 1) {
        imprimirNivel(nodo->izquierda, nivel - 1, espacio);
        imprimirNivel(nodo->derecha, nivel - 1, espacio);
    }
}

// Visualización básica del árbol
template <typename T>
void ABB<T>::visualizarArbol() {
    if (estaVacio()) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    int h = altura(raiz);
    int espacio = 4;

    std::cout << "Visualización del árbol:" << std::endl;
    std::cout << "------------------------" << std::endl;

    for (int i = 1; i <= h; i++) {
        imprimirNivel(raiz, i, (1 << (h - i)) * espacio);
        std::cout << std::endl;
    }
}

// Visualización detallada del árbol (más interactiva)
template <typename T>
void ABB<T>::visualizarArbolDetallado() {
    if (estaVacio()) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    std::cout << "\nVisualización Detallada del Árbol" << std::endl;
    std::cout << "=================================" << std::endl;

    std::queue<std::pair<Nodo<T>*, std::string>> cola;
    cola.push({raiz, "Raíz"});

    while (!cola.empty()) {
        int nivelSize = cola.size();

        for (int i = 0; i < nivelSize; i++) {
            auto [nodo, posicion] = cola.front();
            cola.pop();

            std::cout << posicion << ": " << nodo->dato;

            // Mostrar información de hijos
            if (nodo->izquierda || nodo->derecha) {
                std::cout << " (";

                if (nodo->izquierda) {
                    std::cout << "Izq=" << nodo->izquierda->dato;
                    cola.push({nodo->izquierda, posicion + " -> Izq"});
                } else {
                    std::cout << "Izq=NULL";
                }

                std::cout << ", ";

                if (nodo->derecha) {
                    std::cout << "Der=" << nodo->derecha->dato;
                    cola.push({nodo->derecha, posicion + " -> Der"});
                } else {
                    std::cout << "Der=NULL";
                }

                std::cout << ")";
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;  // Separación entre niveles
    }
}

#endif // ABB_CPP