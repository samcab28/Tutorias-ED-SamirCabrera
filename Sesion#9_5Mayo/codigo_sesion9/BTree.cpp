#include "BTree.h"
#include <iostream>

// Constructor del nodo
BTreeNode::BTreeNode(bool isLeaf, int _t) : leaf(isLeaf), n(0), t(_t) {
    // Reservar espacio para el máximo número de claves y punteros a hijos
    keys.resize(2 * t - 1);
    if (!leaf) {
        children.resize(2 * t);
    }
}

// Destructor del nodo
BTreeNode::~BTreeNode() {
    if (!leaf) {
        for (int i = 0; i <= n; i++) {
            delete children[i];
        }
    }
}

// Busca una clave en el nodo actual y devuelve el índice
int BTreeNode::findKey(int key) {
    int idx = 0;
    while (idx < n && keys[idx] < key)
        ++idx;
    return idx;
}

// Recorrido inorden del nodo
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        // Si no es hoja, primero visitar el hijo izquierdo
        if (!leaf) {
            children[i]->traverse();
        }
        std::cout << " " << keys[i];
    }

    // Imprimir el último hijo
    if (!leaf) {
        children[i]->traverse();
    }
}

// Inserción en un nodo que no está lleno
void BTreeNode::insertNonFull(int key) {
    // Inicializar el índice como la posición más a la derecha
    int i = n - 1;

    // Si es una hoja, insertamos directamente
    if (leaf) {
        // Mover todas las claves mayores una posición a la derecha
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }

        // Insertar la nueva clave en la posición encontrada
        keys[i + 1] = key;
        n = n + 1;
    } else {
        // Encontrar el hijo donde debe ir la nueva clave
        while (i >= 0 && keys[i] > key)
            i--;

        // Comprobar si el hijo está lleno
        if (children[i + 1]->n == 2 * t - 1) {
            // Si está lleno, dividirlo
            splitChild(i + 1, children[i + 1]);

            // Después de dividir, la clave mediana sube y el nodo se divide en dos
            // Determinar cuál de los dos va a tener la nueva clave
            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Dividir un nodo hijo
void BTreeNode::splitChild(int index, BTreeNode* child) {
    // Crear un nuevo nodo que va a almacenar (t-1) claves del hijo
    BTreeNode* newNode = new BTreeNode(child->leaf, t);
    newNode->n = t - 1;

    // Copiar las últimas (t-1) claves del hijo al nuevo nodo
    for (int j = 0; j < t - 1; j++)
        newNode->keys[j] = child->keys[j + t];

    // Si el hijo no es hoja, copiar también los últimos t hijos
    if (!child->leaf) {
        for (int j = 0; j < t; j++)
            newNode->children[j] = child->children[j + t];
    }

    // Reducir el número de claves en el hijo original
    child->n = t - 1;

    // Hacer espacio para el nuevo hijo en el nodo actual
    for (int j = n; j >= index + 1; j--)
        children[j + 1] = children[j];

    // Enlazar el nuevo hijo en el nodo actual
    children[index + 1] = newNode;

    // Mover una clave del hijo actual al nodo actual
    for (int j = n - 1; j >= index; j--)
        keys[j + 1] = keys[j];

    // Copiar la clave media del hijo a este nodo
    keys[index] = child->keys[t - 1];

    // Incrementar el número de claves en este nodo
    n = n + 1;
}

// Constructor del árbol B
BTree::BTree(int _t) : t(_t) {
    root = new BTreeNode(true, t);
}

// Destructor del árbol B
BTree::~BTree() {
    delete root;
}

// Verifica si el árbol está vacío
bool BTree::isEmpty() {
    return (root->n == 0);
}

// Recorrido del árbol B
void BTree::traverse() {
    if (root != nullptr)
        root->traverse();
    std::cout << std::endl;
}

// Buscar una clave en el árbol B
bool BTree::search(int key) {
    if (root == nullptr)
        return false;
    
    BTreeNode* currentNode = root;
    while (currentNode != nullptr) {
        // Buscar la clave en el nodo actual
        int i = 0;
        while (i < currentNode->n && key > currentNode->keys[i])
            i++;

        // Si la clave se encuentra, retornar verdadero
        if (i < currentNode->n && key == currentNode->keys[i])
            return true;

        // Si el nodo es hoja, la clave no está en el árbol
        if (currentNode->leaf)
            return false;

        // Ir al hijo apropiado
        currentNode = currentNode->children[i];
    }
    
    return false;
}

// Insertar una clave en el árbol B
void BTree::insert(int key) {
    // Si el árbol está vacío
    if (root->n == 0) {
        root->keys[0] = key;
        root->n = 1;
    } else {
        // Si la raíz está llena, el árbol crece en altura
        if (root->n == 2 * t - 1) {
            // Crear una nueva raíz
            BTreeNode* newRoot = new BTreeNode(false, t);
            
            // La raíz actual se convierte en hijo de la nueva raíz
            newRoot->children[0] = root;
            
            // Dividir la antigua raíz y mover una clave a la nueva raíz
            newRoot->splitChild(0, root);
            
            // La nueva raíz tiene dos hijos. Decidimos cuál va a tener la nueva clave
            int i = 0;
            if (newRoot->keys[0] < key)
                i++;
            newRoot->children[i]->insertNonFull(key);
            
            // Cambiar la raíz
            root = newRoot;
        } else {
            // Si la raíz no está llena, llamar a insertNonFull
            root->insertNonFull(key);
        }
    }
}

// Eliminar una clave del árbol B
void BTree::remove(int key) {
    if (!root) {
        std::cout << "El árbol está vacío" << std::endl;
        return;
    }

    // Llamar a la función auxiliar para eliminar
    root->remove(key);

    // Si la raíz queda vacía y no es hoja, hacemos que su primer hijo sea la nueva raíz
    if (root->n == 0 && !root->leaf) {
        BTreeNode* tmp = root;
        root = root->children[0];
        delete tmp;
    }
}

// Eliminar una clave del nodo
void BTreeNode::remove(int key) {
    // Encontrar el índice de la clave
    int idx = findKey(key);

    // La clave a eliminar está presente en este nodo
    if (idx < n && keys[idx] == key) {
        // Caso 1: Si el nodo es hoja, simplemente eliminar la clave
        if (leaf)
            removeFromLeaf(idx);
        // Caso 2: Si el nodo no es hoja, se necesita un procedimiento más complejo
        else
            removeFromNonLeaf(idx);
    } else {
        // La clave no está en este nodo

        // Si este nodo es una hoja, la clave no está en el árbol
        if (leaf) {
            std::cout << "La clave " << key << " no existe en el árbol" << std::endl;
            return;
        }

        // La bandera indica si la clave está presente en el último hijo de este nodo
        bool flag = (idx == n);

        // Si el hijo donde debería estar la clave tiene menos del mínimo de claves
        if (children[idx]->n < t) {
            // Rellenarlo para que tenga al menos t claves
            fill(idx);
        }

        // Si el último hijo se ha fusionado, debemos recurrir al hijo (idx-1)
        if (flag && idx > n)
            children[idx-1]->remove(key);
        else
            children[idx]->remove(key);
    }
}

// Eliminar de un nodo hoja
void BTreeNode::removeFromLeaf(int idx) {
    // Mover todas las claves después de idx una posición hacia atrás
    for (int i = idx + 1; i < n; ++i)
        keys[i-1] = keys[i];

    // Reducir el número de claves
    n--;
}

// Eliminar de un nodo no hoja
void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];

    // Caso 3a: Si el hijo que precede a k tiene al menos t claves
    if (children[idx]->n >= t) {
        // Encontrar el predecesor de k
        int pred = getPred(idx);
        // Reemplazar k por el predecesor
        keys[idx] = pred;
        // Eliminar recursivamente el predecesor
        children[idx]->remove(pred);
    }
    // Caso 3b: Si el hijo que sigue a k tiene al menos t claves
    else if (children[idx+1]->n >= t) {
        // Encontrar el sucesor de k
        int succ = getSucc(idx);
        // Reemplazar k por el sucesor
        keys[idx] = succ;
        // Eliminar recursivamente el sucesor
        children[idx+1]->remove(succ);
    }
    // Caso 3c: Si ambos hijos tienen menos de t claves
    else {
        // Fusionar k y children[idx+1] en children[idx]
        merge(idx);
        // Eliminar k recursivamente del hijo fusionado
        children[idx]->remove(k);
    }
}

