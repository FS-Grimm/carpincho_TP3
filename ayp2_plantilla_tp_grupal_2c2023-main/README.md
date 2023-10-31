# Los Desafios de James

Trabajo Práctico Grupal de Algoritmos y Programación 2 2c2023.

### Integrantes del grupo CARPINCHO:

1. TESTA, Santiago - 108301  -  sttesta@fi.uba.ar
2. CENICEROS, Valentino - 111054 - vceniceros@fi.uba.ar
3. TAUREL, Felipe - Padron - Mail_FIUBA
4. SANTELLAN, Felipe Martin - 109022 - fsantellan@fi.uba.com

### Corrector asignado:

Julian Ruiz Diaz

## Compilación:

El programa se puede compilar utilizando el **CMakeLists.txt** que está en el repositorio o bien ejecutando por consola:

> g++ -I include src/*.cpp main.cpp -o main -Wall -Werror -Wconversion

Al compilar con **CMake**, se deben agregar todos los archivos **.cpp** en la línea:

> add_executable(ayp2_plantilla_tp_grupal_2c2023 main.cpp //otros archivos .cpp//)

## Tests:

Para ejecutar los tests, basta con cargar el **CMakeLists.txt** que se encuentra dentro de la carpeta tests/.

## Organización de archivos:

En la carpeta src/ van a encontrar los archivos .cpp del proyecto.<br>
En la carpeta include/ van a encontrar los headers del proyecto.<br>
