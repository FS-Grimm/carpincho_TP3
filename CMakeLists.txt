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
        src/Placa.cpp
        src/Arma.cpp
        src/InventarioArmas.cpp
        src/MenuInventario.cpp
        src/Matriz.cpp
        src/Grafo.cpp
        src/Dijkstra.cpp
        src/Floyd.cpp
        src/MenuGrafo.cpp
        bGVjdG9y/bGVjdG9y.cpp
        bGVjdG9y/ZGVjb2Rl.cpp
        src/Menu.cpp
        main.cpp
        src/Juego.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")