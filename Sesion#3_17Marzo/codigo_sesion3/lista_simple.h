#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <iostream>
#include <string>
using namespace std;

class nodoS {
public:
    nodoS(string v);
    nodoS(string v, nodoS* signodo);

private:
    string valor;
    nodoS* siguiente;
    friend class lista;
};

typedef nodoS* pnodoS;

class lista {
public:
    lista();
    ~lista();

    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos(string v, int pos);
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