//
// Created by Felipe on 26/11/2023.
//

#ifndef TP3_CARPINCHO_JAMES_H
#define TP3_CARPINCHO_JAMES_H
#include "InventarioArmas.hpp"
//Aca quizas deberia ir "ARBOL DE PLACAS", idk.
#include "ABB.hpp"
#include "vector"
#include "Placa.hpp"
#include "InventarioArmas.hpp"
#include "ArbolPlacas.hpp"
#include "random"

const std::vector<std::string> ARMAS_BAJA_POTENCIA = {"cuchillo", "palo", "tuberia_oxidada", "crowbar"};
const std::vector<std::string> ARMAS_MEDIA_POTENCIA = {"pistola_9mm", "revolver_22", "recortada_12"};
const std::vector<std::string> ARMAS_ALTA_POTENCIA = {"escopeta_12", "rifle_caza", "revolver_44_magnum"};

class James {
private:
    InventarioArmas* inventario_armas;
    ArbolPlacas* arbol_placas;
    Arma* arma_equipada;
public:
    //constructor
    James();

    //Pre:-
    //Post: Devuelve true si james tiene armas en el inventario.
    bool tiene_armas();

    //Pre: James no tiene un arma equipada y tiene armas disponibles.
    //Post: Equipa la de mayor prioridad;
    void equipar_arma();

    //Pre: -
    //Post: Devuelve true si james tiene un arma equipada.
    bool tiene_arma_equipada();

    //Pre: James tiene un arma equipada
    //Post: Desequipa el arma a james.
    void desequipar_arma();

    //Pre: -
    //Post: Da un arma de potencia aleatoria a james.
    void dar_arma();

    //Pre: Hay armas en el inventario, hay una equipada,
    //Post: Usa el arma de mayor prioridad.
    void usar_arma();

    //Pre: -
    //Post: Cambia la prioridad del inventario.
    void cambiar_prioridad();

    //Pre: -
    //Post: Da una placa  de ID aleatoria a james.
    void obtener_placa();

    //Pre:-
    //Post: Devuelve la altura del arbol de placas.
    size_t obtener_altura_placas();


};


#endif //TP3_CARPINCHO_JAMES_H
