#ifndef TABLERO_GRAFO_HPP
#define TABLERO_GRAFO_HPP

#include "Grafo.hpp"
#include "Matriz.hpp"
#include "../config/constantes.hpp"
#include <string>

class Utils_grafo {

public:
    Utils_grafo() = default;
    ~Utils_grafo() = default;

    // Pre: Posición válida
    // Post: Asigna peso a aristas entrantes o salientes de la posicion
    static void cargar_pesos_aristas(size_t x, size_t y, Matriz& tablero, Grafo& grafo, int peso, bool saliente);
    // Pre: Posicion válida y siguiente válido 
    // Post: Carga peso de arista especifica, vertical/horizontal - siguiente/anterior - aristas entrantes/salientes
    static void cargar_peso_arista(size_t x, size_t y, Matriz& tablero, Grafo& grafo, int peso, bool horizontal, bool siguiente, bool saliente);

    // Pre:  
    // Post: 
};

#endif