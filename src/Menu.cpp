//
// Created by Felipe on 18/11/2023.
//

#include <iostream>
#include "Menu.hpp"



using namespace std;

string Menu::pasar_prioridad_string(bool prioridad) {
    string prioridad_s=MEJOR;
    if (prioridad)
        prioridad_s=PEOR;
    return prioridad_s;
}


void Menu::guardar_comando_entero(const std::string& comando_s) {
    if (comando_s == COMANDO_ALTA) {
        comando=ALTA_ENTERO;
    } else if (comando_s == COMANDO_BAJA) {
        comando=BAJA_ENTERO;
    } else if (comando_s == COMANDO_CONSULTA) {
        comando = CONSULTAR_ENTERO;
    }else if (comando_s == COMANDO_SALIR){
        this->comando=SALIR_ENTERO;
    } else if(comando_s==COMANDO_CAMBIAR_PRIORIDAD) {
        comando=CAMBIAR_PRIORIDAD_ENTERO;
    }else{
            comando=INVALIDO;
    }
}


void Menu::solicitar_comando() {
    cout<<SOLICITUD_COMANDO_UNO<<endl;
    cout<<COMANDO_ALTA<<", "<<COMANDO_BAJA<<", "<<COMANDO_CONSULTA<<" o "<<COMANDO_SALIR<<SOLICITUD_COMANDO_DOS<<endl;
    string comando_s;
    getline(cin,comando_s);
    guardar_comando_entero(comando_s);
}

bool Menu::quiere_salir() const{
    return comando==SALIR_ENTERO;
}
void Menu::cambiar_prioridad() {
    string prioridad_actual= pasar_prioridad_string(!inventario->obtener_prioridad());
    string prioridad_nueva= pasar_prioridad_string(!inventario->obtener_prioridad());
    inventario->cambiar_prioridad();
    cout << MENSAJE_CAMBIO_PRIORIDAD_UNO << prioridad_actual << MENSAJE_CAMBIO_PRIORIDAD_DOS << prioridad_nueva << MENSAJE_CAMBIO_PRIORIDAD_TRES << endl;
}
void Menu::alta() {
    cout << SOLICITUD_ARMA << endl;
    string nombre_arma; size_t potencia_arma;
    getline(cin,nombre_arma);
    getline(, potencia_arma);
    auto arma=new Arma(nombre_arma, potencia_arma);
    inventario->alta(arma);
    cout<<CREACION_ARMA_EXITOSA<<endl;
}

Arma Menu::baja() {
    string prioridad_actual=pasar_prioridad_string(inventario->obtener_prioridad());
    cout<<INFORME_BAJA<<prioridad_actual<<"."<<endl;
    Arma* arma_aux=inventario->baja();
    Arma arma=*arma_aux;
    delete arma_aux;
    cout<<BAJA_EXITOSA<<endl;
    return arma;
}

void Menu::consultar() {
    cout<<MENSAJE_CONSULTA<< pasar_prioridad_string(inventario->obtener_prioridad())<<MENSAJE_CONSULTA_DOS<<endl;
    inventario->consulta();
}




void Menu::procesar_comando() {
    switch (comando){
        case ALTA_ENTERO:
            alta();
            break;
        case BAJA_ENTERO:
            baja();
            break;
        case CONSULTAR_ENTERO:
            consultar();
            break;
        case CAMBIAR_PRIORIDAD_ENTERO:
            cambiar_prioridad();
    }

}

void Menu::ejecutar_menu() {
    solicitar_comando();
    procesar_comando();
}

Menu::~Menu() {
    while(!inventario->vacio()){
        delete inventario->baja();
    }
    cout << CERRADO << endl;
    delete inventario;
}

