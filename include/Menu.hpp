//
// Created by Felipe on 23/11/2023.
//
#ifndef TP3_CARPINCHO_MENU_H
#define TP3_CARPINCHO_MENU_H

#include "MenuGrafo.hpp"
#include "MenuInventario.hpp"

const std::string MENU_BIENVENIDA_UNO="Bienvenido al menu  de Camino Minimo e inventario de armas favorito delos niños de algoritmos y programación dos,";
const std::string MENU_BIENVENIDA_DOS=" a continuacion se le solicitaran comandos para elegir el menu a usar, ";
const std::string MENU_BIENVENIDA_TRES="puede salir de cualquiera de los menus para volver a este y entrar otro, esperamos que la pase bien  :D";

const std::string SOLICITUD_MENU_UNO="\nPor favor ingrese uno de los comandos validos, estos son: \n";
const std::string COMANDO_MENU_GRAFO="Menu Grafo";
const std::string COMANDO_MENU_INVENTARIO="Menu Inventario";
const std::string SOLICITUD_MENU_DOS=" para elegir un Menu o ";
const std::string SOLICITUD_MENU_TRES=" para salir del programa.";

const size_t MENU_INVENTARIO_ENTERO=1;
const size_t MENU_GRAFO_ENTERO=2;
const size_t MENU_SALIR_ENTERO=14;
const size_t MENU_INVALIDO=404;


const std::string MENU_SALIDA_GRAFO="Ha salido exitosamente del Menu del Grafo.";
const std::string MENU_SALIDA_INVENTARIO="Ha salido exitosamente del Menu del Inventario.";

class Menu {
    size_t comando;
    MenuGrafo *menu_grafo;
    MenuInventario *menu_inventario;


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
    //Pre:-
    //Post: Da la bienvenida al menu al usuario.
    static void bienvenida();

    //Constructor
    Menu();

    //Pre:-
    //Post: Procesa un comando pedido al usuario.
    void ejecutar_menu();

    //Pre:-
    //Post: Devuelve verdadero si el usuario quizo salir, falso en caso contrario.
    [[nodiscard]] bool quiere_salir() const;
    //Destructor
    ~Menu();

};


#endif //TP3_CARPINCHO_MENU_H
