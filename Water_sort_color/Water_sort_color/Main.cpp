#include <iostream>
#include <vector>
#include "table.h"
#define BOTTLE_NUM 6
#define LIQUID_CLASS 4
/*Niveles para acceder a los liquidos de las diferentes botellas*/
#define MAX_LEVEL 3
#define MAX_ATTEMPTS 10 


int main() {
    srand(time(0)); // Inicializar la semilla para números aleatorios

    // Inicializar las botellas
    std::vector<std::vector<char>> bottles(BOTTLE_NUM, std::vector<char>(MAX_LEVEL, ' '));
    instantiate_bottles(bottles);

}