// Obtener el predecesor de keys[idx]
int BTreeNode::getPred(int idx) {
    // Ir al nodo más a la derecha del subárbol izquierdo
    BTreeNode* cur = children[idx];
    while (!cur->leaf)
        cur = cur->children[cur->n];

    // Retornar la última clave
    return cur->keys[cur->n-1];
}

// Obtener el sucesor de keys[idx]
int BTreeNode::getSucc(int idx) {
    // Ir al nodo más a la izquierda del subárbol derecho
    BTreeNode* cur = children[idx+1];
    while (!cur->leaf)
        cur = cur->children[0];

    // Retornar la primera clave
    return cur->keys[0];
}

// Rellenar children[idx] que tiene menos de t-1 claves
void BTreeNode::fill(int idx) {
    // Si el hermano anterior tiene claves suficientes
    if (idx != 0 && children[idx-1]->n >= t)
        borrowFromPrev(idx);
    // Si el hermano siguiente tiene claves suficientes
    else if (idx != n && children[idx+1]->n >= t)
        borrowFromNext(idx);
    // Fusionar con un hermano
    else {
        if (idx != n)
            merge(idx);
        else
            merge(idx-1);
    }
}

// Obtener una clave del hermano anterior
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx-1];

    // Mover todas las claves en child una posición adelante
    for (int i = child->n-1; i >= 0; --i)
        child->keys[i+1] = child->keys[i];

    // Si child no es hoja, mover también todos los punteros a hijos
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->children[i+1] = child->children[i];
    }

    // Colocar la clave idx-1 del nodo actual en la primera posición del hijo
    child->keys[0] = keys[idx-1];

    // Mover el último hijo del hermano como el primer hijo de child
    if (!child->leaf)
        child->children[0] = sibling->children[sibling->n];

    // Mover la clave más a la derecha del hermano a este nodo
    keys[idx-1] = sibling->keys[sibling->n-1];

    // Incrementar y decrementar los contadores de claves
    child->n += 1;
    sibling->n -= 1;
}

