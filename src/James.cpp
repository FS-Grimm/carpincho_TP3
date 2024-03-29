//
// Created by valen on 27/11/2023.
//
#include "James.hpp"

James::James() {
    this->inventario_armas = new InventarioArmas;
    this->arbol_placas = new ArbolPlacas;
    this->arma_equipada = nullptr;
    this->vivo = true;
}


bool James::tiene_armas() {
    return !inventario_armas->vacio();
}

void James::equipar_arma() {
    this->arma_equipada = inventario_armas->consulta();
}

bool James::tiene_arma_equipada() {
    return arma_equipada;
}

void James::desequipar_arma() {
    arma_equipada = nullptr;
}


void James::dar_arma() {
    std::string arma;
    size_t potencia = static_cast<size_t>(Random::random(10, 100));
    if(potencia >= 10 && potencia < 40)
        arma = ARMAS_BAJA_POTENCIA[static_cast<size_t>(Random::random(0, static_cast<int>(ARMAS_BAJA_POTENCIA.size())))];
    else if(potencia >= 40 && potencia < 70)
        arma = ARMAS_MEDIA_POTENCIA[static_cast<size_t>(Random::random(0, static_cast<int>(ARMAS_MEDIA_POTENCIA.size())))];
    else
        arma = ARMAS_ALTA_POTENCIA[static_cast<size_t>(Random::random(0, static_cast<int>(ARMAS_ALTA_POTENCIA.size())))];
    Arma* nueva_arma = new Arma(arma, potencia);
    inventario_armas->alta(nueva_arma);
}

void James::cambiar_prioridad() {
    inventario_armas->cambiar_prioridad();
}

void James::obtener_placa() {
    if(this->vivo){
    int id = Random::random(100, 666);
    std::string placa = "placa" + std::to_string(arbol_placas->tamanio());
    Placa* nueva_placa = new Placa(placa, placa, id);
    if(!arbol_placas->placa_existe(nueva_placa))
        arbol_placas->guardar_placa(nueva_placa);
    else{
        do{
            id = Random::random(100, 666);
            delete nueva_placa;
            nueva_placa = new Placa(placa, placa, id);
        }while (arbol_placas->placa_existe(nueva_placa));
    }
    }
}

void James::usar_arma() {
    if(!inventario_armas->vacio() && arma_equipada){
        delete arma_equipada;
        inventario_armas->baja();
        if(!inventario_armas->vacio()){
            equipar_arma();
        }
    }
}

bool James::esta_vivo() {
    return this->vivo;
}

void James::morir() {
    if(vivo)
        this->vivo = false;
}

James::~James() {
    delete inventario_armas; delete arbol_placas; delete arma_equipada;
}

size_t James::obtener_altura_placas() {
    return this->arbol_placas->altura();
}
