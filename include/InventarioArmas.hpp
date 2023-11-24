//
// Created by Felipe on 18/11/2023.
//

#ifndef CARPINCHO_TP3_INVENTARIO_ARMAS_H
#define CARPINCHO_TP3_INVENTARIO_ARMAS_H

#include "Heap.hpp"
#include "Arma.hpp"


class InventarioArmas {
private:


    Heap<Arma*,Arma::mayor> *heap_mejor_arma;
    Heap<Arma*,Arma::menor> *heap_peor_arma;
    bool prioridad;



public:
    //Constructor
    InventarioArmas();


    //Pre:-
    //Post: Devuelve true si el heap en uso, el indicado por la prioridad, esta vació
    bool vacio();

    //Pre:-
    //Post: Guarda un Arma en el inventario, la organiza según la prioridad indicada.
    void alta(Arma *arma);

    //Pre:-
    //Post: Devuelve true si la prioridad actual del inventario prioriza la mejor arma
    //false si prioriza la peor
    [[nodiscard]] bool obtener_prioridad() const;


    //Pre: El inventario no está vació.
    //Post: Quita el arma de mayor prioridad del inventario
    Arma * baja();

    //Pre:-
    //Post: Muestra el arma de mayor prioridad del inventario, informando si no hay ninguna.
    void consulta();

    //Pre:-
    //Post: Alterna la prioridad del inventario entre priorizar armas fuertes o débiles
    void cambiar_prioridad();

    //Destructor
    ~InventarioArmas();
};


#endif //CARPINCHO_TP3_INVENTARIO_ARMAS_H
