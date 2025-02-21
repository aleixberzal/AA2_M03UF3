// table.cpp
#include "table.h"
#include <iostream>
#include <cstdlib>

#define BOTTLE_NUM 6
#define LIQUID_CLASS 4
#define MAX_LEVEL 3
#define MAX_ATTEMPTS 10

char rand_liquid() {

    /*Función para generar un líquido de tipo random*/
    char liquids[LIQUID_CLASS] = { 'O', 'X', 'S', '#' };
    return liquids[rand() % LIQUID_CLASS];
}

void print_table(const std::vector<std::vector<char>>& bottles) {
    /*Función para imprimir las mismas botellas*/
    /*Tapón*/
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < BOTTLE_NUM; j++) {
            std::cout << "  \\ /   ";
        }
        std::cout << std::endl;
    }

    /*Ponemos entre los pipes, el líquido randomizado anteriormente*/
    for (int i = 0; i < MAX_LEVEL; i++) {
        for (int j = 0; j < BOTTLE_NUM; j++) {
            std::cout << "  |" << bottles[j][i] << "|   ";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < BOTTLE_NUM; j++) {
        std::cout << "  ```   ";
    }
    std::cout << std::endl;

    for (int j = 1; j < BOTTLE_NUM + 1; j++) {
        std::cout << "   " << j << "    ";
    }
    std::cout << std::endl;
}

/*Función para instanciar las botellas*/
void instantiate_bottles(std::vector<std::vector<char>>& bottles) {
    /*Variable de botellas llenas, hacemos que sean dos de ellas de manera random*/
    int full_bottles[2] = { rand() % BOTTLE_NUM, rand() % BOTTLE_NUM };
    /*Mientras la botella llena sea la misma que la segunda llena, generamos un número random para que se llene otra*/
    while (full_bottles[0] == full_bottles[1]) { 
        full_bottles[1] = rand() % BOTTLE_NUM;
    }
    /*Seleccionamos dos botellas aleatoriamente y las llenamos desde abajo */
    for (int i = 0; i < 2; i++) {
        for (int j = MAX_LEVEL - 1; j >= 0; j--) {
            bottles[full_bottles[i]][j] = rand_liquid();
        }
    }
    /*Seleccionamos las botellas restantes y las llenamos pero no del todo*/
    for (int i = 0; i < BOTTLE_NUM; i++) {
        if (i != full_bottles[0] && i != full_bottles[1]) { 
            int num_liquids = rand() % 2 + 1;
            for (int j = MAX_LEVEL - 1; j >= MAX_LEVEL - num_liquids; j--) {
                bottles[i][j] = rand_liquid();
            }
        }
    }
    print_table(bottles);
}

