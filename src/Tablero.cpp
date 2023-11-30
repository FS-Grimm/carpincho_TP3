#include "Tablero.h"

void Tablero::usar_layout_uno(){
    cargar_tablero(ruta_layout1);
    cargar_grafo();
    cargar_pyramids();
}

void Tablero::usar_layout_dos(){
    cargar_tablero(ruta_layout2);
    cargar_grafo();
    cargar_pyramids();
}

void Tablero::cargar_tablero(std::string ruta_archivo){
    std::ifstream archivo(ruta_archivo);
    bool archivo_valido = archivo.is_open();

    if (archivo_valido){        // Validacion de sintaxis
        std::string linea;
        size_t lineas = 0;
        size_t indice;

        while (archivo_valido && getline(archivo,linea)){
            indice = 0;
            while ( archivo_valido && linea[indice] != '\n' ){
                if ( indice % 2 == 1 ){
                    archivo_valido = ( ( linea[indice] == ',' ) || ( linea[indice] == '\n') );
                } else if ( ( linea[indice] == '0' ) || ( linea[indice] == '1' )){
                    tablero[indice/2][lineas] = (linea[indice] == '0') ? PARED : PASILLO;
                } else {
                    archivo_valido = false;
                }
                indice++;
            }

            lineas++;
        }

        archivo.close();
    }
    
    if (!archivo_valido) {      // Pero no imaginé, que evitando la ley, en la trampa caería yo
        for (size_t i = POSICION_INICIAL; i < CANT_FILAS; i++){
            for (size_t ii = POSICION_INICIAL; i < CANT_COLUMNAS; ii++){
                tablero[i][ii] = 0;
            }
        }
        tablero[POSICION_INICIAL][POSICION_INICIAL] = 1;
        tablero[POSICION_FINAL][POSICION_FINAL] = 1;
    }
}

void Tablero::cargar_grafo(){
    grafo = Grafo(CANT_COLUMNAS * CANT_FILAS);

    for (size_t i = 0; i < CANT_COLUMNAS; i++){
        for (size_t ii = 0; ii < CANT_FILAS; ii++){
            cargar_pesos_aristas(i,ii);
        }
    }
}

void Tablero::cargar_pesos_aristas(size_t x, size_t y){
    if ( tablero[x][y] != PARED ){  // Si es una pared. No hay que conectarle nada 
        if ( x > 0 ){ 
            cargar_peso_arista(x,y,(int)PESO_BASE,true,false);
        }
        if ( x + 1 < CANT_COLUMNAS ){
            cargar_peso_arista(x,y,(int)PESO_BASE,true,true);
        }

        if ( y > 0 ){
            cargar_peso_arista(x,y,(int)PESO_BASE,false,false);
        }
        if ( y + 1 < CANT_FILAS ){
            cargar_peso_arista(x,y,(int)PESO_BASE,false,true);
        }
    }
}

void Tablero::cargar_peso_arista(size_t x, size_t y, int peso, bool horizontal, bool siguiente){
    int incremento = (siguiente) ? 1 : -1;
    if ( horizontal && ( tablero[x + incremento][y] != PARED ) ){
        grafo.cambiar_arista( x + y*CANT_FILAS, ( x + incremento )+ y*CANT_FILAS, peso );
    } else if ( tablero[x][y + incremento] != PARED ) {
        grafo.cambiar_arista( x + y*CANT_FILAS, x + (y + incremento)*CANT_FILAS, peso );
    }
}

std::pair<size_t,size_t> Tablero::posicion_pyramid(){
    // Nota, conviene iterar rand() porque es O(1) en tiempo y memoria auxiliar (o eso dicen)
    size_t random = 1; 
    size_t iter = 0;
    size_t ITER_MAX = 100; 
    do {
        random = rand() % ( CANT_COLUMNAS*CANT_FILAS - 2 ) + 1; // Numero entre 1 y 79
        iter++;
    }
    while ( ( tablero[ random % CANT_FILAS ][ random / CANT_FILAS ] != PASILLO ) && (iter < ITER_MAX)) ;    
    
    std::pair<size_t,size_t> result;
    if ((iter < ITER_MAX) && (tablero[ random % CANT_FILAS ][ random / CANT_FILAS ] == PASILLO)){
        result = std::pair<size_t,size_t>((random % CANT_FILAS),(random / CANT_FILAS));
    }
    else {
        result = std::pair<size_t,size_t>((CANT_FILAS),(CANT_COLUMNAS));
    }

    return result;
}

void Tablero::cargar_pyramids(){
    if ( rand()%2 == 0 ){   // Pyramids!!!
        pyramid_head1 = posicion_pyramid();
        pyramid_head2 = posicion_pyramid();
    }

    bool pyramid_head1_valido = ( pyramid_head1.first < CANT_COLUMNAS ) && ( pyramid_head1.second < CANT_FILAS);
    bool pyramid_head2_valido = ( pyramid_head2.first < CANT_COLUMNAS ) && ( pyramid_head2.second < CANT_FILAS);

    if ( pyramid_head1_valido && pyramid_head2_valido ){
        tablero[pyramid_head1.first][pyramid_head1.second] = PYRAMID_HEAD;
        tablero[pyramid_head2.first][pyramid_head2.second] = PYRAMID_HEAD;
    }
}

void Tablero::alternar_estado(bool tiene_arma){
    if ( this->tiene_arma != tiene_arma ){
        alternar_pyramids(true,tiene_arma);
        alternar_pyramids(false,tiene_arma);
        this->tiene_arma = tiene_arma;
    }
}

void Tablero::alternar_pyramids(bool pyramid_1, bool tiene_arma){
    size_t x = (pyramid_1) ? pyramid_head1.first : pyramid_head2.first; 
    size_t y = (pyramid_1) ? pyramid_head1.second : pyramid_head2.second; 

    if (tiene_arma){
        if ( x > 0 ){
            grafo.cambiar_arista( x - 1 + y*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE );
        }
        if ( x + 1 <  CANT_COLUMNAS ){
            grafo.cambiar_arista( x + 1 + y*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE );
        }
        if ( y > 0 ){
            grafo.cambiar_arista( x + (y - 1)*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE );           
        }
        if ( y + 1 < CANT_FILAS ) { 
            grafo.cambiar_arista( x + (y + 1)*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE );           
        }
    } else {
        if ( x > 0 ){   // Solo cambiamos aristas incidentes en los pyramid
            grafo.cambiar_arista( x - 1 + y*CANT_FILAS, x + y*CANT_FILAS, INFINITO );
        }
        if ( x + 1 <  CANT_COLUMNAS ){
            grafo.cambiar_arista( x + 1 + y*CANT_FILAS, x + y*CANT_FILAS, INFINITO );
        }
        if ( y > 0 ){
            grafo.cambiar_arista( x + (y - 1)*CANT_FILAS, x + y*CANT_FILAS, INFINITO );           
        }
        if ( y + 1 < CANT_FILAS ) { 
            grafo.cambiar_arista( x + (y + 1)*CANT_FILAS, x + y*CANT_FILAS, INFINITO );           
        }
    }
}

void Tablero::quitar_pyramid(size_t x, size_t y){
    if ( ( x == pyramid_head1.first ) && ( y == pyramid_head1.second ) ){
        quitar_pyramid(true);
    } else if ( ( x == pyramid_head2.first ) && ( y == pyramid_head2.second ) ){
        quitar_pyramid(false);
    }
}

void Tablero::quitar_pyramid(bool pyramid1){
    
}
