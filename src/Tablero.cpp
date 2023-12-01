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
            cargar_pesos_aristas(i,ii, (int)PESO_BASE, true);
        }
    }
}

void Tablero::cargar_pesos_aristas(size_t x, size_t y, int peso, bool saliente){
    if ( tablero[x][y] != PARED ){  // Si es una pared. No hay que conectarle nada 
        if ( x > 0 ){ 
            cargar_peso_arista(x,y,peso,true,false,saliente);
        }
        if ( x + 1 < CANT_COLUMNAS ){
            cargar_peso_arista(x,y,peso,true,true,saliente);
        }

        if ( y > 0 ){
            cargar_peso_arista(x,y,peso,false,false,saliente);
        }
        if ( y + 1 < CANT_FILAS ){
            cargar_peso_arista(x,y,peso,false,true,saliente);
        }
    }
}

void Tablero::cargar_peso_arista(size_t x, size_t y, int peso, bool horizontal, bool siguiente, bool saliente){
    int incremento = (siguiente) ? 1 : -1;
    if (saliente){  // Cambiamos arista de vertice origen a vertice contiguo
        if ( horizontal && ( tablero[x + incremento][y] != PARED ) ){
            grafo.cambiar_arista( x + y*CANT_FILAS, ( x + incremento )+ y*CANT_FILAS, peso );
        } else if ( tablero[x][y + incremento] != PARED ) {
            grafo.cambiar_arista( x + y*CANT_FILAS, x + (y + incremento)*CANT_FILAS, peso );
        }
    } else {        // Cambiamos arista de vertice contiguo a vertice origen
        if ( horizontal && ( tablero[x + incremento][y] != PARED ) ){
            grafo.cambiar_arista( ( x + incremento ) + y*CANT_FILAS, x + y*CANT_FILAS, peso );
        } else if ( tablero[x][y + incremento] != PARED ) {
            grafo.cambiar_arista( x + (y + incremento)*CANT_FILAS, x + y*CANT_FILAS, peso );
        }
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
        alternar_pyramids(tiene_arma);
        this->tiene_arma = tiene_arma;
    }
}

void Tablero::alternar_pyramids(bool pyramid_1, bool tiene_arma){
    size_t x = (pyramid_1) ? pyramid_head1.first : pyramid_head2.first; 
    size_t y = (pyramid_1) ? pyramid_head1.second : pyramid_head2.second; 
    int peso_pyramid = (tiene_arma) ? PESO_BASE : INFINITO;
    int peso_contiguo = (tiene_arma) ? PESO_BASE : PESO_BASE*MULTIPLICADOR_PYRAMID_HEAD ;
    
    // Cambiamos las aristas desde vertice contiguo hacia vertice del pyramid 
    cargar_pesos_aristas(x,y,peso_pyramid,false);
    // Cambiamos las aristas incidentes en vertices contiguos al pyramid 
    if (x > 0){
        cargar_pesos_aristas(x - 1, y, peso_contiguo, false);
        grafo.cambiar_arista(x - 1 + y*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE);
    }
    if (x + 1 < CANT_COLUMNAS){
        cargar_pesos_aristas(x + 1, y, peso_contiguo, false);
        grafo.cambiar_arista(x + 1 + y*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE);
    }
    if ( y > 0 ){
        cargar_pesos_aristas(x, y - 1, peso_contiguo, false);
        grafo.cambiar_arista(x + (y - 1)*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE);
    }
    if (y + 1 < CANT_FILAS){
        cargar_pesos_aristas(x, y + 1, peso_contiguo, false);
        grafo.cambiar_arista(x + (y + 1)*CANT_FILAS, x + y*CANT_FILAS, PESO_BASE);
    }

/*  DEBUG - Miedo que no funcione 
    if ( x > 0 ){   
        cargar_peso_arista(x, y, peso, true, false, false);
    }
    if ( x + 1 <  CANT_COLUMNAS ){
        cargar_peso_arista(x, y, peso, true, true, false);
    }
    if ( y > 0 ){
        cargar_peso_arista(x, y, peso, true, false, false);
    }
    if ( y + 1 < CANT_FILAS ) { 
        cargar_peso_arista(x, y, peso, true, true, false);
    }
*/


}

void Tablero::alternar_pyramids(bool tiene_arma){
    alternar_pyramids(true,tiene_arma);    
    alternar_pyramids(false,tiene_arma);
}


void Tablero::quitar_pyramid(size_t x, size_t y){
    if ( ( x == pyramid_head1.first ) && ( y == pyramid_head1.second ) ){
        quitar_pyramid(true);
    } else if ( ( x == pyramid_head2.first ) && ( y == pyramid_head2.second ) ){
        quitar_pyramid(false);
    }
}

void Tablero::quitar_pyramid(bool pyramid1){
    alternar_pyramids(pyramid1, true);  // Eliminamos pyramid de grafo 
    if (pyramid1){                      // Eliminamos pyramid de matriz 
        tablero[pyramid_head1.first][pyramid_head1.second] = PASILLO;
        pyramid_head1.first = CANT_COLUMNAS;
        pyramid_head1.first = CANT_FILAS;
    } else {
        tablero[pyramid_head2.first][pyramid_head2.second] = PASILLO;
        pyramid_head2.first = CANT_COLUMNAS;
        pyramid_head2.first = CANT_FILAS;
    }
}
