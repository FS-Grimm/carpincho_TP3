#include "bGVjdG9y/bGVjdG9y.hpp"
#include "bGVjdG9y/ZGVjb2Rl.hpp"
#include <iostream>

void recorrer_vector(std::vector<Placa*> vector);
void eliminar_placas(std::vector<Placa*> vector);

int main() {
    ABB<Placa*, Placa::menor, Placa::igual> arbol_decifrador;
    bGVjdG9y::Y2FyZ2Fy(arbol_decifrador);

    std::string input = "Algo random para que itere";
    std::vector<Placa *> vector_placas;

    std::cout << "=======================================================" << std::endl;
    while (input != "N") {
        std::cout << "Ingrese opcion: ";
        getline(std::cin, input);

        if (input == "P")
            vector_placas = arbol_decifrador.preorder();
        else if (input == "I")
            vector_placas = arbol_decifrador.inorder();
        else if (input == "O")
            vector_placas = arbol_decifrador.postorder();
        else if (input == "A")
            vector_placas = arbol_decifrador.ancho();
        else if (input != "N")
            std::cout << "PIFIASTE. BOCA BOCA" << std::endl;

        if ((input == "P") || (input == "I") || (input == "O") || (input == "A"))
            recorrer_vector(vector_placas);

        std::cout << "\n=======================================================\n" << std::endl;
    }

    eliminar_placas(vector_placas);
    return 0;
}

void eliminar_placas(std::vector<Placa*> vector){
    for (Placa* i:vector)
        delete i;
}

void recorrer_vector(std::vector<Placa*> vector){
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i];
    }
}