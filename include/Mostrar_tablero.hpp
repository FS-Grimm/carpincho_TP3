//
// Created by valen on 3/12/2023.
//
#ifndef TDAS_TESTS_VISUAL_HPP
#define TDAS_TESTS_VISUAL_HPP
#define PARED_EMOJI "\U0001f9f1"
#define CAMINO_MINIMO_EMOJI "\U0001f7e5"
#define JAMES_EMOJI "\U0001f471"
#define PYRAMID_CABEZA_EMOJI "\U0001f479"
#define PISO_EMOJI "\u2B1C"

const int INDICADOR_PARED = 0;
const int INDICADOR_PISO = 1;
const int INDICADOR_PYRAMID = 2;
const int INDICADOR_JAMES= 3;
const int CAMINO_MINIMO = 4;


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