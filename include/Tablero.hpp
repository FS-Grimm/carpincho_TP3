//
// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_TABLERO_HPP
#define TP3_CARPINCHO_TABLERO_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "../config/constantes.hpp"
#include "Grafo.hpp"
#include "Random.hpp"
#include "Tablero_grafo.hpp"
class Tablero {

private: 
    Grafo grafo;
    Matriz tablero;  // Tablero[x][y]

    std::pair<size_t,size_t> pyramid_head1 = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);
    std::pair<size_t,size_t> pyramid_head2 = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);

    // Pre: Archivo csv. 0 = pared, 1 = camino 
    // Post: Carga tablero  
    void cargar_tablero(std::string ruta_archivo);
    // Pre: Tablero cargado
    // Post Carga grafo base (Pyramids pero con arma equipada)
    void cargar_grafo();

    // Pre: - 
    // Post: Carga pyramids en tablero
    void cargar_pyramids();
    // Pre: - 
    // Post: Devuelve posición válida aleatoria equiprobable para el ph
    std::pair<size_t,size_t> posicion_pyramid();
    // Pre: -
    // Post: Alterna pyramid en cuestión
    void alternar_pyramids(bool pyramid_1, bool tiene_arma);
    // Pre: -
    // Post: Alterna pyramids
    void alternar_pyramids(bool tiene_arma);
    //Pre: -
    //Post: Quita el pyramid head de la posicion indicada 
    void quitar_pyramid(bool pyramid_1);
public:
    Tablero();
    ~Tablero() = default;

    //Pre:-
    //Post: Carga el tablero con el layout 1
    void usar_layout_uno();

    //Pre:-
    //Post: Carga el tablero con el layout 2
    void usar_layout_dos();


    //Pre: El tablero fue cargado, hay un pyramid head en la posicion indicada
    //Post: Quita el pyramid head de la posicion indicada 
    void quitar_pyramid(size_t x, size_t y);

    // Pre: El tablero ya fue cargado anteriormente.
    // Post: Carga el tablero al estado deseado
    void alternar_estado(bool tiene_arma);


    //Pre: El tablero ya fue cargado
    //Post: Indica si se puede mover al personaje en la direccion deseada.
    bool puede_moverse_a(size_t x,size_t y,size_t direccion);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un Pyramid Head en la direccion deseada
    bool hay_pyramid_head_en(size_t x, size_t y);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un Pyramid Head en el camino indicado
    size_t hay_pyramid_head_en(std::vector<size_t> camino);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un camino posible desde la posicion a la salida en el estado actual.
    bool hay_camino(size_t x,size_t y);

    //pre: El tablero ya fue cargado
    //post: devuelve en un pair el vector que contiene el recorrido minimo y el peso de ese camino
    std::pair<std::vector<size_t>, int> obtener_mejor_camino(size_t x, size_t y);
    //pre:
    //post:devuelve una copia de matriz
    Matriz obtener_matriz();

    //pre:
    //post: devuelve el costo de movimiento dependiendo de si hay un pyramid en su direccion
    int costo_movimiento(size_t pos_james_1, size_t pos_james_2, size_t direccion);
};


#endif //TP3_CARPINCHO_TABLERO_HPP
