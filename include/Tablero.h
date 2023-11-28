//
// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_TABLERO_H
#define TP3_CARPINCHO_TABLERO_H
#include "Grafo.hpp"

const size_t DIRECCION_ARRIBA=1;
const size_t DIRECCION_DERECHA=2;
const size_t DIRECCION_IZQUIERDA=3;
const size_t DIRECCION_ABAJO=4;


class Tablero {

public:


    //Pre:-
    //Post: Carga el tablero con el layout 1
    void usar_layout_uno();

    //Pre:-
    //Post: Carga el tablero con el layout 2
    void usar_layout_dos();


    //Pre: El tablero fue cargado, hay un pyramid head en la posicion indicada
    //Post: Quita el pyramid head de la posicion indicada y actualiza las posiciones a su alrededor, de ser necesario.
    void quitar_pyramid(size_t pos1, size_t pos2);

    //Pre: El tablero ya fue cargado anteriormente, con un estado ya no deseado.
    //Post: Carga el tablero al otro estado posible.
    void alternar_estado();

    //Pre: El tablero ya fue cargado
    //Post: Devuelve un vector con el mejor camino para el personaje y su peso.
    std::pair<std::vector<size_t>, int> obtener_mejor_camino(size_t pos_personaje1,size_t pos_personaje2);

    //Pre: El tablero ya fue cargado
    //Post: Indica si se puede mover al personaje en la direccion deseada.
    bool puede_moverse_a(size_t pos_personaje1,size_t pos_personaje2,size_t direccion);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un Pyramid Head en la direccion deseada
    bool hay_pyramid_head_en(size_t pos_personaje1,size_t pos_personaje2,size_t direccion);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un Pyramid Head en el camino indicado
    bool hay_pyramid_head_en(std::vector<size_t> camino);


    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un camino posible desde la posicion a la salida en el estado actual.
    bool hay_camino(size_t pos1,size_t pos2);
};


#endif //TP3_CARPINCHO_TABLERO_H
