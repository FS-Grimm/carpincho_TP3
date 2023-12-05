//
// Created by feli on 05/12/23.
//

#ifndef TP3_CARPINCHO_MENU_HPP
#define TP3_CARPINCHO_MENU_HPP
#include "Juego.hpp"
class Menu{
private:
    Juego fachada;
    size_t comando;

    //Pre: -
    //Post: Guarda el valor equivalente al comando_s como numero natural en comando
    void guardar_comando_entero(const std::string &comando_s);

    //Pre:-
    //Post: Solicita un comando al usuario
    void solicitar_comando();

    //Pre: -
    //Post: Llama al metodo indicado por el comando
    void procesar_comando();
public:

    void ver_tablero();

    void ver_puntaje();

    void mover_james_hacia();

    void desequipar_y_equipar_arma();

    void mostrar_camino_minimo();

    void

};
#endif //TP3_CARPINCHO_MENU_HPP
