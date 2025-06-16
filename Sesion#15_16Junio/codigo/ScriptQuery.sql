SELECT * FROM productos;


SELECT p.nombre, c.nombre_categoria
FROM productos p
JOIN productos_categorias pc ON p.id_producto = pc.id_producto
JOIN categorias c ON c.id_categoria = pc.id_categoria;


SELECT pr.nombre, COUNT(e.id_entrada) AS entregas
FROM proveedores pr
JOIN entradas e ON pr.id_proveedor = e.id_proveedor
GROUP BY pr.id_proveedor;



UPDATE productos
SET stock = stock + 10
WHERE id_producto = 1;



DELETE FROM productos WHERE id_producto = 3;


SELECT nombre, stock FROM productos WHERE stock < 20;

SELECT SUM(stock) AS total_stock FROM productos;

SELECT nombre FROM productos
WHERE id_producto IN (
    SELECT id_producto FROM entradas
);
