//
// Created by Felipe on 21/11/2023.
//

#include <iostream>
#include "MenuGrafo.hpp"

using namespace std;


void MenuGrafo::bienvenida() {
    cout<<BIENVENIDA_GRAFO_UNO<<BIENVENIDA_GRAFO_DOS<<endl;
    cout<<ADVERTENCIA<<endl;
}
MenuGrafo::MenuGrafo() {
    grafo=new Grafo;
    comando=INVALIDO_U_ENTERO;
}

void MenuGrafo::guardar_comando_entero(const std::string &comando_s) {
    if(comando_s==COMANDO_FLOYD)
        comando=FLOYD_ENTERO;
    else if(comando_s==COMANDO_DIJKSTRA)
        comando=DIJKSTRA_ENTERO;
    else if(comando_s == M_GRAFO_COMANDO_SALIR)
        comando=M_GRAFO_SALIR_ENTERO;
    else
        comando=INVALIDO_U_ENTERO;
}

void MenuGrafo::solicitar_comando() {
    cout<<SOLICITUD_CAMINO_MINIMO_UNO<<endl;
    cout << COMANDO_DIJKSTRA << ", " << COMANDO_FLOYD << " o " << M_GRAFO_COMANDO_SALIR << SOLICITUD_CAMINO_MINIMO_DOS << endl;
    string comando_s;
    getline(cin,comando_s);
    guardar_comando_entero(comando_s);
}


size_t MenuGrafo::solicitar_origen() {
    cout<<SOLICITUD_ORIGEN<<endl;
    size_t origen;
    string recolector_basura;
    cin>>origen;
    getline(cin,recolector_basura);
    return origen;
}

size_t MenuGrafo::solicitar_destino() {
    cout << SOLICITUD_DESTINO << endl;
    size_t destino;
    string recolector_basura;
    cin >> destino;
    getline(cin, recolector_basura);
    return destino;
}

void MenuGrafo::procesar_comando() {
    switch (comando){
        case DIJKSTRA_ENTERO:
            grafo->usar_dijkstra();
            grafo->obtener_camino_minimo(solicitar_origen(),solicitar_destino());
            break;
        case FLOYD_ENTERO:
            grafo->usar_floyd();
            grafo->obtener_camino_minimo(solicitar_origen(),solicitar_destino());
            break;
    }
}

void MenuGrafo::ejecutar_menu() {
    solicitar_comando();
    procesar_comando();
}

bool MenuGrafo::quiere_salir() const {
    return comando == M_GRAFO_SALIR_ENTERO;
}

MenuGrafo::~MenuGrafo() {
    delete grafo;
}




