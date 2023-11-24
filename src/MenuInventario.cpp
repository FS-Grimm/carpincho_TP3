//
// Created by Felipe on 18/11/2023.
//

#include <iostream>
#include "MenuInventario.hpp"



using namespace std;


void MenuInventario::bienvenida() {
    cout<<BIENVENIDA_INVENTARIO_UNO<<BIENVENIDA_INVENTARIO_DOS<<endl;
}

MenuInventario::MenuInventario() {
    inventario=new InventarioArmas;
}

string MenuInventario::pasar_prioridad_string(bool prioridad) {
    string prioridad_s=MEJOR;
    if (!prioridad)
        prioridad_s=PEOR;
    return prioridad_s;
}


void MenuInventario::guardar_comando_entero(const std::string& comando_s) {
    if (comando_s == COMANDO_ALTA)
        comando=ALTA_ENTERO;
    else if (comando_s == COMANDO_BAJA)
        comando=BAJA_ENTERO;
    else if (comando_s == COMANDO_CONSULTA)
        comando = CONSULTAR_ENTERO;
    else if (comando_s == M_INVENTARIO_COMANDO_SALIR)
        comando=M_INVENTARIO_SALIR_ENTERO;
    else if(comando_s==COMANDO_CAMBIAR_PRIORIDAD)
        comando=CAMBIAR_PRIORIDAD_ENTERO;
    else
        comando=INVALIDO;
}


void MenuInventario::solicitar_comando() {
    cout << SOLICITUD_COMANDO_INVENTARIO_UNO << COMANDO_ALTA << ", " << COMANDO_BAJA << ", " << COMANDO_CONSULTA <<". "<<COMANDO_CAMBIAR_PRIORIDAD<< " o " << M_INVENTARIO_COMANDO_SALIR << SOLICITUD_COMANDO_INVENTARIO_DOS << endl;
    string comando_s;
    getline(cin,comando_s);
    guardar_comando_entero(comando_s);
}

bool MenuInventario::quiere_salir() const{
    return comando==M_INVENTARIO_SALIR_ENTERO;
}
void MenuInventario::cambiar_prioridad() {
    string prioridad_actual= pasar_prioridad_string(inventario->obtener_prioridad());
    string prioridad_nueva= pasar_prioridad_string(!inventario->obtener_prioridad());
    inventario->cambiar_prioridad();
    cout << MENSAJE_CAMBIO_PRIORIDAD_UNO << prioridad_actual << MENSAJE_CAMBIO_PRIORIDAD_DOS << prioridad_nueva << MENSAJE_CAMBIO_PRIORIDAD_TRES << endl;
}
void MenuInventario::alta() {
    cout << SOLICITUD_NOMBRE_ARMA << endl;
    string nombre_arma,recolector_basura;
    size_t potencia_arma;
    getline(cin, nombre_arma);
    cout<<SOLICITUD_POTENCIA_ARMA<<endl;
    cout<<ADVERTENCIA_POTENCIA_ARMA<<endl;

    cin>>potencia_arma;
    getline(cin,recolector_basura);
    auto arma=new Arma(nombre_arma, potencia_arma);
    inventario->alta(arma);
    cout<<CREACION_ARMA_EXITOSA<<endl;
}

Arma MenuInventario::baja() {
    string prioridad_actual=pasar_prioridad_string(inventario->obtener_prioridad());
    cout<<INFORME_BAJA<<prioridad_actual<<"."<<endl;
    Arma* arma_aux=inventario->baja();
    Arma arma=*arma_aux;
    Arma::liberar(arma_aux);
    cout<<BAJA_EXITOSA_UNO<<arma<<BAJA_EXITOSA_DOS<<endl;
    return arma;
}

void MenuInventario::consultar() {
    cout<<MENSAJE_CONSULTA<< pasar_prioridad_string(inventario->obtener_prioridad())<<MENSAJE_CONSULTA_DOS<<endl;
    inventario->consulta();
}




void MenuInventario::procesar_comando() {
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

void MenuInventario::ejecutar_menu() {
    solicitar_comando();
    procesar_comando();
}

MenuInventario::~MenuInventario() {
    while(!inventario->vacio()){
        Arma::liberar(inventario->baja());
    }
    cout << CERRADO << endl;
    delete inventario;
}

