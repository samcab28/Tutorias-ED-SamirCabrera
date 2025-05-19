#include "lista_simple.h"
#include <stdexcept>

nodoS::nodoS(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
    siguiente = NULL;
}

nodoS::nodoS(string nombre, int edad, nodoS* signodo) {
    this->nombre = nombre;
    this->edad = edad;
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

void lista::InsertarInicio(string nombre, int edad) {
    if (ListaVacia()) {
        primero = new nodoS(nombre, edad);
    } else {
        pnodoS nuevo = new nodoS(nombre, edad, primero);
        primero = nuevo;
    }
}

void lista::InsertarFinal(string nombre, int edad) {
    if (ListaVacia()) {
        primero = new nodoS(nombre, edad);
    } else {
        pnodoS aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = new nodoS(nombre, edad);
    }
}

void lista::Mostrar() {
    pnodoS aux = primero;
    while (aux) {
        cout << aux->getNombre() << ";" << aux->getEdad() << " -> ";
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

void lista::InsertarPos(string nombre, int edad, int pos) {
    if (pos < 0) {
        cout << "Posición inválida" << endl;
        return;
    }

    if (pos == 0) {
        InsertarInicio(nombre, edad);
        return;
    }

    pnodoS aux = primero;
    int contador = 0;

    while (aux != NULL && contador < pos - 1) {
        aux = aux->siguiente;
        contador++;
    }

    if (aux != NULL) {
        pnodoS nuevo = new nodoS(nombre, edad, aux->siguiente);
        aux->siguiente = nuevo;
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