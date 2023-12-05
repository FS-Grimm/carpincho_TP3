#include "Grafo.hpp"
#include "Matriz.hpp"
#include <string>

const std::string ruta_layout1 = "config/layout1.csv";
const std::string ruta_layout2 = "config/layout2.csv";

class Tablero_grafo {
private:
    Grafo grafo;
    std::pair<size_t,size_t> pyramid_head1 = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);
    std::pair<size_t,size_t> pyramid_head2 = std::pair<size_t,size_t>(CANT_COLUMNAS,CANT_FILAS);

    // Pre: -
    // Post: Carga los pesos de todas las aristas SALIENTES
    void cargar_peso_aristas(size_t x, size_t y, Matriz matriz, bool pyramid);

    // Pre: Posicion válida y siguiente válido
    // Post: Carga peso de arista especifica, vertical/horizontal - siguiente/anterior - aristas entrantes/salientes
    // Ejemplo: x = 0 no tiene anterior, x = 8 no tiene siguiente
    void cargar_peso_arista(size_t x, size_t y, int peso, bool horizontal, bool siguiente, bool saliente);

public:
    Tablero_grafo(Matriz matriz);
    ~Tablero_grafo();

    // Pre: -
    // Post:
    void alternar_estado(bool tiene_arma);
};