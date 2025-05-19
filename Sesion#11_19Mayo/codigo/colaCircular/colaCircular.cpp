#include "colaCircular.h"

nodoCircular::nodoCircular(string _documento) {
    documento = _documento;
    siguiente = NULL;
}

nodoCircular::nodoCircular(string _documento, nodoCircular* signodo) {
    documento = _documento;
    siguiente = signodo;
}

ImpresoraQueueCircular::ImpresoraQueueCircular() {
    actual = NULL;
    tamanio = 0;
}

ImpresoraQueueCircular::~ImpresoraQueueCircular() {
    if (ColaVacia()) return;
    
    pnodoCircular temp = actual->siguiente;
    pnodoCircular aux;
    
    // Si hay un solo nodo
    if (temp == actual) {
        delete actual;
        actual = NULL;
        tamanio = 0;
        return;
    }
    
    // Más de un nodo
    while (temp != actual) {
        aux = temp;
        temp = temp->siguiente;
        delete aux;
    }
    
    // Eliminar el último nodo (actual)
    delete actual;
    actual = NULL;
    tamanio = 0;
}

bool ImpresoraQueueCircular::ColaVacia() {
    return actual == NULL;
}

void ImpresoraQueueCircular::AgregarDocumento(string documento) {
    pnodoCircular nuevo = new nodoCircular(documento);
    
    if (ColaVacia()) {
        // Si la cola está vacía, el nuevo nodo se apunta a sí mismo
        nuevo->siguiente = nuevo;
        actual = nuevo;
        tamanio = 1;
        cout << "\n📄 [COLA CIRCULAR] Nuevo documento añadido: \"" << documento << "\"" << endl;
        cout << "    📊 Estado: 1 documento en cola" << endl;
    } else {
        // Se inserta después del nodo actual y se actualiza el puntero
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        // El nuevo nodo se convierte en el actual (último agregado)
        actual = nuevo;
        tamanio++;
        cout << "\n📄 [COLA CIRCULAR] Nuevo documento añadido: \"" << documento << "\"" << endl;
        cout << "    📊 Estado: " << tamanio << " documentos en cola" << endl;
    }
}

void ImpresoraQueueCircular::MostrarCola() {
    if (ColaVacia()) {
        cout << "\n📤 [COLA CIRCULAR VACÍA] No hay documentos en espera" << endl;
        return;
    }
    
    cout << "\n🔄 === COLA CIRCULAR DE IMPRESIÓN === 🔄" << endl;
    cout << "Documentos en cola circular: " << tamanio << endl;
    cout << "--------------------------------------" << endl;
    
    pnodoCircular temp = actual->siguiente; // Comienza desde el primero en la cola (siguiente al actual)
    int posicion = 1;
    
    // Recorre la cola circular completa
    do {
        if (temp == actual->siguiente) {
            cout << posicion << ". 🟢 \"" << temp->documento << "\" [SIGUIENTE EN IMPRIMIR]" << endl;
        } else if (temp == actual) {
            cout << posicion << ". 🔵 \"" << temp->documento << "\" [ÚLTIMO AGREGADO]" << endl;
        } else {
            cout << posicion << ". 📄 \"" << temp->documento << "\"" << endl;
        }
        temp = temp->siguiente;
        posicion++;
    } while (temp != actual->siguiente);
    
    cout << "--------------------------------------" << endl;
}

void ImpresoraQueueCircular::ImprimirDocumento() {
    if (ColaVacia()) {
        cout << "\n❌ [ERROR] No hay documentos para imprimir" << endl;
        return;
    }
    
    pnodoCircular temp = actual->siguiente; // El primero en la cola
    cout << "\n🖨️ [IMPRIMIENDO] \"" << temp->documento << "\"" << endl;
    cout << "    ✅ Documento impreso correctamente" << endl;
    
    // Si solo hay un elemento en la cola
    if (temp == actual) {
        delete temp;
        actual = NULL;
        tamanio = 0;
        cout << "    📤 Cola de impresión vacía" << endl;
    } else {
        // Eliminamos el primer elemento y ajustamos los punteros
        actual->siguiente = temp->siguiente;
        delete temp;
        tamanio--;
        cout << "    📊 Quedan " << tamanio << " documentos en cola" << endl;
    }
}

int ImpresoraQueueCircular::TamanioCola() {
    return tamanio;
}

void ImpresoraQueueCircular::RotarCola() {
    if (!ColaVacia() && tamanio > 1) {
        actual = actual->siguiente;
        cout << "\n🔄 [ROTACIÓN] Documento actual ahora: \"" << actual->documento << "\"" << endl;
    } else if (tamanio == 1) {
        cout << "\n⚠️ [AVISO] Solo hay un documento en la cola, no es necesario rotar" << endl;
    } else {
        cout << "\n❌ [ERROR] No se puede rotar una cola vacía" << endl;
    }
}

string ImpresoraQueueCircular::DocumentoActual() {
    if (ColaVacia()) {
        return "";
    }
    return actual->documento;
}

bool ImpresoraQueueCircular::EsUltimoDocumento() {
    return tamanio == 1;
}