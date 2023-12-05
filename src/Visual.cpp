//
// Created by feli on 04/12/23.
//
#include "Visual.hpp"
Visual::Visual(){
    this->fachada = new Juego;
    this->tablero = new Tablero;
};
void Visual::Mostrar_Tablero() {
    tablero->usar_layout_uno();
    auto tablero_aux = tablero->obtener_tablero();
    for (size_t y =  0; y < 8; y++) {
        for (size_t x = 0; x < 8; x++)
            std::cout << "[" << tablero_aux[x][y] << "]";
        std::cout << std::endl;
    }
};
void Visual::Mostrar_PyramidHead(){

};
void Visual::Mostrar_James(){

};

void Visual::Mostrar_camino_minimo(){

};

void Visual::Mostrar_Puntaje(){

};

Visual::~Visual(){

};