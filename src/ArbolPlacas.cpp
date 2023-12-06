//
// Created by valen on 27/11/2023.
//
#include "ArbolPlacas.hpp"

ArbolPlacas::ArbolPlacas() {
    this->arbol_placas = new ABB<Placa*,Placa::menor, Placa::igual>;
}

size_t ArbolPlacas::altura() {
    return this->arbol_placas->altura();
}

size_t ArbolPlacas::tamanio() {
    return arbol_placas->tamanio();
}

bool ArbolPlacas::placa_existe(Placa *placa) {
    return arbol_placas->consulta(placa);
}

void ArbolPlacas::guardar_placa(Placa* placa) {
    this->arbol_placas->alta(placa);
}

ArbolPlacas::~ArbolPlacas() {
    delete arbol_placas;
}


