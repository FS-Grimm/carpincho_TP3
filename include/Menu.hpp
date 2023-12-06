//
// Created by feli on 05/12/23.
//

#ifndef TP3_CARPINCHO_MENU_HPP
#define TP3_CARPINCHO_MENU_HPP
#include "Juego.hpp"

const int MOVER_JAMES_HACIA = 1;

const int VER_ARMA = 2;

const int DESEQUIPAR_ARMA = 3;

const int EQUIPAR_ARMA = 4;

const int MOSTRAR_CAMINO_MINIMO = 5;

const int MOVER_CAMINO_MINIMO = 6;

const int ALTERNAR_PRIORIDAD = 7;

const int VER_PUNTAJE = 8;

const int SALIR = 14;


const int INVALIDO = 404;

const std::string COMANDO_MOVER_JAMES = "mover james hacia";

const std::string COMANDO_VER_ARMA = "ver arma";

const std::string COMANDO_EQUIPAR_ARMA = "equipar arma";

const std::string COMANDO_DESEQUIPAR_ARMA = "desequipar arma";

const std::string COMANDO_MOSTRAR_CAMINO_MINIMO = "ver camino minimo";

const std::string COMANDO_MOVER_CAMINO_MINIMO = "transitar camino minimo";

const std::string COMANDO_ALTERNAR_PRIORIDAD = "cambiar a arma mas chica";

const std::string COMANDO_VER_PUNTAJE = "ver puntaje previo a terminar";

const std::string DERECHA = "derecha";

const std::string IZQUIERDA = "izquierda";

const std::string ABAJO = "abajo";

const std::string ARRIBA = "arriba";

const std::string COMANDO_SALIR = "salir";


class Menu{
private:
    Juego* juego;
    size_t comando;

    void ver_tablero();

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

    bool gano();

    void victoria();

    void derrota();

     ~Menu();
};
#endif //TP3_CARPINCHO_MENU_HPP