// Obtener una clave del hermano siguiente
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx+1];

    // La clave idx del nodo actual se inserta como la última clave en child
    child->keys[child->n] = keys[idx];

    // El primer hijo del hermano se mueve como el último hijo de child
    if (!child->leaf)
        child->children[child->n+1] = sibling->children[0];

    // La primera clave del hermano se mueve a keys[idx]
    keys[idx] = sibling->keys[0];

    // Mover todas las claves en el hermano una posición atrás
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    // Mover los punteros a hijos una posición atrás
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->children[i-1] = sibling->children[i];
    }

    // Incrementar y decrementar los contadores de claves
    child->n += 1;
    sibling->n -= 1;
}

// Fusionar children[idx] con children[idx+1]
void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx+1];

    // Insertar la clave del nodo actual en la posición t-1 del hijo
    child->keys[t-1] = keys[idx];

    // Copiar las claves del hermano al hijo
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i+t] = sibling->keys[i];

    // Copiar los punteros a hijos del hermano al hijo
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->children[i+t] = sibling->children[i];
    }

    // Mover todas las claves después de idx una posición atrás
    for (int i = idx+1; i < n; ++i)
        keys[i-1] = keys[i];

    // Mover los punteros a hijos una posición atrás
    for (int i = idx+2; i <= n; ++i)
        children[i-1] = children[i];

    // Actualizar el número de claves
    child->n += sibling->n + 1;
    n--;

    // Liberar la memoria del hermano
    delete sibling;
}