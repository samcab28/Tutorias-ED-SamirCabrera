#include <iostream>
#include <fstream>
#include <string>
#include "lista_simple.h"

using namespace std;

int main() {
    // Crear una instancia de la lista
    lista miLista;

    // Ruta del archivo - usa una ruta absoluta o coloca el archivo en el directorio de compilación
    const string ruta = "/home/samir-cabrera/projects/universidad/tutoriasED/Tutorias-ED-SamirCabrera/Sesion#3_17Marzo/codigo_sesion3/Archivo1.txt";

    // Abrir el archivo
    ifstream archivo(ruta);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << ruta << endl;
        return 1;
    }

    cout << "Archivo abierto correctamente: " << ruta << endl;

    // Leer el archivo línea por línea
    string linea;

    while (getline(archivo, linea)) {


        // Si la línea no está vacía, procesarla
        if (!linea.empty()) {
            // En este caso, insertamos directamente la línea como string
            miLista.InsertarFinal(linea);
            cout << "Insertado: " << linea << endl;
        }
    }

    // Cerrar el archivo
    archivo.close();

    // Mostrar la lista resultante
    cout << "\nContenido de la lista:" << endl;
    miLista.Mostrar();

    return 0;
}