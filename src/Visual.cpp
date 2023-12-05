//
// Created by feli on 04/12/23.
//
#include "Visual.hpp"

using namespace std;
Visual::Visual(){
    this->fachada = new Juego;
};
void Visual::Mostrar_Tablero() {
    Matriz tablero_aux = fachada->Matriz_a_tablero();
    Mostrar_James(0,0);
    for (int y = CANT_COLUMNAS - 1; y > -1; y--){
        for (size_t x = 0; x < CANT_COLUMNAS; x++) {
            int elemento=tablero_aux.elemento(x, (size_t) y);
            switch (elemento) {
                case CAMINO_NUMBER:
                    cout << CAMINO;
                    break;
                case PARED_NUMBER:
                    cout << LADRILLO_EMOJI;
                    break;
                case PYRAMIDE_NUMBER:
                    cout << PH;
                    break;
                case JAMES_NUMBER:
                    cout << JAMES;
                    break;
                case MINIMO_NUMBER:
                    cout << CAMINO_MINIMO;
                    break;
            }
            std::cout << std::endl;
        }
    }
    Mostrar_Puntaje();

    /*
    for (size_t y =  0; y < 8; y++) {
        for (size_t x = 0; x < 8; x++)
            std::cout << "[" <<prueba.elemento(x, y) << "]";
        std::cout << std::endl;
    }*/
};

void Visual::Mostrar_James(size_t x, size_t y){
    prueba.elemento(x,y) = 3;
};

void Visual::Mostrar_camino_minimo(){
    vector<size_t> aux = fachada->mostrar_mejor_camino();

    for (size_t i = 0; i < aux.size(); i++){
        if (prueba.elemento(aux[i] % (size_t)9, aux[i] / (size_t)9) != 3){
            prueba.elemento(aux[i] % (size_t)9, aux[i] / (size_t)9) = 4;
        }
    }
};

void Visual::Mostrar_Puntaje(){
    int puntaje = fachada->mostrar_puntaje();
    cout << "Puntaje: " << puntaje << endl;
};
