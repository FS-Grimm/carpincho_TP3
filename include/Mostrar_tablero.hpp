//
// Created by valen on 3/12/2023.
//
#ifndef TDAS_TESTS_VISUAL_HPP
#define TDAS_TESTS_VISUAL_HPP

#include "../config/constantes.hpp"
#include "Matriz.hpp"
#include "vector"



class Mostrar_tablero{
private:

    //PRE: -
    //POST: muestra el tablero
    static void mostrar_tablero(Matriz* tablero,size_t pos_james_x,size_t pos_james_y);
    //PRE:
    //POST:Guarda James en el tablero recibido.
    static void guardar_james(size_t x, size_t y, Matriz* tablero);
public:
    //PRE:
    //POST:Muestra el tablero
    static void mostrar_tablero(Matriz tablero,size_t pos_james_x,size_t pos_james_y);

    //PRE:
    //POST:Muestra el camino minimo
    static void mostrar_camino_minimo(Matriz tablero, const std::vector<size_t>& camino_minimo,size_t pos_james_x,size_t pos_james_y);

    static void mostrar_puntaje(int puntaje);
};
#endif //TDAS_TESTS_VISUAL_HPP