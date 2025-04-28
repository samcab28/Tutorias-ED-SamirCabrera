#include "arbol_rojinegro.h"
#include <iostream>
#include <iomanip>

// Constructor del nodo
Nodo::Nodo(int val) : valor(val), color(ROJO), izquierda(nullptr), derecha(nullptr), padre(nullptr) {}

// Constructor del árbol
ArbolRojiNegro::ArbolRojiNegro() {
    nil = new Nodo(0);
    nil->color = NEGRO;
    nil->izquierda = nullptr;
    nil->derecha = nullptr;
    raiz = nil;
}

// Destructor del árbol
ArbolRojiNegro::~ArbolRojiNegro() {
    liberarMemoria(raiz);
    delete nil;
}

// Método para liberar memoria recursivamente
void ArbolRojiNegro::liberarMemoria(Nodo* nodo) {
    if (nodo != nil) {
        liberarMemoria(nodo->izquierda);
        liberarMemoria(nodo->derecha);
        delete nodo;
    }
}

// Rotación a la izquierda
void ArbolRojiNegro::rotacionIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    x->derecha = y->izquierda;
    
    if (y->izquierda != nil) {
        y->izquierda->padre = x;
    }
    
    y->padre = x->padre;
    
    if (x->padre == nullptr) {
        raiz = y;
    } else if (x == x->padre->izquierda) {
        x->padre->izquierda = y;
    } else {
        x->padre->derecha = y;
    }
    
    y->izquierda = x;
    x->padre = y;
}

// Rotación a la derecha
void ArbolRojiNegro::rotacionDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    y->izquierda = x->derecha;
    
    if (x->derecha != nil) {
        x->derecha->padre = y;
    }
    
    x->padre = y->padre;
    
    if (y->padre == nullptr) {
        raiz = x;
    } else if (y == y->padre->izquierda) {
        y->padre->izquierda = x;
    } else {
        y->padre->derecha = x;
    }
    
    x->derecha = y;
    y->padre = x;
}

// Método para arreglar el árbol después de inserción
void ArbolRojiNegro::arreglarInsercion(Nodo* k) {
    Nodo* u;
    while (k->padre != nullptr && k->padre->color == ROJO) {
        if (k->padre == k->padre->padre->derecha) {
            u = k->padre->padre->izquierda;
            if (u != nil && u->color == ROJO) {
                // Caso 1: El tío de k es rojo
                k->padre->color = NEGRO;
                u->color = NEGRO;
                k->padre->padre->color = ROJO;
                k = k->padre->padre;
            } else {
                if (k == k->padre->izquierda) {
                    // Caso 2: k es hijo izquierdo y su padre es hijo derecho
                    k = k->padre;
                    rotacionDerecha(k);
                }
                // Caso 3: k es hijo derecho y su padre es hijo derecho
                k->padre->color = NEGRO;
                k->padre->padre->color = ROJO;
                rotacionIzquierda(k->padre->padre);
            }
        } else {
            u = k->padre->padre->derecha;
            if (u != nil && u->color == ROJO) {
                // Caso 1: El tío de k es rojo
                k->padre->color = NEGRO;
                u->color = NEGRO;
                k->padre->padre->color = ROJO;
                k = k->padre->padre;
            } else {
                if (k == k->padre->derecha) {
                    // Caso 2: k es hijo derecho y su padre es hijo izquierdo
                    k = k->padre;
                    rotacionIzquierda(k);
                }
                // Caso 3: k es hijo izquierdo y su padre es hijo izquierdo
                k->padre->color = NEGRO;
                k->padre->padre->color = ROJO;
                rotacionDerecha(k->padre->padre);
            }
        }
        if (k == raiz) {
            break;
        }
    }
    raiz->color = NEGRO;
}

// Método para insertar un valor en el árbol
void ArbolRojiNegro::insertar(int valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->izquierda = nil;
    nuevo->derecha = nil;
    
    Nodo* y = nullptr;
    Nodo* x = raiz;
    
    while (x != nil) {
        y = x;
        if (nuevo->valor < x->valor) {
            x = x->izquierda;
        } else {
            x = x->derecha;
        }
    }
    
    nuevo->padre = y;
    if (y == nullptr) {
        raiz = nuevo;
    } else if (nuevo->valor < y->valor) {
        y->izquierda = nuevo;
    } else {
        y->derecha = nuevo;
    }
    
    if (nuevo->padre == nullptr) {
        nuevo->color = NEGRO;
        return;
    }
    
    if (nuevo->padre->padre == nullptr) {
        return;
    }
    
    arreglarInsercion(nuevo);
}

// Método para trasplantar un subarbol
void ArbolRojiNegro::transplante(Nodo* u, Nodo* v) {
    if (u->padre == nullptr) {
        raiz = v;
    } else if (u == u->padre->izquierda) {
        u->padre->izquierda = v;
    } else {
        u->padre->derecha = v;
    }
    v->padre = u->padre;
}

