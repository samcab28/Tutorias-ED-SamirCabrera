/**
 * Ejemplo de generación de reportes en C++ usando libHaru
 * 
 * Este ejemplo muestra cómo generar reportes PDF en C++ de forma programática
 * sin utilizar una interfaz gráfica, similar a Fast Report pero vía código.
 * 
 * Requisitos:
 * - libharu (https://github.com/libharu/libharu)
 * - Compilación: g++ -o report_generator report_generator.cpp -lhpdf
 */

#include <hpdf.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

// Estructura para almacenar los datos del producto (ejemplo)
struct Producto {
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    double total;
};

// Función para manejar errores de libHaru
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data) {
    std::cerr << "ERROR: error_no=" << (unsigned int)error_no << ", detail_no=" << (unsigned int)detail_no << std::endl;
    throw std::runtime_error("Error en la generación del PDF");
}

// Obtener la fecha actual formateada
std::string obtener_fecha_actual() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d/%m/%Y %H:%M:%S");
    return oss.str();
}

// Clase para generar reportes
class GeneradorReportes {
private:
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    HPDF_Font font_bold;
    float page_width;
    float page_height;
    float current_y;
    
    // Inicializar el documento PDF
    void inicializar_documento() {
        pdf = HPDF_New(error_handler, NULL);
        if (!pdf) {
            throw std::runtime_error("No se pudo crear el documento PDF");
        }
        
        // Configuración del documento
        HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
        
        // Crear una página
        page = HPDF_AddPage(pdf);
        HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
        
        // Obtener dimensiones de la página
        page_width = HPDF_Page_GetWidth(page);
        page_height = HPDF_Page_GetHeight(page);
        current_y = page_height - 60;
        
        // Configurar fuentes
        font = HPDF_GetFont(pdf, "Helvetica", NULL);
        font_bold = HPDF_GetFont(pdf, "Helvetica-Bold", NULL);
    }
    
    // Agregar encabezado al reporte
    void agregar_encabezado(const std::string& titulo_reporte) {
        HPDF_Page_SetFontAndSize(page, font_bold, 16);
        HPDF_Page_BeginText(page);
        
        // Título centrado
        float texto_ancho = HPDF_Page_TextWidth(page, titulo_reporte.c_str());
        HPDF_Page_TextOut(page, (page_width - texto_ancho) / 2, current_y, titulo_reporte.c_str());
        HPDF_Page_EndText(page);
        
        current_y -= 30;
        
        // Fecha del reporte
        std::string fecha = "Fecha: " + obtener_fecha_actual();
        HPDF_Page_SetFontAndSize(page, font, 10);
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, 50, current_y, fecha.c_str());
        HPDF_Page_EndText(page);
        
