#include "Grafo.hpp"
#include "Matriz.hpp"
#include <string>

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
class Utils_grafo {

public:
    Utils_grafo() = default;
    ~Utils_grafo() = default;

    // Pre: Posición válida
    // Post: Asigna peso a aristas entrantes o salientes de la posicion
    static void cargar_pesos_aristas(size_t x, size_t y, Matriz& matriz, Grafo& grafo, int peso, bool saliente);
};