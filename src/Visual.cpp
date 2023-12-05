//
// Created by feli on 04/12/23.
//
#include "Visual.hpp"
using namespace std;
Visual::Visual(){

};
void Visual::mostrar_tablero(Matriz tablero,size_t pos_james_x,size_t pos_james_y) {
    guardar_james(pos_james_x,pos_james_y, &tablero);
    mostrar_camino_minimo(tablero);
    for (int y = CANT_COLUMNAS - 1; y > -1; y--){
        for (size_t x = 0; x < CANT_COLUMNAS; x++) {
            int elemento=tablero.elemento(x, (size_t) y);
            switch (elemento) {
                case INDICADOR_CAMINO_MINIMO:
                    cout << PISO_EMOJI;
                    break;
                case PARED:
                    cout << PARED_EMOJI;
                    break;
                case PYRAMID:
                    cout << PYRAMID_CABEZA_EMOJI;
                    break;
                case JAMES_NUMBER:
                    cout << JAMES_EMOJI;
                    break;
                case MINIMO_NUMBER:
                    cout << CAMINO_MINIMO;
                    break;
            }
            std::cout << std::endl;
        }
    }
    mostrar_puntaje();

    /*
    for (size_t y =  0; y < 8; y++) {
        for (size_t x = 0; x < 8; x++)
            std::cout << "[" <<prueba.elemento(x, y) << "]";
        std::cout << std::endl;
    }*/
}
void Visual::guardar_james(size_t x, size_t y, Matriz* tablero){
    tablero->elemento(x,y) = 3;
}

void Visual::mostrar_camino_minimo(Matriz tablero, vector<size_t> camino_minimo){
    for (size_t i = 0; i < camino_minimo.size(); i++){
        if (tablero.elemento(camino_minimo[i] % (size_t)9, camino_minimo[i] / (size_t)9) != 3){
            tablero.elemento(camino_minimo[i] % (size_t)9, camino_minimo[i] / (size_t)9) = 4;
        }
    }
}

void Visual::mostrar_puntaje(int puntaje){
    int puntaje = mostrar_puntaje();
    cout << "Puntaje: " << puntaje << endl;
};
