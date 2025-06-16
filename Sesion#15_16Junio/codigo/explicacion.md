# Taller de Introducción a SQL

## 📋 Índice
1. [Introducción a SQL](#introducción-a-sql)
2. [Conceptos Fundamentales](#conceptos-fundamentales)
3. [Tipos de Datos](#tipos-de-datos)
4. [Comandos DDL (Data Definition Language)](#comandos-ddl-data-definition-language)
5. [Comandos DML (Data Manipulation Language)](#comandos-dml-data-manipulation-language)
6. [Comandos DQL (Data Query Language)](#comandos-dql-data-query-language)
7. [Relaciones entre Tablas](#relaciones-entre-tablas)
8. [Proyecto Práctico: Sistema de Inventario](#proyecto-práctico-sistema-de-inventario)

---

## 🔍 Introducción a SQL

**SQL (Structured Query Language)** es un lenguaje de programación diseñado para gestionar y manipular bases de datos relacionales. Es el estándar para trabajar con sistemas de gestión de bases de datos (SGBD) como MySQL, PostgreSQL, SQL Server, Oracle, entre otros.

### ¿Por qué aprender SQL?
- Es el lenguaje estándar para bases de datos relacionales
- Permite consultar, insertar, actualizar y eliminar datos
- Es fundamental en el desarrollo de aplicaciones
- Ampliamente utilizado en análisis de datos y business intelligence

---

## 🏗️ Conceptos Fundamentales

### Base de Datos
Una base de datos es una colección organizada de información estructurada que se almacena electrónicamente en un sistema informático.

### Tabla
Una tabla es una estructura que organiza datos en filas y columnas, similar a una hoja de cálculo.

### Registro (Fila)
Un registro es una entrada individual en una tabla que contiene datos relacionados.

### Campo (Columna)
Un campo es un atributo específico de los datos almacenados en una tabla.

### Clave Primaria (Primary Key)
Un campo o combinación de campos que identifica únicamente cada registro en una tabla.

### Clave Foránea (Foreign Key)
Un campo que crea una relación entre dos tablas, referenciando la clave primaria de otra tabla.

---

## 📊 Tipos de Datos

### Tipos Numéricos
- **INT**: Números enteros (-2,147,483,648 a 2,147,483,647)
- **DECIMAL(p,s)**: Números decimales con precisión fija
- **FLOAT**: Números de punto flotante

### Tipos de Texto
- **CHAR(n)**: Cadena de caracteres de longitud fija
- **VARCHAR(n)**: Cadena de caracteres de longitud variable
- **TEXT**: Texto largo

### Tipos de Fecha y Hora
- **DATE**: Fecha (YYYY-MM-DD)
- **TIME**: Hora (HH:MM:SS)
- **TIMESTAMP**: Fecha y hora completa
- **DATETIME**: Fecha y hora

### Otros Tipos
- **BOOLEAN**: Verdadero o falso
- **BLOB**: Datos binarios grandes

---

## 🔨 Comandos DDL (Data Definition Language)

Los comandos DDL se utilizan para definir y modificar la estructura de la base de datos.

### CREATE DATABASE
Crea una nueva base de datos.
```sql
CREATE DATABASE nombre_base_datos;
```

### USE
Selecciona una base de datos para trabajar.
```sql
USE nombre_base_datos;
```

### CREATE TABLE
Crea una nueva tabla.
```sql
CREATE TABLE nombre_tabla (
    campo1 TIPO_DATO restricciones,
    campo2 TIPO_DATO restricciones,
    ...
);
```

### ALTER TABLE
Modifica la estructura de una tabla existente.
```sql
ALTER TABLE nombre_tabla ADD COLUMN nuevo_campo TIPO_DATO;
ALTER TABLE nombre_tabla DROP COLUMN campo_existente;
ALTER TABLE nombre_tabla MODIFY COLUMN campo NUEVO_TIPO;
```

### DROP TABLE
Elimina una tabla completa.
```sql
DROP TABLE nombre_tabla;
```

---

## 📝 Comandos DML (Data Manipulation Language)

Los comandos DML se utilizan para manipular los datos dentro de las tablas.

### INSERT
Inserta nuevos registros en una tabla.
```sql
INSERT INTO tabla (campo1, campo2) VALUES (valor1, valor2);
INSERT INTO tabla VALUES (valor1, valor2, valor3);
```

### UPDATE
Actualiza registros existentes.
```sql
UPDATE tabla SET campo1 = nuevo_valor WHERE condición;
```

### DELETE
Elimina registros de una tabla.
```sql
DELETE FROM tabla WHERE condición;
```

---

## 🔍 Comandos DQL (Data Query Language)

### SELECT
El comando más importante de SQL para consultar datos.

#### Sintaxis Básica
```sql
SELECT campo1, campo2 FROM tabla;
SELECT * FROM tabla; -- Selecciona todos los campos
```

#### WHERE - Filtrado de Datos
```sql
SELECT * FROM tabla WHERE condición;
```

#### Operadores de Comparación
- `=` (igual)
- `!=` o `<>` (diferente)
- `>` (mayor que)
- `<` (menor que)
- `>=` (mayor o igual)
- `<=` (menor o igual)
- `BETWEEN` (entre dos valores)
- `IN` (dentro de una lista)
- `LIKE` (coincidencia de patrón)

#### ORDER BY - Ordenamiento
```sql
SELECT * FROM tabla ORDER BY campo ASC;  -- Ascendente
SELECT * FROM tabla ORDER BY campo DESC; -- Descendente
```

#### GROUP BY - Agrupación
```sql
SELECT campo, COUNT(*) FROM tabla GROUP BY campo;
```

#### Funciones de Agregación
- `COUNT()`: Cuenta registros
- `SUM()`: Suma valores
- `AVG()`: Promedio
- `MAX()`: Valor máximo
- `MIN()`: Valor mínimo

#### HAVING - Filtrado de Grupos
```sql
SELECT campo, COUNT(*) FROM tabla 
GROUP BY campo 
HAVING COUNT(*) > 1;
```

---

## 🔗 Relaciones entre Tablas

### INNER JOIN
Devuelve registros que tienen coincidencias en ambas tablas.
```sql
SELECT campos FROM tabla1
INNER JOIN tabla2 ON tabla1.campo = tabla2.campo;
```

### LEFT JOIN
Devuelve todos los registros de la tabla izquierda y los coincidentes de la derecha.
```sql
SELECT campos FROM tabla1
LEFT JOIN tabla2 ON tabla1.campo = tabla2.campo;
```

### RIGHT JOIN
Devuelve todos los registros de la tabla derecha y los coincidentes de la izquierda.
```sql
SELECT campos FROM tabla1
RIGHT JOIN tabla2 ON tabla1.campo = tabla2.campo;
```

### FULL OUTER JOIN
Devuelve registros cuando hay coincidencia en cualquiera de las tablas.
```sql
SELECT campos FROM tabla1
FULL OUTER JOIN tabla2 ON tabla1.campo = tabla2.campo;
```

---

## 💼 Proyecto Práctico: Sistema de Inventario

### Descripción del Proyecto
Desarrollaremos un sistema básico de inventario que permita gestionar productos, categorías, proveedores y entradas de mercancía.

### Diagrama de la Base de Datos
```
productos ←→ productos_categorias ←→ categorias
    ↓
entradas ←→ proveedores
```

### 1. Creación de la Base de Datos

```sql
CREATE DATABASE inventario;
USE inventario;
```

### 2. Creación de Tablas

#### Tabla productos
```sql
CREATE TABLE productos (
    id_producto INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(100) NOT NULL,
    descripcion TEXT,
    precio DECIMAL(10, 2) NOT NULL,
    stock INT NOT NULL
);
```

#### Tabla categorias
```sql
CREATE TABLE categorias (
    id_categoria INT PRIMARY KEY AUTO_INCREMENT,
    nombre_categoria VARCHAR(100) NOT NULL
);
```

#### Tabla productos_categorias (Relación muchos a muchos)
```sql
CREATE TABLE productos_categorias (
    id_producto INT,
    id_categoria INT,
    PRIMARY KEY (id_producto, id_categoria),
    FOREIGN KEY (id_producto) REFERENCES productos(id_producto),
    FOREIGN KEY (id_categoria) REFERENCES categorias(id_categoria)
);
```

#### Tabla proveedores
```sql
CREATE TABLE proveedores (
    id_proveedor INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(100) NOT NULL,
    telefono VARCHAR(20),
    correo VARCHAR(100)
);
```

#### Tabla entradas
```sql
CREATE TABLE entradas (
    id_entrada INT PRIMARY KEY AUTO_INCREMENT,
    id_producto INT,
    cantidad INT,
    fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    id_proveedor INT,
    FOREIGN KEY (id_producto) REFERENCES productos(id_producto),
    FOREIGN KEY (id_proveedor) REFERENCES proveedores(id_proveedor)
);
```

### 3. Inserción de Datos

#### Insertar categorías
```sql
INSERT INTO categorias (nombre_categoria) VALUES 
('Electrónica'), ('Oficina'), ('Hogar');
```

#### Insertar productos
```sql
INSERT INTO productos (nombre, descripcion, precio, stock) VALUES 
('Mouse Logitech', 'Mouse inalámbrico', 15.99, 100),
('Teclado HP', 'Teclado USB', 20.50, 50),
('Silla ergonómica', 'Silla de oficina con respaldo', 120.00, 10);
```

#### Insertar proveedores
```sql
INSERT INTO proveedores (nombre, telefono, correo) VALUES
('Distribuciones CR', '2222-1111', 'contacto@distribucionescr.com'),
('Tecnología XYZ', '2233-4444', 'ventas@xyz.com');
```

#### Insertar entradas
```sql
INSERT INTO entradas (id_producto, cantidad, id_proveedor) VALUES
(1, 50, 1),
(2, 20, 2),
(3, 5, 1);
```

#### Relacionar productos con categorías
```sql
INSERT INTO productos_categorias VALUES
(1, 1), (2, 1), (3, 2);
```

### 4. Consultas Básicas

#### Consultar todos los productos
```sql
SELECT * FROM productos;
```

#### Productos con sus categorías
```sql
SELECT p.nombre, c.nombre_categoria
FROM productos p
JOIN productos_categorias pc ON p.id_producto = pc.id_producto
JOIN categorias c ON c.id_categoria = pc.id_categoria;
```

#### Proveedores y cantidad de entregas
```sql
SELECT pr.nombre, COUNT(e.id_entrada) AS entregas
FROM proveedores pr
JOIN entradas e ON pr.id_proveedor = e.id_proveedor
GROUP BY pr.id_proveedor;
```

### 5. Actualización de Datos

#### Actualizar stock de un producto
```sql
UPDATE productos
SET stock = stock + 10
WHERE id_producto = 1;
```

### 6. Eliminación de Datos

#### Eliminar un producto
```sql
DELETE FROM productos WHERE id_producto = 3;
```

### 7. Consultas Avanzadas

#### Productos con stock bajo
```sql
SELECT nombre, stock FROM productos WHERE stock < 20;
```

#### Total de stock en inventario
```sql
SELECT SUM(stock) AS total_stock FROM productos;
```

#### Productos con entradas registradas (subconsulta)
```sql
SELECT nombre FROM productos
WHERE id_producto IN (
    SELECT id_producto FROM entradas
);
```

---


## 📚 Recursos Adicionales

### Mejores Prácticas
- Usar nombres descriptivos para tablas y campos
- Siempre usar WHERE en UPDATE y DELETE
- Hacer respaldos antes de modificaciones importantes
- Usar índices para mejorar el rendimiento
- Normalizar las tablas para evitar redundancia

### Comandos Útiles
```sql
DESCRIBE tabla;           -- Describe la estructura de una tabla
SHOW TABLES;             -- Muestra todas las tablas
SHOW DATABASES;          -- Muestra todas las bases de datos
```

### Funciones de Cadena
```sql
UPPER(campo)             -- Convierte a mayúsculas
LOWER(campo)             -- Convierte a minúsculas
LENGTH(campo)            -- Longitud de la cadena
SUBSTRING(campo, inicio, longitud) -- Extrae parte de la cadena
```

### Funciones de Fecha
```sql
NOW()                    -- Fecha y hora actual
CURDATE()               -- Fecha actual
CURTIME()               -- Hora actual
YEAR(fecha)             -- Extrae el año
MONTH(fecha)            -- Extrae el mes
DAY(fecha)              -- Extrae el día
```

---

## 🎓 Conclusión

SQL es una herramienta fundamental para cualquier profesional que trabaje con datos. Con los conceptos y ejemplos presentados en este taller, tienes las bases sólidas para comenzar a trabajar con bases de datos relacionales.

¡Practica regularmente y no dudes en experimentar con diferentes consultas para fortalecer tu comprensión de SQL!