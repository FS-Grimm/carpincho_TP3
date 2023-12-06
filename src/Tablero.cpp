#include "Tablero.hpp"

Tablero::Tablero() {
    tablero = Matriz(CANT_COLUMNAS, (int)PASILLO);
}

void Tablero::usar_layout_uno(){
    cargar_tablero(ruta_layout1);
    cargar_pyramids();
    cargar_grafo();
}

void Tablero::usar_layout_dos(){
    cargar_tablero(ruta_layout2);
    cargar_pyramids();
    cargar_grafo();
}

void Tablero::cargar_tablero(std::string ruta_archivo){
    std::ifstream archivo(ruta_archivo);
    bool archivo_valido = archivo.is_open();

    if (archivo_valido){
        std::string linea;
        size_t lineas = 0;
        size_t indice;

        while (archivo_valido && getline(archivo,linea)){
            indice = 0;
            while ( archivo_valido && linea[indice] != '\0' ){
                if ( indice % 2 == 1 ){
                    archivo_valido = ( ( linea[indice] == ',' ) || ( linea[indice] == '\0'));
                } else if ( ( linea[indice] == '0' ) || ( linea[indice] == '1' )){
                    tablero.elemento(indice/2, lineas) = (int)(linea[indice] == '0') ? PARED : PASILLO;
                } else {
                    archivo_valido = false;
                }
                indice++;
            }

            lineas++;
        }

        archivo.close();
    }
    
    if (!archivo_valido) {

        for (size_t y = POSICION_INICIAL; y < CANT_FILAS; y++){
            for (size_t x = POSICION_INICIAL; x < CANT_COLUMNAS; x++){
                tablero.elemento(x,y) = (int)PARED;
            }
        }
        tablero.elemento(POSICION_INICIAL,POSICION_INICIAL) = (int)PASILLO;
        tablero.elemento(POSICION_FINAL,POSICION_FINAL) = (int)PASILLO;
    }
}

void Tablero::cargar_grafo(){

    grafo = Grafo(CANT_COLUMNAS * CANT_FILAS);

    for (size_t x = POSICION_INICIAL; x < CANT_COLUMNAS; x++){
        for (size_t y = POSICION_INICIAL; y < CANT_FILAS; y++){
            Utils_grafo::cargar_pesos_aristas(x,y,tablero,grafo, (int)PESO_BASE, true);
        }
    }

    alternar_estado(false);
}

std::pair<size_t,size_t> Tablero::posicion_pyramid(){
    size_t random = 1;
    size_t iter = 0;
    size_t ITER_MAX = 100; 

    bool iterar = true;
    do {
        random = (size_t) Random::random(1,CANT_COLUMNAS*CANT_FILAS - 2);
        iter++;
        iterar = ( tablero.elemento(random % CANT_FILAS,random / CANT_FILAS) != PASILLO ) && (iter < ITER_MAX );
    } while ( iterar ) ;    
    
    size_t x,y;
    if ((iter < ITER_MAX) && ( tablero.elemento(random % CANT_FILAS,random / CANT_FILAS) == PASILLO) ){
        x = random % CANT_FILAS;
        y = random / CANT_FILAS;
    } else {
        x = CANT_COLUMNAS;
        y = CANT_FILAS;
    }

    return std::pair<size_t,size_t>(x,y);
}

void Tablero::cargar_pyramids(){
    if ( Random::random(0,1) == 0 ){
        pyramid_head1 = posicion_pyramid();
        tablero.elemento(pyramid_head1.first, pyramid_head1.second) = PYRAMID_HEAD;
    }
    if ( Random::random(0,1) == 0 ){
        pyramid_head2 = posicion_pyramid();
        tablero.elemento(pyramid_head2.first, pyramid_head2.second) = PYRAMID_HEAD;
    }
}

void Tablero::alternar_estado(bool tiene_arma){
    alternar_pyramids(tiene_arma);
}

void Tablero::alternar_pyramids(bool pyramid_1, bool tiene_arma){
    size_t x = (pyramid_1) ? pyramid_head1.first  : pyramid_head2.first ; 
    size_t y = (pyramid_1) ? pyramid_head1.second : pyramid_head2.second; 
    int peso_pyramid = (tiene_arma) ? PESO_BASE : INFINITO;
    int peso_contiguo = (tiene_arma) ? PESO_BASE : PESO_BASE * MULTIPLICADOR_PYRAMID_HEAD ;
    
    Utils_grafo::cargar_pesos_aristas(x,y,tablero,grafo,peso_pyramid,false);
    if (x > 0){
        Utils_grafo::cargar_pesos_aristas(x - 1, y,tablero,grafo, peso_contiguo, false);
    }
    if (x + 1 < CANT_COLUMNAS){
        Utils_grafo::cargar_pesos_aristas(x + 1, y,tablero,grafo, peso_contiguo, false);
    }
    if ( y > 0 ){
        Utils_grafo::cargar_pesos_aristas(x, y - 1,tablero,grafo, peso_contiguo, false);
    }
    if (y + 1 < CANT_FILAS){
        Utils_grafo::cargar_pesos_aristas(x, y + 1,tablero,grafo, peso_contiguo, false);
    }

    Utils_grafo::cargar_pesos_aristas(x,y,tablero,grafo,PESO_BASE,true);



}