// Encontrar el valor mínimo en un subárbol
Nodo* ArbolRojiNegro::minimo(Nodo* nodo) {
    while (nodo->izquierda != nil) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Método para arreglar el árbol después de eliminar un nodo
void ArbolRojiNegro::arreglarEliminacion(Nodo* x) {
    Nodo* w;
    while (x != raiz && x->color == NEGRO) {
        if (x == x->padre->izquierda) {
            w = x->padre->derecha;
            if (w->color == ROJO) {
                // Caso 1: El hermano w es rojo
                w->color = NEGRO;
                x->padre->color = ROJO;
                rotacionIzquierda(x->padre);
                w = x->padre->derecha;
            }
            if (w->izquierda->color == NEGRO && w->derecha->color == NEGRO) {
                // Caso 2: Ambos hijos de w son negros
                w->color = ROJO;
                x = x->padre;
            } else {
                if (w->derecha->color == NEGRO) {
                    // Caso 3: Hijo derecho de w es negro
                    w->izquierda->color = NEGRO;
                    w->color = ROJO;
                    rotacionDerecha(w);
                    w = x->padre->derecha;
                }
                // Caso 4: Hijo derecho de w es rojo
                w->color = x->padre->color;
                x->padre->color = NEGRO;
                w->derecha->color = NEGRO;
                rotacionIzquierda(x->padre);
                x = raiz;
            }
        } else {
            w = x->padre->izquierda;
            if (w->color == ROJO) {
                // Caso 1: El hermano w es rojo
                w->color = NEGRO;
                x->padre->color = ROJO;
                rotacionDerecha(x->padre);
                w = x->padre->izquierda;
            }
            if (w->derecha->color == NEGRO && w->izquierda->color == NEGRO) {
                // Caso 2: Ambos hijos de w son negros
                w->color = ROJO;
                x = x->padre;
            } else {
                if (w->izquierda->color == NEGRO) {
                    // Caso 3: Hijo izquierdo de w es negro
                    w->derecha->color = NEGRO;
                    w->color = ROJO;
                    rotacionIzquierda(w);
                    w = x->padre->izquierda;
                }
                // Caso 4: Hijo izquierdo de w es rojo
                w->color = x->padre->color;
                x->padre->color = NEGRO;
                w->izquierda->color = NEGRO;
                rotacionDerecha(x->padre);
                x = raiz;
            }
        }
    }
    x->color = NEGRO;
}

// Método para eliminar un valor del árbol
void ArbolRojiNegro::eliminar(int valor) {
    Nodo* z = raiz;
    while (z != nil) {
        if (valor < z->valor) {
            z = z->izquierda;
        } else if (valor > z->valor) {
            z = z->derecha;
        } else {
            break;
        }
    }
    
    if (z == nil) {
        std::cout << "El valor " << valor << " no existe en el árbol." << std::endl;
        return;
    }
    
    Nodo* y = z;
    Nodo* x;
    Color y_original_color = y->color;
    
    if (z->izquierda == nil) {
        x = z->derecha;
        transplante(z, z->derecha);
    } else if (z->derecha == nil) {
        x = z->izquierda;
        transplante(z, z->izquierda);
    } else {
        y = minimo(z->derecha);
        y_original_color = y->color;
        x = y->derecha;
        
        if (y->padre == z) {
            x->padre = y;
        } else {
            transplante(y, y->derecha);
            y->derecha = z->derecha;
            y->derecha->padre = y;
        }
        
        transplante(z, y);
        y->izquierda = z->izquierda;
        y->izquierda->padre = y;
        y->color = z->color;
    }
    
    delete z;
    
    if (y_original_color == NEGRO) {
        arreglarEliminacion(x);
    }
}

// Método para buscar un valor en el árbol
bool ArbolRojiNegro::buscar(int valor) {
    Nodo* actual = raiz;
    while (actual != nil) {
        if (valor == actual->valor) {
            return true;
        } else if (valor < actual->valor) {
            actual = actual->izquierda;
        } else {
            actual = actual->derecha;
        }
    }
    return false;
}

// Método auxiliar para el recorrido inorden
void ArbolRojiNegro::inordenRecursivo(Nodo* nodo) {
    if (nodo != nil) {
        inordenRecursivo(nodo->izquierda);
        std::cout << nodo->valor << "(" << (nodo->color == ROJO ? "R" : "N") << ") ";
        inordenRecursivo(nodo->derecha);
    }
}

// Método para realizar un recorrido inorden
void ArbolRojiNegro::inorden() {
    if (raiz == nil) {
        std::cout << "Árbol vacío" << std::endl;
        return;
    }
    inordenRecursivo(raiz);
    std::cout << std::endl;
}

// Método para imprimir la estructura del árbol
void ArbolRojiNegro::imprimirArbolRecursivo(Nodo* nodo, int nivel, int indentacion) {
    if (nodo == nil) {
        return;
    }
    
    indentacion += nivel;
    
    imprimirArbolRecursivo(nodo->derecha, nivel, indentacion);
    
    std::cout << std::endl;
    for (int i = nivel; i < indentacion; i++) {
        std::cout << " ";
    }
    std::string color = (nodo->color == ROJO) ? "R" : "N";
    std::cout << nodo->valor << "(" << color << ")" << std::endl;
    
    imprimirArbolRecursivo(nodo->izquierda, nivel, indentacion);
}

// Método para imprimir la estructura del árbol
void ArbolRojiNegro::imprimirArbol() {
    if (raiz == nil) {
        std::cout << "Árbol vacío" << std::endl;
        return;
    }
    imprimirArbolRecursivo(raiz, 10, 0);
}

// Método para verificar si el árbol está vacío
bool ArbolRojiNegro::estaVacio() {
    return raiz == nil;
}