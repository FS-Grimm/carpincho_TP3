//
// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_TABLERO_H
#define TP3_CARPINCHO_TABLERO_H

#include "Grafo.hpp"
#include "Random.hpp"
#include "James.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "Matriz.hpp"

const size_t DIRECCION_ARRIBA=1;
const size_t DIRECCION_DERECHA=2;
const size_t DIRECCION_IZQUIERDA=3;
const size_t DIRECCION_ABAJO=4;

const size_t CANT_FILAS = 9;
const size_t CANT_COLUMNAS = 9;
const size_t CANT_PYRAMIDS = 2;

const size_t PARED = 0;
const size_t PASILLO = 1;
const size_t PYRAMID_HEAD = 2;

const size_t POSICION_INICIAL = 0;
const size_t POSICION_FINAL = 8;

const size_t PESO_BASE = 10;
const size_t MULTIPLICADOR_PYRAMID_HEAD = 5;

const std::string ruta_layout1 = "config/layout1.csv";
const std::string ruta_layout2 = "config/layout2.csv";

class Tablero {

private: 
    Grafo grafo;
    Matriz tablero;  // Tablero[x][y]

    //std::pair<size_t,size_t> pos_james = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);
    std::pair<size_t,size_t> pyramid_head1 = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);
    std::pair<size_t,size_t> pyramid_head2 = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);

    // Pre: Archivo csv. 0 = pared, 1 = camino 
    // Post: Carga tablero  
    void cargar_tablero(std::string ruta_archivo);
    // Pre: Tablero cargado
    // Post Carga grafo base (Pyramids pero con arma equipada)
    void cargar_grafo();
    // Pre: Posición válida
    // Post: Asigna peso a aristas entrantes o salientes de la posicion
    void cargar_pesos_aristas(size_t x, size_t y, int peso, bool saliente);
    // Pre: Posicion válida y siguiente válido 
    // Post: Carga peso de arista especifica, vertical/horizontal - siguiente/anterior - aristas entrantes/salientes
    // Ejemplo: x = 0 no tiene anterior, x = 8 no tiene siguiente
    void cargar_peso_arista(size_t x, size_t y, int peso, bool horizontal, bool siguiente, bool saliente);
    // Pre: - 
    // Post: Carga pyramids en tablero
    void cargar_pyramids();
    // Pre: - 
    // Post: Devuelve posición válida aleatoria equiprobable para el ph
    std::pair<size_t,size_t>  posicion_pyramid();
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
    //Post: Devuelve un vector con el mejor camino para el personaje y su peso.
    //std::pair<std::vector<size_t>, int> obtener_mejor_camino(size_t pos_personaje1,size_t pos_personaje2);

    //Pre: El tablero ya fue cargado
    //Post: Indica si se puede mover al personaje en la direccion deseada.
    bool puede_moverse_a(size_t x,size_t y,size_t direccion);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un Pyramid Head en la direccion deseada
    bool hay_pyramid_head_en(size_t x,size_t y,size_t direccion);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un Pyramid Head en el camino indicado
    bool hay_pyramid_head_en(std::vector<size_t> camino);

    //Pre: El tablero ya fue cargado
    //Post: Devuelve verdadero si hay un camino posible desde la posicion a la salida en el estado actual.
    bool hay_camino(size_t x,size_t y);

    //pre: El tablero ya fue cargado
    //post: devuelve en un pair el vector que contiene el recorrido minimo y el peso de ese camino
    std::pair<std::vector<size_t>, int> obtener_mejor_camino(size_t x, size_t y);

    //pre: el tablero fue cargado,y tiene que ser capaz de moverse en esa direccion
    //post: modifica la posicion de james

    void imprimir();
    void prueba_matar_ph(bool pyramid);
    //void mover_james(size_t direccion);
};


#endif //TP3_CARPINCHO_TABLERO_H
