#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

#include <string>
#include <vector>

// CONSTANTES DE JAMES
const std::vector<std::string> ARMAS_BAJA_POTENCIA = {"cuchillo", "palo", "tuberia_oxidada", "crowbar"};
const std::vector<std::string> ARMAS_MEDIA_POTENCIA = {"pistola_9mm", "revolver_22", "recortada_12"};
const std::vector<std::string> ARMAS_ALTA_POTENCIA = {"escopeta_12", "rifle_caza", "revolver_44_magnum"};

// CONSTANTES JUEGO
const int CHANCE_DE_NUEVA_ARMA=20;

// CONSTANTES MOSTRAR TABLERO 
#define PARED_EMOJI "\U0001f9f1"
#define CAMINO_MINIMO_EMOJI "\U0001f7e5"
#define JAMES_EMOJI "\U0001f471"
#define PYRAMID_CABEZA_EMOJI "\U0001f479"
#define PISO_EMOJI "\u2B1C"

const int INDICADOR_PARED = 0;
const int INDICADOR_PISO = 1;
const int INDICADOR_PYRAMID = 2;
const int INDICADOR_JAMES= 3;
const int CAMINO_MINIMO = 4;

// CONSTANTES TABLERO 
const size_t DIRECCION_ARRIBA=1;
const size_t DIRECCION_DERECHA=2;
const size_t DIRECCION_IZQUIERDA=3;
const size_t DIRECCION_ABAJO=4;

const size_t CANT_FILAS = 9;
const size_t CANT_COLUMNAS = 9;
const size_t CANT_PYRAMIDS = 2;

const size_t PARED = 0;
const size_t PASILLO = 1;
const size_t PYRAMID_HEAD = 2;

const size_t POSICION_INICIAL = 0;
const size_t POSICION_FINAL = 8;

const size_t PESO_BASE = 10;
const size_t MULTIPLICADOR_PYRAMID_HEAD = 5;

const std::string ruta_layout1 = "config/layout1.csv";
const std::string ruta_layout2 = "config/layout2.csv";

#endif