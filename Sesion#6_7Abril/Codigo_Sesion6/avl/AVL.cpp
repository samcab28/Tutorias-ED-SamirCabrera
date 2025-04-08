#include "AVL.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

// Implementación de la clase NodoAVL
NodoAVL::NodoAVL(int val) : valor(val), altura(1), izquierda(nullptr), derecha(nullptr) {}

// Constructor
ArbolAVL::ArbolAVL() : raiz(nullptr) {}

// Destructor
ArbolAVL::~ArbolAVL() {
    destruir(raiz);
}

// Destruir el árbol
void ArbolAVL::destruir(pNodoAVL nodo) {
    if (nodo) {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}

// Verificar si el árbol está vacío
bool ArbolAVL::estaVacio() {
    return raiz == nullptr;
}

// Obtener altura del nodo
int ArbolAVL::obtenerAltura(pNodoAVL nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura;
}

// Calcular factor de balance de un nodo
int ArbolAVL::factorBalance(pNodoAVL nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

// Rotación a la derecha
pNodoAVL ArbolAVL::rotacionDerecha(pNodoAVL y) {
    pNodoAVL x = y->izquierda;
    pNodoAVL T2 = x->derecha;
    
    // Realizar rotación
    x->derecha = y;
    y->izquierda = T2;
    
    // Actualizar alturas
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    
    cout << "Rotación Derecha en nodo " << y->valor << endl;
    
    // Devolver nueva raíz
    return x;
}

// Rotación a la izquierda
pNodoAVL ArbolAVL::rotacionIzquierda(pNodoAVL x) {
    pNodoAVL y = x->derecha;
    pNodoAVL T2 = y->izquierda;
    
    // Realizar rotación
    y->izquierda = x;
    x->derecha = T2;
    
    // Actualizar alturas
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    
    cout << "Rotación Izquierda en nodo " << x->valor << endl;
    
    // Devolver nueva raíz
    return y;
}

// Insertar un valor en el árbol
void ArbolAVL::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

// Método auxiliar para insertar un valor
pNodoAVL ArbolAVL::insertar(pNodoAVL nodo, int valor) {
    // Realizar inserción BST normal
    if (nodo == nullptr) {
        return new NodoAVL(valor);
    }
    
    if (valor < nodo->valor) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->valor) {
        nodo->derecha = insertar(nodo->derecha, valor);
    } else {
        // Valor duplicado, no se permite
        return nodo;
    }
    
    // Actualizar altura del nodo actual
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
    
    // Obtener factor de balance para ver si el nodo quedó desbalanceado
    int balance = factorBalance(nodo);
    
    // Casos de desbalance
    
    // Caso Izquierda-Izquierda
    if (balance > 1 && valor < nodo->izquierda->valor) {
        return rotacionDerecha(nodo);
    }
    
    // Caso Derecha-Derecha
    if (balance < -1 && valor > nodo->derecha->valor) {
        return rotacionIzquierda(nodo);
    }
    
    // Caso Izquierda-Derecha
    if (balance > 1 && valor > nodo->izquierda->valor) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }
    
    // Caso Derecha-Izquierda
    if (balance < -1 && valor < nodo->derecha->valor) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }
    
    // Nodo balanceado, retornar sin cambios
    return nodo;
}

// Buscar un valor en el árbol
bool ArbolAVL::buscar(int valor) {
    return buscarNodo(raiz, valor) != nullptr;
}

// Método auxiliar para buscar un nodo
pNodoAVL ArbolAVL::buscarNodo(pNodoAVL nodo, int valor) {
    if (nodo == nullptr || nodo->valor == valor) {
        return nodo;
    }
    
    if (valor < nodo->valor) {
        return buscarNodo(nodo->izquierda, valor);
    } else {
        return buscarNodo(nodo->derecha, valor);
    }
}

// Encontrar el nodo con valor mínimo
pNodoAVL ArbolAVL::encontrarMinimo(pNodoAVL nodo) {
    pNodoAVL actual = nodo;
    
    while (actual && actual->izquierda != nullptr) {
        actual = actual->izquierda;
    }
    
    return actual;
}

// Eliminar un valor del árbol
void ArbolAVL::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}

