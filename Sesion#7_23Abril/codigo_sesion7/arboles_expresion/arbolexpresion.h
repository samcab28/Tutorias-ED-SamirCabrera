#ifndef ARBOL_EXPRESION_H
#define ARBOL_EXPRESION_H

#include <iostream>
#include <string>

// Enumeración para identificar tipos de nodos
enum TipoNodo {
    OPERANDO,
    OPERADOR
};

// Clase para representar un nodo en el árbol de expresión
class Nodo {
private:
    TipoNodo tipo;
    double valor;     // Para nodos de tipo OPERANDO
    char operador;    // Para nodos de tipo OPERADOR
    Nodo* izquierdo;
    Nodo* derecho;

public:
    // Constructores
    Nodo(double val);  // Constructor para nodo operando
    Nodo(char op, Nodo* izq, Nodo* der);  // Constructor para nodo operador
    
    // Destructores y métodos relacionados
    ~Nodo();
    
    // Getters
    TipoNodo getTipo() const;
    double getValor() const;
    char getOperador() const;
    Nodo* getIzquierdo() const;
    Nodo* getDerecho() const;
    
    // Para permitir que ArbolExpresion acceda a los miembros privados
    friend class ArbolExpresion;
};

// Clase para representar el árbol de expresión completo
class ArbolExpresion {
private:
    Nodo* raiz;
    
    // Métodos privados auxiliares
    void liberarArbol(Nodo* nodo);
    void imprimirInorden(Nodo* nodo) const;
    void imprimirPosorden(Nodo* nodo) const;
    void imprimirPreorden(Nodo* nodo) const;
    double evaluar(Nodo* nodo) const;
    Nodo* construirDesdeExpresionPostfija(const std::string& expresion);
    Nodo* clonar(const Nodo* nodo) const;

public:
    // Constructores
    ArbolExpresion();
    ArbolExpresion(double valor);  // Crea un árbol con un solo nodo operando
    ArbolExpresion(char operador, ArbolExpresion& izq, ArbolExpresion& der);  // Crea un árbol con operador
    ArbolExpresion(const std::string& expresionPostfija);  // Construye desde notación postfija
    ArbolExpresion(const ArbolExpresion& otro);  // Constructor de copia
    
    // Destructor
    ~ArbolExpresion();
    
    // Operaciones
    double evaluar() const;  // Evalúa la expresión y retorna su valor
    void imprimir(const std::string& formato = "inorden") const;  // Imprime la expresión
    
    // Operador de asignación
    ArbolExpresion& operator=(const ArbolExpresion& otro);
};

#endif // ARBOL_EXPRESION_H