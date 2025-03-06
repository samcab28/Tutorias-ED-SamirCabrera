#include "lista_simple.h"
#include "lista_circular.h"

int main() {
    cout << "=== Lista Simple ===" << endl;
    lista ListaSimple;
    ListaSimple.InsertarInicio(4);
    ListaSimple.InsertarInicio(56);
    ListaSimple.InsertarInicio(79);
    ListaSimple.InsertarFinal(80);
    ListaSimple.Mostrar();

    cout << "\n=== Lista Circular ===" << endl;
    listaC ListaCircular;
    ListaCircular.InsertarInicio(4);
    ListaCircular.InsertarInicio(56);
    ListaCircular.InsertarInicio(79);
    ListaCircular.InsertarFinal(80);
    ListaCircular.Mostrar();

    return 0;
}