// Método auxiliar para eliminar un valor
pNodoAVL ArbolAVL::eliminar(pNodoAVL nodo, int valor) {
    // Realizar eliminación BST estándar
    if (nodo == nullptr) {
        return nullptr;
    }
    
    if (valor < nodo->valor) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    } else if (valor > nodo->valor) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    } else {
        // Nodo con el valor a eliminar encontrado
        
        // Caso 1: Nodo sin hijos o con un solo hijo
        if ((nodo->izquierda == nullptr) || (nodo->derecha == nullptr)) {
            pNodoAVL temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
            
            // Sin hijos
            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else {
                // Un hijo
                *nodo = *temp; // Copiar contenido del hijo
            }
            
            delete temp;
        } else {
            // Caso 2: Nodo con dos hijos
            pNodoAVL temp = encontrarMinimo(nodo->derecha);
            
            // Copiar valor del sucesor
            nodo->valor = temp->valor;
            
            // Eliminar el sucesor
            nodo->derecha = eliminar(nodo->derecha, temp->valor);
        }
    }
    
    // Si el árbol tenía solo un nodo
    if (nodo == nullptr) {
        return nodo;
    }
    
    // Actualizar altura
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
    
    // Obtener factor de balance
    int balance = factorBalance(nodo);
    
    // Casos de desbalance
    
    // Caso Izquierda-Izquierda
    if (balance > 1 && factorBalance(nodo->izquierda) >= 0) {
        return rotacionDerecha(nodo);
    }
    
    // Caso Izquierda-Derecha
    if (balance > 1 && factorBalance(nodo->izquierda) < 0) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }
    
    // Caso Derecha-Derecha
    if (balance < -1 && factorBalance(nodo->derecha) <= 0) {
        return rotacionIzquierda(nodo);
    }
    
    // Caso Derecha-Izquierda
    if (balance < -1 && factorBalance(nodo->derecha) > 0) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }
    
    return nodo;
}

// Mostrar el árbol en orden (inorden)
void ArbolAVL::mostrarInOrden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "Recorrido InOrden: ";
    inOrden(raiz);
    cout << endl;
}

// Método auxiliar para recorrido inorden
void ArbolAVL::inOrden(pNodoAVL nodo) {
    if (nodo) {
        inOrden(nodo->izquierda);
        cout << nodo->valor << " ";
        inOrden(nodo->derecha);
    }
}

// Mostrar el árbol en preorden
void ArbolAVL::mostrarPreOrden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "Recorrido PreOrden: ";
    preOrden(raiz);
    cout << endl;
}

// Método auxiliar para recorrido preorden
void ArbolAVL::preOrden(pNodoAVL nodo) {
    if (nodo) {
        cout << nodo->valor << " ";
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

// Mostrar el árbol en postorden
void ArbolAVL::mostrarPostOrden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "Recorrido PostOrden: ";
    postOrden(raiz);
    cout << endl;
}

// Método auxiliar para recorrido postorden
void ArbolAVL::postOrden(pNodoAVL nodo) {
    if (nodo) {
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        cout << nodo->valor << " ";
    }
}

// Visualización básica del árbol
void ArbolAVL::visualizarArbol() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    int h = obtenerAltura(raiz);
    int espacio = 4;
    
    cout << "Visualización del árbol AVL:" << endl;
    cout << "----------------------------" << endl;
    
    for (int i = 1; i <= h; i++) {
        imprimirNivel(raiz, i, (1 << (h - i)) * espacio);
        cout << endl;
    }
}

// Imprimir un nivel específico del árbol
void ArbolAVL::imprimirNivel(pNodoAVL nodo, int nivel, int espacio) {
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

// Visualización detallada del árbol
void ArbolAVL::visualizarArbolDetallado() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\nVisualización Detallada del Árbol AVL" << endl;
    cout << "====================================" << endl;
    
    queue<pair<pNodoAVL, string>> cola;
    cola.push({raiz, "Raíz"});
    
    while (!cola.empty()) {
        int nivelSize = cola.size();
        
        for (int i = 0; i < nivelSize; i++) {
            pNodoAVL nodo = cola.front().first;
            string posicion = cola.front().second;
            cola.pop();
            
            cout << posicion << ": " << nodo->valor << " (FB=" << factorBalance(nodo) << ")";
            
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