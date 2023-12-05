//
// Created by valen on 3/12/2023.
//
#ifndef TDAS_TESTS_VISUAL_HPP
#define TDAS_TESTS_VISUAL_HPP
#define PARED_EMOJI "\U0001f9f1"
#define CAMINO_MINIMO "\U0001f7e5"
#define JAMES_EMOJI "\U0001f471"
#define PYRAMID_CABEZA_EMOJI "\U0001f479"
#define PISO_EMOJI "\u2B1C"

const int PARED = 0;
const int INDICADOR_CAMINO_MINIMO = 1;
const int PYRAMID = 2;
const int JAME= 3;
const int MINIMO_NUMBER = 4;


#include "Matriz.hpp"
#include "vector"



class Visual{
public:
    //PRE:
    //POST:Muestra el tablero
    static void mostrar_tablero(Matriz tablero,size_t pos_james_x,size_t pos_james_y);

    //PRE:
    //POST:Muestra a james
    static void guardar_james(size_t x, size_t y, Matriz* tablero);

    //PRE:
    //POST:Muestra el camino minimo
    static void mostrar_camino_minimo(Matriz tablero, std::vector<size_t> camino_minimo);

    //PRE:
    //POST:Muestra el puntaje
    static void mostrar_puntaje(int puntaje);
};
#endif //TDAS_TESTS_VISUAL_HPP