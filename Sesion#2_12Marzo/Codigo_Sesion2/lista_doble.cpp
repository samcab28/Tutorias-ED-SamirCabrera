#include "lista_doble.h"

nodoD::nodoD(string _cancion) {
    cancion = _cancion;
    siguiente = NULL;
    anterior = NULL;
}

nodoD::nodoD(string _cancion, nodoD* sig, nodoD* ant) {
    cancion = _cancion;
    siguiente = sig;
    anterior = ant;
}

ReproductorMP3::ReproductorMP3() {
    primero = NULL;
    ultimo = NULL;
    actual = NULL;
}

ReproductorMP3::~ReproductorMP3() {
    pnodoD aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
    ultimo = NULL;
    actual = NULL;
}

bool ReproductorMP3::ListaVacia() {
    return primero == NULL;
}

void ReproductorMP3::InsertarCancion(string cancion) {
    pnodoD nuevo = new nodoD(cancion);
    
    if (ListaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
        actual = nuevo;
        cout << "\n🎵 [AGREGADA] Primera canción en la playlist: \"" << cancion << "\"" << endl;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
        cout << "\n🎵 [AGREGADA] Nueva canción en la playlist: \"" << cancion << "\"" << endl;
    }
}

void ReproductorMP3::MostrarPlaylist() {
    if (ListaVacia()) {
        cout << "\n❌ [ERROR] La playlist está vacía" << endl;
        return;
    }
    
    cout << "\n📋 === PLAYLIST ACTUAL === 📋" << endl;
    pnodoD aux = primero;
    int contador = 1;
    
    while (aux) {
        if (aux == actual) {
            cout << contador << ". ▶️ \"" << aux->cancion << "\" [REPRODUCIENDO]" << endl;
        } else {
            cout << contador << ". 🎵 \"" << aux->cancion << "\"" << endl;
        }
        aux = aux->siguiente;
        contador++;
    }
    
    cout << "------------------------" << endl;
}

void ReproductorMP3::ReproducirSiguiente() {
    if (ListaVacia()) {
        cout << "\n❌ [ERROR] La playlist está vacía" << endl;
        return;
    }
    
    if (actual == ultimo) {
        cout << "\n⚠️ [AVISO] Ya estás en la última canción de la playlist" << endl;
        return;
    }
    
    actual = actual->siguiente;
    cout << "\n⏭️ [SIGUIENTE] Reproduciendo: \"" << actual->cancion << "\"" << endl;
}

void ReproductorMP3::ReproducirAnterior() {
    if (ListaVacia()) {
        cout << "\n❌ [ERROR] La playlist está vacía" << endl;
        return;
    }
    
    if (actual == primero) {
        cout << "\n⚠️ [AVISO] Ya estás en la primera canción de la playlist" << endl;
        return;
    }
    
    actual = actual->anterior;
    cout << "\n⏮️ [ANTERIOR] Reproduciendo: \"" << actual->cancion << "\"" << endl;
}

void ReproductorMP3::ReproducirActual() {
    if (ListaVacia()) {
        cout << "\n❌ [ERROR] La playlist está vacía" << endl;
        return;
    }
    
    cout << "\n▶️ [REPRODUCIENDO] Ahora suena: \"" << actual->cancion << "\"" << endl;
}