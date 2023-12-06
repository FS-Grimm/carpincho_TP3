#include "Grafo.hpp"
#include "Matriz.hpp"
#include "config/constantes.hpp"
#include <string>

class Utils_grafo {

public:
    Utils_grafo() = default;
    ~Utils_grafo() = default;

    // Pre: Posición válida
    // Post: Asigna peso a aristas entrantes o salientes de la posicion
    static void cargar_pesos_aristas(size_t x, size_t y, Matriz& matriz, Grafo& grafo, int peso, bool saliente);
};