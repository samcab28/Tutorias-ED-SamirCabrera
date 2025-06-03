#include "listaSimple.h"

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
    }
    else {
        pnodoS nuevo = new nodoS(v, primero);
        primero = nuevo;
    }
}

void lista::InsertarFinal(int v) {
    if (ListaVacia()) {
        primero = new nodoS(v);
    }
    else {
        pnodoS aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = new nodoS(v);
    }
}

void lista::InsertarPos(int v, int pos) {
    if (pos <= 0) {
        InsertarInicio(v);
        return;
    }

    if (ListaVacia() || pos >= largoLista()) {
        InsertarFinal(v);
        return;
    }

    pnodoS aux = primero;
    for (int i = 0; i < pos - 1; i++) {
        aux = aux->siguiente;
    }

    pnodoS nuevo = new nodoS(v, aux->siguiente);
    aux->siguiente = nuevo;
}

void lista::BorrarInicio() {
    if (!ListaVacia()) {
        pnodoS aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

void lista::BorrarFinal() {
    if (ListaVacia()) {
        return;
    }

    if (primero->siguiente == NULL) {
        delete primero;
        primero = NULL;
        return;
    }

    pnodoS aux = primero;
    while (aux->siguiente->siguiente != NULL) {
        aux = aux->siguiente;
    }
    delete aux->siguiente;
    aux->siguiente = NULL;
}

void lista::borrarPosicion(int pos) {
    if (ListaVacia() || pos < 0) {
        return;
    }

    if (pos == 0) {
        BorrarInicio();
        return;
    }

    pnodoS aux = primero;
    for (int i = 0; i < pos - 1 && aux->siguiente != NULL; i++) {
        aux = aux->siguiente;
    }

    if (aux->siguiente == NULL) {
        return;
    }

    pnodoS aBorrar = aux->siguiente;
    aux->siguiente = aBorrar->siguiente;
    delete aBorrar;
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

void lista::Mostrar() {
    pnodoS aux = primero;
    while (aux) {
        std::cout << aux->valor << " -> ";
        aux = aux->siguiente;
    }
    std::cout << "NULL" << std::endl;
}

std::string lista::MostrarComoString() {
    std::string resultado;
    pnodoS aux = primero;
    while (aux) {
        resultado += std::to_string(aux->valor) + " -> ";
        aux = aux->siguiente;
    }
    resultado += "NULL";
    return resultado;
}