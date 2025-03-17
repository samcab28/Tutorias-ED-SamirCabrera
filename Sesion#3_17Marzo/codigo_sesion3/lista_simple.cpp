#include "lista_simple.h"

nodoS::nodoS(string v) {
    valor = v;
    siguiente = NULL;
}

nodoS::nodoS(string v, nodoS* signodo) {
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

void lista::InsertarInicio(string v) {
    if (ListaVacia()) {
        primero = new nodoS(v);
    } else {
        pnodoS nuevo = new nodoS(v, primero);
        primero = nuevo;
    }
}

void lista::InsertarFinal(string v) {
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

void lista::BorrarInicio() {
    if (ListaVacia()) {
        cout << "No hay elementos para borrar" << endl;
    } else {
        pnodoS aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

void lista::BorrarFinal() {
    if (ListaVacia()) {
        cout << "No hay elementos para borrar" << endl;
    } else if (primero->siguiente == NULL) {
        delete primero;
        primero = NULL;
    } else {
        pnodoS aux = primero;
        while (aux->siguiente->siguiente != NULL) {
            aux = aux->siguiente;
        }
        pnodoS temp = aux->siguiente;
        aux->siguiente = NULL;
        delete temp;
    }
}

void lista::borrarPosicion(int pos) {
    if (ListaVacia()) {
        cout << "Lista vacía" << endl;
        return;
    }

    if (pos < 0) {
        cout << "Posición inválida" << endl;
        return;
    }

    if (pos == 0) {
        BorrarInicio();
        return;
    }

    pnodoS aux = primero;
    int contador = 0;

    while (aux->siguiente && contador < pos - 1) {
        aux = aux->siguiente;
        contador++;
    }

    if (aux->siguiente) {
        pnodoS temp = aux->siguiente;
        aux->siguiente = aux->siguiente->siguiente;
        delete temp;
    } else {
        cout << "Posición fuera de rango" << endl;
    }
}

int lista::largoLista() {
    int contador = 0;
    pnodoS aux = primero;

    while (aux != NULL) {
        contador++;
        aux = aux->siguiente;
    }

    return contador;
}

void lista::InsertarPos(string v, int pos) {
    if (pos < 0) {
        cout << "Posición inválida" << endl;
        return;
    }

    if (pos == 0) {
        InsertarInicio(v);
        return;
    }

    pnodoS aux = primero;
    int contador = 0;

    while (aux != NULL && contador < pos - 1) {
        aux = aux->siguiente;
        contador++;
    }

    if (aux != NULL) {
        pnodoS nuevo = new nodoS(v, aux->siguiente);
        aux->siguiente = nuevo;
    } else {
        cout << "Posición fuera de rango" << endl;
    }
}