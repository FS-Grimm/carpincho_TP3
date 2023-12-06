// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_JUEGO_HPP
#define TP3_CARPINCHO_JUEGO_HPP
#include "James.hpp"
#include "Tablero.hpp"
#include "Random.hpp"
#include "Mostrar_tablero.hpp"


const int CHANCE_DE_NUEVA_ARMA=20;

class Juego {
private:
    Tablero* tablero;
    James* james;
    size_t niveles_recorridos;
    int costo_total;
    bool finalizo;
    size_t pos_james_1;
    size_t pos_james_2;
    Mostrar_tablero* visual;

    //Pre: James esta vivo y se puede mover en esa direccion
    //Post: Mueve a james en la direccion solicitada
    void cambiar_pos_james(size_t direccion);

    //Pre: James esta vivo y llego al final del tablero
    //Post: Recarga el tablero y da un arma a james si este tuvo suerte.
    void finalizar_nivel();

    //Pre: El escenario anterior finalizo
    //Post: Crea un nuevo escenario
    void nuevo_escenario();

    //Pre:-
    //Post: Devuelve true si obtuvo un arma aleatoriamente
    static bool puede_obtener_arma();

    //Pre: James esta vivo, james esta en la posicion de un pyramid head.
    //Post: James asusta al pyramid si tiene arma equipada, muere si no.
    void james_pelea_pyramid_head();

    //pre:
    //post: devuelve el vector camino minimo
    std::vector<size_t> mostrar_camino();

public:
    //CONSTRUCTOR
    Juego();

    //Pre: Hay un camino valido para llegar al final del tablero
    //Post: Imprime en pantalla el mejor camino al final del tablero
    void mostrar_mejor_camino();


    //Pre:-
    //Post: Devuelve verdadero si el juego termino.
    bool termino() const;

    //Pre: James Murio
    //Post: Imprime en pantalla un mensaje de derrota, el puntaje y termina el juego
    void derrota();

    //pre: -
    //post: devuelve true si tiene un arma equipado
    bool james_tiene_arma_equipada();

    //Pre: Se quiere mover a james en una dirección, james esta vivo.
    //Post: Si se podia mover a james, se mueve en esa direccion.
    void mover_james_hacia(size_t direccion);

    //Pre: Hay un camino a el final del tablero
    //Post: James se mueve por el mejor camino hasta el final del mapa.
    void moverse_por_el_mejor_camino();

    //Pre: James  esta vivo, tiene armas para equipar y no las tiene equipadas
    //Post: Se equipa el arma de mayor prioridad a james
    bool equipar_arma();

    //Pre: -
    //Post: Cambia la prioridad con la que se muestran las armas del invenario de james, de mejor a peor o peor a mejor.
    void alternar_prioridad();

    //Pre: James esta vivo, tiene armas para equipar y tiene un arma equipada
    //Post: Se desequipa el arma de mayor prioridad a james
    bool desequipar_arma();

    //Pre: -
    //Post: Devuelve puntaje actual de james, que varia segun su recorrido
    int obtener_puntaje();

    //Pre:
    //Post: Devuelve verdadero si James vive :D
    bool james_esta_vivo();

    //Pre: James recorrio 5 escenarios
    //Post: Imprime en pantalla un mensaje de victoria para el usuario, el puntaje y termina el juego
    void victoria();

    //pre:
    //post: imprime el tablero
    void imprimir_tablero();

    //pre:
    //post: imprime el puntaje
    void mostrar_puntaje();

    //DESTRUCTOR
    ~Juego();

};


#endif //TP3_CARPINCHO_JUEGO_HPP
