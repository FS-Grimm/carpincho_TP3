//
// Created by Felipe on 18/11/2023.
//

#include "InventarioArmas.hpp"
#include <iostream>
using namespace std;

InventarioArmas::InventarioArmas() {
    heap_peor_arma=new Heap<Arma*,Arma::menor>;
    heap_mejor_arma=new Heap<Arma*,Arma::mayor>;
    prioridad=true;
}


bool InventarioArmas::obtener_prioridad() const {
    return prioridad;
}

Arma * InventarioArmas::baja() {
    Arma* arma=nullptr;
    if (!vacio()) {
        if (prioridad)
            arma = heap_mejor_arma->baja();
        else
            arma = heap_peor_arma->baja();
    }
    return arma;
}


bool InventarioArmas::vacio() {
    bool vacio=heap_peor_arma->vacio();
    if(prioridad)
        vacio=heap_mejor_arma->vacio();
    return vacio;
}


void InventarioArmas::cambiar_prioridad() {
   while(!vacio()){
       if(prioridad)
           heap_peor_arma->alta(heap_mejor_arma->baja());
       else
           heap_mejor_arma->alta(heap_peor_arma->baja());
   }
    prioridad=!prioridad;
}

void InventarioArmas::alta(Arma *arma) {
    if(prioridad)
        heap_mejor_arma->alta(arma);
    else
        heap_peor_arma->alta(arma);
}

Arma * InventarioArmas::consulta() {
    Arma* arma_consultada=nullptr;
    if (!heap_mejor_arma->vacio() || !heap_peor_arma->vacio()) {
        if (prioridad) {
            arma_consultada=heap_mejor_arma->primero();
        } else {
            arma_consultada=heap_peor_arma->primero();
        }
    }
    return arma_consultada;
}

InventarioArmas::~InventarioArmas() {
    delete heap_peor_arma; delete heap_mejor_arma;
}
