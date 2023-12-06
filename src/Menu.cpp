//
// Created by feli on 05/12/23.
//
#include "Menu.hpp"
size_t Menu::recibir_direccion_james(){
    size_t direccion;
    std::string comando_direccion;
    getline(std::cin, comando_direccion);
    if(comando_direccion == DERECHA)
        direccion = DIRECCION_DERECHA;
    else if(comando_direccion == IZQUIERDA)
        direccion = DIRECCION_IZQUIERDA;
    else if(comando_direccion == ARRIBA)
        direccion = DIRECCION_ARRIBA;
    else if(comando_direccion == ABAJO)
        direccion = DIRECCION_ABAJO;
    else
        direccion=INVALIDO;

    return direccion;
};

void Menu::guardar_comando_entero(const std::string &comando_s){
    if(comando_s == COMANDO_MOVER_JAMES)
        comando = MOVER_JAMES_HACIA;
    else if(comando_s == COMANDO_VER_ARMA)
        comando = VER_ARMA;
    else if(comando_s == COMANDO_EQUIPAR_ARMA)
        comando = EQUIPAR_ARMA;
    else if(comando_s == COMANDO_DESEQUIPAR_ARMA)
        comando = DESEQUIPAR_ARMA;
    else if(comando_s == COMANDO_MOSTRAR_CAMINO_MINIMO)
        comando = MOSTRAR_CAMINO_MINIMO;
    else if(comando_s == COMANDO_MOVER_CAMINO_MINIMO)
        comando = MOVER_CAMINO_MINIMO;
    else if(comando_s == COMANDO_ALTERNAR_PRIORIDAD)
        comando = ALTERNAR_PRIORIDAD;
    else if(comando_s == COMANDO_VER_PUNTAJE)
        comando = VER_PUNTAJE;
    else if (comando_s == COMANDO_SALIR)
        comando=SALIR;
    else
        comando=INVALIDO;
};

void Menu::solicitar_comando(){
    std::cout << "ingrese el comando que desee ejecutar" << std::endl << COMANDO_MOVER_JAMES << ", " << COMANDO_VER_ARMA << ", "<<  COMANDO_EQUIPAR_ARMA << ", " << COMANDO_DESEQUIPAR_ARMA << ","
    << COMANDO_MOSTRAR_CAMINO_MINIMO << ", " << COMANDO_MOVER_CAMINO_MINIMO << ", " << COMANDO_ALTERNAR_PRIORIDAD << ", "<< COMANDO_VER_PUNTAJE << ", " << std::endl;

    std::string comando_s;
    getline(std::cin, comando_s);
    guardar_comando_entero(comando_s);
};

void Menu::ver_tablero() {
    juego.imprimir_tablero();
}

void Menu::procesar_comando(){
    switch (comando) {
        case MOVER_JAMES_HACIA:
            std::cout<<"ingrese dirección "<<DERECHA<<", "<<IZQUIERDA<<", "<<ARRIBA<<", "<< ABAJO<<std::endl;
            juego.mover_james_hacia(recibir_direccion_james());
            break;
        case VER_ARMA:
            if(juego.james_tiene_arma_equipada())
                std::cout<<"james esta armado"<<std::endl;
            else
                std::cout<<"james no esta armado"<<std::endl;
            break;
        case EQUIPAR_ARMA:
            juego.equipar_arma();
            std::cout << "Se equipo el arma" << std::endl;
            break;
        case DESEQUIPAR_ARMA:
            juego.desequipar_arma();
            std::cout << "Se desequipo el arma" << std::endl;
            break;
        case MOSTRAR_CAMINO_MINIMO:
            juego.mostrar_mejor_camino();
            break;
        case MOVER_CAMINO_MINIMO:
            juego.moverse_por_el_mejor_camino();
            break;
        case ALTERNAR_PRIORIDAD:
            juego.alternar_prioridad();
            break;
        case VER_PUNTAJE:
            juego.mostrar_puntaje();
            break;
        default:
            std::cout << "Comando incorrecto, intente de vuelta." << std::endl;
    }
}

void Menu::ejecutar_menu() {
    if(this->comando != MOSTRAR_CAMINO_MINIMO)
        ver_tablero();
    solicitar_comando();
    procesar_comando();
}

bool Menu::quiere_salir() const {
    return (comando == SALIR || juego.termino());
}

