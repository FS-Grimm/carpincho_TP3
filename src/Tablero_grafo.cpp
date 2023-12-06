#include "Tablero_grafo.hpp"

void Utils_grafo::cargar_pesos_aristas(size_t x, size_t y, Matriz& tablero, Grafo& grafo, int peso, bool saliente){
    if ( tablero.elemento(x,y) != PARED ){      // Si es una pared. No hay que conectarle nada
        if ( x > POSICION_INICIAL ){ 
            cargar_peso_arista(x,y,peso,true,false,saliente);
        }
        if ( x < POSICION_FINAL ){
            cargar_peso_arista(x,y,peso,true,true,saliente);
        }
        if ( y > POSICION_INICIAL ){
            cargar_peso_arista(x,y,peso,false,false,saliente);
        }
        if ( y < POSICION_FINAL ){
            cargar_peso_arista(x,y,peso,false,true,saliente);
        }
    }    
}
