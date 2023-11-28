//
// Created by Felipe on 26/11/2023.
//

#include <iostream>
#include "Juego.h"

const std::string NO_CAMINO_DISPONIBLE="No hay camino a la salida con las condiciones actuales, si james tiene armas disponibles, deberia equiparlas.";
size_t POSICION_INICIAL=0;
size_t POSICION_FINAL=9;
using namespace std;








Juego::Juego() {
    james = new James;
    tablero = new Tablero;
    costo_total = 0;
    niveles_recorridos = 0;
    finalizo = false;
    nuevo_escenario();
}

bool Juego::termino() {
    return finalizo;
}

void Juego::alternar_prioridad() {
    james->cambiar_prioridad();

}

void Juego::equipar_arma() {
    if (!james->tiene_arma_equipada()) {
        james->equipar_arma();
        tablero->alternar_estado();
    }
}

void Juego::desequipar_arma() {
    if (james->tiene_armas() && james->tiene_arma_equipada()) {
        james->desequipar_arma();
        tablero->alternar_estado();
    }
}

void Juego::nuevo_escenario() {
    james->dar_placa();
    if (james->obtener_altura_placas()%2){
        tablero->usar_layout_uno();
    } else{
        tablero->usar_layout_dos();
    }
    pos_james_1 = POSICION_INICIAL;
    pos_james_2 = POSICION_INICIAL;
}


bool Juego::puede_obtener_arma() {
    int chance_arma=rand() %100+1;
    return chance_arma<=CHANCE_DE_NUEVA_ARMA;
}

void Juego::finalizar_nivel() {
    if (puede_obtener_arma()){
        james->dar_arma();
    }
    niveles_recorridos++;
    if (niveles_recorridos==5){
        victoria();
    } else {
        nuevo_escenario();
    }
}
void Juego::cambiar_pos_james(size_t direccion) {
    switch(direccion){
        case DIRECCION_ARRIBA:
            pos_james_1++;
            break;

        case DIRECCION_ABAJO:
            pos_james_1--;
            break;

        case DIRECCION_DERECHA:
            pos_james_2++;
            break;

        case DIRECCION_IZQUIERDA:
            pos_james_2--;
            break;

    }
}

void Juego::james_pelea_pyramid_head() {
    if(james->tiene_arma_equipada()){
        james->usar_arma();
        tablero->quitar_pyramid(pos_james_1,pos_james_2);
    } else{
        james->morir();
        derrota();
    }
}

void Juego::mover_james_hacia(size_t direccion) {
    if (tablero->puede_moverse_a(pos_james_1,pos_james_2,direccion)){
        cambiar_pos_james(direccion);
        if(tablero->hay_pyramid_head_en(pos_james_1,pos_james_2,direccion)){
            james_pelea_pyramid_head();
        }else if(pos_james_1==pos_james_2==POSICION_FINAL){
                finalizar_nivel();
        }
    }
}


void Juego::mostrar_mejor_camino() {
    vector<size_t> camino=tablero->obtener_mejor_camino(pos_james_1,pos_james_1).first;
    mostrar_camino(camino);
}

void Juego::victoria() {

    finalizo=true;
}

void Juego::derrota() {

    finalizo=true;

}

void Juego::moverse_por_el_mejor_camino() {
    if(tablero->hay_camino(pos_james_1,pos_james_2)){
        costo_total += tablero->obtener_mejor_camino(pos_james_1,pos_james_2).second;
        finalizar_nivel();
    }else{
        cout<<NO_CAMINO_DISPONIBLE<<endl;
    }
}

void Juego::mostrar_camino(std::vector<size_t> vector1) {

}

void Juego::mostrar_puntaje() {

}

Juego::~Juego() {
    delete james; delete tablero;

}

