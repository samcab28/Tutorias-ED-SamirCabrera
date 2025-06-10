# Algoritmos de Árbol de Expansión Mínima (MST)
## Teoría Completa: Kruskal y Prim

---

## 📚 **Tabla de Contenidos**
1. [Conceptos Fundamentales](#conceptos-fundamentales)
2. [Propiedades Matemáticas del MST](#propiedades-matemáticas-del-mst)
3. [Algoritmo de Kruskal](#algoritmo-de-kruskal)
4. [Algoritmo de Prim](#algoritmo-de-prim)
5. [Análisis Comparativo](#análisis-comparativo)
6. [Aplicaciones Prácticas](#aplicaciones-prácticas)
7. [Ejercicios y Ejemplos](#ejercicios-y-ejemplos)

---

## 🔍 **Conceptos Fundamentales**

### **¿Qué es un Árbol de Expansión Mínima?**

Un **Árbol de Expansión Mínima (MST - Minimum Spanning Tree)** de un grafo ponderado y conectado es un subgrafo que:

- **Conecta todos los vértices** del grafo original
- **Es un árbol** (no contiene ciclos)
- **Tiene el peso total mínimo** entre todos los árboles de expansión posibles

### **Propiedades de un Árbol**
- Un árbol con `n` vértices tiene exactamente `n-1` aristas
- Es conexo (existe un camino entre cualquier par de vértices)
- No contiene ciclos
- Eliminar cualquier arista lo desconecta
- Agregar cualquier arista crea exactamente un ciclo

### **Definiciones Clave**

- **Grafo Ponderado**: Grafo donde cada arista tiene un peso o costo asociado
- **Grafo Conectado**: Existe al menos un camino entre cualquier par de vértices
- **Corte**: Partición de los vértices del grafo en dos conjuntos disjuntos
- **Arista de Corte**: Arista que cruza un corte (conecta vértices de diferentes conjuntos)

---

## 🧮 **Propiedades Matemáticas del MST**

### **Teorema del Corte (Cut Property)**

> **Si en cualquier corte de un grafo, una arista tiene el peso mínimo entre todas las aristas que cruzan el corte, entonces esa arista pertenece a algún MST.**

**Demostración por contradicción:**
1. Supongamos que la arista `e` de peso mínimo en el corte no está en ningún MST
2. Sea `T` un MST cualquiera
3. Al agregar `e` a `T`, se forma exactamente un ciclo
4. Este ciclo debe contener otra arista `f` que cruza el mismo corte
5. Como `peso(e) ≤ peso(f)`, podemos reemplazar `f` por `e`
6. El nuevo árbol tiene peso menor o igual, contradiciendo que `T` era mínimo

### **Teorema del Ciclo (Cycle Property)**

> **Para cualquier ciclo en un grafo, la arista de mayor peso en el ciclo no puede estar en ningún MST.**

### **Unicidad del MST**

El MST es **único** si y solo si para cada corte del grafo, existe una única arista de peso mínimo que lo cruza.

---

## 🌲 **Algoritmo de Kruskal**

### **Idea Principal**
Kruskal usa un enfoque **greedy** basado en aristas: ordena todas las aristas por peso y las selecciona de menor a mayor, evitando formar ciclos.

### **Pseudocódigo Detallado**

```
ALGORITMO KRUSKAL(G):
    1. MST ← ∅
    2. Ordenar todas las aristas E por peso ascendente
    3. Inicializar Union-Find con todos los vértices
    4. 
    5. Para cada arista (u,v) en E ordenado:
        6. Si Find(u) ≠ Find(v):  // No forman ciclo
            7. MST ← MST ∪ {(u,v)}
            8. Union(u,v)
            9. Si |MST| = |V| - 1:
                10. BREAK  // Ya tenemos el MST completo
    11. 
    12. RETORNAR MST
```

### **Estructura Union-Find (Disjoint Set)**

La clave del algoritmo de Kruskal es la estructura **Union-Find**, que permite:

#### **Operaciones Principales:**
- **Find(x)**: Encuentra el representante del conjunto que contiene x
- **Union(x,y)**: Une los conjuntos que contienen x e y

#### **Optimizaciones:**

1. **Compresión de Camino (Path Compression)**
   ```cpp
   int find(int x) {
       if (parent[x] != x)
           parent[x] = find(parent[x]);  // Compresión
       return parent[x];
   }
   ```

2. **Unión por Rango (Union by Rank)**
   ```cpp
   void union(int x, int y) {
       int rootX = find(x), rootY = find(y);
       if (rank[rootX] < rank[rootY])
           parent[rootX] = rootY;
       else if (rank[rootX] > rank[rootY])
           parent[rootY] = rootX;
       else {
           parent[rootY] = rootX;
           rank[rootX]++;
       }
   }
   ```

### **Análisis de Complejidad - Kruskal**

- **Tiempo**: O(E log E) donde E = número de aristas
  - Ordenamiento: O(E log E)
  - Union-Find: O(E α(V)) ≈ O(E) donde α es la función inversa de Ackermann
- **Espacio**: O(V) para la estructura Union-Find

### **Correctitud de Kruskal**

**Invariante del Bucle**: En cada iteración, las aristas seleccionadas forman un bosque donde cada componente es un MST de los vértices que contiene.

**Demostración**: Se basa en el teorema del corte. Cada arista seleccionada es la de menor peso en el corte definido por las componentes conexas actuales.

---

## 🎯 **Algoritmo de Prim**

### **Idea Principal**
Prim usa un enfoque **greedy** basado en vértices: comienza desde un vértice y expande el árbol agregando la arista de menor peso que conecte un vértice del árbol con uno fuera de él.

### **Pseudocódigo Detallado**

```
ALGORITMO PRIM(G, r):  // r = vértice inicial
    1. MST ← ∅
    2. V_MST ← {r}  // Vértices en el MST
    3. Inicializar cola de prioridad Q con todas las aristas de r
    4. 
    5. Mientras |V_MST| < |V|:
        6. (u,v,peso) ← extraer mínimo de Q
        7. Si v ∉ V_MST:  // v no está en el MST
            8. MST ← MST ∪ {(u,v)}
            9. V_MST ← V_MST ∪ {v}
            10. Para cada arista (v,w) adyacente a v:
                11. Si w ∉ V_MST:
                    12. Insertar (v,w,peso) en Q
    13. 
    14. RETORNAR MST
```

### **Implementaciones de Prim**

#### **1. Con Lista de Adyacencia + Heap Binario**
- **Complejidad**: O(E log V)
- **Mejor para**: Grafos densos

#### **2. Con Matriz de Adyacencia + Búsqueda Lineal**
- **Complejidad**: O(V²)
- **Mejor para**: Grafos muy densos

#### **3. Con Heap de Fibonacci**
- **Complejidad**: O(E + V log V)
- **Mejor para**: Grafos dispersos (teóricamente)

### **Análisis de Complejidad - Prim**

**Con Heap Binario**:
- **Tiempo**: O(E log V)
  - Cada arista se inserta/extrae del heap: O(log V)
  - Total de operaciones: O(E)
- **Espacio**: O(V) para el heap y estructuras auxiliares

### **Correctitud de Prim**

**Invariante del Bucle**: En cada iteración, las aristas seleccionadas forman un MST del subgrafo inducido por los vértices visitados.

**Demostración**: Se basa en el teorema del corte. La arista de menor peso que cruza el corte entre vértices visitados y no visitados debe estar en el MST.

---

## ⚖️ **Análisis Comparativo**

### **Tabla Comparativa**

| Aspecto | Kruskal | Prim |
|---------|---------|------|
| **Enfoque** | Basado en aristas | Basado en vértices |
| **Estructura clave** | Union-Find | Cola de prioridad |
| **Complejidad** | O(E log E) | O(E log V) |
| **Mejor para** | Grafos dispersos | Grafos densos |
| **Inicio** | Global (todas las aristas) | Local (un vértice) |
| **Memoria** | O(V) | O(V) |

### **¿Cuándo usar cada uno?**

#### **Usar Kruskal cuando:**
- El grafo es **disperso** (E << V²)
- Necesitas **todas las aristas ordenadas**
- Implementación más **simple conceptualmente**
- Trabajas con **listas de aristas**

#### **Usar Prim cuando:**
- El grafo es **denso** (E ≈ V²)
- Tienes **lista de adyacencia eficiente**
- Quieres **construcción incremental**
- Necesitas el **árbol desde un vértice específico**

---

## 🌍 **Aplicaciones Prácticas**

### **1. Redes de Telecomunicaciones**
- **Problema**: Conectar todas las ciudades con cable de fibra óptica minimizando el costo
- **Solución**: MST donde los vértices son ciudades y las aristas son posibles conexiones con sus costos

### **2. Redes Eléctricas**
- **Problema**: Diseñar una red eléctrica que conecte todas las casas con el mínimo cableado
- **Solución**: MST donde el peso representa la distancia o costo del cableado

### **3. Clustering (Agrupamiento)**
- **Problema**: Agrupar datos similares
- **Solución**: Construir MST y eliminar las k-1 aristas más pesadas para obtener k clusters

### **4. Aproximación para TSP**
- **Problema**: Encontrar el tour más corto que visite todas las ciudades
- **Solución**: El MST da una aproximación 2-factor para el TSP métrico

### **5. Análisis de Imágenes**
- **Problema**: Segmentación de imágenes
- **Solución**: MST donde los píxeles son vértices y los pesos representan diferencias de intensidad

---

## 📝 **Ejercicios y Ejemplos**

### **Ejemplo Paso a Paso**

Consideremos el siguiente grafo:

```
    A ----4---- B
    |\          |\
    | \         | \
    2  \5       1  \3
    |   \       |   \
    |    \      |    \
    C ----6---- D ----7---- E
         1
```

**Aristas**: (A,B,4), (A,C,2), (A,D,5), (B,D,1), (B,E,3), (C,D,6), (D,E,7)

#### **Ejecución de Kruskal:**

1. **Ordenar aristas**: (B,D,1), (A,C,2), (B,E,3), (A,B,4), (A,D,5), (C,D,6), (D,E,7)
2. **Seleccionar (B,D,1)**: No hay ciclo → Agregar
3. **Seleccionar (A,C,2)**: No hay ciclo → Agregar
4. **Seleccionar (B,E,3)**: No hay ciclo → Agregar
5. **Seleccionar (A,B,4)**: No hay ciclo → Agregar
6. **Terminado**: 4 aristas para 5 vértices

**MST Kruskal**: {(B,D,1), (A,C,2), (B,E,3), (A,B,4)} con peso total = 10

#### **Ejecución de Prim (desde A):**

1. **Inicio**: V_MST = {A}, Q = {(A,B,4), (A,C,2), (A,D,5)}
2. **Seleccionar (A,C,2)**: V_MST = {A,C}, agregar aristas de C
3. **Seleccionar (A,B,4)**: V_MST = {A,C,B}, agregar aristas de B
4. **Seleccionar (B,D,1)**: V_MST = {A,C,B,D}, agregar aristas de D
5. **Seleccionar (B,E,3)**: V_MST = {A,C,B,D,E}

**MST Prim**: {(A,C,2), (A,B,4), (B,D,1), (B,E,3)} con peso total = 10

### **Ejercicios Propuestos**

#### **Ejercicio 1: Teórico**
Demuestra que si todos los pesos de las aristas de un grafo son distintos, entonces el MST es único.

#### **Ejercicio 2: Práctico**
Encuentra el MST del siguiente grafo usando ambos algoritmos:
```
Vértices: {1,2,3,4,5,6}
Aristas: (1,2,7), (1,3,9), (1,6,14), (2,3,10), (2,4,15), 
         (3,4,11), (3,6,2), (4,5,6), (5,6,9)
```

#### **Ejercicio 3: Análisis**
¿Cuál sería la complejidad de Prim si usáramos una búsqueda lineal en lugar de heap para encontrar la arista mínima?

---

## 🎓 **Conceptos Avanzados**

### **Variantes y Extensiones**

#### **1. MST Dinámico**
- **Problema**: Mantener el MST cuando se agregan/eliminan aristas
- **Solución**: Algoritmos especializados como Link-Cut Trees

#### **2. MST con Restricciones**
- **Grado acotado**: MST donde ningún vértice tiene grado mayor a k
- **MST dirigido**: Problema del árbol de expansión mínima en grafos dirigidos

#### **3. k-MST**
- **Problema**: Encontrar el árbol que conecte exactamente k vértices con peso mínimo
- **Aplicación**: Facility location problems

### **Optimizaciones Avanzadas**

#### **Algoritmo de Borůvka**
- **Complejidad**: O(E log V)
- **Paralelizable**: Cada componente puede trabajar independientemente
- **Histórico**: Primer algoritmo conocido para MST (1926)

#### **Algoritmo Lineal (Teórico)**
- **Karger-Klein-Tarjan**: O(V + E) en el modelo de comparación
- **Práctico**: Solo para casos muy específicos

---

## 📖 **Referencias y Lecturas Adicionales**

### **Libros Recomendados**
1. **Cormen, T. H.** - "Introduction to Algorithms" (Capítulo 23)
2. **Kleinberg, J.** - "Algorithm Design" (Capítulo 4)
3. **Sedgewick, R.** - "Algorithms" (Capítulo 4.3)

### **Papers Fundamentales**
1. **Kruskal, J. B.** (1956) - "On the shortest spanning subtree of a graph"
2. **Prim, R. C.** (1957) - "Shortest connection networks"
3. **Borůvka, O.** (1926) - "O jistém problému minimálním"

### **Recursos Online**
- Visualizaciones interactivas en VisuAlgo
- Implementaciones en GeeksforGeeks
- Problemas de práctica en LeetCode y HackerRank

---

## 🏆 **Conclusiones**

Los algoritmos de Kruskal y Prim son fundamentales en ciencias de la computación y tienen aplicaciones directas en problemas del mundo real. Su belleza radica en:

1. **Simplicidad conceptual**: Ambos usan estrategias greedy intuitivas
2. **Garantía de optimalidad**: Siempre encuentran la solución óptima
3. **Eficiencia práctica**: Complejidades razonables para grafos grandes
4. **Versatilidad**: Aplicables a diversos dominios de problemas

El dominio de estos algoritmos no solo es crucial para entender grafos, sino que también proporciona una base sólida para algoritmos más avanzados y problemas de optimización combinatoria.

---

*Desarrollado para profundizar el entendimiento teórico y práctico de los algoritmos MST. Para preguntas o aclaraciones adicionales, consultar las referencias proporcionadas.*