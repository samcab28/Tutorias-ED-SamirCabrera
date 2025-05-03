#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>

// Nodo del árbol B
class BTreeNode {
public:
    std::vector<int> keys;           // Arreglo de claves
    std::vector<BTreeNode*> children; // Punteros a los hijos
    bool leaf;                       // Indica si el nodo es hoja o no
    int n;                           // Número actual de claves
    int t;                           // Grado mínimo

    // Constructor del nodo
    BTreeNode(bool isLeaf = true, int _t = 2);
    
    // Destructor
    ~BTreeNode();

    // Busca una clave en el nodo actual
    int findKey(int key);
    
    // Inserta una clave en un nodo que no está lleno
    void insertNonFull(int key);
    
    // Divide un nodo hijo lleno
    void splitChild(int index, BTreeNode* child);
    
    // Elimina una clave del nodo
    void remove(int key);
    
    // Elimina una clave del nodo en posición idx
    void removeFromLeaf(int idx);
    
    // Elimina una clave del nodo interno en posición idx
    void removeFromNonLeaf(int idx);
    
    // Obtiene el predecesor de keys[idx]
    int getPred(int idx);
    
    // Obtiene el sucesor de keys[idx]
    int getSucc(int idx);
    
    // Rellena el nodo hijo children[idx] que tiene menos de t-1 claves
    void fill(int idx);
    
    // Obtiene una clave del nodo hermano a la izquierda y la inserta en children[idx]
    void borrowFromPrev(int idx);
    
    // Obtiene una clave del nodo hermano a la derecha y la inserta en children[idx]
    void borrowFromNext(int idx);
    
    // Fusiona children[idx] con children[idx+1]
    void merge(int idx);
    
    // Imprime el nodo y sus hijos (recorrido inorden)
    void traverse();
};

// Clase principal del árbol B
class BTree {
private:
    BTreeNode* root; // Raíz del árbol B
    int t;           // Grado mínimo del árbol B

public:
    // Constructor
    BTree(int _t);
    
    // Destructor
    ~BTree();
    
    // Inserta una clave en el árbol B
    void insert(int key);
    
    // Elimina una clave del árbol B
    void remove(int key);
    
    // Busca una clave en el árbol B
    bool search(int key);
    
    // Imprime el árbol B (recorrido inorden)
    void traverse();
    
    // Verifica si el árbol está vacío
    bool isEmpty();
};

#endif