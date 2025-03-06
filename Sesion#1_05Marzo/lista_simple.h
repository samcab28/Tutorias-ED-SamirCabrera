#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <iostream>
using namespace std;

class nodoS {
public:
    nodoS(int v);
    nodoS(int v, nodoS* signodo);

private:
    int valor;
    nodoS* siguiente;
    friend class lista;
};

typedef nodoS* pnodoS;

class lista {
public:
    lista();
    ~lista();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos(int v, int pos);
    bool ListaVacia();
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

private:
    pnodoS primero;
};

#endif // LISTA_SIMPLE_H