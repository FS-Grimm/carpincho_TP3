//
// Created by valen on 3/12/2023.
//
#ifndef TDAS_TESTS_VISUAL_HPP
#define TDAS_TESTS_VISUAL_HPP
#define LADRILLO_EMOJI "\U0001f9f1"
#define FUEGO_EMOJI "\U0001f525"
#define MEDIAS_EMOJI "\U0001f9e6"
#define BOTELLA_DE_GRITOS_EMOJI "\U0001f9f4"
#define AHUYENTA_RANDALL_EMOJI "\U0001f6b7"
#define MARTILLO_EMOJI "\U0001f528"
#define EXTINTOR_EMOJI "\U0001f9ef"
#define JAMES "\U0001f471"
#define PH "\U0001f479"
#define CAMINO "\u2B1C"
#include "Juego.h"
#include "Matriz.hpp"



class Visual{
private:
    Juego* fachada;
    Tablero* tablero;
    Matriz prueba;
public:
    //constructor
    Visual();
    //PRE:
    //POST:Muestra el tablero
    void Mostrar_Tablero();

    //PRE:
    //POST:Muestra a james
    void Mostrar_James(size_t x, size_t y);

    //PRE:
    //POST:Muestra a ph
    void Mostrar_PyramidHead();

    //PRE:
    //POST:Muestra el camino minimo
    void Mostrar_camino_minimo();

    //PRE:
    //POST:Muestra el puntaje
    void Mostrar_Puntaje();

    //destructor

};
#endif //TDAS_TESTS_VISUAL_HPP