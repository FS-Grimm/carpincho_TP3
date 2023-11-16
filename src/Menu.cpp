//
// Created by Felipe on 18/11/2023.
//

#include <iostream>
#include "Menu.hpp"

using namespace std;

string Menu::pasar_prioridad_string(bool prioridad) {
    string prioridad_s;
    if (prioridad)
        prioridad_s=PEOR;
    else
        prioridad_s=MEJOR;
    return prioridad_s;
}
void Menu::cambiar_prioridad() {
    string prioridad_actual= pasar_prioridad_string(!inventario->obtener_prioridad());
    string prioridad_nueva= pasar_prioridad_string(!inventario->obtener_prioridad());
    inventario->cambiar_prioridad();
    cout << CAMBIO_PRIORIDAD_UNO << prioridad_actual << " a " << prioridad_nueva << CAMBIO_PRIORIDAD_DOS << endl;
}
