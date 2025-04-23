#include "arbolexpresion.h"
#include <iostream>
#include <stdexcept>

void probarExpresionManual() {
    std::cout << "\n=== PRUEBA DE CONSTRUCCIÓN MANUAL DE EXPRESIÓN ===" << std::endl;
    std::cout << "Construyendo: (3 + 4) * 5" << std::endl;
    
    // Construimos los nodos hoja (operandos)
    ArbolExpresion tres(3.0);
    ArbolExpresion cuatro(4.0);
    ArbolExpresion cinco(5.0);
    
    // Construimos la expresión (3 + 4)
    ArbolExpresion suma('+', tres, cuatro);
    
    // Construimos la expresión final (3 + 4) * 5
    ArbolExpresion multiplicacion('*', suma, cinco);
    
    // Imprimimos la expresión en diferentes formatos
    multiplicacion.imprimir("inorden");
    multiplicacion.imprimir("preorden");
    multiplicacion.imprimir("posorden");
    
    // Evaluamos la expresión
    std::cout << "Resultado: " << multiplicacion.evaluar() << std::endl;
}

void probarExpresionPostfija() {
    std::cout << "\n=== PRUEBA DE CONSTRUCCIÓN DESDE NOTACIÓN POSTFIJA ===" << std::endl;
    
    try {
        // Expresión: (10 - 5) * ((7 + 3) / 2) en notación postfija: 10 5 - 7 3 + 2 / *
        std::cout << "Construyendo expresión: (10 - 5) * ((7 + 3) / 2)" << std::endl;
        std::cout << "Notación postfija: 10 5 - 7 3 + 2 / *" << std::endl;
        
        ArbolExpresion arbol("10 5 - 7 3 + 2 / *");
        
        // Imprimimos en diferentes formatos
        arbol.imprimir("inorden");
        arbol.imprimir("preorden");
        arbol.imprimir("posorden");
        
        // Evaluamos la expresión
        std::cout << "Resultado: " << arbol.evaluar() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void probarOperacionesComplejas() {
    std::cout << "\n=== PRUEBA DE OPERACIONES COMPLEJAS ===" << std::endl;
    
    try {
        // Expresión: 3^2 + (15 / (7 - 4)) - 2 * 3
        // Notación postfija: 3 2 ^ 15 7 4 - / + 2 3 * -
        std::cout << "Construyendo expresión: 3^2 + (15 / (7 - 4)) - 2 * 3" << std::endl;
        std::cout << "Notación postfija: 3 2 ^ 15 7 4 - / + 2 3 * -" << std::endl;
        
        ArbolExpresion arbol("3 2 ^ 15 7 4 - / + 2 3 * -");
        
        // Imprimimos en diferentes formatos
        arbol.imprimir("inorden");
        arbol.imprimir("preorden");
        arbol.imprimir("posorden");
        
        // Evaluamos la expresión
        std::cout << "Resultado: " << arbol.evaluar() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void probarErrores() {
    std::cout << "\n=== PRUEBA DE MANEJO DE ERRORES ===" << std::endl;
    
    // Probamos una expresión postfija inválida (faltan operandos)
    try {
        std::cout << "Probando expresión postfija inválida: 5 + 3" << std::endl;
        ArbolExpresion arbol("5 +");
        arbol.imprimir();
    } catch (const std::exception& e) {
        std::cout << "Error capturado correctamente: " << e.what() << std::endl;
    }
    
    // Probamos división por cero
    try {
        std::cout << "Probando división por cero: 5 0 /" << std::endl;
        ArbolExpresion arbol("5 0 /");
        std::cout << "Resultado: " << arbol.evaluar() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error capturado correctamente: " << e.what() << std::endl;
    }
}

void probarCopiasYAsignaciones() {
    std::cout << "\n=== PRUEBA DE COPIAS Y ASIGNACIONES ===" << std::endl;
    
    // Creamos un árbol
    ArbolExpresion original("5 3 +");
    std::cout << "Árbol original: ";
    original.imprimir();
    std::cout << "Evaluación original: " << original.evaluar() << std::endl;
    
    // Probamos el constructor de copia
    ArbolExpresion copia(original);
    std::cout << "Copia del árbol: ";
    copia.imprimir();
    std::cout << "Evaluación de la copia: " << copia.evaluar() << std::endl;
    
    // Probamos el operador de asignación
    ArbolExpresion asignado;
    asignado = original;
    std::cout << "Árbol asignado: ";
    asignado.imprimir();
    std::cout << "Evaluación del asignado: " << asignado.evaluar() << std::endl;
}

int main() {
    std::cout << "===== PRUEBA DE ÁRBOL DE EXPRESIÓN =====" << std::endl;
    
    probarExpresionManual();
    probarExpresionPostfija();
    probarOperacionesComplejas();
    probarErrores();
    probarCopiasYAsignaciones();
    
    return 0;
}