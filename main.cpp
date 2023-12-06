
#include <iostream>
#include "Tablero.hpp"
#include "Visual.hpp"
#include "vector"
#include "Juego.hpp"
#include "Menu.hpp"
/*int iterar_mostrar(std::pair<std::vector<size_t>, int> input){
    for (size_t i = 0; i < input.first.size(); i++){
        std::cout << "(" << input.first[i]%9 << ", " << input.first[i]/9 << ")";

        if ( i + 1 != input.first.size() )
            std::cout << "->" ;
    }
    std::cout << "\nPeso total: " << input.second << std::endl;

    return 0; 
}
*/
int main(){

        std::cout << "Bienvenido " << std::endl;
        //Menu::bienvenida();
        auto menu=new Menu;

        while(!menu->quiere_salir()){
            menu->ejecutar_menu();
        }
        if (menu->gano()){
            menu->victoria();
        } else{
            menu->derrota();
        }
        delete menu;

   /* Tablero tablero = Tablero();
    tablero.usar_layout_uno();
    tablero.imprimir();
    
    tablero.alternar_estado(true);  std::cout << "----------- ARMADO -----------" << std::endl;
    iterar_mostrar(tablero.obtener_mejor_camino(0,0));
    tablero.alternar_estado(false);  std::cout << "----------- DES ARMADO -----------" << std::endl;
    iterar_mostrar(tablero.obtener_mejor_camino(0,0));

    tablero.prueba_matar_ph(true); std::cout << "----------- DES ARMADO menos 1-----------" << std::endl;
    iterar_mostrar(tablero.obtener_mejor_camino(0,0));
*/
}
