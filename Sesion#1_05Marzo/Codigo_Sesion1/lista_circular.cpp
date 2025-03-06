#include "lista_circular.h"

nodoC::nodoC(int v) {
    valor = v;
    siguiente = NULL;
}

nodoC::nodoC(int v, nodoC* signodo) {
    valor = v;
    siguiente = signodo;
}

listaC::listaC() {
    primero = NULL;
}

listaC::~listaC() {
    pnodoC aux = primero;
    while (aux) {
        pnodoC aux1 = primero;
        pnodoC tempo = primero;
        while (aux1->siguiente != primero)
            aux1 = aux1->siguiente;
        primero = primero->siguiente;
        aux1->siguiente = primero;
        delete tempo;
        aux = primero;
    }
    cout << "Se borró todo" << endl;
}

bool listaC::ListaVacia() {
    return primero == NULL;
}

void listaC::InsertarInicio(int v) {
    if (ListaVacia()) {
        pnodoC nuevo = new nodoC(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    } else {
        pnodoC nuevo = new nodoC(v);
        pnodoC aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;
        primero = nuevo;
    }
}

void listaC::InsertarFinal(int v) {
    if (ListaVacia()) {
        pnodoC nuevo = new nodoC(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    } else {
        pnodoC nuevo = new nodoC(v);
        pnodoC aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;
    }
}

void listaC::Mostrar() {
    pnodoC aux = primero;
    if (ListaVacia()) {
        cout << "Lista vacía" << endl;
        return;
    }
    do {
        cout << aux->valor << " -> ";
        aux = aux->siguiente;
    } while (aux != primero);
    cout << endl;
}