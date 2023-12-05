//
// Created by feli on 04/12/23.
//
#include "Visual.hpp"

using namespace std;
Visual::Visual(){
    prueba = Matriz(9, 1);

    for (size_t i = 0; i < 5; i++){
        prueba.elemento(i,4) = 0;
        prueba.elemento(6,7) = 2;
    }
    this->fachada = new Juego;
    this->tablero = new Tablero;
};
void Visual::Mostrar_Tablero() {
    //auto tablero_aux = tablero->obtener_tablero();
    Mostrar_James(0,0);
    for (int y = CANT_COLUMNAS - 1; y > -1; y--){
        for (size_t x = 0; x < CANT_COLUMNAS; x++)
            if(prueba.elemento(x, (size_t)y) == 1){
                cout<< CAMINO;
            }else if (prueba.elemento(x, (size_t)y) == 0){
                cout << LADRILLO_EMOJI;
            }else if (prueba.elemento(x, (size_t)y) == 2){
                cout << PH;
            }else if (prueba.elemento(x, (size_t)y) == 3){
                cout << JAMES;
            }
        std::cout << std::endl;
    }/*
    for (size_t y =  0; y < 8; y++) {
        for (size_t x = 0; x < 8; x++)
            std::cout << "[" <<prueba.elemento(x, y) << "]";
        std::cout << std::endl;
    }*/
};
void Visual::Mostrar_PyramidHead(){

};
void Visual::Mostrar_James(size_t x, size_t y){
    prueba.elemento(x,y) = 3;
};

void Visual::Mostrar_camino_minimo(){

};

void Visual::Mostrar_Puntaje(){
    fachada->mostrar_puntaje();
};
