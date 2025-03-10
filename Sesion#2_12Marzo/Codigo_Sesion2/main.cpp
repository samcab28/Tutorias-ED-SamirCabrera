#include "lista_doble.h"
#include "cola.h"
#include "pila.h"
#include <iostream>
#include <limits>
using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "         MENÚ PRINCIPAL" << endl;
    cout << "========================================" << endl;
    cout << "1. Reproductor de Música MP3" << endl;
    cout << "2. Cola de Impresión" << endl;
    cout << "3. Historial de Navegación" << endl;
    cout << "0. Salir" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Seleccione una opción: ";
}

void menuMP3(ReproductorMP3 &reproductor) {
    int opcion = 0;
    string cancion;

    do {
        cout << "\n========================================" << endl;
        cout << "         REPRODUCTOR MP3" << endl;
        cout << "========================================" << endl;
        cout << "1. Agregar canción" << endl;
        cout << "2. Mostrar playlist" << endl;
        cout << "3. Reproducir canción actual" << endl;
        cout << "4. Siguiente canción" << endl;
        cout << "5. Canción anterior" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre de la canción: ";
                getline(cin, cancion);
                reproductor.InsertarCancion(cancion);
                break;
            case 2:
                reproductor.MostrarPlaylist();
                break;
            case 3:
                reproductor.ReproducirActual();
                break;
            case 4:
                reproductor.ReproducirSiguiente();
                break;
            case 5:
                reproductor.ReproducirAnterior();
                break;
            case 0:
                cout << "\n🔙 Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "\n❌ Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void menuImpresora(ImpresoraQueue &impresora) {
    int opcion = 0;
    string documento;

    do {
        cout << "\n========================================" << endl;
        cout << "         COLA DE IMPRESIÓN" << endl;
        cout << "========================================" << endl;
        cout << "1. Agregar documento a la cola" << endl;
        cout << "2. Mostrar cola de impresión" << endl;
        cout << "3. Imprimir documento" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre del documento: ";
                getline(cin, documento);
                impresora.AgregarDocumento(documento);
                break;
            case 2:
                impresora.MostrarCola();
                break;
            case 3:
                impresora.ImprimirDocumento();
                break;
            case 0:
                cout << "\n🔙 Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "\n❌ Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void menuNavegador(NavegadorHistorial &navegador) {
    int opcion = 0;
    string url;

    do {
        cout << "\n========================================" << endl;
        cout << "         HISTORIAL DE NAVEGACIÓN" << endl;
        cout << "========================================" << endl;
        cout << "1. Visitar nueva página" << endl;
        cout << "2. Mostrar historial" << endl;
        cout << "3. Regresar a página anterior" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Ingrese URL a visitar: ";
                getline(cin, url);
                navegador.VisitarURL(url);
                break;
            case 2:
                navegador.MostrarHistorial();
                break;
            case 3:
                navegador.RegresarPagina();
                break;
            case 0:
                cout << "\n🔙 Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "\n❌ Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

int main() {
    ReproductorMP3 reproductor;
    ImpresoraQueue impresora;
    NavegadorHistorial navegador;

    int opcion = 0;

    cout << "╔══════════════════════════════════════╗" << endl;
    cout << "║ ESTRUCTURAS DE DATOS - APLICACIONES  ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuMP3(reproductor);
                break;
            case 2:
                menuImpresora(impresora);
                break;
            case 3:
                menuNavegador(navegador);
                break;
            case 0:
                cout << "\n👋 Gracias por utilizar el programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "\n❌ Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);

    return 0;
}