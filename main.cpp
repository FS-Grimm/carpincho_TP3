
#include <iostream>
#include "Tablero.h"


int iterar_mostrar(std::pair<std::vector<size_t>, int> input){
    for (size_t i = 0; i < input.first.size(); i++){
        std::cout << "x: " << input.first[i]%9 << ", y: " << input.first[i]/9 << "\n";
    }
    std::cout << "\nPeso total: " << input.second << std::endl;

    return 0; 
}

int main(){
    Tablero tablero = Tablero();
    tablero.usar_layout_uno();
    tablero.imprimir();
    
    tablero.alternar_estado(true);  std::cout << "----------- ARMADO -----------" << std::endl;
    iterar_mostrar(tablero.obtener_mejor_camino());
    tablero.alternar_estado(false);  std::cout << "----------- DES ARMADO -----------" << std::endl;
    iterar_mostrar(tablero.obtener_mejor_camino());

    tablero.prueba_matar_ph(true); std::cout << "----------- DES ARMADO menos 1-----------" << std::endl;
    iterar_mostrar(tablero.obtener_mejor_camino());

}
