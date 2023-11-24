//
// Created by Felipe on 23/11/2023.
//

#include <iostream>
#include "Menu.hpp"

using namespace std;


void Menu::bienvenida() {
    cout << MENU_BIENVENIDA_UNO << MENU_BIENVENIDA_DOS << MENU_BIENVENIDA_TRES << endl;
}

Menu::Menu() {
    menu_inventario=new MenuInventario;
    menu_grafo=new MenuGrafo;
}

void Menu::guardar_comando_entero(const std::string &comando_s) {

    if (comando_s == COMANDO_MENU_INVENTARIO)
        comando = MENU_INVENTARIO_ENTERO;
    else if (comando_s == COMANDO_MENU_GRAFO)
        comando = MENU_GRAFO_ENTERO;
    else if (comando_s == M_GRAFO_COMANDO_SALIR)
        comando = MENU_SALIR_ENTERO;
    else
        comando = MENU_INVALIDO;
}

void Menu::solicitar_comando() {
    cout<<SOLICITUD_MENU_UNO<<endl;
    cout << COMANDO_MENU_INVENTARIO << " o " << COMANDO_MENU_GRAFO << SOLICITUD_MENU_DOS << M_GRAFO_COMANDO_SALIR << SOLICITUD_MENU_TRES << endl;
    string comando_s;
    getline(cin,comando_s);
    guardar_comando_entero(comando_s);
}

void Menu::procesar_comando() {
    switch (comando) {
        case MENU_GRAFO_ENTERO:
            menu_grafo->bienvenida();
            while (!menu_grafo->quiere_salir()){
                menu_grafo->ejecutar_menu();
            }
            break;
        case MENU_INVENTARIO_ENTERO:
            menu_inventario->bienvenida();
            while (!menu_inventario->quiere_salir()){
                menu_inventario->ejecutar_menu();
            }
            break;
    }
}

void Menu::ejecutar_menu() {
    solicitar_comando();
    procesar_comando();

}

bool Menu::quiere_salir() const {
    return comando==MENU_SALIR_ENTERO;
}

Menu::~Menu() {
    delete menu_grafo;
    delete menu_inventario;
}


