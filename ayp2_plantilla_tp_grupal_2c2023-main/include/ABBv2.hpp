#ifndef ABB_H
#define ABB_H

#include <exception>
#include "NodoABBv2.hpp"

class ABB_exception : public std::exception {
};
template<typename T, bool menor(T, T), bool igual(T, T)>
class ABB {
private:
    typedef NodoABB<T, menor, igual>* NodoABB;
    NodoABB raiz;
    std::size_t cantidad_datos;

    // Pre: -
    // Post: Agrega el dato al árbol.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    void alta(T dato, NodoABB nodo_actual);

    // Pre: -
    // Post: Elimina el dato del árbol y devuelve la nueva raiz, de haberla.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    void baja(T dato, NodoABB nodo_actual);

    // Pre: -
    // Post: Devuelve true si el dato está en el subárbol.
    bool consulta(T dato, NodoABB nodo_actual);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido inorder.
    void inorder(NodoABB nodo_actual, std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido preorder.
    void preorder(NodoABB nodo_actual, std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido postorder.
    void postorder(NodoABB nodo_actual, std::vector<T>& datos);

    // Pre: -
    // Post: Ejecuta el método/función en el subárbol.
    void ejecutar(void metodo(T), NodoABB nodo_actual);

    void borrar_postorder(NodoABB borrado);

public:
    // Constructor.
    ABB();

    // Pre: El dato a ingresar no puede estar en el árbol.
    // Post: Agrega el dato al árbol. Si no hay datos, crea una nueva raiz.
    void alta(T dato);

    // Pre: -
    // Post: Elimina el dato del árbol. Si no existe, no hace nada.
    // NOTA: Si la raiz cambia (sin importar el caso), se debe reasignar correctamente.
    void baja(T dato);

    // Pre: -
    // Post: Devuelve true si el dato está en el árbol. Si no hay datos, devuelve false.
    bool consulta(T dato);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    std::vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    std::vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    std::vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho.
    std::vector<T> ancho();

    // Pre: -
    // Post: Ejecuta el método/función en cada uno de los nodos.
    // NOTA: No abusar de este método, está solamente para simplificar
    // algunas cosas, como liberar la memoria de los nodos de usar punteros
    // o imprimir por pantalla el contenido. Pueden usar cualquier recorrido.
    void ejecutar(void metodo(T));

    // Pre: -
    // Post: Devuelve la cantidad de datos en el árbol.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el árbol está vacio.
    bool vacio();

    // El constructor de copia está deshabilitado.
    ABB(const ABB& abb) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const ABB& abb) = delete;

    // Destructor.
    ~ABB();



};

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::borrar_postorder(NodoABB borrado) {
    if (!borrado){
        return;
    } else {
        borrar_postorder(borrado->hijo_izquierdo);
        borrar_postorder(borrado->hijo_derecho);
        delete borrado;
    }
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
ABB<T, menor, igual>::ABB() {
    cantidad_datos=0;
    raiz= nullptr;
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
ABB<T, menor, igual>::~ABB() {
    //postorder( delete nodo);
    if (!raiz)
        return;
    else {
        NodoABB borrado=raiz;
        borrar_postorder();
    }
}


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
bool ABB<T, menor, igual>::vacio() {
    return raiz== nullptr;
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
std::size_t ABB<T, menor, igual>::tamanio() {
    return cantidad_datos;
}

#endif