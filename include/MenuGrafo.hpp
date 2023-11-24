//
// Created by Felipe on 21/11/2023.
//

#ifndef TP3_CARPINCHO_MENU_GRAFO_H
#define TP3_CARPINCHO_MENU_GRAFO_H

#include <string>
#include "Grafo.hpp"
#include "Floyd.hpp"
#include "Dijkstra.hpp"


const std::string BIENVENIDA_GRAFO_UNO= "¡Bienvenido al uso de camino minimo favorito de los niños de algoritmos dos! ";
const std::string BIENVENIDA_GRAFO_DOS="A continuacion, se le indicara como usar el camino minimo en el Grafo";
const std::string ADVERTENCIA="ADVERTENCIA: Este menu actualmente no tiene uso, ya que no hay manera de cargar el grafo, los trabajadores aseguramos que sera implementado en futuras iteracions nwn";

const std::string SOLICITUD_CAMINO_MINIMO_UNO= "\nPor favor ingrese el tipo de camino minimo que desea usar, las opciones son: ";
const std::string SOLICITUD_CAMINO_MINIMO_DOS= " para salir.";
const std::string COMANDO_FLOYD="Floyd";
const std::string COMANDO_DIJKSTRA="Dijkstra";
const std::string M_GRAFO_COMANDO_SALIR="Salir";
const std::string ERROR_COMANDO_CAMINO_MINIMO="Error: No se dio comando valido al elegir camino minimo";



const std::string SOLICITUD_ORIGEN="Por favor ingrese la posicion del origen para el camino minimo";
const std::string SOLICITUD_DESTINO="Por favor ingrese la posicion del destino para el camino minimo";
const size_t FLOYD_ENTERO=1;
const size_t DIJKSTRA_ENTERO=2;
const size_t M_GRAFO_SALIR_ENTERO=14;
const size_t INVALIDO_U_ENTERO=404;
class MenuGrafo {
private:
    size_t comando;
    Grafo* grafo;


    //Pre: -
    //Post: Guarda el valor equivalente al comando_s como numero natural en comando
    void guardar_comando_entero(const std::string &comando_s);

    //Pre:-
    //Post: Solicita un comando al usuario
    void solicitar_comando();


    //Pre:-
    //Post: Solicita una posicion para el origen del camino minimo al usuario
    static size_t solicitar_origen();

    //Pre:-
    //Post: Solicita una posicion para el destino del camino minimo al usuario
    static size_t solicitar_destino();

    //Pre: -
    //Post: Llama al metodo indicado por el comando
    void procesar_comando();

public:
    //Pre:-
    //Post: Da la bienvenida al menu al usuario.
    static void bienvenida();

    //Constructor
    MenuGrafo();

    //Pre:-
    //Post: Procesa un comando pedido al usuario.
    void ejecutar_menu();

    //Pre:-
    //Post: Devuelve verdadero si el usuario quizo salir, falso en caso contrario.
    [[nodiscard]] bool quiere_salir() const;
    //Destructor
    ~MenuGrafo();
};

#endif //TP3_CARPINCHO_MENU_GRAFO_H
