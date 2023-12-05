//
// Created by valen on 3/12/2023.
//
#ifndef TDAS_TESTS_VISUAL_HPP
#define TDAS_TESTS_VISUAL_HPP
#define LADRILLO_EMOJI "\U0001f9f1"
#define CAMINO_MINIMO "\U0001f7e5"
#define JAMES "\U0001f471"
#define PH "\U0001f479"
#define CAMINO "\u2B1C"

const int PARED_NUMBER = 0;
const int CAMINO_NUMBER = 1;
const int PYRAMIDE_NUMBER = 2;
const int JAMES_NUMBER = 3;
const int MINIMO_NUMBER = 4;

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
    //POST:Muestra el camino minimo
    void Mostrar_camino_minimo();

    //PRE:
    //POST:Muestra el puntaje
    void Mostrar_Puntaje();

    //destructor

};
#endif //TDAS_TESTS_VISUAL_HPP