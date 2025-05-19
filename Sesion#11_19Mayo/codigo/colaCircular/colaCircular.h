#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H
#include <iostream>
#include <string>
using namespace std;

class nodoCircular {
public:
    nodoCircular(string documento);
    nodoCircular(string documento, nodoCircular* signodo);
private:
    string documento;
    nodoCircular* siguiente;
    friend class ImpresoraQueueCircular;
};
typedef nodoCircular* pnodoCircular;

class ImpresoraQueueCircular {
public:
    ImpresoraQueueCircular();
    ~ImpresoraQueueCircular();
    void AgregarDocumento(string documento);
    bool ColaVacia();
    void MostrarCola();
    void ImprimirDocumento();
    int TamanioCola();
    // Métodos específicos de la cola circular
    void RotarCola();
    string DocumentoActual();
    bool EsUltimoDocumento();
private:
    pnodoCircular actual;  // Referencia al nodo actual en la cola circular
    int tamanio;           // Contador de elementos para optimizar TamanioCola()
};
#endif // COLA_CIRCULAR_H