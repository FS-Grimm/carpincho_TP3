#include "Tablero_grafo.hpp"

Tablero_grafo::Tablero_grafo(Matriz matriz) {
    for (size_t y = 0; y < matriz.filas(); y++){
        for (size_t x = 0; x < matriz.columnas(); x++){
            cargar_peso_aristas(x,y,matriz,false);
        }
    }
}

void Tablero_grafo::alternar_estado(bool tiene_arma) {

}

