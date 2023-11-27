// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_ACCIONESUSUARIO_H
#define TP3_CARPINCHO_ACCIONESUSUARIO_H
#include "James.h"
#include "Tablero.h"
/*
const size_t MINIMA_ID_PLACAS=100;;
const size_t MAXIMA_ID_PLACAS=666;
const size_t MINIMA_POTENCIA_ARMAS=10;
const size_t MAXIMA_POTENCIA_ARMAS=100;
*/
const int CHANCE_DE_NUEVA_ARMA=20;

class AccionesUsuario {
private:
    Tablero* tablero;
    James* james;
    size_t niveles_recorridos;
    int costo_total;
    size_t pos_james_1;
    size_t pos_james_2;



    void finalizar_nivel();

    void nuevo_escenario();

public:
    AccionesUsuario();

    void mostrar_mejor_camino();

    void victoria();

    void derrota();

    void mover_james_hacia(size_t direccion);

    void moverse_por_el_mejor_camino();

    void equipar_arma();


    void cambiar_prioridad();

    void desequipar_arma();

    void mostrar_puntaje();


    ~AccionesUsuario();

    static bool puede_obtener_arma();
};


#endif //TP3_CARPINCHO_ACCIONESUSUARIO_H
