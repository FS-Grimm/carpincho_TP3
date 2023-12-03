cmake_minimum_required(VERSION 3.22)

project(TP3_Carpincho)


set(CMAKE_C_STANDARD 23)
add_compile_options(-Wall -Werror -Wconversion)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")

set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)
include_directories(bGVjdG9y)

add_executable(TP3_Carpincho
        src/ArbolPlacas.cpp
        src/Arma.cpp
        src/Dijkstra.cpp
        src/Floyd.cpp
        src/Grafo.cpp
        src/InventarioArmas.cpp
        src/James.cpp
        src/Juego.cpp
        src/Matriz.cpp
        src/Menu.cpp
        src/MenuGrafo.cpp
        src/MenuInventario.cpp
        src/Placa.cpp
        src/Random.cpp
        src/Tablero.cpp
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")