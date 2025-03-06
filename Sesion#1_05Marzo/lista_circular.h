#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <iostream>
using namespace std;

class nodoC {
public:
    nodoC(int v);
    nodoC(int v, nodoC* signodo);

private:
    int valor;
    nodoC* siguiente;
    friend class listaC;
};

typedef nodoC* pnodoC;

class listaC {
public:
    listaC();
    ~listaC();

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
    pnodoC primero;
};

#endif // LISTA_CIRCULAR_H