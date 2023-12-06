//
// Created by feli on 05/12/23.
//

#ifndef TP3_CARPINCHO_MENU_HPP
#define TP3_CARPINCHO_MENU_HPP
#include "Juego.hpp"
#include "../config/constantes.hpp"
class Menu{
private:
    Juego* juego;
    size_t comando = INVALIDO;

    //Pre:
    //Post: muestra tablero
    void ver_tablero();

    //Pre:
    //Post: le pasa a james una direccion
    size_t recibir_direccion_james();

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
    Menu();
    //Pre:-
    //Post: Procesa un comando pedido al usuario.
    void ejecutar_menu();

    //Pre:-
    //Post: Devuelve verdadero si el usuario quizo salir, falso en caso contrario.
    [[nodiscard]] bool quiere_salir() const;

    //Pre: -
    //Post: determina si el jugador gano
    bool gano();

    //Pre: -
    //Post: mensaje de victoria
    void victoria();

    //Pre: -
    //Post: mensaje de derrota
    void derrota();

     ~Menu();
};
#endif //TP3_CARPINCHO_MENU_HPP
