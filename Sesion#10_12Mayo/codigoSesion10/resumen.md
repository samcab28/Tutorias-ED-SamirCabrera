# Documentación: Generador de Reportes PDF con libHaru

## Descripción General

Esta librería proporciona una interfaz simplificada para generar reportes en formato PDF utilizando la biblioteca libHaru. Está diseñada para crear documentos PDF profesionales de forma programática, sin necesidad de una interfaz gráfica. La librería es especialmente útil para:

- Generación de reportes de inventario
- Facturas y documentos comerciales
- Informes financieros
- Cualquier documento tabular que requiera presentación profesional

## Requisitos

- **libHaru**: Biblioteca base para manipulación de archivos PDF
- **Compilador C++**: Compatible con C++11 o superior
- **Compilación**: `g++ -o report_generator report_generator.cpp -lhpdf`

## Estructura Principal

La librería está compuesta por:

1. **Clase `GeneradorReportes`**: Clase principal para la creación de reportes
2. **Estructura `Producto`**: Estructura de ejemplo para almacenar datos
3. **Funciones auxiliares**: Para manejo de errores y formateo de fecha/hora

## Estructura de Datos

### Estructura `Producto`

```cpp
struct Producto {
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    double total;
};
```

Esta estructura se utiliza como ejemplo para demostrar la generación de reportes basados en una colección de datos estructurados.

## Clase `GeneradorReportes`

### Métodos Públicos

| Método | Descripción |
|--------|-------------|
| `GeneradorReportes()` | Constructor por defecto |
| `~GeneradorReportes()` | Destructor que libera recursos de libHaru |
| `generar_reporte_productos()` | Genera un reporte basado en una colección de productos |

### Método `generar_reporte_productos`

```cpp
void generar_reporte_productos(
    const std::vector<Producto>& productos, 
    const std::string& nombre_archivo,
    const std::string& titulo_reporte,
    const std::string& nombre_empresa
);
```

#### Parámetros:
- `productos`: Vector con los datos de productos a incluir en el reporte
- `nombre_archivo`: Nombre del archivo PDF a generar (incluyendo extensión .pdf)
- `titulo_reporte`: Título que aparecerá en la parte superior del reporte
- `nombre_empresa`: Nombre de la empresa para el pie de página

#### Funcionalidad:
Genera un archivo PDF completo que incluye:
- Encabezado con título y fecha actual
- Tabla de datos formateada con los productos
- Cálculo automático del total general
- Pie de página con información de la empresa

### Métodos Privados

#### `inicializar_documento()`
Configura el documento PDF inicial, creando la página y estableciendo las fuentes básicas.

#### `agregar_encabezado(const std::string& titulo_reporte)`
Agrega un encabezado al reporte que incluye:
- Título centrado en fuente grande y negrita
- Fecha y hora actual del sistema

#### `agregar_tabla(const std::vector<Producto>& productos)`
Crea una tabla formateada con los datos de productos, incluyendo:
- Encabezados de columna
- Datos de cada producto
- Manejo automático de saltos de página
- Líneas separadoras
- Cálculo y visualización del total general

#### `agregar_pie_pagina(const std::string& nombre_empresa)`
Agrega un pie de página con:
- Nombre de la empresa
- Numeración de página simple
- Texto de "Reporte generado automáticamente"

## Funciones Auxiliares

### `error_handler()`
```cpp
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data);
```
Maneja los errores de libHaru, mostrando información y lanzando excepciones cuando es necesario.

### `obtener_fecha_actual()`
```cpp
std::string obtener_fecha_actual();
```
Devuelve una cadena formateada con la fecha y hora actuales del sistema en formato "DD/MM/AAAA HH:MM:SS".

## Ejemplo de Uso

```cpp
// Crear datos
std::vector<Producto> productos = {
    {1, "Laptop HP ProBook", 899.99, 3, 899.99 * 3},
    {2, "Monitor Dell 27\"", 299.50, 5, 299.50 * 5}
    // Más productos...
};

// Generar el reporte
GeneradorReportes generador;
generador.generar_reporte_productos(
    productos,
    "reporte_inventario.pdf",
    "Reporte de Inventario",
    "Mi Empresa S.A."
);
```

## Características Principales

- **Manejo de páginas múltiples**: Creación automática de nuevas páginas cuando la tabla excede el espacio
- **Formateo profesional**: Alineación correcta de textos y datos numéricos
- **Cálculos automáticos**: Suma y presenta el total general de los productos
- **Gestión de errores**: Sistema robusto de manejo de errores con excepciones
- **Personalización**: Fácil adaptación para mostrar diferentes tipos de datos

## Limitaciones Actuales

- Soporte limitado para múltiples páginas (no incluye numeración dinámica)
- No permite personalización de colores y estilos avanzados
- No implementa gráficos o imágenes
- La estructura de datos está acoplada al ejemplo de productos

## Posibles Mejoras

- Agregar soporte para gráficos y visualizaciones
- Implementar personalización de colores y estilos
- Mejorar la gestión de numeración de páginas
- Crear interfaces genéricas para diferentes tipos de datos
- Añadir soporte para imágenes y logos

## Referencias

- [Documentación oficial de libHaru](https://github.com/libharu/libharu)
- [Tutorial de libHaru](http://libharu.sourceforge.net/documentation.html)