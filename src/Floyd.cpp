
#include "Floyd.hpp"

Floyd::Floyd() {}

void Floyd::inicializar_matrices() {
    matriz_caminos = Matriz(cantidad_vertices);
    for (size_t i = 0; i < cantidad_vertices; i++) {
        for (size_t j = 0; j < cantidad_vertices; j++) {
            matriz_caminos.elemento(i, j) = (int) j;
        }
    }
    matriz_costos = matriz_adyacencia;
}

std::vector<size_t> Floyd::obtener_camino(size_t origen, size_t destino) {
    std::vector<size_t> camino;
    size_t i = origen;
    camino.push_back(origen);
    while(i!=destino){
        i = matriz_caminos.elemento(i,destino);
        if (i>=INFINITO)
            throw Indice_no_valido_exception();
        camino.push_back(i);
    }
    return camino;
}

std::vector<size_t>
Floyd::calcular_camino_minimo(Matriz adyacencia, size_t vertices, size_t origen, size_t destino, bool hay_cambios) {
    if (hay_cambios) {
        matriz_adyacencia = adyacencia;
        cantidad_vertices = vertices;
        inicializar_matrices();
        size_t i , j, k;int distancia_total;
        for (k = 0; k < cantidad_vertices;k++){
            for (i = 0;i < cantidad_vertices ;i++){
                for (j = 0;j < cantidad_vertices;j++){
                    distancia_total = matriz_adyacencia.elemento(i, k) + matriz_adyacencia.elemento(k, j);
                    if (distancia_total < matriz_adyacencia.elemento(i,j)) {
                        matriz_adyacencia.elemento(i, j) = distancia_total;
                        matriz_caminos.elemento(i,j) = matriz_caminos.elemento(i,k);
                    }
                }
            }
        }
    }
    return obtener_camino(origen, destino);
}

Floyd::~Floyd() {}