        current_y -= 20;
    }
    
    // Agregar tabla con datos al reporte
    void agregar_tabla(const std::vector<Producto>& productos) {
        // Encabezados de la tabla
        float columnas[] = {50, 200, 100, 80, 100};
        float pos_x = 50;
        
        // Dibujar encabezados
        HPDF_Page_SetFontAndSize(page, font_bold, 10);
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, pos_x, current_y, "ID");
        pos_x += columnas[0];
        HPDF_Page_TextOut(page, pos_x, current_y, "Producto");
        pos_x += columnas[1];
        HPDF_Page_TextOut(page, pos_x, current_y, "Precio");
        pos_x += columnas[2];
        HPDF_Page_TextOut(page, pos_x, current_y, "Cantidad");
        pos_x += columnas[3];
        HPDF_Page_TextOut(page, pos_x, current_y, "Total");
        HPDF_Page_EndText(page);
        
        current_y -= 15;
        
        // Línea separadora
        HPDF_Page_MoveTo(page, 50, current_y);
        HPDF_Page_LineTo(page, 530, current_y);
        HPDF_Page_Stroke(page);
        
        current_y -= 15;
        
        // Agregar datos
        HPDF_Page_SetFontAndSize(page, font, 10);
        
        double suma_total = 0;
        
        for (const auto& producto : productos) {
            // Comprobar si necesitamos una nueva página
            if (current_y < 100) {
                page = HPDF_AddPage(pdf);
                HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
                current_y = page_height - 60;
            }
            
            pos_x = 50;
            
            HPDF_Page_BeginText(page);
            
            // ID
            std::string id_str = std::to_string(producto.id);
            HPDF_Page_TextOut(page, pos_x, current_y, id_str.c_str());
            pos_x += columnas[0];
            
            // Nombre
            HPDF_Page_TextOut(page, pos_x, current_y, producto.nombre.c_str());
            pos_x += columnas[1];
            
            // Precio
            std::ostringstream precio_stream;
            precio_stream << std::fixed << std::setprecision(2) << "$" << producto.precio;
            HPDF_Page_TextOut(page, pos_x, current_y, precio_stream.str().c_str());
            pos_x += columnas[2];
            
            // Cantidad
            std::string cantidad_str = std::to_string(producto.cantidad);
            HPDF_Page_TextOut(page, pos_x, current_y, cantidad_str.c_str());
            pos_x += columnas[3];
            
            // Total
            std::ostringstream total_stream;
            total_stream << std::fixed << std::setprecision(2) << "$" << producto.total;
            HPDF_Page_TextOut(page, pos_x, current_y, total_stream.str().c_str());
            
            HPDF_Page_EndText(page);
            
            current_y -= 20;
            suma_total += producto.total;
        }
        
        // Línea final
        current_y -= 10;
        HPDF_Page_MoveTo(page, 50, current_y);
        HPDF_Page_LineTo(page, 530, current_y);
        HPDF_Page_Stroke(page);
        
        current_y -= 20;
        
        // Total general
        std::ostringstream total_general;
        total_general << std::fixed << std::setprecision(2) << "$" << suma_total;
        
        HPDF_Page_SetFontAndSize(page, font_bold, 10);
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, 380, current_y, "Total General:");
        HPDF_Page_TextOut(page, 480, current_y, total_general.str().c_str());
        HPDF_Page_EndText(page);
    }
    
    // Agregar pie de página
    void agregar_pie_pagina(const std::string& nombre_empresa) {
        float footer_y = 30;
        
        HPDF_Page_SetFontAndSize(page, font, 8);
        HPDF_Page_BeginText(page);
        
        std::string footer_text = nombre_empresa + " - Reporte por Samir";
        float texto_ancho = HPDF_Page_TextWidth(page, footer_text.c_str());
        HPDF_Page_TextOut(page, (page_width - texto_ancho) / 2, footer_y, footer_text.c_str());
        
        HPDF_Page_EndText(page);
        
        // Agregar numeración de página estática (ya que no podemos obtener el índice fácilmente)
        std::string page_text = "Pagina 1"; // Versión simplificada
        
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, page_width - 80, footer_y, page_text.c_str());
        HPDF_Page_EndText(page);
    }
    
public:
    GeneradorReportes() {}
    
    ~GeneradorReportes() {
        if (pdf) {
            HPDF_Free(pdf);
        }
    }
    
    // Generar un reporte de productos
    void generar_reporte_productos(const std::vector<Producto>& productos, 
                                  const std::string& nombre_archivo,
                                  const std::string& titulo_reporte,
                                  const std::string& nombre_empresa) {
        try {
            inicializar_documento();
            agregar_encabezado(titulo_reporte);
            agregar_tabla(productos);
            agregar_pie_pagina(nombre_empresa);
            
            // Guardar el PDF
            HPDF_SaveToFile(pdf, nombre_archivo.c_str());
            std::cout << "Reporte generado exitosamente: " << nombre_archivo << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error al generar el reporte: " << e.what() << std::endl;
            if (pdf) {
                HPDF_Free(pdf);
                pdf = nullptr;
            }
        }
    }
};

int main() {
    // Datos de ejemplo (simulando datos de una base de datos o JSON)
    std::vector<Producto> productos = {
        {1, "Laptop HP ProBook", 899.99, 3, 899.99 * 3},
        {2, "Monitor Dell 27\"", 299.50, 5, 299.50 * 5},
        {3, "Teclado Mecánico RGB", 89.99, 10, 89.99 * 10},
        {4, "Mouse Inalámbrico", 24.99, 15, 24.99 * 15},
        {5, "Disco SSD 1TB", 129.99, 8, 129.99 * 8},
        {6, "Memoria RAM 16GB", 75.50, 12, 75.50 * 12},
        {7, "Tarjeta Gráfica RTX 3070", 599.99, 2, 599.99 * 2},
        {8, "Audífonos Bluetooth", 59.99, 7, 59.99 * 7},
        {9, "Webcam HD", 45.00, 5, 45.00 * 5},
        {10, "Router WiFi 6", 120.00, 4, 120.00 * 4}
    };
    
    // Crear generador de reportes e imprimir un reporte
    GeneradorReportes generador;
    generador.generar_reporte_productos(
        productos,
        "reporte_inventario.pdf",
        "Reporte de Inventario",
        "Mi Empresa S.A."
    );
    
    return 0;
}