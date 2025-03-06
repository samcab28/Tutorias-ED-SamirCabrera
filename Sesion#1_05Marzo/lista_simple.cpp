#include "lista_simple.h"

nodoS::nodoS(int v) {
    valor = v;
    siguiente = NULL;
}

nodoS::nodoS(int v, nodoS* signodo) {
    valor = v;
    siguiente = signodo;
}

lista::lista() {
    primero = NULL;
}

lista::~lista() {
    pnodoS aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

bool lista::ListaVacia() {
    return primero == NULL;
}

void lista::InsertarInicio(int v) {
    if (ListaVacia()) {
        primero = new nodoS(v);
    } else {
        pnodoS nuevo = new nodoS(v, primero);
        primero = nuevo;
    }
}

void lista::InsertarFinal(int v) {
    if (ListaVacia()) {
        primero = new nodoS(v);
    } else {
        pnodoS aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = new nodoS(v);
    }
}

void lista::Mostrar() {
    pnodoS aux = primero;
    while (aux) {
        cout << aux->valor << " -> ";
        aux = aux->siguiente;
    }
    cout << "NULL" << endl;
}