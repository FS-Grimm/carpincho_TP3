//
// Created by Felipe on 18/11/2023.
//

#ifndef TDAS_TESTS_MENU_H
#define TDAS_TESTS_MENU_H
#include "InventarioArmas.hpp"


const std::string MEJOR="priorizar la mejor arma";
const std::string PEOR="priorizar la peor arma";

const std::string CAMBIO_PRIORIDAD_UNO="El inventario paso de ";
const std::string CAMBIO_PRIORIDAD_DOS=" exitosamente.";
const std::string BIENVENIDA_UNO= "¡Bienvenido a el inventario favorito de los niños de algoritmos dos! ";
const std::string BIENVENIDA_DOS="A continuacion, se le indicara como iniciar el inventario";
const std::string CERRADO="El inventario se ha cerrado, lo que contenía fue guardado.";

const std::string SOLICITUD_COMANDO_UNO="Por favor, ingrese un comando que desea usar, los comandos son: ";
const std::string COMANDO_CAMINO_MINIMO="Camino Minimo";
const std::string COMANDO_SALIR="Salir";

const std::string SOLICITUD_COMANDO_DOS=" para terminar el programa";

const std::string COMANDO_FLOYD="Floyd";
const std::string COMANDO_DIJKSTRA="Dijkstra";
const size_t COMANDO_INVALIDO=404;


class Menu {

    size_t comando;
    InventarioArmas* inventario;



    //Pre:-
    //Post: Guarda un Arma en el inventario, que la organiza segun la prioridad indicada.
    void alta();
    //Pre:-
    //Post: Quita el arma de mayor prioridad del inventario
    Arma baja();

    //Pre:-
    //Post: Muestra el arma de mayor prioridad del inventario
    void consultar();

    //Pre:-
    //Post: Permite al usuario alternar la prioridad del inventario entre priorizar armas fuertes o débiles
    void cambiar_prioridad();

    //Pre:-
    //Post: Solicita un comando al usuario
    void solicitar_comando();

    //Pre: -
    //Post: Guarda el valor equivalente al comando_s como numero natural
    void pasar_equivalente_natural(const std::string &comando_s);

    //Pre:-
    //Post: Devuelve un string con la frase adecuada para la prioridad recibida.
    std::string pasar_prioridad_string(bool prioridad);

    //Pre: -
    //Post: Llama al metodo indicado por el comando
    void procesar_comando();


public:
    //Constructor
    Menu();

    //Pre:-
    //Post: Procesa un comando pedido al usuario.
    void ejecutar_menu_menus();

    //Pre:-
    //Post: Devuelve verdadero si el usuario quizo salir, falso en caso contrario.
    bool quiere_salir();
    //Destructor
    ~Menu();
};


#endif //TDAS_TESTS_MENU_H
