#include "Tablero_grafo.hpp"

void Utils_grafo::cargar_pesos_aristas(size_t x, size_t y, Matriz& tablero, Grafo& grafo, int peso, bool saliente){
    if ( tablero.elemento(x,y) != PARED ){      // Si es una pared. No hay que conectarle nada
        if ( x > POSICION_INICIAL ){ 
            cargar_peso_arista(x,y,tablero, grafo, peso,true,false,saliente);
        }
        if ( x < POSICION_FINAL ){
            cargar_peso_arista(x,y,tablero, grafo,peso,true,true,saliente);
        }
        if ( y > POSICION_INICIAL ){
            cargar_peso_arista(x,y,tablero, grafo, peso,false,false,saliente);
        }
        if ( y < POSICION_FINAL ){
            cargar_peso_arista(x,y,tablero, grafo, peso,false,true,saliente);
        }
    }    
}

void Utils_grafo::cargar_peso_arista(size_t x, size_t y, Matriz& tablero, Grafo& grafo, int peso, bool horizontal, bool siguiente, bool saliente){
    int incremento = (siguiente) ? 1 : -1; //creo q aca la suma no va a funcionar con un negativo porq no existe size_t = -1 (es unsigned)
    if (saliente){  // Cambiamos arista de vertice origen a vertice contiguo
        if ( horizontal && ( tablero.elemento(x + incremento,y) != PARED ) ){
            grafo.cambiar_arista( x + y*(CANT_FILAS), ( x + incremento ) + y*(CANT_FILAS), peso);
        } else if ( !horizontal && tablero.elemento(x,y + incremento) != PARED ) {
            grafo.cambiar_arista( x + y*(CANT_FILAS), x + ( y + incremento )*(CANT_FILAS), peso );
        }
    } else {        // Cambiamos arista de vertice contiguo a vertice origen
        if ( horizontal && ( tablero.elemento(x + incremento,y) != PARED) ){
            grafo.cambiar_arista( ( x + incremento ) + y*(CANT_FILAS), x + y*(CANT_FILAS), peso );
        } else if ( !horizontal && tablero.elemento(x,y + incremento) != PARED ) {
            grafo.cambiar_arista( x + (y + incremento)*(CANT_FILAS), x + y*(CANT_FILAS), peso );
        }
    }
}
