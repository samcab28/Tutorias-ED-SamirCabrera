#include "sistema_restaurante.h"
#include <iostream>
#include <string>

// Constructor
SistemaRestaurante::SistemaRestaurante() {
    for(int i = 0; i < TABLESIZE; i++) {
        tablaHash[i] = nullptr;
    }
}

// Destructor
SistemaRestaurante::~SistemaRestaurante() {
    for(int i = 0; i < TABLESIZE; i++) {
        Cliente* actual = tablaHash[i];
        while(actual != nullptr) {
            Cliente* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
}

// Calcular hash
int SistemaRestaurante::calcularHash(std::string cedula) {
    return std::stoi(cedula) % TABLESIZE;
}

// Insertar cliente
bool SistemaRestaurante::insertarCliente(std::string cedula, std::string nombre) {
    int index = calcularHash(cedula);
    Cliente* actual = tablaHash[index];
    
    // Verificar si ya existe
    while(actual != nullptr) {
        if(actual->cedula == cedula) {
            std::cout << "Error: Cliente con cédula " << cedula << " ya existe.\n";
            return false;
        }
        actual = actual->siguiente;
    }
    
    // Insertar al inicio de la lista
    Cliente* nuevo = new Cliente();
    nuevo->cedula = cedula;
    nuevo->nombre = nombre;
    nuevo->siguiente = tablaHash[index];
    tablaHash[index] = nuevo;
    
    std::cout << "Cliente " << nombre << " (" << cedula << ") insertado en posición " << index << std::endl;
    return true;
}

// Buscar cliente
void SistemaRestaurante::buscarCliente(std::string cedula) {
    int index = calcularHash(cedula);
    Cliente* actual = tablaHash[index];
    
    while(actual != nullptr) {
        if(actual->cedula == cedula) {
            std::cout << "Cliente encontrado: " << actual->nombre 
                     << " (Cédula: " << actual->cedula 
                     << ", Hash: " << index << ")\n";
            return;
        }
        actual = actual->siguiente;
    }
    
    std::cout << "Cliente con cédula " << cedula << " no encontrado.\n";
}

// Mostrar tabla
void SistemaRestaurante::mostrarTabla() {
    std::cout << "\n--- Estado Actual de la Tabla Hash ---\n";
    for(int i = 0; i < TABLESIZE; i++) {
        std::cout << "[" << i << "]: ";
        Cliente* actual = tablaHash[i];
        while(actual != nullptr) {
            std::cout << actual->cedula << "->";
            actual = actual->siguiente;
        }
        std::cout << "NULL\n";
    }
    std::cout << "-------------------------------------\n";
}

// Eliminar cliente
bool SistemaRestaurante::eliminarCliente(std::string cedula) {
    int index = calcularHash(cedula);
    Cliente* actual = tablaHash[index];
    Cliente* anterior = nullptr;
    
    while(actual != nullptr) {
        if(actual->cedula == cedula) {
            // Si es el primer nodo
            if(anterior == nullptr) {
                tablaHash[index] = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            
            delete actual;
            std::cout << "Cliente con cédula " << cedula << " eliminado.\n";
            return true;
        }
        
        anterior = actual;
        actual = actual->siguiente;
    }
    
    std::cout << "Cliente con cédula " << cedula << " no encontrado.\n";
    return false;
}

// Verificar si está vacía
bool SistemaRestaurante::estaVacia() const {
    for(int i = 0; i < TABLESIZE; i++) {
        if(tablaHash[i] != nullptr) {
            return false;
        }
    }
    return true;
}

// Contar clientes
int SistemaRestaurante::contarClientes() const {
    int total = 0;
    for(int i = 0; i < TABLESIZE; i++) {
        Cliente* actual = tablaHash[i];
        while(actual != nullptr) {
            total++;
            actual = actual->siguiente;
        }
    }
    return total;
}