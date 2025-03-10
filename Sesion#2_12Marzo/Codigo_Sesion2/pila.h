#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <string>
using namespace std;

class nodoP {
public:
    nodoP(string url);
    nodoP(string url, nodoP* signodo);
private:
    string url;
    nodoP* siguiente;
    friend class NavegadorHistorial;
};
typedef nodoP* pnodoP;

class NavegadorHistorial {
public:
    NavegadorHistorial();
    ~NavegadorHistorial();
    void VisitarURL(string url);
    bool HistorialVacio();
    void MostrarHistorial();
    void RegresarPagina();
    int TamanioHistorial();
private:
    pnodoP cima;
};
#endif // PILA_H