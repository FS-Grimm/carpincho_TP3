//
// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_JAMES_H
#define TP3_CARPINCHO_JAMES_H
#include "InventarioArmas.hpp"
//Aca quizas deberia ir "ARBOL DE PLACAS", idk.
#include "ABB.hpp"
#include "Placa.hpp"

class James {
private:
public:


    //Pre:-
    //Post: Devuelve true si james tiene armas en el inventario.
    bool tiene_armas();

    //Pre: James no tiene un arma equipada y tiene armas disponibles.
    //Post: Equipa la de mayor prioridad;
    void equipar_arma();

    //Pre: -
    //Post: Devuelve true si james tiene un arma equipada.
    bool tiene_arma_equipada();

    //Pre: James tiene un arma equipada
    //Post: Desequipa el arma a james.
    void desequipar_arma();

    //Pre: -
    //Post: Da un arma de potencia aleatoria a james.
    void dar_arma();

    //Pre: -
    //Post: Da una placa  de ID aleatoria a james.
    void dar_placa();

    //Pre:-
    //Post: Devuelve la altura del arbol de placas.
    size_t obtener_altura_placas();

    //Pre: Hay armas en el inventario, hay una equipada,
    //Post: Usa el arma de mayor prioridad.
    void usar_arma();

    //Pre: -
    //Post: Cambia la prioridad del inventario.
    void cambiar_prioridad();


};


#endif //TP3_CARPINCHO_JAMES_H