void Tablero::alternar_pyramids(bool tiene_arma){
    if ( ( pyramid_head1.first != CANT_COLUMNAS ) && ( pyramid_head1.second != CANT_FILAS ) ){
        alternar_pyramids(true, tiene_arma);    
    }
    if ( ( pyramid_head2.first != CANT_COLUMNAS ) && ( pyramid_head2.second != CANT_FILAS ) ){
        alternar_pyramids(false, tiene_arma);    
    }
}

void Tablero::quitar_pyramid(size_t x, size_t y){
    bool posicion_valida = ( x != CANT_COLUMNAS ) && ( y != CANT_FILAS );
    bool posicion_pyramid_head1 = ( x == pyramid_head1.first ) && ( y == pyramid_head1.second ) ;
    bool posicion_pyramid_head2 = ( x == pyramid_head2.first ) && ( y == pyramid_head2.second ) ;

    if ( posicion_pyramid_head1 && posicion_valida ){
        quitar_pyramid(true);
    } else if ( posicion_pyramid_head2 && posicion_valida ){
        quitar_pyramid(false);
    }
}

void Tablero::quitar_pyramid(bool pyramid1){
    bool pyramid_en_juego;
    if (pyramid1){
        pyramid_en_juego = ( pyramid_head1.first != CANT_COLUMNAS ) && ( pyramid_head1.second != CANT_FILAS );
    } else {
        pyramid_en_juego = ( pyramid_head2.first != CANT_COLUMNAS ) && ( pyramid_head2.second != CANT_FILAS );
    }

    if ( pyramid_en_juego ){
        alternar_pyramids(pyramid1, true);  // Eliminamos pyramid de grafo 
    }

    if (pyramid1){                      // Eliminamos pyramid de matriz 
        tablero.elemento(pyramid_head1.first, pyramid_head1.second) = PASILLO;
        pyramid_head1.first = CANT_COLUMNAS;
        pyramid_head1.first = CANT_FILAS;
    } else {
        tablero.elemento(pyramid_head2.first,pyramid_head2.second) = PASILLO;
        pyramid_head2.first = CANT_COLUMNAS;
        pyramid_head2.first = CANT_FILAS;
    }
}



bool Tablero::hay_pyramid_head_en(size_t x, size_t y) {


    if ( ( x < 0 ) || ( x >= CANT_COLUMNAS ) ){
        return false;
    }
    else if ( ( y < 0 ) || ( x  >= CANT_FILAS ) ){
        return false;
    }
    else {
        return (tablero.elemento(x, y) == PYRAMID_HEAD);
    }
}

bool Tablero::puede_moverse_a(size_t x,size_t y,size_t direccion){
    int x_final = (int) x;
    int y_final = (int) y;

    switch (direccion){
        case DIRECCION_ABAJO:       y_final -= 1; break;
        case DIRECCION_ARRIBA:      y_final += 1; break;
        case DIRECCION_IZQUIERDA:   x_final -= 1; break;
        case DIRECCION_DERECHA:     x_final += 1; break;
    }

    if ( ( x_final < 0 ) || ( x_final >= (int)tablero.columnas() ) ){
        return false;
    }
    else if ( ( y_final < 0 ) || ( y_final  >= (int)tablero.filas() ) ){
        return false;
    }
    else {
        return ( tablero.elemento((size_t)x_final, (size_t)y_final) != PARED );
    }
}

std::pair<std::vector<size_t>, int> Tablero::obtener_mejor_camino(size_t x, size_t y) {

    size_t pos = x + y*CANT_FILAS;
    grafo.usar_dijkstra();


    std::pair<std::vector<size_t>, int> resultado = grafo.obtener_camino_minimo(pos, CANT_FILAS * CANT_COLUMNAS - 1);


    return resultado;
}


bool Tablero::hay_camino(size_t x, size_t y) {
    size_t pos_james_actual = x + y * CANT_FILAS;
    std::vector<size_t> inicio;
    inicio.push_back(pos_james_actual);
    return (obtener_mejor_camino(x, y).first != inicio);
}



Matriz Tablero::obtener_matriz() {
    return this->tablero;
}

size_t Tablero::hay_pyramid_head_en(std::vector<size_t> camino) {
    size_t x_final;
    size_t y_final;
    size_t i = 0;
    bool encontrado = false;
    while ( i < camino.size() && !encontrado) {
        x_final = camino[i] % tablero.columnas();
        y_final = camino[i] / tablero.filas();
        if (tablero.elemento((size_t) x_final, (size_t) y_final) == PYRAMID_HEAD){
            encontrado = true;
        }
        i++;
    }
    return camino[i];
}

int Tablero::costo_movimiento(size_t pos_james_1, size_t pos_james_2, size_t direccion) {
    int costo = (int)PESO_BASE;
    if (hay_pyramid_head_en(pos_james_1, pos_james_2)){
        costo *= MULTIPLICADOR_PYRAMID_HEAD;
    } else {
        switch (direccion) {
            case DIRECCION_ABAJO:
                pos_james_2 += 1;
                break;
            case DIRECCION_ARRIBA:
                pos_james_2 -= 1;
                break;
            case DIRECCION_IZQUIERDA:
                pos_james_1 += 1;
                break;
            case DIRECCION_DERECHA:
                pos_james_1 = 1;
                break;
        }
        if (hay_pyramid_head_en(pos_james_1, pos_james_2)) {
            costo *= MULTIPLICADOR_PYRAMID_HEAD;
        }
    }
    return costo;
}