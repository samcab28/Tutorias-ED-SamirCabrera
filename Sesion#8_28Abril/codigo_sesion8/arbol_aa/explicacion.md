# Árbol AA: Estructura, Implementación y Pruebas

## Definición de Árbol AA

Un **Árbol AA** es una variante simplificada del árbol rojo-negro, desarrollada por Arne Andersson en 1993. Esta estructura de datos mantiene un balance automático para garantizar operaciones eficientes de búsqueda, inserción y eliminación, con una complejidad temporal de O(log n).

### Características principales

1. **Niveles en lugar de colores**: A diferencia de los árboles rojo-negro que utilizan colores (rojo o negro) para cada nodo, los árboles AA utilizan un valor numérico llamado "nivel" para mantener el equilibrio.

2. **Restricciones de nivel**:
   - Todos los nodos hoja (sin hijos) tienen nivel 1
   - Un hijo izquierdo debe tener un nivel estrictamente menor que su padre
   - Un hijo derecho puede tener el mismo nivel que su padre, pero no mayor
   - No puede haber dos hijos derechos consecutivos con el mismo nivel

3. **Operaciones de rebalanceo**:
   - **Skew**: Corrige la situación cuando un hijo izquierdo tiene el mismo nivel que su padre
   - **Split**: Corrige la situación cuando hay dos hijos derechos consecutivos con el mismo nivel

### Ventajas de los árboles AA

- Implementación más sencilla que los árboles rojo-negro
- Mantienen un buen equilibrio, garantizando operaciones en O(log n)
- Las reglas son más simples de entender y aplicar
- Las operaciones de rebalanceo (skew y split) son conceptualmente más claras

## Implementación

La implementación proporcionada consta de tres archivos:

1. **arbol_aa.h**: Define la interfaz de la clase ArbolAA
2. **arbol_aa.cpp**: Implementa los métodos de la clase
3. **main.cpp**: Contiene un programa de ejemplo que muestra el funcionamiento

### Estructura de nodo

Cada nodo del árbol AA contiene:

```cpp
struct Nodo {
    int valor;       // Valor almacenado
    int nivel;       // Nivel del nodo (para balance)
    Nodo* izquierdo; // Hijo izquierdo
    Nodo* derecho;   // Hijo derecho
};
```

### Operaciones principales

1. **Inserción**: Inserta un nuevo valor en el árbol manteniendo el balance
2. **Eliminación**: Elimina un valor existente del árbol y reajusta el balance
3. **Búsqueda**: Encuentra si un valor existe en el árbol
4. **Recorridos**: Permite recorrer el árbol en preorden, inorden y postorden

### Operaciones de rebalanceo

- **Skew**: Realiza una rotación a la derecha cuando un hijo izquierdo tiene el mismo nivel que su padre
- **Split**: Realiza una rotación a la izquierda cuando hay dos hijos derechos consecutivos con el mismo nivel

## Pruebas realizadas

El archivo main.cpp demuestra varias operaciones sobre un árbol AA:

### 1. Inserción de elementos

Se insertan 11 elementos: 10, 5, 15, 3, 7, 12, 18, 1, 6, 11, 20

### 2. Visualización del árbol

Después de insertar los elementos, se muestra la estructura del árbol. Cada nodo se muestra con su valor y nivel entre corchetes. La estructura resultante está balanceada según las reglas de los árboles AA.

### 3. Recorridos del árbol

Se realizan tres tipos de recorridos:
- **Preorden**: Visita primero la raíz, luego el subárbol izquierdo y finalmente el subárbol derecho
- **Inorden**: Visita primero el subárbol izquierdo, luego la raíz y finalmente el subárbol derecho (produce los elementos en orden ascendente)
- **Postorden**: Visita primero el subárbol izquierdo, luego el subárbol derecho y finalmente la raíz

### 4. Operaciones de búsqueda

Se buscan dos valores:
- El valor 7 (que existe en el árbol)
- El valor 22 (que no existe en el árbol)

### 5. Eliminación de elementos

Se eliminan tres elementos para mostrar diferentes casos:
- **Eliminar 5**: Nodo con dos hijos
- **Eliminar 1**: Nodo hoja (sin hijos)
- **Eliminar 18**: Nodo con un solo hijo

Después de cada eliminación, se muestra la estructura del árbol para verificar que mantiene su balance.

### 6. Recorridos finales

Finalmente, se muestran los recorridos del árbol después de todas las operaciones para verificar su estado final.

## Resultados esperados

- Al ejecutar el programa, veremos cómo el árbol mantiene su balance automáticamente después de cada operación de inserción y eliminación.
- Los recorridos inorden siempre mostrarán los elementos en orden ascendente.
- Las búsquedas de elementos existentes devolverán "Encontrado" y las de elementos no existentes "No encontrado".
- Después de las eliminaciones, el árbol seguirá manteniendo sus propiedades de balance.

Esta implementación demuestra las principales características de los árboles AA y cómo mantienen su eficiencia a través de las operaciones de rebalanceo skew y split.