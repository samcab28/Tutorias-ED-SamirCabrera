#ifndef SISTEMA_RESTAURANTE_H
#define SISTEMA_RESTAURANTE_H

#include <string>
#include <iostream>

const int TABLESIZE = 13;

struct Cliente {
    std::string cedula;
    std::string nombre;
    Cliente* siguiente;
    
    Cliente() : siguiente(nullptr) {}
};

class SistemaRestaurante {
private:
    Cliente* tablaHash[TABLESIZE];
    
    // Función privada para calcular el hash
    int calcularHash(std::string cedula);
    
public:
    // Constructor
    SistemaRestaurante();
    
    // Destructor para liberar memoria
    ~SistemaRestaurante();
    
    // Insertar un nuevo cliente
    bool insertarCliente(std::string cedula, std::string nombre);
    
    // Buscar un cliente por cédula
    void buscarCliente(std::string cedula);
    
    // Mostrar el estado actual de la tabla hash
    void mostrarTabla();
    
    // Eliminar un cliente por cédula
    bool eliminarCliente(std::string cedula);
    
    // Verificar si la tabla está vacía
    bool estaVacia() const;
    
    // Contar total de clientes en la tabla
    int contarClientes() const;
};

#endif // SISTEMA_RESTAURANTE_H