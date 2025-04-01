#include <iostream>
#include <string>
#include <limits>
#include "ABB.h"

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Demostración con enteros
void demoEnteros() {
    ABB<int> arbol;
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n==== MENÚ ÁRBOL DE ENTEROS ====" << std::endl;
        std::cout << "1. Insertar número" << std::endl;
        std::cout << "2. Buscar número" << std::endl;
        std::cout << "3. Eliminar número" << std::endl;
        std::cout << "4. Visualizar árbol (simple)" << std::endl;
        std::cout << "5. Visualizar árbol (detallado)" << std::endl;
        std::cout << "6. Mostrar recorrido InOrden" << std::endl;
        std::cout << "7. Mostrar recorrido PreOrden" << std::endl;
        std::cout << "8. Mostrar recorrido PostOrden" << std::endl;
        std::cout << "0. Volver al menú principal" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Intente de nuevo." << std::endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {  // Insertar
                int valor;
                std::cout << "Ingrese el número a insertar: ";
                std::cin >> valor;

                if (std::cin.fail()) {
                    std::cout << "Valor inválido." << std::endl;
                    limpiarBuffer();
                } else {
                    arbol.insertar(valor);
                    std::cout << "Número " << valor << " insertado correctamente." << std::endl;
                }
                break;
            }

            case 2: {  // Buscar
                if (arbol.estaVacio()) {
                    std::cout << "El árbol está vacío." << std::endl;
                    break;
                }

                int valor;
                std::cout << "Ingrese el número a buscar: ";
                std::cin >> valor;

                if (std::cin.fail()) {
                    std::cout << "Valor inválido." << std::endl;
                    limpiarBuffer();
                } else {
                    if (arbol.buscar(valor)) {
                        std::cout << "El número " << valor << " se encuentra en el árbol." << std::endl;
                    } else {
                        std::cout << "El número " << valor << " NO se encuentra en el árbol." << std::endl;
                    }
                }
                break;
            }

            case 3: {  // Eliminar
                if (arbol.estaVacio()) {
                    std::cout << "El árbol está vacío." << std::endl;
                    break;
                }

                int valor;
                std::cout << "Ingrese el número a eliminar: ";
                std::cin >> valor;

                if (std::cin.fail()) {
                    std::cout << "Valor inválido." << std::endl;
                    limpiarBuffer();
                } else {
                    arbol.eliminar(valor);
                    std::cout << "Se ha eliminado el número " << valor << " del árbol (si existía)." << std::endl;
                }
                break;
            }

            case 4:  // Visualizar (simple)
                arbol.visualizarArbol();
                break;

            case 5:  // Visualizar (detallado)
                arbol.visualizarArbolDetallado();
                break;

            case 6:  // InOrden
                arbol.mostrarInOrden();
                break;

            case 7:  // PreOrden
                arbol.mostrarPreOrden();
                break;

            case 8:  // PostOrden
                arbol.mostrarPostOrden();
                break;

            case 0:  // Volver
                std::cout << "Volviendo al menú principal..." << std::endl;
                break;

            default:
                std::cout << "Opción inválida. Intente de nuevo." << std::endl;
        }
    }
}

// Estructura para demostración de árbol de cadenas
struct Cadena {
    std::string texto;

    Cadena() : texto("") {}
    Cadena(const std::string& str) : texto(str) {}

    bool operator<(const Cadena& otra) const {
        return texto < otra.texto;
    }

    bool operator>(const Cadena& otra) const {
        return texto > otra.texto;
    }

    bool operator==(const Cadena& otra) const {
        return texto == otra.texto;
    }

    friend std::ostream& operator<<(std::ostream& os, const Cadena& c) {
        os << c.texto;
        return os;
    }
};

// Demostración con cadenas
void demoCadenas() {
    ABB<Cadena> arbol;
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n==== MENÚ ÁRBOL DE CADENAS ====" << std::endl;
        std::cout << "1. Insertar cadena" << std::endl;
        std::cout << "2. Buscar cadena" << std::endl;
        std::cout << "3. Eliminar cadena" << std::endl;
        std::cout << "4. Visualizar árbol (simple)" << std::endl;
        std::cout << "5. Visualizar árbol (detallado)" << std::endl;
        std::cout << "6. Mostrar recorrido InOrden" << std::endl;
        std::cout << "0. Volver al menú principal" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Intente de nuevo." << std::endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {  // Insertar
                std::string texto;
                std::cout << "Ingrese la cadena a insertar: ";
                limpiarBuffer();
                std::getline(std::cin, texto);

                arbol.insertar(Cadena(texto));
                std::cout << "Cadena \"" << texto << "\" insertada correctamente." << std::endl;
                break;
            }

            case 2: {  // Buscar
                if (arbol.estaVacio()) {
                    std::cout << "El árbol está vacío." << std::endl;
                    break;
                }

                std::string texto;
                std::cout << "Ingrese la cadena a buscar: ";
                limpiarBuffer();
                std::getline(std::cin, texto);

                if (arbol.buscar(Cadena(texto))) {
                    std::cout << "La cadena \"" << texto << "\" se encuentra en el árbol." << std::endl;
                } else {
                    std::cout << "La cadena \"" << texto << "\" NO se encuentra en el árbol." << std::endl;
                }
                break;
            }

            case 3: {  // Eliminar
                if (arbol.estaVacio()) {
                    std::cout << "El árbol está vacío." << std::endl;
                    break;
                }

                std::string texto;
                std::cout << "Ingrese la cadena a eliminar: ";
                limpiarBuffer();
                std::getline(std::cin, texto);

                arbol.eliminar(Cadena(texto));
                std::cout << "Se ha eliminado la cadena \"" << texto << "\" del árbol (si existía)." << std::endl;
                break;
            }

            case 4:  // Visualizar (simple)
                arbol.visualizarArbol();
                break;

            case 5:  // Visualizar (detallado)
                arbol.visualizarArbolDetallado();
                break;

            case 6:  // InOrden
                arbol.mostrarInOrden();
                break;

            case 0:  // Volver
                std::cout << "Volviendo al menú principal..." << std::endl;
                break;

            default:
                std::cout << "Opción inválida. Intente de nuevo." << std::endl;
        }
    }
}

// Menú principal
int main() {
    int opcion = -1;

    std::cout << "====================================" << std::endl;
    std::cout << "DEMOSTRACIÓN DE ÁRBOL BINARIO DE BÚSQUEDA" << std::endl;
    std::cout << "====================================" << std::endl;

    while (opcion != 0) {
        std::cout << "\n===== MENÚ PRINCIPAL =====" << std::endl;
        std::cout << "1. Árbol de números enteros" << std::endl;
        std::cout << "2. Árbol de cadenas de texto" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Intente de nuevo." << std::endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1:
                demoEnteros();
                break;

            case 2:
                demoCadenas();
                break;

            case 0:
                std::cout << "Gracias por usar la demostración de Árboles Binarios de Búsqueda." << std::endl;
                break;

            default:
                std::cout << "Opción inválida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}