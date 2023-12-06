//
// Created by Felipe on 26/11/2023.
//

#include <iostream>
#include "Juego.hpp"

const std::string NO_CAMINO_DISPONIBLE="No hay camino a la salida con las condiciones actuales, si james tiene armas disponibles, deberia equiparlas.";
//size_t POSICION_INICIAL = 0;
//size_t POSICION_FINAL = 9;
using namespace std;


Juego::Juego() {
    james = new James;
    tablero = new Tablero;
    costo_total = 0;
    niveles_recorridos = 0;
    finalizo = false;
    james->obtener_placa();
    nuevo_escenario();
}

bool Juego::termino() const {
    return finalizo;
}

void Juego::alternar_prioridad() {
    james->cambiar_prioridad();

}

void Juego::equipar_arma() {
    if (!james->tiene_arma_equipada()) {
        james->equipar_arma();
        tablero->alternar_estado(true);
    }
}

void Juego::desequipar_arma() {
    if (james->tiene_armas() && james->tiene_arma_equipada()) {
        james->desequipar_arma();
        tablero->alternar_estado(false);
    }
}

void Juego::nuevo_escenario() {
    james->obtener_altura_placas();
    if (james->obtener_altura_placas()%2==0){
        tablero->usar_layout_uno();
    } else{
        tablero->usar_layout_dos();
    }
    pos_james_1 = POSICION_INICIAL;
    pos_james_2 = POSICION_INICIAL;
}


bool Juego::puede_obtener_arma() {
    int chance_arma = Random::random(0, 100);
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
    switch (direccion) {
        case DIRECCION_ARRIBA:
            pos_james_2++;
            break;
        case DIRECCION_ABAJO:
            pos_james_2--;
            break;
        case DIRECCION_DERECHA:
            pos_james_1++;
            break;
        case DIRECCION_IZQUIERDA:
            pos_james_1--;
            break;
    }
}

bool Juego::james_esta_vivo(){
    return james->esta_vivo();
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
 //       costo_total += tablero->costo_movimiento(pos_james_1,pos_james_2,direccion);
        if(tablero->hay_pyramid_head_en(pos_james_1,pos_james_2,direccion)){
            james_pelea_pyramid_head();
        }else if((pos_james_1==pos_james_2) && (pos_james_2==POSICION_FINAL)){ // lo cambie yo(negro) porq creo q habia un error de sintaxis A CHEQUEAR
                finalizar_nivel();
        }
    }
}


void Juego::mostrar_mejor_camino() {
    vector<size_t> camino=tablero->obtener_mejor_camino(pos_james_1, pos_james_2).first;
    Visual::mostrar_camino_minimo(tablero->obtener_matriz(),camino,pos_james_1,pos_james_2);
}

void Juego::victoria() {
    finalizo = true;
    imprimir_tablero();
}

void Juego::derrota() {
    finalizo = true;
    imprimir_tablero();
}

void Juego::moverse_por_el_mejor_camino() {
    if(tablero->hay_camino(pos_james_1,pos_james_2)){
        costo_total += tablero->obtener_mejor_camino(pos_james_1, pos_james_2).second;
        finalizar_nivel();
    }else{
        cout<<NO_CAMINO_DISPONIBLE<<endl;
    }
}

vector<size_t> Juego::mostrar_camino() {
    vector<size_t> camino = tablero->obtener_mejor_camino(pos_james_1, pos_james_2).first;
    return camino;
}

int Juego::obtener_puntaje() {
    return costo_total;
}

void Juego::mostrar_puntaje(){
    int puntaje = obtener_puntaje();
    Visual::mostrar_puntaje(puntaje);
};

void Juego::imprimir_tablero() {
    Visual::mostrar_tablero(tablero->obtener_matriz(), this->pos_james_1, this->pos_james_2);
}


Juego::~Juego() {
    delete james; delete tablero;

}



bool Juego::james_tiene_arma_equipada() {
    return james->tiene_arma_equipada();
}



