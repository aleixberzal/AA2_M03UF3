#include <iostream>
#define BOTTLE_NUM 6


void print_table() {
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < BOTTLE_NUM; j++) {
            std::cout << " \\  /  ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOTTLE_NUM; j++) {
            std::cout << "  | |  ";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < BOTTLE_NUM; j++) {
        std::cout << "  ```  ";
    }
    std::cout << std::endl;
}