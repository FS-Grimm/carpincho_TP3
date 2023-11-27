//
// Created by Felipe on 26/11/2023.
//

#include "AccionesUsuario.h"
using namespace std;








AccionesUsuario::AccionesUsuario() {
    james=new James;
    tablero=new Tablero;
    costo_total=0;
    niveles_recorridos=0;
    nuevo_escenario();
}

void AccionesUsuario::equipar_arma() {
    if (!james->tiene_arma_equipada()) {
        james->equipar_arma();
        tablero->alternar_estado();
    }
}

void AccionesUsuario::desequipar_arma() {
    if (james->tiene_armas() && james->tiene_arma_equipada()) {
        james->desequipar_arma();
        tablero->alternar_estado();
    }
}

void AccionesUsuario::nuevo_escenario() {
    james->dar_placa();
    if (james->obtener_altura_placas()%2){
        tablero->usar_layout_uno();
    } else{
        tablero->usar_layout_dos();
    }
}


bool AccionesUsuario::puede_obtener_arma() {
    int chance_arma=rand() %100+1;
    return chance_arma<=CHANCE_DE_NUEVA_ARMA;
}

void AccionesUsuario::finalizar_nivel() {
    if (puede_obtener_arma()){
        james->dar_arma();
    }
    niveles_recorridos++;
    nuevo_escenario();
}


void AccionesUsuario::mover_james_hacia(size_t direccion) {
    tablero->mover_james_hacia(direccion);
}

void AccionesUsuario::mostrar_mejor_camino() {
    vector<size_t> camino=camino_coste.first;

    mostrar_camino(camino);
}

void AccionesUsuario::victoria() {

}

void AccionesUsuario::derrota() {

}

void AccionesUsuario::moverse_por_el_mejor_camino() {
    if(tablero->hay_camino(pos_james_1,pos_james_2)){
        costo_total+= tablero->obtener_mejor_camino(pos_james_1,pos_james_2).sec    ond;
    }

}


