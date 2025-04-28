# Árboles Rojo-Negro

## Definición

Un árbol rojo-negro es una estructura de datos de tipo árbol binario de búsqueda con auto-balanceo que tiene las siguientes propiedades:

1. Cada nodo es rojo o negro.
2. La raíz siempre es negra.
3. Las hojas nulas (NIL) son consideradas negras.
4. Si un nodo es rojo, sus hijos deben ser negros (no pueden haber dos nodos rojos adyacentes).
5. Para cada nodo, todos los caminos desde el nodo hacia las hojas descendientes contienen el mismo número de nodos negros.

Estas propiedades garantizan que la altura del árbol permanezca logarítmica respecto al número de nodos, lo que asegura operaciones eficientes.

## Ventajas

- Las operaciones de búsqueda, inserción y eliminación tienen un tiempo de complejidad de O(log n) en el peor caso.
- Se rebalancea automáticamente después de inserciones y eliminaciones.
- Es más eficiente en modificaciones que otros árboles autobalanceados como los árboles AVL.

## Explicación de la Implementación

En nuestra implementación:

- La clase `ArbolRojiNegro` encapsula la estructura completa del árbol.
- La clase `Nodo` representa cada elemento del árbol, con su valor, color y punteros a sus nodos hijos y padre.
- Usamos un nodo especial `nil` como centinela para representar las hojas nulas.

### Operaciones Principales:

1. **Inserción**: 
   - Se inserta un nuevo nodo siguiendo las reglas de un árbol binario de búsqueda.
   - El nuevo nodo se colorea como rojo.
   - Se realiza un rebalanceo para restaurar las propiedades del árbol rojo-negro.

2. **Eliminación**:
   - Se elimina el nodo siguiendo el algoritmo estándar de eliminación en árboles binarios de búsqueda.
   - Se realizan ajustes para mantener las propiedades del árbol rojo-negro.

3. **Búsqueda**:
   - Se realiza una búsqueda binaria estándar en el árbol.

4. **Rotaciones**:
   - Las rotaciones a la izquierda y derecha son operaciones fundamentales para rebalancear el árbol.

## Análisis de la Corrida de Ejemplo

En el `main.cpp` se realiza una demostración completa del árbol rojo-negro:

1. **Inserción de elementos**:
   - Se insertan 8 valores: 10, 20, 30, 15, 25, 5, 35, 40.
   - Cada inserción puede activar rotaciones y recoloraciones para mantener las propiedades del árbol.

2. **Visualización**:
   - Se muestra el árbol en recorrido inorden (de menor a mayor valor).
   - Se visualiza la estructura del árbol con la representación del color de cada nodo (R=Rojo, N=Negro).

3. **Búsqueda**:
   - Se demuestra la búsqueda de valores existentes (25) y no existentes (100).

4. **Eliminación**:
   - Se elimina el valor 20, lo que causa una reconfiguración del árbol.
   - Se muestra el estado del árbol después de la eliminación.
   - Se elimina la raíz original (10), lo que demuestra cómo el árbol maneja casos más complejos.
   - Se intenta eliminar un valor inexistente (100) para mostrar el manejo de errores.

En cada paso, el árbol mantiene sus propiedades de rojo-negro, asegurando que siga siendo balanceado y eficiente para todas las operaciones.

## Consideraciones Prácticas

Los árboles rojo-negro son ampliamente utilizados en implementaciones de diccionarios, conjuntos y mapas en muchas bibliotecas estándar de lenguajes de programación, como la librería estándar de C++ (map, set), Java (TreeMap, TreeSet), entre otros. Su capacidad para mantener un desempeño consistente en operaciones dinámicas los hace ideales para aplicaciones que requieren actualizaciones frecuentes mientras mantienen un acceso rápido a los datos.