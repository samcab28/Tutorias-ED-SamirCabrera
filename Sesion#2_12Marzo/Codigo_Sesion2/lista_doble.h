#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <iostream>
#include <string>
using namespace std;

class nodoD {
public:
    nodoD(string cancion);
    nodoD(string cancion, nodoD* sig, nodoD* ant);
private:
    string cancion;
    nodoD* siguiente;
    nodoD* anterior;
    friend class ReproductorMP3;
};
typedef nodoD* pnodoD;

class ReproductorMP3 {
public:
    ReproductorMP3();
    ~ReproductorMP3();
    void InsertarCancion(string cancion);
    bool ListaVacia();
    void MostrarPlaylist();
    void ReproducirSiguiente();
    void ReproducirAnterior();
    void ReproducirActual();
private:
    pnodoD primero;
    pnodoD ultimo;
    pnodoD actual;
};
#endif // LISTA_DOBLE_H