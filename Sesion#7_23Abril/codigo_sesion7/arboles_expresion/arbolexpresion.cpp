#include "arbolexpresion.h"
#include <stack>
#include <sstream>
#include <cmath>
#include <stdexcept>

// Implementación de Nodo
Nodo::Nodo(double val) : tipo(OPERANDO), valor(val), operador('\0'), izquierdo(nullptr), derecho(nullptr) {}

Nodo::Nodo(char op, Nodo* izq, Nodo* der) : tipo(OPERADOR), valor(0.0), operador(op), izquierdo(izq), derecho(der) {}

Nodo::~Nodo() {
    // El destructor no libera los nodos hijos,
    // esto se maneja en ArbolExpresion::liberarArbol
}

TipoNodo Nodo::getTipo() const {
    return tipo;
}

double Nodo::getValor() const {
    return valor;
}

char Nodo::getOperador() const {
    return operador;
}

Nodo* Nodo::getIzquierdo() const {
    return izquierdo;
}

Nodo* Nodo::getDerecho() const {
    return derecho;
}

// Implementación de ArbolExpresion
ArbolExpresion::ArbolExpresion() : raiz(nullptr) {}

ArbolExpresion::ArbolExpresion(double valor) : raiz(new Nodo(valor)) {}

ArbolExpresion::ArbolExpresion(char operador, ArbolExpresion& izq, ArbolExpresion& der) {
    // Clonamos los subárboles para evitar problemas de propiedad
    Nodo* izqClone = clonar(izq.raiz);
    Nodo* derClone = clonar(der.raiz);
    raiz = new Nodo(operador, izqClone, derClone);
}

ArbolExpresion::ArbolExpresion(const std::string& expresionPostfija) {
    raiz = construirDesdeExpresionPostfija(expresionPostfija);
}

ArbolExpresion::ArbolExpresion(const ArbolExpresion& otro) {
    raiz = clonar(otro.raiz);
}

ArbolExpresion::~ArbolExpresion() {
    liberarArbol(raiz);
}

void ArbolExpresion::liberarArbol(Nodo* nodo) {
    if (nodo) {
        liberarArbol(nodo->izquierdo);
        liberarArbol(nodo->derecho);
        delete nodo;
    }
}

Nodo* ArbolExpresion::clonar(const Nodo* nodo) const {
    if (!nodo) return nullptr;
    
    if (nodo->tipo == OPERANDO) {
        return new Nodo(nodo->valor);
    } else {
        Nodo* izqClone = clonar(nodo->izquierdo);
        Nodo* derClone = clonar(nodo->derecho);
        return new Nodo(nodo->operador, izqClone, derClone);
    }
}

Nodo* ArbolExpresion::construirDesdeExpresionPostfija(const std::string& expresion) {
    std::stack<Nodo*> pila;
    std::istringstream iss(expresion);
    std::string token;
    
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            // Es un operador
            if (pila.size() < 2) {
                throw std::runtime_error("Expresión postfija inválida: faltan operandos para el operador " + token);
            }
            
            Nodo* derecho = pila.top(); pila.pop();
            Nodo* izquierdo = pila.top(); pila.pop();
            
            Nodo* nodoOperador = new Nodo(token[0], izquierdo, derecho);
            pila.push(nodoOperador);
        } else {
            // Es un operando (número)
            try {
                double valor = std::stod(token);
                Nodo* nodoOperando = new Nodo(valor);
                pila.push(nodoOperando);
            } catch (const std::exception&) {
                throw std::runtime_error("Valor inválido en la expresión: " + token);
            }
        }
    }
    
    if (pila.size() != 1) {
        // Liberar memoria antes de lanzar la excepción
        while (!pila.empty()) {
            Nodo* nodo = pila.top();
            pila.pop();
            liberarArbol(nodo);
        }
        throw std::runtime_error("Expresión postfija inválida: sobran operandos");
    }
    
    return pila.top();
}

double ArbolExpresion::evaluar() const {
    return evaluar(raiz);
}

double ArbolExpresion::evaluar(Nodo* nodo) const {
    if (!nodo) {
        throw std::runtime_error("No se puede evaluar un árbol vacío");
    }
    
    if (nodo->tipo == OPERANDO) {
        return nodo->valor;
    }
    
    double valorIzquierdo = evaluar(nodo->izquierdo);
    double valorDerecho = evaluar(nodo->derecho);
    
    switch (nodo->operador) {
        case '+': return valorIzquierdo + valorDerecho;
        case '-': return valorIzquierdo - valorDerecho;
        case '*': return valorIzquierdo * valorDerecho;
        case '/': 
            if (valorDerecho == 0) {
                throw std::runtime_error("División por cero");
            }
            return valorIzquierdo / valorDerecho;
        case '^': return std::pow(valorIzquierdo, valorDerecho);
        default:
            throw std::runtime_error(std::string("Operador desconocido: ") + nodo->operador);
    }
}

void ArbolExpresion::imprimir(const std::string& formato) const {
    if (!raiz) {
        std::cout << "Árbol vacío" << std::endl;
        return;
    }
    
    if (formato == "inorden") {
        std::cout << "Inorden: ";
        imprimirInorden(raiz);
    } else if (formato == "posorden") {
        std::cout << "Posorden: ";
        imprimirPosorden(raiz);
    } else if (formato == "preorden") {
        std::cout << "Preorden: ";
        imprimirPreorden(raiz);
    } else {
        std::cout << "Formato desconocido. Utilizando inorden: ";
        imprimirInorden(raiz);
    }
    std::cout << std::endl;
}

void ArbolExpresion::imprimirInorden(Nodo* nodo) const {
    if (!nodo) return;
    
    if (nodo->tipo == OPERADOR) {
        std::cout << "(";
        imprimirInorden(nodo->izquierdo);
        std::cout << " " << nodo->operador << " ";
        imprimirInorden(nodo->derecho);
        std::cout << ")";
    } else {
        std::cout << nodo->valor;
    }
}

void ArbolExpresion::imprimirPosorden(Nodo* nodo) const {
    if (!nodo) return;
    
    imprimirPosorden(nodo->izquierdo);
    imprimirPosorden(nodo->derecho);
    
    if (nodo->tipo == OPERADOR) {
        std::cout << nodo->operador << " ";
    } else {
        std::cout << nodo->valor << " ";
    }
}

void ArbolExpresion::imprimirPreorden(Nodo* nodo) const {
    if (!nodo) return;
    
    if (nodo->tipo == OPERADOR) {
        std::cout << nodo->operador << " ";
    } else {
        std::cout << nodo->valor << " ";
    }
    
    imprimirPreorden(nodo->izquierdo);
    imprimirPreorden(nodo->derecho);
}

ArbolExpresion& ArbolExpresion::operator=(const ArbolExpresion& otro) {
    if (this != &otro) {
        liberarArbol(raiz);
        raiz = clonar(otro.raiz);
    }
    return *this;
}