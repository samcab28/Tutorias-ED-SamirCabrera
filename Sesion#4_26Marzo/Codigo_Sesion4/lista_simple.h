#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <iostream>
#include <string>
using namespace std;

class nodoS {
public:
    nodoS(string nombre, int edad);
    nodoS(string nombre, int edad, nodoS* signodo);

    // Métodos getter
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    nodoS* getSiguiente() { return siguiente; }

private:
    string nombre;
    int edad;
    nodoS* siguiente;
    friend class lista;
};

typedef nodoS* pnodoS;

class lista {
public:
    lista();
    ~lista();

    void InsertarInicio(string nombre, int edad);
    void InsertarFinal(string nombre, int edad);
    void InsertarPos(string nombre, int edad, int pos);
    bool ListaVacia();
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

    // Método getter
    pnodoS getPrimero() { return primero; }

private:
    pnodoS primero;
};

#endif // LISTA_SIMPLE_H