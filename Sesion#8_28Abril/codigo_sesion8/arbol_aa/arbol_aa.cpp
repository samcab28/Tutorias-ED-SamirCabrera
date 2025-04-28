#include "arbol_aa.h"
#include <iostream>

// Constructor
ArbolAA::ArbolAA() : raiz(nullptr) {}

// Destructor
ArbolAA::~ArbolAA() {
    destruir(raiz);
}

// Liberar memoria recursivamente
void ArbolAA::destruir(Nodo* nodo) {
    if (nodo != nullptr) {
        destruir(nodo->izquierdo);
        destruir(nodo->derecho);
        delete nodo;
    }
}

// Operación skew: rotación derecha si el hijo izquierdo tiene el mismo nivel
ArbolAA::Nodo* ArbolAA::skew(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;
    
    if (nodo->izquierdo != nullptr && nodo->izquierdo->nivel == nodo->nivel) {
        // Rotación a la derecha
        Nodo* L = nodo->izquierdo;
        nodo->izquierdo = L->derecho;
        L->derecho = nodo;
        return L;
    }
    return nodo;
}

// Operación split: rotación izquierda si hay dos hijos derechos consecutivos con el mismo nivel
ArbolAA::Nodo* ArbolAA::split(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;
    
    if (nodo->derecho != nullptr && nodo->derecho->derecho != nullptr && 
        nodo->nivel == nodo->derecho->derecho->nivel) {
        // Rotación a la izquierda y aumento de nivel
        Nodo* R = nodo->derecho;
        nodo->derecho = R->izquierdo;
        R->izquierdo = nodo;
        R->nivel++;
        return R;
    }
    return nodo;
}

// Insertar un valor en el árbol
void ArbolAA::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

// Inserción recursiva
ArbolAA::Nodo* ArbolAA::insertar(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return new Nodo(valor);
    }
    
    if (valor < nodo->valor) {
        nodo->izquierdo = insertar(nodo->izquierdo, valor);
    } else if (valor > nodo->valor) {
        nodo->derecho = insertar(nodo->derecho, valor);
    } else {
        // Valor ya existe, no hacer nada
        return nodo;
    }
    
    // Rebalanceo
    nodo = skew(nodo);
    nodo = split(nodo);
    
    return nodo;
}

// Buscar un valor en el árbol
bool ArbolAA::buscar(int valor) {
    Nodo* actual = raiz;
    while (actual != nullptr) {
        if (valor < actual->valor) {
            actual = actual->izquierdo;
        } else if (valor > actual->valor) {
            actual = actual->derecho;
        } else {
            return true; // Valor encontrado
        }
    }
    return false; // Valor no encontrado
}

// Encuentra el nodo con valor mínimo
ArbolAA::Nodo* ArbolAA::encontrarMin(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;
    while (nodo->izquierdo != nullptr) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// Ajuste de nivel durante eliminación
ArbolAA::Nodo* ArbolAA::disminuirNivel(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;
    
    int nivelDeseado = 1;
    if (nodo->izquierdo != nullptr) nivelDeseado = nodo->izquierdo->nivel;
    if (nodo->derecho != nullptr && nodo->derecho->nivel < nivelDeseado) {
        nivelDeseado = nodo->derecho->nivel;
    }
    nivelDeseado++;
    
    if (nivelDeseado < nodo->nivel) {
        nodo->nivel = nivelDeseado;
        if (nodo->derecho != nullptr && nivelDeseado < nodo->derecho->nivel) {
            nodo->derecho->nivel = nivelDeseado;
        }
    }
    
    return nodo;
}

// Eliminar un valor del árbol
void ArbolAA::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}

// Eliminación recursiva
ArbolAA::Nodo* ArbolAA::eliminar(Nodo* nodo, int valor) {
    if (nodo == nullptr) return nullptr;
    
    if (valor < nodo->valor) {
        nodo->izquierdo = eliminar(nodo->izquierdo, valor);
    } else if (valor > nodo->valor) {
        nodo->derecho = eliminar(nodo->derecho, valor);
    } else {
        // Caso: encontramos el nodo a eliminar
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
            // Caso 1: es una hoja
            delete nodo;
            return nullptr;
        } else if (nodo->izquierdo == nullptr) {
            // Caso 2: solo tiene hijo derecho
            Nodo* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (nodo->derecho == nullptr) {
            // Caso 3: solo tiene hijo izquierdo
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        } else {
            // Caso 4: tiene dos hijos
            // Reemplazar con el sucesor (mínimo del subárbol derecho)
            Nodo* sucesor = encontrarMin(nodo->derecho);
            nodo->valor = sucesor->valor;
            nodo->derecho = eliminar(nodo->derecho, sucesor->valor);
        }
    }
    
    // Rebalanceo después de eliminar
    nodo = disminuirNivel(nodo);
    nodo = skew(nodo);
    if (nodo->derecho != nullptr) {
        nodo->derecho = skew(nodo->derecho);
        if (nodo->derecho->derecho != nullptr) {
            nodo->derecho->derecho = skew(nodo->derecho->derecho);
        }
    }
    nodo = split(nodo);
    if (nodo->derecho != nullptr) {
        nodo->derecho = split(nodo->derecho);
    }
    
    return nodo;
}

// Verifica si el árbol está vacío
bool ArbolAA::estaVacio() const {
    return raiz == nullptr;
}

// Imprime el árbol de manera visual
void ArbolAA::imprimir() {
    if (estaVacio()) {
        std::cout << "Árbol vacío" << std::endl;
    } else {
        std::cout << "Estructura del Árbol AA:" << std::endl;
        imprimir(raiz, 0);
    }
}

// Impresión recursiva
void ArbolAA::imprimir(Nodo* nodo, int profundidad) {
    if (nodo != nullptr) {
        imprimir(nodo->derecho, profundidad + 1);
        
        for (int i = 0; i < profundidad; i++) {
            std::cout << "    ";
        }
        
        std::cout << nodo->valor << "[" << nodo->nivel << "]" << std::endl;
        
        imprimir(nodo->izquierdo, profundidad + 1);
    }
}

// Recorrido en preorden
void ArbolAA::recorridoPreorden() {
    std::cout << "Recorrido Preorden: ";
    preorden(raiz);
    std::cout << std::endl;
}

void ArbolAA::preorden(Nodo* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->valor << " ";
        preorden(nodo->izquierdo);
        preorden(nodo->derecho);
    }
}

// Recorrido en inorden
void ArbolAA::recorridoInorden() {
    std::cout << "Recorrido Inorden: ";
    inorden(raiz);
    std::cout << std::endl;
}

void ArbolAA::inorden(Nodo* nodo) {
    if (nodo != nullptr) {
        inorden(nodo->izquierdo);
        std::cout << nodo->valor << " ";
        inorden(nodo->derecho);
    }
}

// Recorrido en postorden
void ArbolAA::recorridoPostorden() {
    std::cout << "Recorrido Postorden: ";
    postorden(raiz);
    std::cout << std::endl;
}

void ArbolAA::postorden(Nodo* nodo) {
    if (nodo != nullptr) {
        postorden(nodo->izquierdo);
        postorden(nodo->derecho);
        std::cout << nodo->valor << " ";
    }
}