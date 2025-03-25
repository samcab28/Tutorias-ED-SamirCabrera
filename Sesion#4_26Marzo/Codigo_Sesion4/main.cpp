#include <iostream>
#include <string>
#include <stdexcept>
#include "lista_simple.h"
#include "file_handler.h"
#include "sistema_restaurante.h"

using namespace std;

void mostrarMenuPrincipal() {
    cout << "\n--- MENÚ PRINCIPAL ---" << endl;
    cout << "1. Operaciones con Archivos" << endl;
    cout << "2. Operaciones con Tabla Hash" << endl;
    cout << "3. Salir" << endl;
    cout << "Elija una opción: ";
}

void mostrarMenuArchivos() {
    cout << "\n--- MENÚ DE OPERACIONES CON ARCHIVOS ---" << endl;
    cout << "1. Leer archivo" << endl;
    cout << "2. Insertar persona" << endl;
    cout << "3. Escribir lista en archivo" << endl;
    cout << "4. Mostrar lista actual" << endl;
    cout << "5. Regresar al menú principal" << endl;
    cout << "Elija una opción: ";
}

void mostrarMenuHash() {
    cout << "\n--- MENÚ DE OPERACIONES CON TABLA HASH ---" << endl;
    cout << "1. Insertar cliente" << endl;
    cout << "2. Buscar cliente" << endl;
    cout << "3. Eliminar cliente" << endl;
    cout << "4. Mostrar tabla hash" << endl;
    cout << "5. Verificar si tabla está vacía" << endl;
    cout << "6. Contar clientes" << endl;
    cout << "7. Ejecutar casos de prueba originales" << endl;
    cout << "8. Regresar al menú principal" << endl;
    cout << "Elija una opción: ";
}

void ejecutarCasosPrueba(SistemaRestaurante& sistema) {
    cout << "\n=== EJECUTANDO CASOS DE PRUEBA ORIGINALES ===\n";

    // Caso 1: Inserción básica
    sistema.insertarCliente("123456789", "Juan Pérez");
    sistema.mostrarTabla();

    // Caso 2: Inserción sin colisión
    sistema.insertarCliente("987654321", "María Gómez");
    sistema.mostrarTabla();

    // Caso 3: Intento de inserción duplicada
    sistema.insertarCliente("123456789", "Pedro Sánchez"); // Debe fallar
    sistema.insertarCliente("123456782", "Ana Ruiz"); // Colisiona con Juan Pérez
    sistema.mostrarTabla();

    // Continuar con más casos...
    sistema.insertarCliente("100000001", "Carlos López");
    sistema.insertarCliente("100000014", "Laura Díaz");
    sistema.mostrarTabla();

    // Búsquedas
    sistema.buscarCliente("123456789");
    sistema.buscarCliente("987654321");
    sistema.buscarCliente("999999999"); // No existente
}

int main() {
    lista miLista;
    SistemaRestaurante sistema;
    string ruta = "/home/samir-cabrera/projects/universidad/tutoriasED/Tutorias-ED-SamirCabrera/Sesion#4_26Marzo/Codigo_Sesion4/Archivo1.txt";
    int opcionPrincipal, opcionArchivos, opcionHash;
    string nombre, cedula;
    int edad;

    do {
        mostrarMenuPrincipal();
        cin >> opcionPrincipal;
        cin.ignore(); // Limpiar buffer de entrada

        switch(opcionPrincipal) {
            case 1: // Menú de Archivos
                do {
                    mostrarMenuArchivos();
                    cin >> opcionArchivos;
                    cin.ignore(); // Limpiar buffer de entrada

                    try {
                        switch(opcionArchivos) {
                            case 1:
                                if (FileHandler::leerArchivo(ruta, miLista)) {
                                    cout << "Archivo leído correctamente." << endl;
                                }
                                break;

                            case 2:
                            {
                                cout << "Ingrese el nombre: ";
                                getline(cin, nombre);

                                while (true) {
                                    cout << "Ingrese la edad: ";
                                    if (cin >> edad) {
                                        cin.ignore(); // Limpiar buffer
                                        break;
                                    } else {
                                        cout << "Edad inválida. Intente de nuevo." << endl;
                                        cin.clear(); // Limpiar estado de error
                                    }
                                }

                                miLista.InsertarFinal(nombre, edad);
                                if (FileHandler::insertarLinea(ruta, nombre, edad)) {
                                    cout << "Persona insertada correctamente." << endl;
                                }
                                break;
                            }

                            case 3:
                                if (FileHandler::escribirListaEnArchivo(ruta, miLista)) {
                                    cout << "Lista escrita en archivo correctamente." << endl;
                                }
                                break;

                            case 4:
                                cout << "Contenido de la lista:" << endl;
                                miLista.Mostrar();
                                break;

                            case 5:
                                cout << "Regresando al menú principal..." << endl;
                                break;

                            default:
                                cout << "Opción inválida. Intente de nuevo." << endl;
                        }
                    } catch (const exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                } while (opcionArchivos != 5);
                break;

            case 2: // Menú de Hash
                do {
                    mostrarMenuHash();
                    cin >> opcionHash;
                    cin.ignore(); // Limpiar buffer de entrada

                    switch(opcionHash) {
                        case 1: // Insertar cliente
                        {
                            cout << "Ingrese la cédula: ";
                            getline(cin, cedula);
                            cout << "Ingrese el nombre: ";
                            getline(cin, nombre);
                            sistema.insertarCliente(cedula, nombre);
                            break;
                        }

                        case 2: // Buscar cliente
                        {
                            cout << "Ingrese la cédula a buscar: ";
                            getline(cin, cedula);
                            sistema.buscarCliente(cedula);
                            break;
                        }

                        case 3: // Eliminar cliente
                        {
                            cout << "Ingrese la cédula a eliminar: ";
                            getline(cin, cedula);
                            sistema.eliminarCliente(cedula);
                            break;
                        }

                        case 4: // Mostrar tabla
                            sistema.mostrarTabla();
                            break;

                        case 5: // Verificar si está vacía
                            cout << "Tabla " << (sistema.estaVacia() ? "está vacía" : "tiene elementos") << endl;
                            break;

                        case 6: // Contar clientes
                            cout << "Total de clientes: " << sistema.contarClientes() << endl;
                            break;

                        case 7: // Ejecutar casos de prueba originales
                            ejecutarCasosPrueba(sistema);
                            break;

                        case 8: // Regresar al menú principal
                            cout << "Regresando al menú principal..." << endl;
                            break;

                        default:
                            cout << "Opción inválida. Intente de nuevo." << endl;
                    }
                } while (opcionHash != 8);
                break;

            case 3:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcionPrincipal != 3);

    return 0;
}