INSERT INTO categorias (nombre_categoria) VALUES 
('Electrónica'), ('Oficina'), ('Hogar');

INSERT INTO productos (nombre, descripcion, precio, stock) VALUES 
('Mouse Logitech', 'Mouse inalámbrico', 15.99, 100),
('Teclado HP', 'Teclado USB', 20.50, 50),
('Silla ergonómica', 'Silla de oficina con respaldo', 120.00, 10);

INSERT INTO proveedores (nombre, telefono, correo) VALUES
('Distribuciones CR', '2222-1111', 'contacto@distribucionescr.com'),
('Tecnología XYZ', '2233-4444', 'ventas@xyz.com');

INSERT INTO entradas (id_producto, cantidad, id_proveedor) VALUES
(1, 50, 1),
(2, 20, 2),
(3, 5, 1);

INSERT INTO productos_categorias VALUES
(1, 1), (2, 1), (3, 2);
