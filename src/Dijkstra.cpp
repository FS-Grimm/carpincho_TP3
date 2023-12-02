#include "Dijkstra.hpp"
#include <iostream>

Dijkstra::Dijkstra() {
    vertices_visitados = nullptr;
    distancia = nullptr;
    recorrido = nullptr;
}

void Dijkstra::inicializar_arreglos(size_t origen) {
    delete[] vertices_visitados;
    delete[] distancia;
    delete[] recorrido;

    vertices_visitados = new bool[cantidad_vertices];
    distancia = new int[cantidad_vertices];
    recorrido = new size_t[cantidad_vertices];

    for (size_t i = 0; i < cantidad_vertices; i++) {
        vertices_visitados[i] = false;
        recorrido[i] = origen;
        distancia[i] = matriz_adyacencia.elemento(origen, i);
    }
    vertices_visitados[origen] = true;
}


size_t Dijkstra::vertice_minima_distancia() {
    int distancia_minima = INFINITO;
    size_t vertice_minimo = 0;
    for (size_t i = 0; i < cantidad_vertices; i++) {
        if (!vertices_visitados[i] && distancia[i] <= distancia_minima) {
            distancia_minima = distancia[i];
            vertice_minimo = i;
        }
    }
    return vertice_minimo;
}

void Dijkstra::actualizar_distancia(size_t vertice) {
    for (size_t i = 0; i < cantidad_vertices; i++) {
        if (!vertices_visitados[i] && distancia[vertice] != INFINITO &&
            distancia[i] > matriz_adyacencia.elemento(vertice, i) + distancia[vertice]) {
            distancia[i] = matriz_adyacencia.elemento(vertice, i) + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

std::vector<size_t> Dijkstra::obtener_camino(size_t origen, size_t destino) {
    std::vector<size_t> camino;
    if (distancia[destino] >= INFINITO){
        throw Indice_no_valido_exception();
    }
    size_t actual = destino;
    size_t intentos = 0;
    while ( (actual != origen) && intentos < 100 ) {
        camino.insert(camino.begin(), actual);
        actual = recorrido[actual];
        intentos += 1;
    }
    if (intentos < 100)
        camino.insert(camino.begin(), origen);
    else {
        camino.clear();
        camino.push_back(origen);
    }
    return camino;
}

std::vector<size_t>
Dijkstra::calcular_camino_minimo(Matriz adyacencia, size_t vertices, size_t origen, size_t destino,
                                 bool hay_cambios) {
    //saque el if (hay_cambios) porque juli me dijo que era innecesario
        matriz_adyacencia = adyacencia;
        cantidad_vertices = vertices;
        inicializar_arreglos(origen);
        size_t vertice_actual;
        for (size_t i = 0; i < vertices; i++) {
            vertice_actual = vertice_minima_distancia();
            vertices_visitados[vertice_actual] = true;
            actualizar_distancia(vertice_actual);
        }

    return obtener_camino(origen, destino);
}

Dijkstra::~Dijkstra() {
    delete[] vertices_visitados;
    delete[] distancia;
    delete[] recorrido;
}