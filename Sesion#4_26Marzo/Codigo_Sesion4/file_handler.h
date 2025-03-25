#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "lista_simple.h"

using namespace std;

class FileHandler {
public:
    // Leer datos del archivo y cargar en la lista
    static bool leerArchivo(const string& ruta, lista& miLista);
    
    // Escribir datos de la lista al archivo
    static bool escribirArchivo(const string& ruta, lista& miLista);
    
    // Insertar una nueva línea en el archivo
    static bool insertarLinea(const string& ruta, const string& nombre, int edad);

    // Eliminar una línea específica del archivo
    static bool eliminarLinea(const string& ruta, const string& nombre, int edad);

    // Convertir una cadena separada por ; a lista
    static void procesarCadena(const string& cadena, lista& miLista);

    // Nuevo método para escribir la lista completa al archivo
    static bool escribirListaEnArchivo(const string& ruta, lista& miLista);

private:
    // Validar formato de entrada
    static bool validarEntrada(const string& entrada);
};

#endif // FILE_HANDLER_H