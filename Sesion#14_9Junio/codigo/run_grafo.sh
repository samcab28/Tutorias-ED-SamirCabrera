#!/bin/bash

echo "Compilando proyecto de algoritmos MST..."

# Limpiar archivos objeto previos
rm -f *.o mst_program

# Compilar cada archivo .cpp por separado
echo "Compilando grafo.cpp..."
g++ -Wall -Wextra -std=c++11 -c grafo.cpp -o grafo.o

echo "Compilando kruskal.cpp..."
g++ -Wall -Wextra -std=c++11 -c kruskal.cpp -o kruskal.o

echo "Compilando prim.cpp..."
g++ -Wall -Wextra -std=c++11 -c prim.cpp -o prim.o

echo "Compilando main.cpp..."
g++ -Wall -Wextra -std=c++11 -c main.cpp -o main.o

# Enlazar todos los archivos objeto
echo "Enlazando archivos..."
g++ -Wall -Wextra -std=c++11 -o mst_program main.o grafo.o kruskal.o prim.o

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa!"
    echo "Ejecutando programa..."
    echo "=========================="
    ./mst_program
else
    echo "Error en la compilación"
    exit 1
fi