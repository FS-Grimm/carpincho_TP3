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
    Arma* arma;
    if(prioridad)
        arma=heap_mejor_arma->baja();
    else
        arma=heap_peor_arma->baja();
    return arma;
}


bool InventarioArmas::activo_esta_vacio() {
    bool vacio;
    if(prioridad)
        vacio=heap_mejor_arma->vacio();
    else
        vacio=heap_peor_arma->vacio();
    return vacio;
}


void InventarioArmas::cambiar_prioridad() {
   while(!activo_esta_vacio()){
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

void InventarioArmas::consulta() {
    if (!heap_mejor_arma->vacio() || !heap_peor_arma->vacio()) {
        cout<<CONSULTA_ARMA<<endl;
        if (prioridad)
            cout<<heap_mejor_arma->primero()<<endl;
        else
            cout<<heap_peor_arma->primero()<<endl;
    } else
        cout << CONSULTA_NO_ARMAS <<endl;
}

InventarioArmas::~InventarioArmas() {

}
