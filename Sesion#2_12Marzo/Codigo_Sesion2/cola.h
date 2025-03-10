#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <string>
using namespace std;

class nodoC {
public:
    nodoC(string documento);
    nodoC(string documento, nodoC* signodo);
private:
    string documento;
    nodoC* siguiente;
    friend class ImpresoraQueue;
};
typedef nodoC* pnodoC;

class ImpresoraQueue {
public:
    ImpresoraQueue();
    ~ImpresoraQueue();
    void AgregarDocumento(string documento);
    bool ColaVacia();
    void MostrarCola();
    void ImprimirDocumento();
    int TamanioCola();
private:
    pnodoC primero;
    pnodoC ultimo;
};
#endif // COLA_H