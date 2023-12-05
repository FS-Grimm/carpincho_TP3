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
#define MOVIMIENTOS_EMOJI "\U0001f45f"
#define MIKE_EMOJI "\U0001f47e"
#include "Juego.h"

class Visual{
private:
    Juego* fachada;
    Tablero* tablero;
public:
    //constructor
    Visual();
    //PRE:
    //POST:Muestra el tablero
    void Mostrar_Tablero();

    //PRE:
    //POST:Muestra a james
    void Mostrar_James();

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
    ~Visual();
};
#endif //TDAS_TESTS_VISUAL_HPP