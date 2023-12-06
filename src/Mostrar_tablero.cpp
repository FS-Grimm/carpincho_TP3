//
// Created by feli on 04/12/23.
//
#include "Mostrar_tablero.hpp"

#include "iostream"

void Mostrar_tablero::mostrar_tablero(Matriz *tablero, size_t pos_james_x, size_t pos_james_y) {
    guardar_james(pos_james_x,pos_james_y, tablero);
    int cant_columnas=(int)tablero->columnas(),elemento;
    size_t y,x;
    for (y=1;y <=tablero->columnas(); y++) {
        for (x=0 ; x < tablero->columnas(); x++) {
            elemento = tablero->elemento(x, (size_t) cant_columnas - y);
            switch (elemento) {
                case INDICADOR_PISO:
                    std::cout << PISO_EMOJI;
                    break;
                case INDICADOR_PARED:
                    std::cout << PARED_EMOJI;
                    break;
                case INDICADOR_PYRAMID:
                    std::cout << PYRAMID_CABEZA_EMOJI;
                    break;
                case INDICADOR_JAMES:
                    std::cout << JAMES_EMOJI;
                    break;
                case CAMINO_MINIMO:
                    std::cout << CAMINO_MINIMO_EMOJI;
                    break;
            }
        }
        std::cout << std::endl;
    }

}

void Mostrar_tablero::mostrar_tablero(Matriz tablero, size_t pos_james_x, size_t pos_james_y) {

    mostrar_tablero(&tablero,pos_james_x,pos_james_y);
}
void Mostrar_tablero::guardar_james(size_t x, size_t y, Matriz* tablero){
    tablero->elemento(x,y) = 3;
}

void Mostrar_tablero::mostrar_camino_minimo(Matriz tablero, const std::vector<size_t>& camino_minimo, size_t pos_james_x, size_t pos_james_y){
    int elemento;
    for (size_t elemento_pos : camino_minimo){
        elemento=tablero.elemento(elemento_pos % tablero.columnas(), elemento_pos / tablero.columnas());
        if (elemento!= INDICADOR_JAMES && elemento!=INDICADOR_PYRAMID ){
            tablero.elemento(elemento_pos % tablero.columnas(), elemento_pos / tablero.columnas()) = CAMINO_MINIMO;
        }
    }
    mostrar_tablero(&tablero,pos_james_x,pos_james_y);
}

void Mostrar_tablero::mostrar_puntaje(int puntaje) {
    std::cout << "El puntaje es: " << puntaje << std::endl;
}