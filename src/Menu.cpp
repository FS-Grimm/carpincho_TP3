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
    cout<<SOLICITUD_MENU_UNO<< COMANDO_MENU_INVENTARIO << " o " << COMANDO_MENU_GRAFO << SOLICITUD_MENU_DOS << M_GRAFO_COMANDO_SALIR << SOLICITUD_MENU_TRES << endl;
    string comando_s;
    getline(cin,comando_s);
    guardar_comando_entero(comando_s);
}

void Menu::procesar_comando() {
    switch (comando) {
        case MENU_GRAFO_ENTERO:
            MenuGrafo::bienvenida();
            do{
                menu_grafo->ejecutar_menu();
            } while (!menu_grafo->quiere_salir());
            cout<<MENU_SALIDA_GRAFO<<endl;
            break;
        case MENU_INVENTARIO_ENTERO:
            MenuInventario::bienvenida();
            do{
                menu_inventario->ejecutar_menu();
            } while (!menu_inventario->quiere_salir());
            cout<<MENU_SALIDA_INVENTARIO<<endl;
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


