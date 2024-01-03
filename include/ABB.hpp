    #ifndef ABB_H
#define ABB_H

#include <exception>
#include "NodoABB.hpp"

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
    // Post: Elimina el dato del árbol y devuelve la nueva raiz, de haberla.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    void baja(NodoABB<T, menor, igual>* nodo_actual);


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
    //void ejecutar(void metodo(T), NodoABB<T, menor, igual>* nodo_actual);
    
    // Pre: Tiene un solo hijo
    // Post: Reapuntado de nodos como lista doble enlazada
    void reapuntar_padre_hijo( NodoABB<T, menor, igual>* nodo);

    // Pre: -
    // Post: Intercambia nodo viejo con nuevo. Nodo viejo queda sin hijos 
    void intercambiar_nodo( NodoABB<T, menor, igual>* nodo_viejo, NodoABB<T, menor, igual>* nodo_nuevo);

    // Pre: -
    // Post: Devuelve sucesor, o null si no tiene
    NodoABB<T, menor, igual>* sucesor(NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Devuelve precesor, o null si no tiene
    NodoABB<T, menor, igual>* precesor(NodoABB<T, menor, igual>* nodo_actual);

    // Pre: -
    // Post: Elimina nodos alocados
    void borrar_postorder(NodoABB<T, menor, igual>* borrado);

    // Pre: -
    // Post: Crea nodo nuevo, asignando dato y padre
    NodoABB<T, menor, igual>* crear_nodo(T dato, NodoABB<T,menor,igual>* padre);

    // Pre: Nodo Valido 
    // Post: Devuelve altura del sub-arbol
    size_t altura(NodoABB<T,menor,igual>* nodo);

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
    //void ejecutar(void metodo(T));

    // Pre: -
    // Post: Devuelve la cantidad de datos en el árbol.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el árbol está vacio.
    bool vacio();

    // Pre: -
    // Post: Devuelve altura del arbol
    size_t altura();

    // El constructor de copia está deshabilitado.
    ABB(const ABB& abb) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const ABB& abb) = delete;

    // Destructor.
    ~ABB();

};


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
ABB<T, menor, igual>::ABB() {
    this->cantidad_datos = 0;
    this->raiz = nullptr;

}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
bool ABB<T, menor, igual>::vacio() {
    return !this->raiz;

}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
std::size_t ABB<T, menor, igual>::tamanio() {
    return this->cantidad_datos;

}

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
    

    if (this->raiz)
        alta(dato, this->raiz);
    else
        this->raiz = crear_nodo(dato,nullptr);

    this->cantidad_datos++;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T,menor,igual>* ABB<T, menor, igual>::crear_nodo(T dato, NodoABB<T,menor,igual>* padre){
//TAREA: HACER INTERNO DE NODO
    auto nuevo = new NodoABB<T,menor,igual>;
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
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::preorder(NodoABB<T, menor, igual> *nodo_actual, std::vector <T> &datos) {
    datos.push_back(nodo_actual->dato);
    if (nodo_actual->hijo_izquierdo)
        preorder(nodo_actual->hijo_izquierdo, datos);
    if (nodo_actual->hijo_derecho)
        preorder(nodo_actual->hijo_derecho, datos);

}


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
std::vector <T> ABB<T, menor, igual>::preorder() {
    std::vector<T> datos;
    if(this->raiz)
        preorder(this->raiz, datos);

    return  datos;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void ABB<T, menor, igual>::inorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos) {
    if (nodo_actual->hijo_izquierdo)
        inorder(nodo_actual->hijo_izquierdo, datos);
    datos.push_back(nodo_actual->dato);
    if (nodo_actual->hijo_derecho)

        this->inorder(nodo_actual->hijo_derecho, datos);
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::inorder() {
    std::vector<T> datos;
    if (this->raiz)
        inorder(this->raiz, datos);
    return datos;
}


template<typename T, bool menor(T, T), bool igual(T, T)>
void ABB< T, menor, igual>::postorder(NodoABB<T, menor, igual>* nodo_actual, std::vector<T>& datos){
    if (nodo_actual->hijo_izquierdo)
        this->postorder(nodo_actual->hijo_izquierdo, datos);
    if (nodo_actual->hijo_derecho)
        this->postorder(nodo_actual->hijo_derecho, datos);

    datos.push_back(nodo_actual->dato);
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB< T, menor, igual>::postorder() {
    std::vector<T> datos;
    if (this->raiz)
        this->postorder(this->raiz, datos);
    return datos;
}


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
NodoABB<T, menor, igual> *ABB<T, menor, igual>::sucesor(NodoABB<T, menor, igual> *nodo_actual) {
    if(!nodo_actual->hijo_izquierdo){
        return nodo_actual;
    }else
        return sucesor(nodo_actual->hijo_izquierdo);
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
NodoABB<T, menor, igual> *ABB<T, menor, igual>::precesor(NodoABB<T, menor, igual> *nodo_actual) {
    if(!nodo_actual->hijo_derecho){
        return nodo_actual;
    }else
        return sucesor(nodo_actual->hijo_derecho);
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::reapuntar_padre_hijo( NodoABB<T, menor, igual>* nodo){
    if ( nodo->hijo_derecho )
        nodo->hijo_derecho->padre = nodo->padre;
    else if ( nodo->hijo_izquierdo )
        nodo->hijo_izquierdo->padre = nodo->padre;

    if ( !nodo->padre )
        this->raiz = ( nodo->hijo_derecho ) ? nodo->hijo_derecho : nodo->hijo_izquierdo;
    else {
        if ( nodo->padre->hijo_derecho = nodo )
            nodo->padre->hijo_derecho = ( nodo->hijo_derecho ) ? nodo->hijo_derecho : nodo->hijo_izquierdo;
        else
            nodo->padre->hijo_izquierdo = ( nodo->hijo_derecho ) ? nodo->hijo_derecho : nodo->hijo_izquierdo;
    }

    nodo->hijo_derecho = nullptr;
    nodo->hijo_izquierdo = nullptr;
}


template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::intercambiar_nodo( NodoABB<T, menor, igual>* nodo_viejo, NodoABB<T, menor, igual>* nodo_nuevo){
    nodo_nuevo->padre = nodo_viejo->padre;
    nodo_nuevo->hijo_derecho = nodo_viejo->hijo_derecho;
    nodo_nuevo->hijo_izquierdo = nodo_viejo->hijo_izquierdo;

    if ( !nodo_viejo->padre )
        this->raiz = nodo_nuevo;
    else {
        if ( nodo_viejo->padre->hijo_izquierdo == nodo_viejo )
            nodo_viejo->padre->hijo_izquierdo = nodo_nuevo;
        else
            nodo_viejo->padre->hijo_derecho = nodo_nuevo;
    }

    if ( nodo_viejo->hijo_derecho )
        nodo_viejo->hijo_derecho->padre = nodo_nuevo;

    if ( nodo_viejo->hijo_izquierdo )
        nodo_viejo->hijo_izquierdo->padre = nodo_nuevo;

    nodo_viejo->hijo_derecho = nullptr;
    nodo_viejo->hijo_izquierdo = nullptr;
    
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::baja(NodoABB<T, menor, igual>* nodo_actual){

    if ( nodo_actual->hijo_derecho && nodo_actual->hijo_izquierdo ){
        NodoABB<T, menor, igual>* sucesor = this->sucesor(nodo_actual);
        NodoABB<T, menor, igual>* precesor = this->precesor(nodo_actual);

        if ( precesor == nodo_actual->hijo_derecho ){
            reapuntar_padre_hijo( precesor );
            intercambiar_nodo(nodo_actual,precesor);
        }
        else ( sucesor == nodo_actual->hijo_izquierdo ){
            reapuntar_padre_hijo( sucesor );
            intercambiar_nodo(nodo_actual,sucesor);
        }
    }
    else if ( nodo_actual->hijo_derecho || nodo_actual->hijo_izquierdo )
        reapuntar_padre_hijo(nodo_actual);

    delete nodo_actual;
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::baja(T dato, NodoABB<T, menor, igual>* nodo_actual){
    if ( igual(nodo_actual->dato,dato) )
        return baja(nodo_actual);
     else  if ( menor(nodo_actual->dato, dato))
        return baja(dato, nodo_actual->hijo_derecho);
     else
        return baja(dato, nodo_actual->hijo_izquierdo);
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::baja(T dato) {
    if (consulta(dato)){
        baja(dato, this->raiz);
        this->cantidad_datos -= 1;
    }
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
void ABB<T, menor, igual>::borrar_postorder(NodoABB<T, menor, igual>* borrado) {

    if (!borrado)
        return;
     else {
        borrar_postorder(borrado->hijo_izquierdo);
        borrar_postorder(borrado->hijo_derecho);
        delete borrado;
    }
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
size_t ABB<T, menor, igual>::altura(){
    if (this->vacio())
        return 0;
    else
        return altura(raiz);
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
size_t ABB<T, menor, igual>::altura(NodoABB<T,menor,igual>* nodo){
    if (!nodo)
        throw ABB_exception();

    size_t altura_izq = 1;
    size_t altura_der = 1;

    if (nodo->hijo_izquierdo)
        altura_izq += altura(nodo->hijo_izquierdo);
    if (nodo->hijo_derecho)
        altura_der += altura(nodo->hijo_derecho);

    return (altura_izq > altura_der) ? altura_izq : altura_der;
}

template<typename T, bool (*menor)(T, T), bool (*igual)(T, T)>
ABB<T, menor, igual>::~ABB() {

    if (!this->raiz)
        return;
    else
        borrar_postorder(this->raiz);
}
#endif
