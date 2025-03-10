#include "pila.h"

nodoP::nodoP(string _url) {
    url = _url;
    siguiente = NULL;
}

nodoP::nodoP(string _url, nodoP* signodo) {
    url = _url;
    siguiente = signodo;
}

NavegadorHistorial::NavegadorHistorial() {
    cima = NULL;
}

NavegadorHistorial::~NavegadorHistorial() {
    pnodoP aux;
    while (cima) {
        aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
    cima = NULL;
}

bool NavegadorHistorial::HistorialVacio() {
    return cima == NULL;
}

void NavegadorHistorial::VisitarURL(string url) {
    pnodoP nuevo = new nodoP(url, cima);
    cima = nuevo;
    cout << "\n🌐 [NAVEGANDO] Visitando: \"" << url << "\"" << endl;
    cout << "    📊 Historial: " << TamanioHistorial() << " páginas" << endl;
}

void NavegadorHistorial::MostrarHistorial() {
    if (HistorialVacio()) {
        cout << "\n🕸️ [HISTORIAL VACÍO] No hay páginas visitadas" << endl;
        return;
    }
    
    cout << "\n🔍 === HISTORIAL DE NAVEGACIÓN === 🔍" << endl;
    cout << "Total de páginas: " << TamanioHistorial() << endl;
    cout << "------------------------" << endl;
    
    pnodoP aux = cima;
    int posicion = 1;
    
    while (aux) {
        if (posicion == 1) {
            cout << posicion << ". 🟢 \"" << aux->url << "\" [PÁGINA ACTUAL]" << endl;
        } else {
            cout << posicion << ". 🌐 \"" << aux->url << "\"" << endl;
        }
        aux = aux->siguiente;
        posicion++;
    }
    
    cout << "------------------------" << endl;
}

void NavegadorHistorial::RegresarPagina() {
    if (HistorialVacio() || cima->siguiente == NULL) {
        cout << "\n❌ [ERROR] No hay páginas anteriores para regresar" << endl;
        return;
    }
    
    pnodoP aux = cima;
    string paginaActual = aux->url;
    string paginaAnterior = aux->siguiente->url;
    
    cima = cima->siguiente;
    delete aux;
    
    cout << "\n◀️ [REGRESANDO] De \"" << paginaActual << "\" a \"" << paginaAnterior << "\"" << endl;
    cout << "    🌐 Página actual: \"" << paginaAnterior << "\"" << endl;
}

int NavegadorHistorial::TamanioHistorial() {
    int contador = 0;
    pnodoP aux = cima;
    
    while (aux) {
        contador++;
        aux = aux->siguiente;
    }
    
    return contador;
}