#include "cola.h"

nodoC::nodoC(string _documento) {
    documento = _documento;
    siguiente = NULL;
}

nodoC::nodoC(string _documento, nodoC* signodo) {
    documento = _documento;
    siguiente = signodo;
}

ImpresoraQueue::ImpresoraQueue() {
    primero = NULL;
    ultimo = NULL;
}

ImpresoraQueue::~ImpresoraQueue() {
    pnodoC aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
    ultimo = NULL;
}

bool ImpresoraQueue::ColaVacia() {
    return primero == NULL;
}

void ImpresoraQueue::AgregarDocumento(string documento) {
    pnodoC nuevo = new nodoC(documento);
    
    if (ColaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
        cout << "\n📄 [COLA] Nuevo documento añadido a la cola: \"" << documento << "\"" << endl;
        cout << "    📊 Estado: 1 documento en cola" << endl;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
        cout << "\n📄 [COLA] Nuevo documento añadido a la cola: \"" << documento << "\"" << endl;
        cout << "    📊 Estado: " << TamanioCola() << " documentos en cola" << endl;
    }
}

void ImpresoraQueue::MostrarCola() {
    if (ColaVacia()) {
        cout << "\n📤 [COLA VACÍA] No hay documentos en espera" << endl;
        return;
    }
    
    cout << "\n🖨️ === COLA DE IMPRESIÓN === 🖨️" << endl;
    cout << "Documentos en espera: " << TamanioCola() << endl;
    cout << "------------------------" << endl;
    
    pnodoC aux = primero;
    int posicion = 1;
    
    while (aux) {
        if (posicion == 1) {
            cout << posicion << ". 🟢 \"" << aux->documento << "\" [SIGUIENTE EN IMPRIMIR]" << endl;
        } else {
            cout << posicion << ". 📄 \"" << aux->documento << "\"" << endl;
        }
        aux = aux->siguiente;
        posicion++;
    }
    
    cout << "------------------------" << endl;
}

void ImpresoraQueue::ImprimirDocumento() {
    if (ColaVacia()) {
        cout << "\n❌ [ERROR] No hay documentos para imprimir" << endl;
        return;
    }
    
    pnodoC aux = primero;
    cout << "\n🖨️ [IMPRIMIENDO] \"" << aux->documento << "\"" << endl;
    cout << "    ✅ Documento impreso correctamente" << endl;
    
    primero = primero->siguiente;
    delete aux;
    
    if (primero == NULL) {
        ultimo = NULL;
        cout << "    📤 Cola de impresión vacía" << endl;
    } else {
        cout << "    📊 Quedan " << TamanioCola() << " documentos en cola" << endl;
    }
}

int ImpresoraQueue::TamanioCola() {
    int contador = 0;
    pnodoC aux = primero;
    
    while (aux) {
        contador++;
        aux = aux->siguiente;
    }
    
    return contador;
}