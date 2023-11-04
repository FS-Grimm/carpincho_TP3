#ifndef ABB_H
#define ABB_H

#include <exception>
#include "NodoABBv2.hpp"

#include <queue>
class ABB_exception : public std::exception {
};
template<typename T, bool menor(T, T), bool igual(T, T)>
class ABB {
private:
  
    NodoABB<T, menor, igual>* raiz;
    std::size_t cantidad_datos;

    // Pre: -
    // Post: Agrega el dato al árbol.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    void alta(T dato, NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Elimina el dato del árbol y devuelve la nueva raiz, de haberla.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    void baja(T dato, NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Devuelve true si el dato está en el subárbol.
    bool consulta(T dato, NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido inorder.
    void inorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido preorder.
    void preorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido postorder.
    void postorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos);

    // Pre: -
    // Post: Ejecuta el método/función en el subárbol.
    void ejecutar(void metodo(T), NodoABB<T, menor, igual>* nodo_actual);
    
    // Pre: Debe tener sucesor o precesor, segun corresponda
    // Post: Reemplaza nodo actual con sucesor (true) o precesor(false)
    void reemplazar(bool sucesor,NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Devuelve precesor, o null si no tiene 
    NodoABB<T, menor, igual>* precesor(NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Devuelve sucesor, o null si no tiene
    NodoABB<T, menor, igual>* sucesor(NodoABB<T, menor, igual>* nodo_actual);
  
    void borrar_postorder(NodoABB<T, menor, igual>* borrado);

    NodoABB<T, menor, igual>* crear_nodo(T dato, NodoABB<T,menor,igual>* padre);

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
void ABB<T, menor, igual>::preorder(NodoABB<T, menor, igual> *nodo_actual, std::vector <T> &datos) {
    if(nodo_actual == nullptr){
        return;
    }
    datos.push_back(nodo_actual->dato);
    preorder(nodo_actual->hijo_izquierdo, datos);
    preorder(nodo_actual->hijo_derecho, datos);
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
std::vector <T> ABB<T, menor, igual>::preorder() {
    std::vector<T> datos;
    preorder(raiz, datos);
    return  datos;
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::alta(T dato, NodoABB<T, menor, igual> *nodo_actual) {
    if(menor(dato,nodo_actual->dato)) {
        if (nodo_actual->hijo_izquierdo)
            alta(dato, nodo_actual->hijo_izquierdo);
        else
            nodo_actual->hijo_izquierdo = this->crear_nodo(dato,nodo_actual);
    }else{
        if (nodo_actual->hijo_derecho)
            alta(dato, nodo_actual->hijo_derecho);
        else
            nodo_actual->hijo_derecho = this->crear_nodo(dato,nodo_actual);
    }
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::alta(T dato) {
    if(consulta(dato)) 
        throw ABB_exception();
    
    if (this->raiz != nullptr)
        alta(dato, raiz);
    else
        this->raiz = this->crear_nodo(dato,nullptr);

    cantidad_datos++;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T,menor,igual>* ABB<T, menor, igual>::crear_nodo(T dato, NodoABB<T,menor,igual>* padre){
    NodoABB<T,menor,igual>* nuevo = new NodoABB<T,menor,igual>;
    nuevo->dato = dato;
    nuevo->padre = padre;
    nuevo->hijo_derecho = nullptr;
    nuevo->hijo_izquierdo = nullptr;

    return nuevo;
}


template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB< T, menor, igual>::ancho(){
    std::vector<T> resultado;
    std::queue< NodoABB< T, menor , igual>* > cola;
    NodoABB<T,menor,igual>* nodo_parcial;

    if (this->raiz)
        cola.push(this->raiz);
    while (!cola.empty()){
        nodo_parcial = cola.front(); 
        cola.pop();

        resultado.push_back(nodo_parcial->dato);
        if (nodo_parcial->hijo_izquierdo)
            cola.push(nodo_parcial->hijo_izquierdo);
        if (nodo_parcial->hijo_derecho)
            cola.push(nodo_parcial->hijo_derecho);
    }

    return resultado;
};

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB< T, menor, igual>::postorder(){
    std::vector <T> resultado;
    if (this->raiz)
        this->postorder(this->raiz, resultado);    
    return resultado;
};

template<typename T, bool menor(T, T), bool igual(T, T)>
void ABB< T, menor, igual>::postorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos){
    if (nodo_actual->hijo_izquierdo)
        this->postorder(nodo_actual->hijo_izquierdo, datos);
    if (nodo_actual->hijo_derecho)
        this->postorder(nodo_actual->hijo_derecho, datos);

    datos.push_back(nodo_actual->dato);
};

template<typename T, bool menor(T, T), bool igual(T, T)>
bool ABB<T, menor, igual>::consulta(T dato) {
    if (this->raiz)
        return consulta(dato,this->raiz);
    else
        return false;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
bool ABB<T, menor, igual>::consulta(T dato, NodoABB<T, menor, igual> *nodo_actual) {
    if (igual(nodo_actual->dato, dato))
        return true;
    else if (menor (dato, nodo_actual->dato)){
        if (nodo_actual->hijo_izquierdo)
            return consulta(dato, nodo_actual->hijo_izquierdo);
        else 
            return false;
    }
    else{
        if (nodo_actual->hijo_derecho)
            return consulta(dato, nodo_actual->hijo_derecho);
        else 
            return false;
    }
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::inorder() {
    std::vector<T> ordenado;
    if (raiz)
        inorder(raiz, ordenado);
    return ordenado;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void ABB<T, menor, igual>::inorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos) {
    if (nodo_actual->hijo_izquierdo != nullptr)
        this->inorder(nodo_actual->hijo_izquierdo, datos);
    datos.push_back(nodo_actual->dato);
    if (nodo_actual->hijo_derecho != nullptr)
        this->inorder(nodo_actual->hijo_derecho, datos);
}


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
ABB<T, menor, igual>::ABB() {
    cantidad_datos=0;
    raiz= nullptr;
}


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
bool ABB<T, menor, igual>::vacio() {
    return ( !this->raiz );
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
std::size_t ABB<T, menor, igual>::tamanio() {
    return cantidad_datos;
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::borrar_postorder(NodoABB<T, menor, igual>* borrado) {
    if (!borrado){
        return;
    } else {
        borrar_postorder(borrado->hijo_izquierdo);
        borrar_postorder(borrado->hijo_derecho);
        delete borrado;
    }
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
ABB<T, menor, igual>::~ABB() {
    if (!raiz)
        return;
    else {
        NodoABB<T, menor, igual>* borrado=raiz;
        borrar_postorder(raiz);
    }
}


#endif
