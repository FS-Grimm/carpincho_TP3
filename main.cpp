
#include <iostream>
#include "Tablero.hpp"
#include "Mostrar_tablero.hpp"
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
}
