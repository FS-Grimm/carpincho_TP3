//
// Created by valen on 27/11/2023.
//

#ifndef TDAS_TESTS_ARBOLPLACAS_HPP
#define TDAS_TESTS_ARBOLPLACAS_HPP
#include "Placa.hpp"
#include "ABB.hpp"
class ArbolPlacas{
private:
    ABB<Placa*, Placa::menor, Placa::igual>* arbol_placas;
public:
    //constructor
    ArbolPlacas();

    //PRE:
    //POST: devuelve altura del arbol
    size_t altura();

    //PRE:
    //POST: devuelve tamaño del arbol
    size_t tamanio();


    //PRE:
    //POST: indica si la placa ya exite
    bool placa_existe(Placa* placa);

    //PRE: la placa no existe en el arbol
    //POST: guarda una placa en arbol
    void guardar_placa(Placa* placa);

    //destructor
    ~ArbolPlacas();
};
#endif //TDAS_TESTS_ARBOLPLACAS_HPP
