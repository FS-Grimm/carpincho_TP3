//
// Created by Felipe on 18/11/2023.
//

#ifndef TDAS_TESTS_MENU_H
#define TDAS_TESTS_MENU_H

#include "InventarioArmas.hpp"

const std::string MEJOR="mejor arma";
const std::string PEOR="peor arma";


const std::string BIENVENIDA_INVENTARIO_UNO= "¡Bienvenido a el inventario favorito de los niños de algoritmos dos! ";
const std::string BIENVENIDA_INVENTARIO_DOS="A continuacion, se le indicara como usar el inventario";

const std::string MENSAJE_CAMBIO_PRIORIDAD_UNO="El inventario paso de priorizar a la ";
const std::string MENSAJE_CAMBIO_PRIORIDAD_DOS=" a priorizar la ";
const std::string MENSAJE_CAMBIO_PRIORIDAD_TRES=" exitosamente.";

const std::string INFORME_BAJA="Se realizara una baja de la ";
const std::string BAJA_EXITOSA_UNO="La baja del arma ";
const std::string BAJA_EXITOSA_DOS="  ocurrió sin problemas nwn";

const std::string  SOLICITUD_NOMBRE_ARMA="Por favor, ingrese un nombre para el arma";
const std::string  SOLICITUD_POTENCIA_ARMA="Por favor, ingrese una potencia";
const std::string  ADVERTENCIA_POTENCIA_ARMA="Advertencia:\nIngresar potencias negativas dañara el funcionamiento correcto del inventario.";

const std::string CREACION_ARMA_EXITOSA="El arma fue agregada al inventario";

const std::string MENSAJE_CONSULTA="La ";
const std::string MENSAJE_CONSULTA_DOS=" actualmente es:";


const std::string SOLICITUD_COMANDO_INVENTARIO_UNO="\nPor favor, ingrese un comando que desea usar, los comandos son: \n";

const std::string COMANDO_ALTA="Alta";
const std::string COMANDO_BAJA="Baja";
const std::string COMANDO_CONSULTA="Consulta";
const std::string COMANDO_CAMBIAR_PRIORIDAD="Cambiar Prioridad";
const std::string M_INVENTARIO_COMANDO_SALIR="Salir";
const std::string SOLICITUD_COMANDO_INVENTARIO_DOS=" para terminar el programa";

const size_t INVALIDO=404;
const size_t ALTA_ENTERO=1;
const size_t BAJA_ENTERO=2;
const size_t CONSULTAR_ENTERO=3;
const size_t CAMBIAR_PRIORIDAD_ENTERO=4;
const size_t M_INVENTARIO_SALIR_ENTERO=14;

const std::string CERRADO="El inventario se cerro exitosamente.";

class MenuInventario {



    size_t comando;
    InventarioArmas* inventario;




    //Pre:-
    //Post: Devuelve un string con la frase adecuada para la prioridad recibida.
    static std::string pasar_prioridad_string(bool prioridad);

    //Pre: -
    //Post: Guarda el valor equivalente al comando_s como numero natural
    void guardar_comando_entero(const std::string &comando_s);


    //Pre:-
    //Post: Solicita un comando al usuario
    void solicitar_comando();

    //Pre:-
    //Post: Permite al usuario alternar la prioridad del inventario entre priorizar armas fuertes o débiles
    void cambiar_prioridad();


    //Pre:-
    //Post: Guarda un Arma en el inventario si el usuario ingreso un nombre y una potencia no nula
    void alta();
    //Pre:-
    //Post: Saca el arma de mayor priodad del inventario y la devuelve
    Arma baja();

    //Pre:-
    //Post: Muestra el arma de mayor prioridad del inventario
    void consultar();


    //Pre: -
    //Post: Llama al metodo indicado por el comando
    void procesar_comando();


public:

    //Pre:-
    //Post: Da la bienvenida al menu al usuario.
    static void bienvenida();

    //Constructor
    MenuInventario();

    //Pre:-
    //Post: Procesa un comando pedido al usuario.
    void ejecutar_menu();

    //Pre:-
    //Post: Devuelve verdadero si el usuario quizo salir, falso en caso contrario.
    [[nodiscard]] bool quiere_salir() const;
    //Destructor
    ~MenuInventario();

};


#endif //TDAS_TESTS_MENU_H
