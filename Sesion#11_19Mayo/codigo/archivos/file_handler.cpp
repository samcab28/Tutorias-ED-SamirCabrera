#include "file_handler.h"
#include <stdexcept>

bool FileHandler::validarEntrada(const string& entrada) {
    // Verificar que la entrada tenga el formato nombre;edad
    size_t pos = entrada.find(';');
    if (pos == string::npos) return false;

    string nombre = entrada.substr(0, pos);
    string edadStr = entrada.substr(pos + 1);

    // Verificar que el nombre no esté vacío
    if (nombre.empty()) return false;

    // Verificar que la edad sea un número válido
    try {
        int edad = stoi(edadStr);
        if (edad < 0) return false;
    } catch (...) {
        return false;
    }

    return true;
}

bool FileHandler::leerArchivo(const string& ruta, lista& miLista) {
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << ruta << endl;
        return false;
    }

    // Limpiar la lista antes de cargar
    while (!miLista.ListaVacia()) {
        miLista.BorrarInicio();
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty() && validarEntrada(linea)) {
            // Separar nombre y edad
            size_t pos = linea.find(';');
            string nombre = linea.substr(0, pos);
            int edad = stoi(linea.substr(pos + 1));

            miLista.InsertarFinal(nombre, edad);
        }
    }

    archivo.close();
    return true;
}

bool FileHandler::escribirArchivo(const string& ruta, lista& miLista) {
    ofstream archivo(ruta);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << ruta << endl;
        return false;
    }

    pnodoS aux = miLista.getPrimero();
    while (aux) {
        archivo << aux->getNombre() << ";" << aux->getEdad() << endl;
        aux = aux->getSiguiente();
    }

    archivo.close();
    return true;
}

bool FileHandler::insertarLinea(const string& ruta, const string& nombre, int edad) {
    // Primero leer el contenido actual
    lista listaTemp;
    if (!leerArchivo(ruta, listaTemp)) {
        return false;
    }

    // Insertar al final
    listaTemp.InsertarFinal(nombre, edad);

    // Escribir de vuelta al archivo
    return escribirArchivo(ruta, listaTemp);
}

bool FileHandler::eliminarLinea(const string& ruta, const string& nombre, int edad) {
    // Primero leer el contenido actual
    lista listaTemp;
    if (!leerArchivo(ruta, listaTemp)) {
        return false;
    }

    // Encontrar y eliminar la línea
    pnodoS aux = listaTemp.getPrimero();
    int pos = 0;
    while (aux) {
        if (aux->getNombre() == nombre && aux->getEdad() == edad) {
            listaTemp.borrarPosicion(pos);
            break;
        }
        aux = aux->getSiguiente();
        pos++;
    }

    // Escribir de vuelta al archivo
    return escribirArchivo(ruta, listaTemp);
}


void FileHandler::procesarCadena(const string& cadena, lista& miLista) {
    // Limpiar la lista antes de cargar
    while (!miLista.ListaVacia()) {
        miLista.BorrarInicio();
    }

    // Separar por ;
    stringstream ss(cadena);
    string item;

    while (getline(ss, item, ';')) {
        if (!item.empty()) {
            // Separar nombre y edad
            size_t pos = item.find(';');
            string nombre = item.substr(0, pos);
            int edad = stoi(item.substr(pos + 1));

            miLista.InsertarFinal(nombre, edad);
        }
    }
}

// Nuevo método para escribir la lista completa al archivo
bool FileHandler::escribirListaEnArchivo(const string& ruta, lista& miLista) {
    ofstream archivo(ruta);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << ruta << endl;
        return false;
    }

    // Recorrer todos los nodos de la lista
    pnodoS aux = miLista.getPrimero();
    while (aux) {
        // Escribir cada nodo en el formato nombre;edad
        archivo << aux->getNombre() << ";" << aux->getEdad() << endl;
        aux = aux->getSiguiente();
    }

    archivo.close();
    return true;
}